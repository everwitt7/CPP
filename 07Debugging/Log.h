/* 
What is #pragma once?
This tells the compiler during preprocessing to ONLY include this header file once. Specifically, it does not
allow us to include this header into the SAME translation unit more than once. Imagine in Main.cpp we include
Log and Print, and imagine in Print that we include Log, then we would be including Log twice in Main.cpp, and
#pragma once tells the compiler to only copy and paste the contents of Log.h once into Main.cpp

#pragma once is a "header guard" Another way to do this would be to wrap the entire header file in:
#ifndef _HEADER
#define _HEADER
<header>
#endif
This works the same way where if the _HEADER is present, then the compiler does not inject the header twice
during preprocessing. The #ifndef was the legacy way to guard against duplicate headers.
 */
#pragma once

void InitLog();
void Log(const char *);
