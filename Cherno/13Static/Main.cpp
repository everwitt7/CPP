/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief static in translational units
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#define log(x) std::cout << x << std::endl;
/**
 * @brief static acts similar to the word private for classes. When you use static in a cpp file to declare a function
 * or a variable, it makes the scope of that function or variable local only to that cpp file - it is NOT global. Making things
 * global can lead to linker errors if we have the same variable or function defined with the same name (and signature)
 * 
 * we get "duplicate symbol for architecture x86_64" when we run this code and do not make var static in Second.cpp,
 * but if we make it static then that is fine because we basically have 1 global var and 1 local var of the same name
 * and the local var has precedent over the globabl var. Think about configuration files (settings for all projects,
 * then settings for a specific project in VSCode. Settings for .zshrc and .gitconfig are in /etc, ~/.zshrc). This is an
 * identical concept. 
 */

int var = 10;
void Function()
{
}

struct Entity
{
    static int x, y;
    static void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

// int main()
// {
//     Entity e1;
//     e1.x = 5;
//     e1.y = 3;

//     Entity e2;
//     e2.x = 9;
//     e2.y = 7;

//     e1.Print();
//     e2.Print();
// }
/**
 * @brief this is equivalent to the previous main method, which shows exactly why we are getting 9, 7 to print
 * when we run both e1.Print() and e2.print(). This is because static in classes and structs functions differently
 * then it does in translational units (cpp files). Using static makes a function or variable global to ALL instances of
 * a given class. You could think of each instance having a pointer that points to the exact same memory address, so when
 * once instance changes that value it changes the value for ALL instances. 
 * 
 * Static methods can ONLY use static variables, not attributes that are specific to a class because static functions do not
 * have an object that they are a part of. They live outside of the object, as you can see we namespace the struct and then
 * call the static function, we do not need to use an object name to call that static method. 
 * "a static method does not have a class instance"
 * 
 * In python we can think about this in terms of class methods. We pass cls into the class methods and self into the
 * object methods.  
 */
int main()
{
    Entity::x = 5;
    Entity::y = 3;

    Entity::x = 9;
    Entity::y = 7;

    Entity::Print();
    Entity::Print();

    // Person p;
    // log(p.p);

    // added after to test static when using a class from a different translational unit
}

/**
 * @brief this is basically what the static Print() method looks like, which is why it will error on x and y if they 
 * are not static variables beacuse there is no reference for them. They are undefined, not linked
 */
void Print()
{
    // Main.cpp:87:18: error: use of undeclared identifier 'x'; did you mean 'Entity::x'?
    // std::cout << x << ", " << y << std::endl;
}

/**
 * @brief this is what an object does - it passes the class in as an input to a method, and then you can access the
 * variables of that object. This is why in python we pass in "self" and "cls" for certain methods.  
 */
void Print(Entity e)
{
    std::cout << e.x << ", " << e.y << std::endl;
}