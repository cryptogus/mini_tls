#include <iostream>
#include "der_types.hpp"

int main()
{
    ber::DerType types = {.tag = ber::BMP_STRING, .pc = ber::PRIMITIVE,.cls = ber::PRIVATE};
    printf("value: %02X\n", types.value);
    if (types.value == 0xDE)
        std::cout << "Success" << std::endl;
    return 0;
}