#include "property.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

uint32_t Property::GetFlags() const
{
    static auto _ApiFunction = Resolver::GetExport<uint32_t(*)(const Property*)>("il2cpp_property_get_flags");
    return _ApiFunction(this);
}

const Method* Property::Getter() const
{
    static auto _ApiFunction = Resolver::GetExport<const Method * (*)(const Property*)>("il2cpp_property_get_get_method");
    return _ApiFunction(this);
}

const Method* Property::Setter() const
{
    static auto _ApiFunction = Resolver::GetExport<const Method * (*)(const Property*)>("il2cpp_property_get_set_method");
    return _ApiFunction(this);
}

const std::string Property::GetName() const
{
    static auto _ApiFunction = Resolver::GetExport<const char* (*)(const Property*)>("il2cpp_property_get_name");
    return _ApiFunction(this);
}

Class* Property::GetParent() const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Property*)>("il2cpp_property_get_parent");
    return _ApiFunction(this);
}
