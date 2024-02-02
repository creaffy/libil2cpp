#pragma once
#include "../base.h"
#include <string>
#include <vector>

namespace Il2Cpp
{
    typedef struct Type Type;
    typedef struct Image Image;
    typedef struct Field Field;
    typedef struct Property Property;
    typedef struct Method Method;

    struct Class : public Il2CppClass
    {
        const Type* GetEnumBaseType() const;
        bool IsGeneric() const;
        bool IsInflated() const;
        bool IsAssignableFrom(Class* klass) const;
        bool IsSubclassOf(Class* klass, bool check_interfaces) const;
        bool HasParent(Class* klass) const;
        bool IsValueType() const;
        bool IsBittable() const;
        bool IsAbstract() const;
        bool IsInterface() const;
        bool HasReferences() const;
        bool IsEnum() const;
        Class* GetElementClass(Class* klass) const;
        const std::vector<EventInfo*> GetEvents() const;
        const std::vector<Field*> GetFields() const;
        const std::vector<Class*> GetNestedTypes() const;
        const std::vector<Class*> GetInterfaces() const;
        const std::vector<Property*> GetProperties() const;
        const std::vector<Method*> GetMethods() const;
        const Property* GetPropertyFromName(std::string_view name) const;
        Field* GetFieldFromName(std::string_view name) const;
        const Method* GetMethodFromName(std::string_view name, int32_t args_count) const;
        std::string_view GetName() const;
        std::string_view GetNamespace() const;
        Class* GetParent() const;
        Class* GetDeclaringType() const;
        int32_t GetInstanceSize() const;
        size_t GetNumFields() const;
        int32_t GetValueSize(uint32_t* alignment) const;
        int32_t GetFlags() const;
        int32_t GetArrayElementSize() const;
        const Type* GetType() const;
        uint32_t GetToken() const;
        bool HasAttribute(Class* attr_class) const;
        const Image* GetImage() const;
        std::string_view GetAssemblyName() const;
        int32_t GetRank() const;
        uint32_t GetDataSize() const;
        void* GetStaticFieldsData() const;
        static Class* FromType(const Type* type);
        static Class* FromIl2CppType(const Type* type);
        static Class* FromName(const Image* image, std::string_view namespaze, std::string_view name);
        static Class* FromSystemType(Il2CppReflectionType* type);
        static void ForEach(void(*func)(Class* klass, void* user_data), void* user_data);
    };
}