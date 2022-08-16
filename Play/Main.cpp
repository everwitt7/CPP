#include <iostream>
#include <cstdint>

class RGBA
{
public:
    using dtype = std::uint_fast8_t;

private:
    dtype m_red{};
    dtype m_green{};
    dtype m_blue{};
    dtype m_alpha{};

public:
    RGBA(dtype m_red = 0, dtype m_green = 0, dtype m_blue = 0, dtype m_alpha = 255)
        : m_red{m_red}, m_green{m_green}, m_blue{m_blue}, m_alpha{m_alpha}
    {
    }
    void print()
    {
        std::cout << "r=" << static_cast<int>(m_red)
                  << " g=" << static_cast<int>(m_green)
                  << " b=" << static_cast<int>(m_blue)
                  << " a=" << static_cast<int>(m_alpha) << std::endl;
    }
};

int main()
{
    RGBA teal{0, 127, 127};
    teal.print();

    return 0;
}