#include <cassert>
#include <string>
#include <iostream>
#include <vector>


/// Function to check the number of arguments
void checkNumArguments(const size_t &argc)
{
    if (argc != 2) {
        throw std::runtime_error("Error: Invalid number of arguments.");
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


/// Function to run the main task
int doMain(const std::vector<std::string> &args)
{
    try
    {

        // Check number of arguments
        checkNumArguments(args.size());

        // Convert argument into a number
        const int value{std::stoi(args[1u])};

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

    return 0;
}


/// Function to test the task performing behavior of the program
void testUse()
{
    assert(doMain( { "correct_cpp2", "1"} ) == 0);
    assert(doMain( { "correct_cpp2", "3"} ) == 0);
    assert(doMain( { "correct_cpp2", "-1"} ) == 0);
}


/// Function to test the error handling behavior of the program
void testAbuse()
{
    assert(doMain( { "correct_cpp2", "nonsense"} ) == 1);
    assert(doMain( { "correct_cpp2", "123456789123456789"} ) == 1);
    assert(doMain( { "correct_cpp2", "1", "7"} ) == 1);
    assert(doMain( { "correct_cpp2"} ) == 1);
}


/// Function to test the program
void test()
{
    testUse();
    testAbuse();
}


/// Program to determine if a number is prime
int main(int argc, char* argv[])
{

    // Preparation
    const std::vector<std::string> args(argv, argv + argc);

    // Test the program
    test();

    // Run the program
    return doMain(args);
}
