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
        std::string_view GetName() const;
        std::string_view GetFileName() const;
        const Method* GetEntryPoint() const;
        size_t GetClassCount() const;
        const Class* GetClass(size_t index) const;
    };
}