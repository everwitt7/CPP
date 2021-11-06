#include "Log.h"

/* 
If statements causes the program to branch, so checking conditions in these if statements does carry
some overhead, and if you are trying to optimize speed, you would want to cut down on the number of
branches in your program. So how can you write code with the same functionality without if statements? 
Just something to keep in mind... don't try and write code without conditionals!
 */

int main()
{
    int x = 5;
    // x == 5 basically checks the bytes of x and the bytes of 5 and makes sure that they are equal
    bool comp = x == 5;
    if (comp)
    {
        Log("hello world!");
    }

    // when the conditional only spans one line, curly brackets are optional
    if (x)
        Log("i do not need curly brackets");
    else
        Log("run me");

    const char *ptr = "Hello";
    if (ptr)
        Log(ptr);
}

/* 
There are two different parts to programming, Mathematical and Logical programming. Mathematical being
no branches and just doing mathematical operations. For example, dot-product, linear algebra, etc... And
Logical which is conditional and all about logic. Generally, Mathematical is fast and Logical is slower.
 */