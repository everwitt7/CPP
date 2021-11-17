// removing static will lead to a duplicate symbol linker error
#include <string>
static int var = 8;
static void Function()
{
}

class Person
{
public:
    static std::string p = "person";
};