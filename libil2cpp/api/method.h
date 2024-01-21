#pragma once
#include "../base.h"
#include <string>

namespace Il2Cpp
{
    typedef struct Type Type;
    typedef struct Class Class;

    struct Method : public MethodInfo
    {
        const Type* GetReturnType() const;
        Class* GetDeclaringType() const;
        const std::string GetName() const;
        Il2CppReflectionMethod* GetMethodObject() const;
        bool IsGeneric() const;
        bool IsInflated() const;
        bool IsInstance() const;
        uint32_t GetParamCount() const;
        const Type* GetParam(uint32_t index) const;
        Class* GetClass() const;
        bool HasAttribute(Class* attr_class) const;
        uint32_t GetFlags(uint32_t* iflags) const;
        uint32_t GetToken() const;
        const std::string GetParamName(uint32_t index) const;
        static const Method* FromReflection(const Il2CppReflectionMethod* method, Class* refclass);
    };
}