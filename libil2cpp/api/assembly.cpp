#include "assembly.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

const Image* Assembly::GetImage() const
{
    static auto _ApiFunction = Resolver::GetExport<Image * (*)(const Assembly*)>("il2cpp_assembly_get_image");
    return _ApiFunction(this);
}