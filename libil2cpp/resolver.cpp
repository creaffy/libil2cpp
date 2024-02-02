#include "resolver.h"
#include "base.h"
#include "api/domain.h"
#include "api/assembly.h"
#include "api/misc.h"

using namespace Il2Cpp;

Class* Resolver::GetClass(std::string_view _AssemblyName, std::string_view _NamespaceName, std::string_view _ClassName)
{
    static Domain* _Domain = Domain::Get();
    if (!_Domain)
        return NULL;
    const Assembly* _Assembly = _Domain->OpenAssembly(_AssemblyName);
    if (!_Assembly)
        return NULL;
    const Image* _Image = _Assembly->GetImage();
    if (!_Image)
        return NULL;
    return Class::FromName(_Image, _NamespaceName, _ClassName);
}

const Method* Resolver::GetMethod(std::string_view _AssemblyName, std::string_view _NamespaceName, std::string_view _ClassName, std::string_view _MethodName, int32_t _ArgsCount)
{
    Class* _Class = GetClass(_AssemblyName, _NamespaceName, _ClassName);
    if (!_Class)
        return NULL;
    return _Class->GetMethodFromName(_MethodName, _ArgsCount);
}

const Property* Resolver::GetProperty(std::string_view _AssemblyName, std::string_view _NamespaceName, std::string_view _ClassName, std::string_view _PropertyName)
{
    Class* _Class = GetClass(_AssemblyName, _NamespaceName, _ClassName);
    if (!_Class)
        return NULL;
    return _Class->GetPropertyFromName(_PropertyName);
}

Il2CppMethodPointer Resolver::GetInternalCall(std::string_view _Name)
{
    return ResolveInternalCall(_Name);
}