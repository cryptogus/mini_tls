#pragma once

#include "der_reader.hpp"
#include <json/json.h>

namespace json
{
    Json::Value der2json(std::istream& is);
} // namespace json