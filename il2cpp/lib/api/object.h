#pragma once
#include "../base.h"
#include "property.h"

namespace Il2Cpp {
    struct Object : Il2CppObject {
        template <Traits::Object T = Object>
        static inline T* Create(Il2Cpp::Class* ClassArg) {
            static void* fn = GetExport("il2cpp_object_new");
            return reinterpret_cast<T*(*)(Class*)>(fn)(ClassArg);
        }

        template <class T>
        inline SmartProperty<T> GetProperty(std::string_view PropertyArg) {
            auto iter = std::ranges::find_if(klass->GetProperties(), [PropertyArg](const Il2Cpp::Property& p) { return PropertyArg == p.name; });
            return SmartProperty<T>(&(*iter), this);
        }
    };
}