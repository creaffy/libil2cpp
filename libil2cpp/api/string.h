#pragma once
#include "../base.h"
#include <string>

namespace Il2Cpp
{
    struct String : public Il2CppString
    {
        int32_t GetLength() const;
        std::string GetString() const;
        std::wstring GetWString() const;
        static String* New(const std::string str);
        static String* NewWrapper(const std::string str);
        static String* NewLen(const char*, uint32_t length);
        static String* NewUtf16(const Il2CppChar* str, int32_t len);
    };
}