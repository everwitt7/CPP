#include <iostream>
#include "Log.h"

/* 
for some reason the debugger ONLY works when I include the Log.cpp file, otherwise
the debugger DOES NOT do the linking that it needs to. #include .cpp of whatever file I need,
which is unwise... OR...?

What I figured out - I need to go through User Guide and C++ on VSCode...
https://stackoverflow.com/questions/69860487/vscode-c-debugger-mac-not-linking-cpp-files/69860528#69860528
 
 Synopsis: in order to set up the C++ debugger, you need to create launch.json and task.json in the
 .vscode folder at the root of the project directory. In the tasks.json you must update the g++
 command to compile and link ALL .cpp files so that we do not get linking errors where a function
 is declared but not defined. I had to do the exact same thing for the code-runner extension
 */

/* 
A "breakpoint" is a point in the code at which the debugger will break (stop) and allow you to inspect the value
of variables, we can look at the "state" of the program (the memory of the program)

I need to read through VSCodes debugging page, but everything is working at the moment - I just know there
are useful features I am currently unaware of. For example, I was not able to locate the memory address of
the variables, which would be a very useful feature, and I need to get used to looking at variables in 
hexadecimal
 */

int main()
{
    int var = 9;
    const char *x = "my program";
    long num = 234893;

    for (int i = 0; i < 10; i++)
    {
        std::cout << x[i] << std::endl;
    }

    Log("hello world!");
}
