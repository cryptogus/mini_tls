#pragma once

#include "der_types.hpp"
#include <iostream>
#include <vector>

namespace ber
{
    DerType read_type(uint8_t c);
    size_t read_len(std::istream& is);
    std::vector<uint8_t> read_value(std::istream& is, size_t len);
}