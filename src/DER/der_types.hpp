/**
 * @file der_types.hpp
 */

#pragma once

#include <cstdint>

namespace ber
{
//----------------------------------
// Define
//----------------------------------
/**
 * @brief A class represents what kind of data it is
 */
enum DerClass : uint8_t
{
    UNIVERSAL,
    APPLICATION,
    CONTEXT_SPECIFIC,
    PRIVATE
};
/**
 * @brief
 */
enum  DerPC : uint8_t
{
    PRIMITIVE,
    CONSTRUCTED
};
enum  DerTag : uint8_t
{
    EOC,
    BOOLEAN,
    INTERGER,
    BIT_STRING,
    OCTET_STRING,
    NULL_TYPE,
    OBJECT_INDENTIFIER,
    OBJECT_DESCRIPTOR,
    EXTERNAL,
    REAL,
    ENUMERATED,
    EMBEDDED_PDV,
    UTF8STRING,
    RELATIVE_OID,
    RESERVED1,
    RESERVED2,
    SEQUENCE,
    SET,
    NUMBER_STRING,
    PRINTABLE_STRING,
    T61_STRING,
    VIDEOTEX_STRING,
    IA5_STRING,
    UTCTIME,
    GENERALIZED_TIME,
    GRAPHIC_STRING,
    VISIBLE_STRING,
    GENERAL_STRING,
    UNIVERSAL_STRING,
    CHARACTER_STRING,
    BMP_STRING
};

//----------------------------------
// Structure
//----------------------------------
union DerType
{
    uint8_t value;
    struct
    {
        DerTag tag : 5;
        DerPC pc : 1;
        DerClass cls : 2;
    };
};

} //namespace ber