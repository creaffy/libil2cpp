#pragma once
#include "../base.h"
#include <string>

namespace Il2Cpp
{
    typedef struct Object Object;
    typedef struct Class Class;

    struct Type : public Il2CppType
    {
        Object* GetTypeObject() const;
        Il2CppTypeEnum GetType() const;
        const std::string GetName() const;
        Class* GetClassOrElementClass() const;
        const std::string GetAssemblyQualifiedName() const;
        bool IsByref() const;
        uint32_t GetAttrs() const;
        bool Equals(const Type* other) const;
        bool IsStatic() const;
        bool IsPointerType() const;
    };
}