#include "domain.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

const Assembly* Domain::OpenAssembly(std::string_view name) const
{
    static auto _ApiFunction = Resolver::GetExport<Assembly * (*)(const Domain*, const char*)>("il2cpp_domain_assembly_open");
    return _ApiFunction(this, name.data());
}

const std::vector<Assembly*> Domain::GetAssemblies() const
{
    static auto _ApiFunction = Resolver::GetExport<Assembly * *(*)(const Domain*, size_t*)>("il2cpp_domain_get_assemblies");
    size_t _Size = 0;
    Assembly** _Array = _ApiFunction(this, &_Size);
    return std::vector<Assembly*>(_Array, _Array + _Size);
}

Domain* Domain::Get()
{
    static auto _ApiFunction = Resolver::GetExport<Domain * (*)(void)>("il2cpp_domain_get");
    return _ApiFunction();
}