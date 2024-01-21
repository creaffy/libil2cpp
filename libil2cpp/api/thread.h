#pragma once
#include "../base.h"
#include <vector>

namespace Il2Cpp
{
    typedef struct Domain Domain;

    struct Thread : public Il2CppThread
    {
        void Detach();
        bool IsVM() const;
        static Thread* GetCurrent();
        static Thread* Attach(Domain* domain);
        static std::vector<Thread*> GetAllAttached();
    };
}