/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief interface
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <iostream>
#define log(x) std::cout << x << std::endl

/**
 * @brief this defines a PURE virtual function, which makes this class 'Printable' and interface. That is, any class that
 * inherits from it (or is derived from it) MUST implement the function 'GetClassName()'. We denote a pure virtual
 * function by setting the function equal to 0;
 */
class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual std::string GetName() { return "Entity"; }
    std::string GetClassName() override { return "Entity"; }
};

/**
 * @brief we make EVERY class the inherits from Printable NEED to define the function GetClassName(). This is also nice
 * because we can use Printable as an input to some function, which guarantees that any class we pass in MUST have the
 * function declared in the interface defined in the subclass. So we know we can pass Player, Entity, A, or any class
 * that inherits from Printable.
 * 
 * A good example of using an interface would be trading bots. Say you create different trading bots that use different logic
 * to predict what tickers they want to buy, regardless of how they calculate it, they all need to generate some 
 * GetPositions() function that describes the stocks they want to purchase. This is nice because you can create an interface,
 * pass that into a function, and then use any derivation of a TradingBot and make the logic for calculating what to buy
 * as complex as you want. You are guaranteed to be able to call GetPositions() on that subclass though and get the output
 * in some defined form, e.g. a list.
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
    std::string GetName() override
    {
        return m_Name;
    }
    std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity *entity)
{
    log(entity->GetName());
}

void PrintClassName(Printable *print)
{
    log(print->GetClassName());
}

class A : public Printable
{
    std::string GetClassName() override { return "A"; }
};

int main()
{
    Entity *e = new Entity();
    // PrintName(e);
    Player *p = new Player("Everett");
    // PrintName(p);
    PrintClassName(e);
    PrintClassName(p);
    PrintClassName(new A); // this is a memory leak, do not do this - we allocate memory to the heap and never delete it
}
