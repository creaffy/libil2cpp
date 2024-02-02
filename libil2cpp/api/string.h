#pragma once
#include "../base.h"
#include <string>

namespace Il2Cpp
{
    struct String : public Il2CppString
    {
        int32_t GetLength() const;
        std::string_view GetString() const;
        std::wstring_view GetWString() const;
        static String* New(std::string_view str);
        static String* NewWrapper(std::string_view str);
        static String* NewLen(const char*, uint32_t length);
        static String* NewUtf16(const Il2CppChar* str, int32_t len);
    };
}