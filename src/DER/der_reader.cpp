#include "der_types.hpp"

namespace ber
{
    DerType read_DER_type(uint8_t c)
    {
        DerType tmp;
        tmp.value = c;
        return tmp;
    }
}