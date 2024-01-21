#include "method.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

const Type* Method::GetReturnType() const
{
    static auto _ApiFunction = Resolver::GetExport<const Type * (*)(const Method*)>("il2cpp_method_get_return_type");
    return _ApiFunction(this);
}

Class* Method::GetDeclaringType() const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Method*)>("il2cpp_method_get_declaring_type");
    return _ApiFunction(this);
}

const std::string Method::GetName() const
{
    static auto _ApiFunction = Resolver::GetExport<const char* (*)(const Method*)>("il2cpp_method_get_name");
    return _ApiFunction(this);
}

Il2CppReflectionMethod* Method::GetMethodObject() const
{
    static auto _ApiFunction = Resolver::GetExport<Il2CppReflectionMethod * (*)(const Method*)>("il2cpp_method_get_object");
    return _ApiFunction(this);
}

bool Method::IsGeneric() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Method*)>("il2cpp_method_is_generic");
    return _ApiFunction(this);
}

bool Method::IsInflated() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Method*)>("il2cpp_method_is_inflated");
    return _ApiFunction(this);
}

bool Method::IsInstance() const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Method*)>("il2cpp_method_is_instance");
    return _ApiFunction(this);
}

uint32_t Method::GetParamCount() const
{
    static auto _ApiFunction = Resolver::GetExport<uint32_t(*)(const Method*)>("il2cpp_method_get_param_count");
    return _ApiFunction(this);
}

const Type* Method::GetParam(uint32_t index) const
{
    static auto _ApiFunction = Resolver::GetExport<const Type * (*)(const Method*, uint32_t)>("il2cpp_method_get_param");
    return _ApiFunction(this, index);
}

Class* Method::GetClass() const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Method*)>("il2cpp_method_get_class");
    return _ApiFunction(this);
}

bool Method::HasAttribute(Class* attr_class) const
{
    static auto _ApiFunction = Resolver::GetExport<bool(*)(const Method*, Class*)>("il2cpp_method_has_attribute");
    return _ApiFunction(this, attr_class);
}

uint32_t Method::GetFlags(uint32_t* iflags) const
{
    static auto _ApiFunction = Resolver::GetExport<uint32_t(*)(const Method*, uint32_t*)>("il2cpp_method_get_flags");
    return _ApiFunction(this, iflags);
}

uint32_t Method::GetToken() const
{
    static auto _ApiFunction = Resolver::GetExport<uint32_t(*)(const Method*)>("il2cpp_method_get_token");
    return _ApiFunction(this);
}

const std::string Method::GetParamName(uint32_t index) const
{
    static auto _ApiFunction = Resolver::GetExport<const char* (*)(const Method*, uint32_t)>("il2cpp_method_get_param_name");
    return _ApiFunction(this, index);
}

const Method* Method::FromReflection(const Il2CppReflectionMethod* method, Class* refclass)
{
    static auto _ApiFunction = Resolver::GetExport<const Method * (*)(const Il2CppReflectionMethod*, Class*)>("il2cpp_method_get_declaring_type");
    return _ApiFunction(method, refclass);
}
