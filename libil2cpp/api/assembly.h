#pragma once
#include "../base.h"

namespace Il2Cpp
{
    typedef struct Image Image;

    struct Assembly : public Il2CppAssembly
    {
        const Image* GetImage() const;
    };
}