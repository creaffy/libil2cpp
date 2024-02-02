#pragma once
#include "../base.h"
#include <string>

namespace Il2Cpp
{
    typedef struct Method Method;
    typedef struct Class Class;

    struct Property : public PropertyInfo
    {
        uint32_t GetFlags() const;
        const Method* Getter() const;
        const Method* Setter() const;
        std::string_view GetName() const;
        Class* GetParent() const;
    };
}