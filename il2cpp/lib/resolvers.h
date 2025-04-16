#pragma once
#include "base.h"
#include "api/class.h"
#include "api/method.h"
#include "api/property.h"
#include <vector>

namespace Il2Cpp {
    inline Image* GetImage(std::string_view ImageArg) {
        static void* fn = GetExport("il2cpp_assembly_load");
        return reinterpret_cast<Assembly*(*)(const char*)>(fn)(ImageArg.data())->image;
    }

    inline Class* GetClass(std::string_view ImageArg, std::string_view NamespaceArg, std::string_view ClassArg) {
        static void* fn = GetExport("il2cpp_class_from_name");
        return reinterpret_cast<Class*(*)(Image*, const char*, const char*)>(fn)(GetImage(ImageArg), NamespaceArg.data(), ClassArg.data());
    }

    inline Class* GetClass(Type* TypeArg) {
        static void* fn = GetExport("il2cpp_class_from_il2cpp_type");
        return reinterpret_cast<Class*(*)(Type*, bool)>(fn)(TypeArg, false);
    }

    // Leave parameter count as -1 to find the first method just with matching name
    inline Method* GetMethod(std::string_view ImageArg, std::string_view NamespaceArg, std::string_view ClassArg, std::string_view MethodArg, int32_t ArgsCountArg = -1) {
        Class* klass = GetClass(ImageArg, NamespaceArg, ClassArg);
        if (!klass)
            return nullptr;
        return klass->GetMethod(MethodArg, ArgsCountArg);
    }

    inline Property* GetProperty(std::string_view ImageArg, std::string_view NamespaceArg, std::string_view ClassArg, std::string_view PropertyArg) {
        Class* klass = GetClass(ImageArg, NamespaceArg, ClassArg);
        if (!klass)
            return nullptr;
        auto iter = std::ranges::find_if(klass->GetProperties(), [&PropertyArg](Property& p) { return p.name == PropertyArg; });
        return iter == klass->GetProperties().end() ? nullptr : &*iter;
    }

    inline void* GetIcall(std::string_view IcallArg) {
        static void* fn = GetExport("il2cpp_resolve_icall");
        return reinterpret_cast<void*(*)(const char*)>(fn)(IcallArg.data());
    }

    inline std::vector<Class*> GetClasses() {
        static void* fn = GetExport("il2cpp_class_for_each");
        std::vector<Class*> classes{};
        reinterpret_cast<void(*)(void(*)(Class*, std::vector<Class*>*), void*)>(fn)([](Class* ClassArg, std::vector<Class*>* _vec) { _vec->push_back(ClassArg); }, &classes);
        return classes;
    }

    inline const std::span<Assembly*> GetAssemblies() {
        static void* fn = GetExport("il2cpp_domain_get_assemblies");
        size_t size = 0;
        Assembly** data = reinterpret_cast<Assembly**(*)(Domain*, size_t*)>(fn)(nullptr, &size); 
        return std::span(data, size);
    }
}