#include "field.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

int32_t Field::GetFlags() const
{
    static auto _ApiFunction = Resolver::GetExport<int32_t(*)(const Field*)>("il2cpp_field_get_flags");
    return _ApiFunction(this);
}

std::string_view Field::GetName() const
{
    static auto _ApiFunction = Resolver::GetExport<const char* (*)(const Field*)>("il2cpp_field_get_name");
    return _ApiFunction(this);
}

Class* Field::GetParent() const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Field*)>("il2cpp_field_get_parent");
    return _ApiFunction(this);
}

size_t Field::GetOffset() const
{
    static auto _ApiFunction = Resolver::GetExport<size_t(*)(const Field*)>("il2cpp_field_get_offset");
    return _ApiFunction(this);
}

const Type* Field::GetType() const
{
    static auto _ApiFunction = Resolver::GetExport<const Type * (*)(const Field*)>("il2cpp_field_get_type");
    return _ApiFunction(this);
}

bool Field::HasAttribute(Class* attr_class) const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Field*, Class*)>("il2cpp_field_has_attribute");
    return _ApiFunction(this, attr_class);
}

bool Field::IsLiteral() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Field*)>("il2cpp_field_is_literal");
    return _ApiFunction(this);
}

Object* Field::GetValueObject(Object* obj) const
{
    static auto _ApiFunction = Resolver::GetExport<Object*(*)(const Field*, Object* obj)>("il2cpp_field_get_value_object");
    return _ApiFunction(this, obj);
}

void Field::SetValueObject(Object* obj, Object* value) 
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(Object*, const Field*, Object*)>("il2cpp_field_set_value_object");
    return _ApiFunction(obj, this, value);
}