/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief virtual functions
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <iostream>
#define log(x) std::cout << x << std::endl

class Entity
{
public:
    virtual std::string GetName() { return "Entity"; }
};

/**
 * @brief we need to specify that the function GetName should have different functionality when called for an Entity
 * or a Player. We use the keyword `virtual` to denote that we will OVERRIDE this parent function in a child class. 
 * Also, it is proper syntax to add the keyword `override` to the child function that corresponds with the virtual
 * function and create a 1:1 correspondence, which will help prevent errors that occur mistyping. 
 * `virtual` creates a Vlookup table and places that function in it, but more on this later... what is a Vlookup table?
 * 
 * There are two runtime costs: 
 * additional memory for the vtable
 * everytime we call a virtual function we need to go through that vtable
 */
class Player : public Entity
{
private:
    std::string m_Name;

public:
    Player(const std::string &name)
    {
        m_Name = name;
    }
    // warning: 'override' keyword is a C++11 extension [-Wc++11-extensions], need to pass -std=c++11 in g++ flags
    std::string GetName() override
    {
        return m_Name;
    }
};

// when we have a pointer to a class we use -> instead of . to access member variables and methods
void PrintName(Entity *entity)
{
    log(entity->GetName());
}

int main()
{
    Entity *e = new Entity();
    PrintName(e);
    Player *p = new Player("Everett");
    PrintName(p);
}