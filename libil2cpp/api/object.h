#pragma once
#include "../base.h"

namespace Il2Cpp
{
    typedef struct Class Class;
    typedef struct Method Method;

    struct Object : public Il2CppObject
    {
        Class* GetClass() const;
        uint32_t GetSize() const;
        const Method* GetVirtualMethod(const Method* method) const;
        void* Unbox() const;
        static Object* New(const Class* klass);
        static Object* BoxValue(Class* klass, void* data);
    };
}