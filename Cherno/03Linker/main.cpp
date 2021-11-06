/* 
This is a "preprocessor statement"... anything that contains a # is a preprocessor statement
#include, #define, #if, #ifdef are the most common preprocessor statements that we use
and #pragma statements

The first thing a compiler does when it receives a source file is preprocess all of the 
preprocessor statements, that is anything that begins with a hash. This gets done before compilation, so
imagine something going through this file, reading the #include statements, substituting the code it 
represents into this file, and then finally compiling that larger file

#include statements are similar to imports in python - it takes all of the contents of the file
<iostream> and pastes it into the top of the current file. We generally include header files.

Question: if you include headers only, how does the program know the actual functionality of the functions, etc?
> I believe the answer to this question is linking - here we have the declaration for a function, but it finds
the definition of that function in the log.cpp file. So when you add a header you basically inject a bunch of
of function declarations into the current .cpp file, then it is the linkers job to find the object files that
contain the definition for those declared functions (I believe you can declare classes and other data too)

One potential issue you could face is defining a function twice, but like don't do that. That is basically the
same thing as naming the same function twice in python WITH the same signature, that is, same data inputs
*/
#include <iostream>

/*
We are including the print header file in both main.cpp and print.cpp. Remember that calling
include basically copies and pastes the contents of that file into this file, so because we 
DEFINED the function in the header file, we will have two definitions for the same function.

For some reason this is not erroring...?
We are creating duplicate symbols, i.e. void Print(const char *message) is defined both
in this file, main.cpp AND in print.cpp and neither is static, so it should throw an error.
One way to remedy this would be to add 'static' to the function definition in print.h, or 
add 'inline' in the print.h, but the best thing to do is to DECLARE the function in the header,
and DEFINE the function in the .cpp file. Then including #include "print.h" will include the
DECLARATION and the linker will find the DEFINITION elsewhere (in this case, in print.cpp)
*/
#include "print.h"
void Print(const char *message);

/*
g++ -o main main.cpp log.cpp
I needed to compile both programs, log.cpp and main.cpp in order to get this to work - building just the Log.cpp
works, but building just main.cpp does not work and I get a linker error:
CPP  ❯ g++ -o main main.cpp
Undefined symbols for architecture x86_64:
  "Log(char const*)", referenced from:
      _main in main-ad029b.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)

My understanding - each declaration needs a definition, because we declare a function the compiler looks for the
definition but finds none and this leads to a linker error. So basically, when we declare a function but do not
provide a definition with a body then we will keep getting this error.
*/
const char *Log(const char *message);
// This method has NO DEFINITION because I changed the name in log.cpp to Logger, but running this program
// with no call to Log in the main function allows the function to be built because the linker does not
// try to link this function. However, if we call Log in another function, e.g. Mult, even if we do not call
// Mult in the main there will still be a linker error because we could call this Mult function in a different
// .cpp file. The way to fix this error is to add the keyword 'static' to the function, which tells the compiler
// that ONLY this .cpp file will use this function, no other cpp file will use it. So now if we do not call
// Mult in the main the linker will work because it knows NOT to link Mult any other .cpp file, so it does
// not need to know the definition of the Log function just yet.

/*
'static' tells the compiler that I will only ever use this function in this file, no where else. This is 
important for compilation reasons. If I call Log in Math, the linker will try 

add and remove static from the function to see what it does
*/
static int Mult(int a, int b)
{
    Log("multiply");
    return a * b;
}

int main()
{
    /*
    we move the log function into its own cpp file, log.cpp. When we run the compiler it will compile each
    *.cpp file seperately, and then it needs something that LINKS the files together. 

    Keywords:
    - Declaration:  this just states that a function exists
    - Definition:   this defines exactly what a function does

    Declarations are basically functions without a body, definitions are functions with a body specifying
    what that function does       

    */

    /*
    > g++ -o main main.cpp && ./main (compiles, links, AND runs the binary executable file)
    > g++ -c -o main main.cpp (just compiles)

    > g++ -o main main.cpp (tries to both link and compile)
    Undefined symbols for architecture x86_64:
    "Log(char const*)", referenced from:
        _main in main-f30cc3.o
    ld: symbol(s) not found for architecture x86_64
    clang: error: linker command failed with exit code 1 (use -v to see invocation)
    ***
    We can still compile AND link without calling Log(msg) in the main

    However, if we define int Mult(args) without the static keyword, even if we do not call Mult in the main
    function we get this linking error because the linker thinks that another .cpp file might use this
    function Mult, so it needs to link Log, but it cannot link log because there is no definition for it

    If we define static int Mult(args) the linker will work because static makes sure the 
    linker knows that only this translation unit (TODO: difference between an object file and transunit?)
    is the only file that will use this function. NOTE: I would ALWAYS be able to compile all of these examples 
    without errors, but sometimes linking will cause errors.

    NOTE: "build" means BOTH compiling AND linking (g++ -o main main.cpp)
    "compile" just means compiling (g++ -c -o main main.cpp)
    */
    // Log("hello world!!!");

    /* 
    BIG TAKEAWAY: you should NEVER have to include a .cpp file in another .cpp file, you should
    ONLY ever have to include the header of a translation unit.
     */
    Print("asdf");
    return 0;
}
/*
each *.cpp file in our project gets compiled, header files DO NOT get compiled
header files only get included via preprocessor statements #include <header.h>
It's when you include a header file in a cpp file that it gets compiled...
*/

/*
We need to go from this raw text file to a binary file, which is a two step process: compiling, then linking.
So all our compiler needs to do is create intermediate object files that can then be passed to the linker.

The compiler is responsible for two things: taking our text file and creating constant data or instructions

Every time the compiler receives what it thinks is a .cpp file, it will create a "translation unit", and
a translation unit will result in an object file. Object files contain machine code, but it is only one part of
the application, we need all the .cpp files's machine code to get the executable that runs the whole program

Question: where are my object files? or are these intermediary steps, so the g++ compiler just creates the
object files then passes them to the linker which generates the binary and I do not see the intermediate
steps?

Question: what is an Abstract Syntax Tree?

BUILD means COMPILE & LINK but NOT run the executable: cmd + shift + b (shortcut)
Starting build...
> g++ -fdiagnostics-color=always -g *.cpp -o /Users/Everwitt/Documents/SoftwareEng/CPP/07Debugging/Main
Build finished successfully.
*/