/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief lesson on classes
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#define LOG(x) std::cout << x << std::endl;
/**
 * @brief defining a player class - basically this class has DATA (attributes, which are variables)
 * and functions to MANIPULATE that data (methods)
 * Anything you can do with classes you could have done WITHOUT classes - they add no new functionality,
 * they just make organization of code easier. This is why languages like C exist and they are perfectly fine,
 * we just use classes to make our life easier
 */

class Player
{
public:
    int x, y;
    int speed;
    void Move(int xa, int ya)
    {
        // no need to pass player by reference, we have access to all the object's attributes (x, y, speed, etc...)
        x += xa * speed;
        y += ya * speed;
    }
}; //NEEDS a semicolon

// function to move a player: however, it would be better to make this a method internal to the class!
void Move(Player &player, int xa, int ya)
{
    // need to pass player by reference because we are updating its attributes
    player.x += xa * player.speed;
    player.y += ya * player.speed;
}

int main()
{
    int PlayerX, PlayerY; //coordinates of a player
    int PlayerSpeed = 2;

    // what if we want to add another player!?
    int Player2X, Player2Y;
    int Player2Speed = 3;

    // what if we want to move a player
    // func(int& x, int&y, int speed)...
    // the point is this gets messy incredibly quickly, using classes makes organization so much better

    // using classes:
    Player player;
    player.x = 5; // we need the member variable of player to be PUBLIC if we are going to access it... default is private
    player.speed = 2;
    LOG(player.x);
    Move(player, 2, 1);
    LOG(player.x);
    player.Move(-2, -1); // exact same functionality as Move function
    LOG(player.x);
}

/**
 * @brief the only difference between a STRUCT and a CLASS is that by default a class makes everything private
 * and a struct makes everything public. So for classes you have to explicitly say that something is public
 * and for structs you have to explicitly say that something is private
 * 
 * Structs are here to maintain backwards compatibility with C. Semantically, Cherno and others use structs to
 * define just data and methods without very complex functionality. Structs are not supposed to contain a massive
 * amount of functionality like classes
 * 
 * Cherno will never use structs for inheritance, only classes. He only wants structs to be structures of data 
 */
struct Vec2
{
    float a, b;

    void Add(const Vec2 &other) //very simple function for adding two Vec2 structs together
    {
        a += other.a;
        b += other.b;
    }
};