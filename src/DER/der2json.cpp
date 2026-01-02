#include "der_reader.hpp"
#include <json/json.h>

namespace json
{
    static Json::Value type_change(ber::DerTag tag, std::vector<uint8_t> v)
    {
        switch(tag)
        {
            case ber::EOC:
            case ber::BOOLEAN:
                return static_cast<bool>(v[0]) ? true : false;
            case ber::INTEGER:
            case ber::BIT_STRING:
            case ber::OCTET_STRING:
            case ber::NUMBER_STRING:
            case ber::OBJECT_INDENTIFIER:
            case ber::OBJECT_DESCRIPTOR:
            {
                std::stringstream ss;
                for (uint8_t byte : v)
                {
                    ss << std::hex << std::setw(2) << std::setfill('0') << +byte << ':';
                }
                return ss.str();
            }
            case ber::NULL_TYPE:
                return "null";
            case ber::EXTERNAL:
            case ber::REAL:
                return *(reinterpret_cast<float*>(v.data()));
            case ber::ENUMERATED:
            case ber::EMBEDDED_PDV:
            case ber::RELATIVE_OID:

            default:
            {
                std::stringstream ss;
                for (uint8_t byte : v)
                {
                    ss << byte;
                }
                return ss.str();
            }
        }
    }
} // namespace json