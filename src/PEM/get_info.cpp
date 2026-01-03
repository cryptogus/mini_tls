#include "get_info.hpp"

namespace PEM
{
std::string get_certificate_core(std::istream& is)
{
    std::string s, r;
    while(s != "-----BEGIN") // -----BEGIN CERTIFICATE-----
    {
        if (!(is >> s))
        {
            return r;
        }
    }
    getline(is, s); // skip the rest of the BEGIN line
    for (is >> s; s != "-----END"; is >> s) // -----END CERTIFICATE-----
    {
        r += s;
    }
    return r;
}
} // namespace PEM