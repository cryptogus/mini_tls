/**
 * @file tls_hdr.hpp
 */

#pragma once

#include <cstdint>

//----------------------------------
// Define
//----------------------------------
enum TlsType : uint8_t
{
    Change_Cipher_Spc = 0x14,
    Alert,
    Handshake,
    Application_Data
};
//----------------------------------
// Structure
//----------------------------------
struct [[gnu::packed]] TlsHdr
{
    uint8_t type;
    uint8_t ver[2];
    uint8_t len[2];
};

static_assert(sizeof(TlsHdr) == 5, "TLS Header size is not 5-bytes");
