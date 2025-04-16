#pragma once
#include "../base.h"
#include "method.h"

namespace Il2Cpp {
    struct Property : PropertyInfo {
        template <class T>
        inline Traits::RealT<T> Get(const void* This) const {
            return reinterpret_cast<Traits::RealT<T>(*)(const void*)>(get->methodPointer)(This);
        }

        template <class T>
        inline void Set(void* This, Traits::RealT<T> Value) {
            return reinterpret_cast<void(*)(void*, Traits::RealT<T>)>(set->methodPointer)(This, Value);
        }
    };

    template <class T>
    struct SmartProperty {
        using RealT = Traits::RealT<T>;

        Property* const propertyInfo;
        void* const referencedObject;

        inline RealT Get() { 
            return reinterpret_cast<RealT(*)(void*)>(propertyInfo->get->methodPointer)(referencedObject); 
        }

        inline void Set(RealT Value) {
            reinterpret_cast<void(*)(void*, RealT)>(propertyInfo->set->methodPointer)(referencedObject, Value);
        }

        inline SmartProperty& operator=(RealT Value) {
            Set(Value); 
            return *this;
        }

        inline operator RealT() { 
            return Get(); 
        };

        inline RealT operator->() {
            return Get(); 
        };
    };
};