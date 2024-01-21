#include "image.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

const Assembly* Image::GetAssembly() const
{
    static auto _ApiFunction = Resolver::GetExport<Assembly * (*)(const Image*)>("il2cpp_image_get_assembly");
    return _ApiFunction(this);
}

const std::string Image::GetName() const
{
    static auto _ApiFunction = Resolver::GetExport<const char* (*)(const Image*)>("il2cpp_image_get_name");
    return _ApiFunction(this);
}

const std::string Image::GetFileName() const
{
    static auto _ApiFunction = Resolver::GetExport<const char* (*)(const Image*)>("il2cpp_image_get_filename");
    return _ApiFunction(this);
}

const Method* Image::GetEntryPoint() const
{
    static auto _ApiFunction = Resolver::GetExport<const Method * (*)(const Image*)>("il2cpp_image_get_entry_point");
    return _ApiFunction(this);
}

size_t Image::GetClassCount() const
{
    static auto _ApiFunction = Resolver::GetExport<size_t(*)(const Image*)>("il2cpp_image_get_class_count");
    return _ApiFunction(this);
}

const Class* Image::GetClass(size_t index) const
{
    static auto _ApiFunction = Resolver::GetExport<const Class * (*)(const Image*, size_t)>("il2cpp_image_get_class");
    return _ApiFunction(this, index);
}
