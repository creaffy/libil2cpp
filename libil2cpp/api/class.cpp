#include "class.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

const Type* Class::GetEnumBaseType() const
{
    static auto _ApiFunction = Resolver::GetExport<const Type * (*)(const Class*)>("il2cpp_class_enum_basetype");
    return _ApiFunction(this);
}

bool Class::IsGeneric() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*)>("il2cpp_class_is_generic");
    return _ApiFunction(this);
}

bool Class::IsInflated() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*)>("il2cpp_class_is_inflated");
    return _ApiFunction(this);
}

bool Class::IsAssignableFrom(Class* klass) const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*, Class*)>("il2cpp_class_is_assignable_from");
    return _ApiFunction(this, klass);
}

bool Class::IsSubclassOf(Class* klass, bool check_interfaces) const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*, Class*, bool)>("il2cpp_class_is_subclass_of");
    return _ApiFunction(this, klass, check_interfaces);
}

bool Class::HasParent(Class* klass) const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*, Class*)>("il2cpp_class_has_parent");
    return _ApiFunction(this, klass);
}

bool Class::IsValueType() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*)>("il2cpp_class_is_valuetype");
    return _ApiFunction(this);
}

bool Class::IsBittable() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*)>("il2cpp_class_is_bittable");
    return _ApiFunction(this);
}

bool Class::IsAbstract() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*)>("il2cpp_class_is_abstract");
    return _ApiFunction(this);
}

bool Class::IsInterface() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*)>("il2cpp_class_is_interface");
    return _ApiFunction(this);
}

bool Class::HasReferences() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*)>("il2cpp_class_has_references");
    return _ApiFunction(this);
}

bool Class::IsEnum() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*)>("il2cpp_class_is_enum");
    return _ApiFunction(this);
}

Class* Class::GetElementClass(Class* klass) const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Class*)>("il2cpp_class_get_element_class");
    return _ApiFunction(this);
}

const std::vector<EventInfo*> Class::GetEvents() const
{
    static auto _ApiFunction = Resolver::GetExport<EventInfo * (*)(const Class*, void**)>("il2cpp_class_get_events");
    void* _Iter = nullptr;
    std::vector<EventInfo*> _Events;
    while (EventInfo* _Event = _ApiFunction(this, &_Iter))
        _Events.push_back(_Event);
    return _Events;
}

const std::vector<Field*> Class::GetFields() const
{
    static auto _ApiFunction = Resolver::GetExport<Field * (*)(const Class*, void**)>("il2cpp_class_get_fields");
    void* _Iter = nullptr;
    std::vector<Field*> _Fields;
    while (Field* _Field = _ApiFunction(this, &_Iter))
        _Fields.push_back(_Field);
    return _Fields;
}

const std::vector<Class*> Class::GetNestedTypes() const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Class*, void**)>("il2cpp_class_get_nested_types");
    void* _Iter = nullptr;
    std::vector<Class*> _NestedTypes;
    while (Class* _NestedType = _ApiFunction(this, &_Iter))
        _NestedTypes.push_back(_NestedType);
    return _NestedTypes;
}

const std::vector<Class*> Class::GetInterfaces() const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Class*, void**)>("il2cpp_class_get_interfaces");
    void* _Iter = nullptr;
    std::vector<Class*> _Interfaces;
    while (Class* _Interface = _ApiFunction(this, &_Iter))
        _Interfaces.push_back(_Interface);
    return _Interfaces;
}

const std::vector<Property*> Class::GetProperties() const
{
    static auto _ApiFunction = Resolver::GetExport<Property * (*)(const Class*, void**)>("il2cpp_class_get_properties");
    void* _Iter = nullptr;
    std::vector<Property*> _Properties;
    while (Property* _Property = _ApiFunction(this, &_Iter))
        _Properties.push_back(_Property);
    return _Properties;
}

const std::vector<Method*> Class::GetMethods() const {
    static auto _ApiFunction = Resolver::GetExport<Method * (*)(const Class*, void**)>("il2cpp_class_get_methods");
    void* _Iter = nullptr;
    std::vector<Method*> _Methods;
    while (Method* _Method = _ApiFunction(this, &_Iter))
        _Methods.push_back(_Method);
    return _Methods;
}

const Property* Class::GetPropertyFromName(std::string_view name) const
{
    static auto _ApiFunction = Resolver::GetExport<const Property * (*)(const Class*, const char*)>("il2cpp_class_get_property_from_name");
    return _ApiFunction(this, name.data());
}

Field* Class::GetFieldFromName(std::string_view name) const
{
    static auto _ApiFunction = Resolver::GetExport<Field * (*)(const Class*, const char*)>("il2cpp_class_get_field_from_name");
    return _ApiFunction(this, name.data());
}

const Method* Class::GetMethodFromName(std::string_view name, int32_t args_count) const
{
    static auto _ApiFunction = Resolver::GetExport<const Method * (*)(const Class*, const char*, int32_t)>("il2cpp_class_get_method_from_name");
    return _ApiFunction(this, name.data(), args_count);
}

std::string_view Class::GetName() const
{
    static auto _ApiFunction = Resolver::GetExport<const char* (*)(const Class*)>("il2cpp_class_get_name");
    return _ApiFunction(this);
}

std::string_view Class::GetNamespace() const
{
    static auto _ApiFunction = Resolver::GetExport<const char* (*)(const Class*)>("il2cpp_class_get_namespace");
    return _ApiFunction(this);
}

Class* Class::GetParent() const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Class*)>("il2cpp_class_get_parent");
    return _ApiFunction(this);
}

Class* Class::GetDeclaringType() const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Class*)>("il2cpp_class_get_declaring_type");
    return _ApiFunction(this);
}

int32_t Class::GetInstanceSize() const
{
    static auto _ApiFunction = Resolver::GetExport<int32_t(*)(const Class*)>("il2cpp_class_instance_size");
    return _ApiFunction(this);
}

size_t Class::GetNumFields() const
{
    static auto _ApiFunction = Resolver::GetExport<size_t(*)(const Class*)>("il2cpp_class_num_fields");
    return _ApiFunction(this);
}

int32_t Class::GetValueSize(uint32_t* alignment) const
{
    static auto _ApiFunction = Resolver::GetExport<int32_t(*)(const Class*, uint32_t*)>("il2cpp_class_value_size");
    return _ApiFunction(this, alignment);
}

int32_t Class::GetFlags() const
{
    static auto _ApiFunction = Resolver::GetExport<int32_t(*)(const Class*)>("il2cpp_class_flags");
    return _ApiFunction(this);
}

int32_t Class::GetArrayElementSize() const
{
    static auto _ApiFunction = Resolver::GetExport<int32_t(*)(const Class*)>("il2cpp_class_array_element_size");
    return _ApiFunction(this);
}

const Type* Class::GetType() const
{
    static auto _ApiFunction = Resolver::GetExport<const Type * (*)(const Class*)>("il2cpp_class_from_type");
    return _ApiFunction(this);
}

uint32_t Class::GetToken() const
{
    static auto _ApiFunction = Resolver::GetExport<uint32_t(*)(const Class*)>("il2cpp_class_get_type_token");
    return _ApiFunction(this);
}

bool Class::HasAttribute(Class* attr_class) const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Class*, Class*)>("il2cpp_class_has_attribute");
    return _ApiFunction(this, attr_class);
}

const Image* Class::GetImage() const
{
    static auto _ApiFunction = Resolver::GetExport<Image * (*)(const Class*)>("il2cpp_class_get_image");
    return _ApiFunction(this);
}

std::string_view Class::GetAssemblyName() const
{
    static auto _ApiFunction = Resolver::GetExport<const char* (*)(const Class*)>("il2cpp_class_get_assemblyname");
    return _ApiFunction(this);
}

int32_t Class::GetRank() const
{
    static auto _ApiFunction = Resolver::GetExport<int32_t(*)(const Class*)>("il2cpp_class_get_rank");
    return _ApiFunction(this);
}

uint32_t Class::GetDataSize() const
{
    static auto _ApiFunction = Resolver::GetExport<uint32_t(*)(const Class*)>("il2cpp_class_get_data_size");
    return _ApiFunction(this);
}

void* Class::GetStaticFieldsData() const
{
    static auto _ApiFunction = Resolver::GetExport<void* (*)(const Class*)>("il2cpp_class_get_static_field_data");
    return _ApiFunction(this);
}

Class* Class::FromType(const Type* type)
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Type*)>("il2cpp_class_from_type");
    return _ApiFunction(type);
}

Class* Class::FromIl2CppType(const Type* type)
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Type*)>("il2cpp_class_from_il2cpp_type");
    return _ApiFunction(type);
}

Class* Class::FromName(const Image* image, std::string_view namespaze, std::string_view name)
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Image*, const char*, const char*)>("il2cpp_class_from_name");
    return _ApiFunction(image, namespaze.data(), name.data());
}

Class* Class::FromSystemType(Il2CppReflectionType* type)
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(Il2CppReflectionType*)>("il2cpp_class_from_system_type");
    return _ApiFunction(type);
}

void Class::ForEach(void(*func)(Class* klass, void* user_data), void* user_data)
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(void(Class*, void*), void*)>("il2cpp_class_for_each");
    return _ApiFunction(func, user_data);
}