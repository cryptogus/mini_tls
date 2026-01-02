#include "der_types.hpp"
#include <iostream>
#include <vector>

namespace ber
{
    DerType read_DER_type(uint8_t c)
    {
        DerType tmp;
        tmp.value = c;
        return tmp;
    }
    /**
     * istream is the C++ standard input stream class.
     * It provides an interface for reading data into a program,
     * whether from the keyboard (`cin`), files (`ifstream`), or strings (`istringstream`).
     * Common operations include the extraction operator (`>>`), `getline()`, `get()`, and `read()`.
     * It is the base class for all input stream types in C++.
     * */
    std::vector<uint8_t> read_len(std::istream& is)
    {
        uint8_t c;
        if (!(is >> std::noskipws >> c))
            throw "reached eof in read_len";

        std::vector<uint8_t> v;
        if (c & 0x80) // Length represented using multiple byte
        {
            for (uint32_t i = 0, j = c & 0x7F; i < j; i++) // length is in 2 ~ 127 Byte
            {
                is >> c;
                v.push_back(c); // v's Bytes size will be same with c & 0x7F
            }
        }
        else
        {
            v.push_back(c);
        }
        return v;
    }
}

int main()
{
    return 0;
}