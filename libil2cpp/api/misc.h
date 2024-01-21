#pragma once
#include "../base.h"
#include <windows.h>
#include <string>

namespace Il2Cpp
{
    typedef struct Image Image;

    void SetMemoryCallbacks(Il2CppMemoryCallbacks* callbacks);
    const Image* GetCorlib();
    void AddInternalCall(const std::string name, Il2CppMethodPointer method);
    Il2CppMethodPointer ResolveInternalCall(const std::string name);

    void* Alloc(size_t size);
    void Free(void* ptr);

    Il2CppManagedMemorySnapshot* CaptureMemorySnapshot();
    void FreeMemorySnapshot(Il2CppManagedMemorySnapshot* snapshot);

    void SetFindPluginCallback(Il2CppSetFindPlugInCallback method);
    void SetRegisterLogCallback(Il2CppLogCallback method);
}