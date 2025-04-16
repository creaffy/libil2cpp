#pragma once
#include "../base.h"

namespace Il2Cpp {
    struct String : Il2CppString {
        static inline String* New(std::string_view StringArg) {
            static void* fn = GetExport("il2cpp_string_new");
            return reinterpret_cast<String*(*)(const char*)>(fn)(StringArg.data());
        }

        static inline String* New(std::u16string_view StringArg) {
            static void* fn = GetExport("il2cpp_string_new_utf16");
            return reinterpret_cast<String*(*)(const char16_t*)>(fn)(StringArg.data());
        }

        inline operator std::u16string_view() const {
            return std::u16string_view(reinterpret_cast<const char16_t*>(chars), length);
        }

        inline operator std::string() const {
            std::string string(length, 0);
            for (size_t i = 0; i < length; ++i)
                string[i] = static_cast<char>(chars[i]);
            return string;
        }

        inline std::u16string_view U16() const {
            return *this;
        }

        inline std::string U8() const {
            return *this;
        }
    };
}