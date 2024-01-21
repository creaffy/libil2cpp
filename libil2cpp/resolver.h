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
        Class* GetClass(const std::string _Assembly, const std::string _Namespace, const std::string _Class);
        const Method* GetMethod(const std::string _Assembly, const std::string _Namespace, const std::string _Class, const std::string _Method, int32_t _ArgsCount);
        const Property* GetProperty(const std::string _Assembly, const std::string _Namespace, const std::string _Class, const std::string _Property);
        Il2CppMethodPointer GetInternalCall(const std::string _Name);
        template <typename T>
        constexpr T GetExport(std::string_view _ExportName)
        {
            static HMODULE _Module = GetModuleHandleA("GameAssembly.dll");
            return reinterpret_cast<T>(GetProcAddress(_Module, _ExportName.data()));
        }
    }
}