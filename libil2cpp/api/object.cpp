#include "object.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

Class* Object::GetClass() const
{
    static auto _ApiFunction = Resolver::GetExport<Class * (*)(const Object*)>("il2cpp_object_get_class");
    return _ApiFunction(this);
}

uint32_t Object::GetSize() const
{
    static auto _ApiFunction = Resolver::GetExport<uint32_t(*)(const Object*)>("il2cpp_object_get_size");
    return _ApiFunction(this);
}

const Method* Object::GetVirtualMethod(const Method* method) const
{
    static auto _ApiFunction = Resolver::GetExport<const Method * (*)(const Object*, const Method*)>("il2cpp_object_get_virtual_method");
    return _ApiFunction(this, method);
}

Object* Object::New(const Class* klass)
{
    static auto _ApiFunction = Resolver::GetExport<Object * (*)(const Class*)>("il2cpp_object_new");
    return _ApiFunction(klass);
}

void* Object::Unbox() const
{
    static auto _ApiFunction = Resolver::GetExport<void* (*)(const Object*)>("il2cpp_object_unbox");
    return _ApiFunction(this);
}

Object* Object::BoxValue(Class* klass, void* data)
{
    static auto _ApiFunction = Resolver::GetExport<Object * (*)(const Class*, void*)>("il2cpp_value_box");
    return _ApiFunction(klass, data);
}
