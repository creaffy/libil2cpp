#include "misc.h"
#include "../resolver.h"

void Il2Cpp::SetMemoryCallbacks(Il2CppMemoryCallbacks* callbacks)
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(Il2CppMemoryCallbacks*)>("il2cpp_set_memory_callbacks");
    _ApiFunction(callbacks);
}

const Il2Cpp::Image* Il2Cpp::GetCorlib()
{
    static auto _ApiFunction = Resolver::GetExport<const Image * (*)()>("il2cpp_get_corlib");
    return _ApiFunction();
}

void Il2Cpp::AddInternalCall(const std::string name, Il2CppMethodPointer method)
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(const char*, Il2CppMethodPointer)>("il2cpp_add_internal_call");
    _ApiFunction(name.c_str(), method);
}

Il2CppMethodPointer Il2Cpp::ResolveInternalCall(const std::string name)
{
    static auto _ApiFunction = Resolver::GetExport<Il2CppMethodPointer(*)(const char*)>("il2cpp_resolve_icall");
    return _ApiFunction(name.c_str());
}

void* Il2Cpp::Alloc(size_t size)
{
    static auto _ApiFunction = Resolver::GetExport<void* (*)(size_t)>("il2cpp_alloc");
    return _ApiFunction(size);
}

void Il2Cpp::Free(void* ptr)
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(void*)>("il2cpp_free");
    _ApiFunction(ptr);
}

Il2CppManagedMemorySnapshot* Il2Cpp::CaptureMemorySnapshot()
{
    static auto _ApiFunction = Resolver::GetExport<Il2CppManagedMemorySnapshot * (*)()>("il2cpp_capture_memory_snapshot");
    return _ApiFunction();
}

void Il2Cpp::FreeMemorySnapshot(Il2CppManagedMemorySnapshot* snapshot)
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(Il2CppManagedMemorySnapshot*)>("il2cpp_free_captured_memory_snapshot");
    _ApiFunction(snapshot);
}

void Il2Cpp::SetFindPluginCallback(Il2CppSetFindPlugInCallback method)
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(Il2CppSetFindPlugInCallback)>("il2cpp_set_find_plugin_callback");
    _ApiFunction(method);
}

void Il2Cpp::SetRegisterLogCallback(Il2CppLogCallback method)
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(Il2CppLogCallback)>("il2cpp_register_log_callback");
    _ApiFunction(method);
}
