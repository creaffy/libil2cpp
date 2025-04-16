#pragma once
#include "../base.h"
#include "property.h"
#include <span>

namespace Il2Cpp {
    struct Class : Il2CppClass {
        inline std::span<Method*> GetMethods() {
            return std::span<Method*>(methods, method_count);
        }

        inline std::span<Field> GetFields() {
            return std::span(fields, field_count);
        }

        inline std::span<Property> GetProperties() {
            return std::span(properties, property_count);
        }

        inline Method* GetMethod(std::string_view MethodArg, int32_t ArgsCountArg = -1) {
            auto iter = std::ranges::find_if(GetMethods(), [&MethodArg, ArgsCountArg](Method* m) { return m->name == MethodArg && (ArgsCountArg == -1 || m->parameters_count == ArgsCountArg); });
            return iter == klass->GetMethods().end() ? nullptr : *iter;
        }

        template <class T>
        inline T* GetStatics() {
            static void* fn = GetExport("il2cpp_class_get_static_field_data");
            return reinterpret_cast<T*(*)(Class*)>(fn)(this);
        }
    };
}