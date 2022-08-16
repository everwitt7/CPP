#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>

void natNumDiv3And5() {
    unsigned int limit = 0;
    std::cout << "Upper Limit:";
    std::cin >> limit;

    unsigned long long sum = 0;
    for (unsigned int i = 3; i < limit; ++i) {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    std::cout << "sum=" << sum << std::endl;
}

// if we are using recursion should we not pass by reference...
// we change the values of `a` and `b`
unsigned int gcd(unsigned int const a, unsigned int const b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm (int const a, int const b) {
    return a * b / gcd(a, b);
}

// using templates
template<class InputIt>
int lcmr(InputIt first, InputIt last)
{
    return std::accumulate(first, last, 1, lcm);
}

bool isPrime(int const num) {
    if (num <= 3) { return num > 1; }
    else if (num % 2 == 0 || num % 3 == 0) { return false; }
    else {
        for (int i = 5; i * i < num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

void sexyPrimes(unsigned int limit) {
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i) && isPrime(i+6)) {
            std::cout << i << ", " << i+6 << std::endl;
        }
    }
}

std::string toRoman(unsigned int num) {
    std::vector<std::pair<unsigned int, char const*>> roman {
        { 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" },
        { 100, "C" }, { 90, "XC" }, { 50, "L" }, { 40, "XL" },
        { 10, "X" }, { 9, "IX" }, { 5, "V" }, { 4, "IV" }, { 1, "I" }
    };

    std::string result;
    for (auto const & kvp : roman) {
        while (num >= kvp.first) {
            result += kvp.second;
            num -= kvp.first;
        }
    }
    return result;
}

int main() 
{
    std::cout << toRoman(43);

    return 1;
}