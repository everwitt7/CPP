/* 
We get a compiler error "identifier "Log" is undefined when we try and run this log init function without
declaring that the function log exists. The compiler needs to know that this function exists somewhere so
that the linker can link the function. Thus, we must DECLARE the Log function here, and then compiling will
work and the linker will link this Log function to the one DEFINED in Main.cpp

What happens if I want another file to use this Log function, then I would have to declare it there too. In 
theory yes, that is exactly what you have to do, but there is an easier way to DECLARE functions, and that
is using header files.

Commented out function and moved it to Log.h
 */
// void Log(const char *message);
#include "Log.h"
#include <iostream>

void InitLog()
{
    Log("Initializing Log");
}

void Log(const char *message)
{
    std::cout << message << std::endl;
}