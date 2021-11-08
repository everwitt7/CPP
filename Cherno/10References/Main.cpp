/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief a lesson on references
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#define LOG(x) std::cout << x << std::endl
/**
 * @brief there is nothing a reference can do that a pointer cannot do. We can use references to make the style
 * of our code shorter and more readable. 
 */

void Increment(int val)
{
    // this does nothing because it creates a copy and does not alter the variable you passed in
    // int val = 5, then adds 1
    val++;
}

/**
 * @brief this does the same thing as IncPtr but with significantly less syntax. It is nicer to use
 * write things with references when you can - at the end of the day they are just aliases for a variable, and
 * references can only be used for variables that already exist, you cannot instantiate a reference as a new
 * variable like you can for a pointer, e.g. int *ptr = 10; (stores memory address of 0x0...0a)
 */
void IncRef(int &val)
{
    val++;
}

void IncPtr(int *val)
{
    // need to dereference the pointer before adding
    (*val)++;
}

int main()
{
    int var = 5;
    int &ref = var; // creates an alias for var, but when we compile this is subsistuted for var.
    int *ptr = &var;
    Increment(var);
    LOG(var); // still 5 because the function above does not alter var
    IncRef(var);
    LOG(var);
    IncPtr(ptr);
    LOG(var);

    // what happens when we try and switch a reference?
    int bvar = 8;
    LOG(bvar);
    // ref = bvar;
    LOG(var); //ref = bvar set the value of var to 8 instead of changing ref. Once a ref is created it cannot be changed

    // you can, however, change the memory address that a pointer points to (which is the desired functionality above)
    int *aptr = &var;
    // *aptr = 9; // would set var = 9
    aptr = &bvar;
    // *aptr = 2; // would set bvar = 2
    LOG(*aptr); //output is 8 because we have changed the integer value of aptr from the memory address of var to the
    // memory address of bvar
}