/**
 * Copyright (c) 2018 Fernando Pelliccioni
 */
#ifndef MSVC_ABI_COMPAT_TEST_HPP_
#define MSVC_ABI_COMPAT_TEST_HPP_

 #include <cstdint>

#if defined _MSC_VER || defined __CYGWIN__
    #define XXX_HELPER_DLL_IMPORT __declspec(dllimport)
    #define XXX_HELPER_DLL_EXPORT __declspec(dllexport)
    #define XXX_HELPER_DLL_LOCAL
#else
    #if __GNUC__ >= 4
        #define XXX_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
        #define XXX_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
        #define XXX_HELPER_DLL_LOCAL  __attribute__ ((visibility ("internal")))
    #else
        #define XXX_HELPER_DLL_IMPORT
        #define XXX_HELPER_DLL_EXPORT
        #define XXX_HELPER_DLL_LOCAL
    #endif
#endif

#if defined XXX_STATIC
    #define XXX_API
    #define XXX_INTERNAL
#elif defined XXX_DLL
    #define XXX_API      XXX_HELPER_DLL_EXPORT
    #define XXX_INTERNAL XXX_HELPER_DLL_LOCAL
#else
    #define XXX_API      XXX_HELPER_DLL_IMPORT
    #define XXX_INTERNAL XXX_HELPER_DLL_LOCAL
#endif

namespace msvc_abi_compat {

// BC_API hash_digest bitcoin_hash(data_slice data);
XXX_API void reverse_n(uint8_t* f, size_t n);

} // namespace msvc_abi_compat

#endif // MSVC_ABI_COMPAT_TEST_HPP_
