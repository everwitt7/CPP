#include <iostream>

/* 
there really isn't much new to learn from this video, but the main point is this:
we generally DECLARE functions in header files and DEFINE functions in translations units (or cpp files)
 */
int Mult(int a, int b)
{
    return a * b;
}

int main()
{
    std::cout << "hello world" << std::endl;
}