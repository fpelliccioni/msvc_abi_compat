// cmake .. -G "Visual Studio 15 2017 Win64" -DCMAKE_VERBOSE_MAKEFILE=ON
// 

/**
 * Copyright (c) Fernando Pelliccioni
 */
#include <msvc_abi_compat/test.hpp>

#include <algorithm>

namespace msvc_abi_compat {

void reverse_n(uint8_t* f, size_t n) {
    std::reverse(f, std::next(f, n));
}

} // namespace msvc_abi_compat
