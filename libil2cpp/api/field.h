#pragma once
#include "../base.h"
#include "../resolver.h"
#include <string>

namespace Il2Cpp
{
    typedef struct Class Class;
    typedef struct Type Type;
    typedef struct Object Object;

    struct Field : public FieldInfo
    {
        int32_t GetFlags() const;
        std::string_view GetName() const;
        Class* GetParent() const;
        size_t GetOffset() const;
        const Type* GetType() const;
        bool HasAttribute(Class* attr_class) const;
        bool IsLiteral() const;
        Object* GetValueObject(Object* obj) const;
        void SetValueObject(Object* obj, Object* value);
        template <typename T>
        T GetValue(Object* obj) const 
        {
            static auto _ApiFunction = Resolver::GetExport<void (*)(Object*, const Field *, void*)>("il2cpp_field_get_value");
            T _Value{};
            _ApiFunction(obj, this, &_Value);
            return _Value;
        }
        template <typename T>
        T GetValueStatic() const 
        {
            static auto _ApiFunction = Resolver::GetExport<void (*)(const Field*, void*)>("il2cpp_field_static_get_value");
            T _Value{};
            _ApiFunction(this, &_Value);
            return _Value;
        }
        template <typename T>
        void SetValue(Object* obj, T& value) 
        {
            static auto _ApiFunction = Resolver::GetExport<void (*)(Object*, const Field*, void*)>("il2cpp_field_set_value");
            _ApiFunction(obj, this, &value);
        }
        template <typename T>
        void SetValueStatic(T& value) 
        {
            static auto _ApiFunction = Resolver::GetExport<void (*)(const Field*, void*)>("il2cpp_field_static_set_value");
            _ApiFunction(this, &value);
        }
    };
}