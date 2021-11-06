#include <iostream>

/**
 * @brief print a message to standard output
 * 
 * @param msg the message to be printed
 */
void log(const char *msg)
{
    std::cout << msg << std::endl;
}
void log(unsigned int msg)
{
    std::cout << msg << std::endl;
}

/**
 * @brief prints all numbers divisible by 3 and 5 up to the limit
 * 
 * @param limit Integer at which we stop finding numbers divisible by 3 or 5
 */
void printDivThreeFive(int limit)
{
    for (int n = 0; n <= limit; n++)
    {
        if (n % 3 == 0 || n % 5 == 0)
        {
            std::cout << n << std::endl;
        }
    }
}

/**
 * @brief prints the greatest common divisor of the two integers
 * 
 * @param bigger first integer
 * @param smaller second integer
 * @return unsigned int that is the greatest common diviser
 */
unsigned int greatestCommonDiv(unsigned int bigger, unsigned int smaller)
{
    // break down each unsigned int into a list primes and pop common primes and multiply?
    // Use the Euclidean Algorithm to find the GCD
    // Recursive process - bigger modulo smaller, if this is 0, then return bigger.
    // If not, bigger = bigger - smaller * bigger modulo smaller. call greatestCommonDiv(smaller, bigger)
    return smaller == 0 ? bigger : greatestCommonDiv(smaller, bigger % smaller);
}

/**
 * @brief calculate the least common multiple of two numbers
 * 
 * @param a first number
 * @param b second number
 * @return unsigned int that is the least common multiple
 */
unsigned int leastCommonMult(unsigned int a, unsigned int b)
{
    // Example: LCM(2,3) = 6 and LCM(6,10) = 30
    // Equation: lcm(a, b) = abs(a * b) / gcd(a, b)
    return a * b / greatestCommonDiv(a, b);
}

/**
 * @brief returns the largest prime number smaller than the input a
 * 
 * @param a the unsigned int threshold for the smallest int
 * @return unsigned int the smallest prime number
 */
unsigned int smallestPrime(unsigned int a)
{
}

// @todo add a test structure to verify the functions work
int main()
{
    // Sum of naturals divisible by 3 and 5
    // printDivThreeFive(20);

    // Greatest common diviser
    // unsigned int gcd = greatestCommonDiv(20, 4);
    // log(gcd);

    // Least common multiple
    // unsigned int lcm = leastCommonMult(3, 7);
    // log(lcm);

    // Largest prime smaller than given number
}