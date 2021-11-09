#include <iostream>
#include <string>

/**
 * @brief A good example of why we would not want to make everything public is changing the location of a button. We might be
 * able to change the X and Y coordinates of the button but we might need to refresh the dispaly to move the button to that
 * new location. If we make X and Y private we cannot alter them by obj.X = newVal; instead we need to call some setter, and
 * in that public setter we might both change the value of X and Y AND call refresh on the display. This makes things easier
 * for another human using the code, because they know NOT to ever touch the private methods. They should not change the values
 * of X and Y directly but instead should call the methods to update them. 
 * 
 * At the end of the day, we use private, public, and protected (visibility) to make things easier for other humans using
 * and altering the code.
 */
class Entity
{
private: // ONLY this class (or friends) can access these attributes and methods
    unsigned int X;
    void Print() {}

protected: // subclasses may access these attributes and methods
    unsigned int Y;
    void PrintY() {}

public: // everyone can access these attributes and methods, you can have a public Method do something with a protected var
    Entity()
    {
        X = 0;
        Print();
    }
};

class Player : public Entity
{
public:
    Player()
    {
        // X = 5; // still cannot X of the parent class because it is private
        // Print(); // same with methods
        Y = 10; // subclass CAN access protected attributes and methods of parent class
    }
};

int main()
{
    Entity e;
    // e.X; // X is inaccessible because it is private
    // e.Print(); // still not accessible
    Player p;
    // p.Y = 11; // cannot access Y from main, ONLY can access it from within the class Player
}