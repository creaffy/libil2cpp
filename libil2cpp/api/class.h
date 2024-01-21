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
        const Property* GetPropertyFromName(const std::string name) const;
        Field* GetFieldFromName(const std::string name) const;
        const Method* GetMethodFromName(const std::string name, int32_t args_count) const;
        const std::string GetName() const;
        const std::string GetNamespace() const;
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
        const std::string GetAssemblyName() const;
        int32_t GetRank() const;
        uint32_t GetDataSize() const;
        void* GetStaticFieldsData() const;
        static Class* FromType(const Type* type);
        static Class* FromIl2CppType(const Type* type);
        static Class* FromName(const Image* image, const std::string namespaze, const std::string name);
        static Class* FromSystemType(Il2CppReflectionType* type);
        static void ForEach(void(*func)(Class* klass, void* user_data), void* user_data);
    };
}