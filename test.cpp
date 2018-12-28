#include <iostream>
#include <sstream>
int main()
{
    std::cout << "The number 42 in octal:   " << std::oct << 175 << '\n'
              << "The number 42 in decimal: " << std::dec << 175 << '\n'
              << "The number 42 in hex:     " << std::hex << 175<< 175 << '\n';
    int n;
    std::istringstream("FF") >> std::hex >> n;
    std::cout << std::dec << "Parsing \"FF\" as hex gives " << n << '\n';
    // the output base is sticky until changed
    std::cout << std::hex << "42 as hex gives " << 42
        << " and 21 as hex gives " << 21 << '\n';
}
