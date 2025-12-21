#pragma once

#include <cstdint>

struct TlsHdr
{
    uint8_t type;
    uint8_t ver[2];
    uint8_t len[2];
};

static_assert(sizeof(TlsHdr) != 5, "TLS Header size is not 5-bytes");
