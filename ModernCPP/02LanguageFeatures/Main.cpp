#include <vector>
#include <array>
#include <iostream>
#include <sstream>

// IPv4 is dot separated digits that can have values 0-255
class ipv4
{
    // 1 piece of memory for each number in the IP address
    std::array<unsigned char, 4> data;

public:
    constexpr ipv4() : data{{0, 0, 0, 0}} {}
    constexpr ipv4(unsigned char const a,
                   unsigned char const b,
                   unsigned char const c,
                   unsigned char const d) : data{{a, b, c, d}} {}
    explicit constexpr ipv4(unsigned long a) : data{{
                                                   static_cast<unsigned char>((a >> 24) & 0xFF),
                                                   static_cast<unsigned char>((a >> 16) & 0xFF),
                                                   static_cast<unsigned char>((a >> 8) & 0xFF),
                                                   static_cast<unsigned char>(a & 0xFF),
                                               }}
    {
    }
    ipv4(ipv4 const &other) noexcept : data(other.data) {}
    ipv4 &operator=(ipv4 const &other) noexcept
    {
        data = other.data; 
        return *this;
    }

    std::string toString() const
    {
        std::stringstream sstr;
        sstr << *this;
        return sstr.str();
    }

    constexpr unsigned long to_ulong() const noexcept
    {
        return (static_cast<unsigned long>(data[0]) << 24) |
               (static_cast<unsigned long>(data[1]) << 16) |
               (static_cast<unsigned long>(data[2]) << 8) |
               static_cast<unsigned long>(data[3]);
    }

    friend std::ostream &operator<<(std::ostream &os, const ipv4 &a)
    {
        std::cout << "PRINTING TO STDOUT" << std::endl;
        os << static_cast<int>(a.data[0]) << '.'
           << static_cast<int>(a.data[1]) << '.'
           << static_cast<int>(a.data[2]) << '.'
           << static_cast<int>(a.data[3]);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ipv4& a)
    {
        char d1, d2, d3;
        int b1, b2, b3, b4;
        is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
        if (d1 == '.' && d2 == '.' && d3 == '.')
            a = ipv4(b1, b2, b3, b4);
        else
            is.setstate(std::ios_base::failbit);
        return is;
    }
};

int
main()
{
    std::cout << "Running" << std::endl;
    // constexpr ipv4() : data{{a, b, c, d}} {}
    // numbers of 8 bits can be expressed as char datatype
    // because char is just 8 bits (1 byte)
    ipv4 address(168, 192, 0, 1);
    // friend std::ostream &operator<<(std::ostream &os, const ipv4 &a)
    // is the function that is called
    // std::cout << address << std::endl;
    address.toString();

    // ipv4 ip;
    // constexpr ipv4() : data{{0, 0, 0, 0}} {}
    // std::cout << ip << std::endl;

    // std::cin >> ip;
    // if(!std::cin.fail())
        // std::cout << ip << std::endl;
}