/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief static being used in functions
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#define Log(x) std::cout << x << std::endl;

// this will print 1 five times
void IncI()
{
    int i = 0;
    i++;
    Log(i)
}

int i = 0;
void Inc()
{
    i++;
    Log(i)
}

/**
 * @brief we can get the exact same desired behavior as the previous Inc() function that increments i everytime the function
 * is called but this time we are creating the variable in a local scope to that function rather than a global scope.
 * Whenever we use the static keyword we are basically saying that its scope is local to this translational unit, or 
 * local to this class, or local to this function.
 */
void staticInc()
{
    static int a = 0;
    a++;
    Log(a);
}

// we can rewrite this class using static
// class Singleton
// {
// private:
//     static Singleton *s_Instance;

// public:
//     static Singleton &Get()
//     {
//         return *s_Instance;
//     }

//     void Hello()
//     {
//     }
// };
// Singleton *Singleton::s_Instance = nullptr;

/**
 * @brief we are using static for BOTH the class AND the method. static Singleton &Get() means that the class has one
 * function that affects all instances of the class (in this case there should only be one instantiation because it is
 * a singleton class). Next the static Singleton instance defined inside the method means that when we call that method we
 * are always refering to the exact SAME instance.
 * 
 * Stack variables GET DELETED. Heap variables do not get deleted UNLESS YOU EXPLICITLY tell them to, e.g. calling a
 * destructor or delete on the heap variable. static Singleton instance is a HEAP variable, but Singleton instance is
 * a STACK variable and would be deleted immediately after the function is called, which would ruin the desired
 * functionality because you would not be referring to the same Singleton instance but rather would be creating a new
 * temporary one and the deleting it everytime you called the Get() function. We basically return a REFERENCE to the
 * instance so this would return different instances every time the funcition is called (i think i messed up the
 * explanation above in some parts)
 */
class Singleton
{
private:
    Singleton *s_Instance;

public:
    static Singleton &Get()
    {
        static Singleton instance; //if you remove static you are creating this variable ON THE STACK
        return instance;
    }
    void Hello()
    {
    }
};

int main()
{
    // prints 1 five times
    IncI();
    IncI();
    IncI();
    IncI();
    IncI();
    // increments i because it is now global
    Inc();
    Inc();
    Inc();

    Singleton::Get().Hello();
}