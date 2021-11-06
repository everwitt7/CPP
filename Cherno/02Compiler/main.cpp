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
void Log(const char *message);

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
    Log("hello world!!!");
    // std::cin.get();

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
*/