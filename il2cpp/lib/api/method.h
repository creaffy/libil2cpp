#pragma once
#include "../base.h"
#include "class.h"
#include <span>

namespace Il2Cpp {
    struct Method : MethodInfo {
        inline std::span<Type*> GetParameters() {
            return std::span(parameters, parameters_count);
        }

        inline std::string_view GetParameterName(int32_t i) {
            static void* fn = GetExport("il2cpp_method_get_param_name");
            return reinterpret_cast<const char*(*)(Method*, int32_t)>(fn)(this, i);
        }
    };
}