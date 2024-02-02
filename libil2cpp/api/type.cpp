#include "type.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

Object* Type::GetTypeObject() const
{
    static auto _ApiFunction = Resolver::GetExport<Object * (*)(const Type*)>("il2cpp_type_get_object");
    return _ApiFunction(this);
}

Il2CppTypeEnum Type::GetType() const
{
    static auto _ApiFunction = Resolver::GetExport<Il2CppTypeEnum(*)(const Type*)>("il2cpp_type_get_type");
    return _ApiFunction(this);
}

Class* Type::GetClassOrElementClass() const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Type*)>("il2cpp_type_get_class_or_element_class");
    return _ApiFunction(this);
}

std::string_view Type::GetName() const
{
    static auto _ApiFunction = Resolver::GetExport<char* (*)(const Type*)>("il2cpp_type_get_name");
    return _ApiFunction(this);
}

std::string_view Type::GetAssemblyQualifiedName() const
{
    static auto _ApiFunction = Resolver::GetExport<char* (*)(const Type*)>("il2cpp_type_get_assembly_qualified_name");
    return _ApiFunction(this);
}

bool Type::IsByref() const
{
    static auto _ApiFunction = Resolver::GetExport<bool (*)(const Type*)>("il2cpp_type_is_byref");
    return _ApiFunction(this);
}

uint32_t Type::GetAttrs() const
{
    static auto _ApiFunction = Resolver::GetExport<uint32_t(*)(const Type*)>("il2cpp_type_get_attrs");
    return _ApiFunction(this);
}

bool Type::Equals(const Type* other) const
{
    static auto _ApiFunction = Resolver::GetExport<bool (*)(const Type*, const Type*)>("il2cpp_type_equals");
    return _ApiFunction(this, other);
}

bool Type::IsStatic() const
{
    static auto _ApiFunction = Resolver::GetExport<bool (*)(const Type*)>("il2cpp_type_is_static");
    return _ApiFunction(this);
}

bool Type::IsPointerType() const
{
    static auto _ApiFunction = Resolver::GetExport<bool (*)(const Type*)>("il2cpp_type_is_pointer_type");
    return _ApiFunction(this);
}
