/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
// now we can call LOG(x) on any piece of data and it will replace LOG(x) with std:cout...
#define LOG(x) std::cout << x << std::endl
/**
 * A pointer is a an integer that stores a memory address. I give examples of binary and hexadecimal values
 * stored in a byte of data, which referred to the value of a variable. But how do we know which memory address
 * contains that value? Pointers are literally some integer represented by hexadecimal that points to an
 * address of memory. Memory is like one big list, and we can index the part of memory to get our variable's 
 * value. Each element in the list of memory is 1 BYTE of data (8 bits, 2 hex). 
 * 
 * A pointer just denotes the address of a byte of data, but how do you know HOW LONG that data is supposed 
 * to be? e.g. long long vs short? Types do not matter, the value of a pointer is always an integer for all
 * types. If we give a pointer a type we just tell it how many bytes of data to use. But this does not change
 * what a pointer is.
 * 
 * A pointer is like any other variable, it just has a memory address integer instead of a value
 */
int main()
{
    // setting a ptr to nullptr, NULL, and 0 all do the same thing - they point to an integer, 0, which is
    // an invalid memory address or one that does not exist (kind of like indexing OOB) but this is legal.
    // changing the type of this pointer CHANGES NOTHING
    void *ptr = nullptr; // no type to this pointer, there is no need!
    if (ptr == NULL)
    {
        LOG("pointer is NULL");
    }
    if (ptr == 0)
    {
        LOG("pointer is 0");
    }

    // set the value of a variable in memory
    int var = 8;
    // set the integer value of varPtr to the memory address that stores the value of var
    int *varPtr = &var;
    // Output: 0x7ffee0019374, which means memory has 16^12 possible values...
    LOG(varPtr);

    // this is called DEREFERENCING a pointer, it looks at the value stored at the memory address of the pointer
    // this is important because if we change int *varPtr to be a char *varPtr and try to write to the address
    // there will be an error because the number of bytes for those data types is different
    *varPtr = 10;
    // value is now 10 even though we never change the value of var we manipulated it's memory address and changed it
    LOG(var);

    /**
     * @brief everything we defined above is using STACK memory. To use HEAP memory we can use the keyword new
     * I could be wrong but I believe it is better to use stack memory. If we use heap memory we must remember to
     * delete it, otherwise we basically just shrink the size of our memory and take a performance hit or the cpu
     * will be fully maxed out
     */
    char *buffer = new char[8]; // we want this buffer pointer to allocate 8 bytes of memory (char is 1 byte)
    memset(buffer, 0, 8);
    char **doublePointer = &buffer; // we get the memory address of the buffer pointer and store it in a new pointer
    delete[] buffer;                // we need to delete the data that we put on heap memory

    /**
     * @brief we can have pointers to pointers, because a pointer is just a variable with an integer value, and 
     * this is stored in memory somewhere!
     */
}
