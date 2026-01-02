#include "der_types.hpp"
#include <iostream>
#include <vector>

namespace ber
{
    static DerType read_type(uint8_t c)
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
    static size_t read_len(std::istream& is)
    {
        uint8_t c;
        if (!(is >> std::noskipws >> c))
            throw "reached eof in read_len";

        if (c & 0x80) // Length represented using multiple byte
        {
            size_t len = 0;
            for (uint32_t i = 0, j = static_cast<uint32_t>(c & 0x7F); i < j; i++) // length is in 2 ~ 127 Byte
            {
                if (j > sizeof(size_t))
                {
                    std::cerr << "Length > size_t is not supported. Use big number library.";
                    return 0;
                }

                is >> c;
                len = len << 8 | c;
            }

            return len;
        }
        else
        {
            return static_cast<size_t>(c);
        }
    }

    std::vector<uint8_t> read_value(std::istream& is, size_t len)
    {
        std::vector<uint8_t> v(len);
        for (size_t i = 0; i < len; i++)
        {
            uint8_t c;
            if (!(is >> std::noskipws >> c))
                throw "reached eof in read_value";

            v[i] = c;
        }
        return v;
    }
}