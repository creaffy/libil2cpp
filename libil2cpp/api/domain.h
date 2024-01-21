#pragma once
#include "../base.h"
#include <vector>
#include <string>

namespace Il2Cpp
{
    typedef struct Assembly Assembly;

    struct Domain : public Il2CppDomain
    {
        const Assembly* OpenAssembly(const std::string name) const;
        const std::vector<Assembly*> GetAssemblies() const;
        static Domain* Get();
    };
}