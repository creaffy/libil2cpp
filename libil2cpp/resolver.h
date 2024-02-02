#pragma once
#include <windows.h>
#include "api/class.h"
#include "api/method.h"
#include "api/property.h"
#include "api/image.h"

namespace Il2Cpp
{
    namespace Resolver
    {
        Class* GetClass(std::string_view _Assembly, std::string_view _Namespace, std::string_view _Class);
        const Method* GetMethod(std::string_view _Assembly, std::string_view _Namespace, std::string_view _Class, std::string_view _Method, int32_t _ArgsCount);
        const Property* GetProperty(std::string_view _Assembly, std::string_view _Namespace, std::string_view _Class, std::string_view _Property);
        Il2CppMethodPointer GetInternalCall(std::string_view _Name);
        template <typename T>
        constexpr T GetExport(std::string_view _ExportName)
        {
            static HMODULE _Module = GetModuleHandleA("GameAssembly.dll");
            return reinterpret_cast<T>(GetProcAddress(_Module, _ExportName.data()));
        }
    }
}