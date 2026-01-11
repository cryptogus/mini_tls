/**
 * @file handshake_hdr.hpp
 */

#pragma once

#include <cstdint>

//----------------------------------
// Define
//----------------------------------
enum HandShakeType : uint8_t
{
    HELLO_REQUEST = 0x00,
    CLIENT_HELLO = 0x01,
    SERVER_HELLO = 0x02,
    CERTIFICATE = 0x0b,
    SERVER_KEY_EXCHANGE = 0x0c,
    CERTIFICATE_REQUEST = 0x0d,
    SERVER_DONE = 0x0e,
    CERTIFICATE_VERIFY = 0x0f,
    CLIENT_KEY_EXCHANGE = 0X10,
    FINISHED = 0x14
};
//----------------------------------
// Structure
//----------------------------------
struct HandShakeHdr
{
    uint8_t handshake_type;
    uint8_t len[3];
};

static_assert(sizeof(HandShakeHdr) == 4, "Handshake Header size is not 4-bytes");
