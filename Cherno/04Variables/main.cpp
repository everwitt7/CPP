#include <iostream>
/* 
When we create a variable it is stored in memory, in one of two places: either the stack or the heap
Question: what is the STACK, what is the HEAP in cpp?

A big question when it comes to cpp's primitive datatypes and figure out which one to use
is the size. How much memory do you want to allocate to a variable?
*/
int main()
{

    /* an integer is generally a datatype that is 4 bytes large, that is 4*8=32 bits, or 32 transistors. This means
    that the maximum value you can assign to an integer is 2^32... that is the case only for an UNSIGNED INT, 
    but a signed int would be -1*(2^32/2), to 2^32/2 -1, by two's complement. 

    It is actually the COMPILER that chooses how large a datatype will be. So if my integer is signed, which is the
    default assumption and >2^31-1, then the size in bits will double to 64, so it will take up 8 bytes of memory
    rather than 4. Then the compiler will say the variable is a long int, etc... it can go up to 64 bits of memory
    which stores a massive number 2^64 = 1.84467441e19
     */
    int var = 8;
    unsigned int varTwo = 3245;

    std::cout << var << std::endl;

    var = 20;

    std::cout << var << "   " << varTwo << std::endl;
    /* 
    Types of vars
    1 byte, 2 bytes, 4 bytes, 4 bytes, 8 bytes  , 4 bytes, 8 bytes, 1 byte
    char  , short  , int    , long   , long long, float  , double , bool (0 false, everthing else true)
    NOTE: all of these variables can be unsigned, which just lets you set a larger number with the same
    number of bytes
    NOTE: you can assign numbers and letters to char, because it is just one byte of data, and characters
    are just a mapping to some number 
    NOTE: bools MUST be 1 byte because of computer architecture, but they only NEED to be 1 bit, so you can
    store 8 bools in the same BYTE of memory to minimize the memory you use!
     */
    char c = 65;
    char d = 'A';
    std::cout << c << "   " << d << std::endl;
    // the number associated with the character 'A' is 65, it is just a mapping

    short a = 66;
    short b = 'B';
    std::cout << a << "   " << b << std::endl;
    // now the reverse happens, when we give it a character value, it maps that to a numeric value

    // floats NEED to be defined with an f at the end otherwise it becomes a double
    // hover mouse over the variables and you will see 'h' is (double)(4.5)
    float f = 4.5f;
    double g = 4.5;
    float h = 4.5;

    // actually printing out the the size of each primitive data type
    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(short) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long) << std::endl;
    std::cout << sizeof(long long) << std::endl;
    std::cout << sizeof(float) << std::endl; //note this is 8 bytes of data!
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(bool) << std::endl;

    // Pointers and References will be touched on later

    return 0;
}
