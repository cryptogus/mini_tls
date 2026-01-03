#include "base64.hpp"

namespace base64
{
    // Convert 6-bit value to Base64 character
    static char b2c(unsigned char b)
    {
        if (b < 26)
            return 'A' + b;
        if (b < 52)
            return 'a' + (b - 26);
        if (b < 62)
            return '0' + (b - 52);
        if (b == 62)
            return '+';
        return '/';
    }

    // Convert Base64 character to 6-bit value
    static unsigned char c2b(char c)
    {
        if (c >= 'A' && c <= 'Z')
            return c - 'A';
        if (c >= 'a' && c <= 'z')
            return c - 'a' + 26;
        if (c >= '0' && c <= '9')
            return c - '0' + 52;
        if (c == '+')
            return 62;
        if (c == '/')
            return 63;
        return 0; // Invalid character
    }

    std::string encode(std::vector<unsigned char> v)
    {
        std::string s;
        int padding = (3 - (v.size() % 3)) % 3; // Calculate padding for 3-byte blocks
        v.insert(v.end(), padding, 0); // Pad with zeros
        for (size_t i = 0; i < v.size(); i += 3)
        {
            unsigned char b1 = v[i];
            unsigned char b2 = v[i + 1];
            unsigned char b3 = v[i + 2];
            s += b2c((b1 >> 2) & 0x3F); // First 6 bits
            s += b2c(((b1 & 0x3) << 4) | ((b2 >> 4) & 0xF)); // Second 6 bits
            s += b2c(((b2 & 0xF) << 2) | ((b3 >> 6) & 0x3)); // Third 6 bits or padding
            s += b2c(b3 & 0x3F); // Fourth 6 bits or padding
        }
        for (int i = 0; i < padding; ++i)
            s[s.size() - 1 - i] = '='; // Replace last characters with '=' for padding
        return s;
    }

    std::vector<unsigned char> decode(const std::string& s)
    {
        std::vector<unsigned char> v;
        size_t padding = 0;
        for (size_t i = s.size(); i > 0 && s[i - 1] == '='; --i)
        {
            ++padding; // Count padding characters
        }
        for (size_t i = 0; i < s.size(); i += 4)
        {
            unsigned char c1 = c2b(s[i]);
            unsigned char c2 = c2b(s[i + 1]);
            unsigned char c3 = c2b(s[i + 2]);
            unsigned char c4 = c2b(s[i + 3]);

            v.push_back((c1 << 2) | (c2 >> 4));
            v.push_back(((c2 & 0xF) << 4) | (c3 >> 2));
            v.push_back(((c3 & 0x3) << 6) | c4);
        }
        v.resize(v.size() - padding); // Remove padding bytes

        return v;
    }
}