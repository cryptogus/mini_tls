#pragma once

#include <iostream>
#include <vector>

namespace base64
{

    std::string encode(std::vector<unsigned char> v);

    std::vector<unsigned char> decode(const std::string& s);

} // namespace base64