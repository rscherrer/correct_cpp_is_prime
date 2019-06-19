#include <cassert>
#include <string>
#include <iostream>


/// Function to check the number of arguments
void checkNumArguments(const int &argc)
{
    if (argc != 2) {
        throw std::runtime_error("Error: invalid number of arguments.\n");
    }
}


/// Function to determine if an integer is prime
bool isPrime(const int &value) noexcept
{

    // A prime number must be more than one
    if (value <= 1) {
        return false;
    }
    else {
        // Try to find a divisor
        for (int divisor = 2; divisor != value / 2 + 1; ++divisor) {
            if (!value % divisor) {
                return true;
            }
        }
    }
    return false;
}


int main(int argc, char* argv[])
{
    try
    {

        // Check number of arguments
        checkNumArguments(argc);

        // Convert argument into a number
        const int value{std::stoi(argv[1])};

        // Determine if the number is prime
        const bool isNumberPrime = isPrime(value);

        // Display the result
        isNumberPrime ? std::cout << "true\n" : std::cout << "false\n";

    }
    catch (const std::runtime_error&)
    {
        return 1;
    }
    catch (const std::invalid_argument&)
    {
        return 1;
    }
    catch (const std::out_of_range&)
    {
        return 1;
    }
}
