#pragma once
#include "../base.h"
#include <string>

namespace Il2Cpp
{
    typedef struct Class Class;
    typedef struct Type Type;
    typedef struct Object Object;

    struct Field : public FieldInfo
    {
        int32_t GetFlags() const;
        const std::string GetName() const;
        Class* GetParent() const;
        size_t GetOffset() const;
        const Type* GetType() const;
        bool HasAttribute(Class* attr_class) const;
        bool IsLiteral() const;
        // i kinda forgot about those and tbh im too lazy to do something about it
        void* GetValue(Object* obj) const;
        Object* GetValueObject(Object* obj) const;
        void* GetValueStatic() const;
        void SetValue(Object* obj, void* value);
        void SetValueObject(Object* obj, Object* value);
        void SetValueStatic(void* value);
    };
}
