/**
 * @file Main.cpp
 * @author everett
 * @brief lesson on inheritance
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#define log(x) std::cout << x << std::endl

class Entity
{
public:
    float x, y;
    Entity() // if you do not set x and y then you get some random value in memory
    {
        x = 0;
        y = 0;
        a = 10;
        b = 1;
    }
    void Move(float xa, float ya)
    {
        x += xa;
        y += ya;
    }

private:
    unsigned int a;

protected:
    unsigned int b;
    void PrintMe()
    {
        log("protected method");
    }
};

// class Player
// {
// public:
//     float x, y;
//     void Move(float xa, float ya)
//     {
//         x += xa;
//         y += ya;
//     }
//     const char *name;
//     void PrintName()
//     {
//         std::cout << name << std::endl;
//     }
// };

// what if it did inherit PRIVATE?
class Player : public Entity
{
    const char *name;
    void PrintName()
    {
        std::cout << name << std::endl;
    }

public:
    void PPrint()
    {
        PrintMe();
    }
};

int main()
{
    Player p;
    p.Move(5, 5); // we can call the functions from Entity that seemingly do not exist in Player
    log(p.x);
    // log(p.a);         // error: 'a' is a private member of 'Entity'
    log(sizeof(Entity)); // 2 floats, 2 unsigned ints is 4 * 4 bytes = 16 bytes
    log(sizeof(Player)); // 8 extra because because of the const char *
    log(sizeof(char *)); // a const char pointer is 8 bytes
    p.PPrint();          // this works!
}
/**
 * @brief creating a subclass is simple, `class Child : public Parent` is the syntax, and basically this does something
 * very similar to include. It copies the PUBLIC code defined in Parent and pastes it into the Child class. This means
 * we can access member variables that are public and call methods that are public - the functionality is inhereted. It
 * also means we can pass Player into ANY argument that expects entity because it has all of the functionality.
 * Although with private variables this might be different?
 */