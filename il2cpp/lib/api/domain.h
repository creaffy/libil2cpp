#pragma once
#include "../base.h"

namespace Il2Cpp {
    struct Domain : Il2CppDomain {
        static inline Domain* Get() {
            static void* fn = GetExport("il2cpp_domain_get");
            return reinterpret_cast<Domain*(*)()>(fn)();
        }
    };
}