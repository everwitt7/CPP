#include "Log.h"

int main()
{
    /* 
    because we #include "Log.h" we can call the function DECLARED there and DEFINED in Log.cpp
    Interesting error, when running 
    > g++ -o main Main.cpp
    Undefined symbols for architecture x86_64:
    "Log(char const*)", referenced from:
        _main in main-ad178a.o
    "InitLog()", referenced from:
        _main in main-ad178a.o
    ld: symbol(s) not found for architecture x86_64
    clang: error: linker command failed with exit code 1 (use -v to see invocation)

    Which means that the functions Log(char const*) and InitLog() were DECLARED but NOT DEFINED. Which is weird
    because we are including Log.h which should have those function declaration. We need to ALSO compile AND
    link Log.cpp, which contains the definitions for thos functions.

    Note: Undefined symbols for architecture x86_64: => Declared NOT Defined
    > g++ -o main Main.cpp Log.cpp
    compiles and links successfully and running the executable generates the correct output

    > g++ -o main *.cpp (for compiling many cpp files in this directory that need to be linked)
     */
    InitLog();
    Log("hello world!");
}
