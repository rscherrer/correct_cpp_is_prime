#include <cassert>
#include <string>
#include <iostream>


/// Function to check the number of arguments
void checkNumArguments(const int &argc)
{
    if (argc != 2) {
        throw std::runtime_error("Error: Invalid number of arguments.\n");
    }
}


/// Function to determine if an integer is prime
bool isPrime(const int &value) noexcept
{

    // A prime number must be more than one
    if (value > 1) {

        // Try to find a divisor
        for (int divisor = 2; divisor != value / 2 + 1; ++divisor) {
            if (value % divisor == 0) {
                return false;
            }
        }

    }
    else {
        return false;
    }
    return true;
}


/// Program to determine if a number is prime
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
    catch (const std::runtime_error &err)
    {
        std::cout << err.what() << '\n';
        return 1;
    }
    catch (const std::invalid_argument&)
    {
        std::cout << "Error: Argument is not an integer.\n";
        return 1;
    }
    catch (const std::out_of_range&)
    {
        std::cout << "Error: Number too big for an integer.\n";
        return 1;
    }
}
