#pragma once
#include "../base.h"
#include <string>

namespace Il2Cpp
{
    typedef struct Assembly Assembly;
    typedef struct Method Method;
    typedef struct Class Class;

    struct Image : public Il2CppImage
    {
        const Assembly* GetAssembly() const;
        const std::string GetName() const;
        const std::string GetFileName() const;
        const Method* GetEntryPoint() const;
        size_t GetClassCount() const;
        const Class* GetClass(size_t index) const;
    };
}