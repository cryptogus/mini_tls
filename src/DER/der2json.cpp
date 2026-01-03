#include "der2json.hpp"
#include <iomanip>

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

    static Json::Value read_constructed(std::istream& is, size_t len)
    {
        Json::Value jv;
        uint32_t start_pos = is.tellg();
        uint8_t c;
        for (uint32_t i = 0, l; static_cast<uint32_t>(is.tellg()) - start_pos < len && is >> std::noskipws >> c; i++)
        {
            ber::DerType der_type = ber::read_type(c);
            l = ber::read_len(is);
            jv[i] = der_type.pc == ber::PRIMITIVE ?
                     type_change(der_type.tag, ber::read_value(is, l)) :
                     read_constructed(is, l);
        }
        return jv;
    }

    Json::Value der2json(std::istream& is)
    {
        Json::Value jv;
        uint8_t c;
        for (uint32_t i = 0, l; is >> std::noskipws >> c; i++)
        {
            ber::DerType der_type = ber::read_type(c);
            l = ber::read_len(is);
            jv[i] = der_type.pc == ber::PRIMITIVE ?
                     type_change(der_type.tag, ber::read_value(is, l)) :
                     read_constructed(is, l);
        }
        return jv;
    }

} // namespace json