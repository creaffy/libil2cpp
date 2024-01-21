#pragma once
#include "../base.h"
#include "../il2cpp.h"
#include "../resolver.h"

namespace Il2Cpp
{
    typedef struct Class Class;

    template <typename T>
    struct Array : Il2CppArray
    {
        T items[0];

        uint32_t GetLength() const
        {
            static auto _ApiFunction = Resolver::GetExport<uint32_t(*)(const Array<T>*)>("il2cpp_array_length");
            return _ApiFunction(this);
        }

        uint32_t GetByteLength() const
        {
            static auto _ApiFunction = Resolver::GetExport<uint32_t(*)(const Array<T>*)>("il2cpp_array_get_byte_length");
            return _ApiFunction(this);
        }

        static int32_t GetElementSize(const Class* array_class)
        {
            static auto _ApiFunction = Resolver::GetExport<int32_t(*)(const Class*)>("il2cpp_array_element_size");
            return _ApiFunction(array_class);
        }

        static Array<T>* New(Class* element_type, il2cpp_array_size_t length)
        {
            static auto _ApiFunction = Resolver::GetExport<Array<T> * (*)(Class*, il2cpp_array_size_t)>("il2cpp_array_new");
            return _ApiFunction(element_type, length);
        }

        static Array<T>* NewSpecific(Class* array_type, il2cpp_array_size_t length)
        {
            static auto _ApiFunction = Resolver::GetExport<Array<T> * (*)(Class*, il2cpp_array_size_t)>("il2cpp_array_new_specific");
            return _ApiFunction(array_type, length);
        }

        static Class* GetBoundedArrayClass(Class* element_class, uint32_t rank, bool bounded)
        {
            static auto _ApiFunction = Resolver::GetExport<Class * (*)(Class*, uint32_t, bool)>("il2cpp_bounded_array_class_get");
            return _ApiFunction(element_class, rank, bounded);
        }

        static Class* GetArrayClass(Class* element_class, uint32_t rank)
        {
            static auto _ApiFunction = Resolver::GetExport<Class * (*)(Class*, uint32_t)>("il2cpp_array_class_get");
            return _ApiFunction(element_class, rank);
        }
    };
}