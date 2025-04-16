#pragma once
#include "lib/resolvers.h"
#include "lib/api/object.h"
#include "lib/api/method.h"
#include <bit>
#include <map>
#include <cmath>
#include <array>
#include <algorithm>

namespace System {
    // System.Collections.Generic.List<T>
    template <class T>
    struct List : Il2Cpp::Object {
        using RealT = Il2Cpp::Traits::RealT<T>;

        Il2Cpp::Array<T>* items;
        int32_t size;
        int32_t version;
        Il2Cpp::Object* syncRoot;

        inline RealT* begin() {
            return items ? &items->items[0] : nullptr;
        }

        inline const RealT* begin() const {
            return items ? &items->items[0] : nullptr;
        }

        inline RealT* end() {
            return items ? &items->items[size] : nullptr;
        }

        inline const RealT* end() const {
            return items ? &items->items[size] : nullptr;
        }

        inline RealT& At(size_t i) {
            return &items->items[i];
        }

        inline const RealT& At(size_t i) const {
            return &items->items[i];
        }

        inline RealT& operator[](size_t i) {
            return At(i);
        }

        inline const RealT& operator[](size_t i) const {
            return At(i);
        }
    };

    // System.Collections.Generic.Dictionary<TKey, TValue>
    template <class K, class V>
    struct Dictionary : Il2Cpp::Object {
        using KeyRealT = Il2Cpp::Traits::RealT<K>;
        using ValRealT = Il2Cpp::Traits::RealT<V>;

        struct Entry {
            int32_t hashCode;
            int32_t next;
            alignas(8) KeyRealT key;
            alignas(8) ValRealT value;
        };

        struct Iterator {
            Entry* ptr;

            inline bool operator==(const Iterator& r) const {
                return r.ptr == ptr;
            }

            inline bool operator!=(const Iterator& r) const {
                return r.ptr != ptr;
            }

            inline Iterator& operator++() {
                ++ptr;
                return *this;
            }

            inline std::pair<KeyRealT&, ValRealT&> operator*() const {
                return { ptr->key, ptr->value };
            }

            inline Entry* operator->() {
                return ptr;
            }

            inline const Entry* operator->() const {
                return ptr;
            }
        };

        Il2Cpp::Array<int32_t>* buckets;
        Il2Cpp::Array<Entry>* entries;
        int32_t count;
        int32_t version;
        int32_t freeList;
        int32_t freeCount;
        void* comparer;
        void* keys;
        void* values;
        Il2Cpp::Object* syncRoot;

        inline Iterator begin() {
            return Iterator(entries ? &entries->items[0] : nullptr);
        }

        inline const Iterator begin() const {
            return Iterator(entries ? &entries->items[0] : nullptr);
        }

        inline Iterator end() {
            return Iterator(entries ? &entries->items[count] : nullptr);
        }

        inline const Iterator end() const {
            return Iterator(entries ? &entries->items[count] : nullptr);
        }

        inline size_t Size() const {
            return count;
        }

        inline ValRealT* At(KeyRealT Key) {
            auto iter = std::find_if(begin(), end(), 
                [&Key](auto&& pair) {
                    return pair.first == Key;
                });

            return iter == end() ? nullptr : &iter->value;
        }

        inline const ValRealT* At(KeyRealT Key) const {
            auto iter = std::find_if(begin(), end(),
                [&Key](const auto&& pair) {
                    return pair.first == Key;
                });

            return iter == end() ? nullptr : &iter->value;
        }

        inline ValRealT* operator[](KeyRealT Key) {
            return At(Key);
        }

        inline const ValRealT* operator[](KeyRealT Key) const {
            return At(Key);
        }
    };

    // System.Type
    struct Type : Il2Cpp::Object {
        intptr_t handle;

        static inline intptr_t GetTypeHandle(Il2Cpp::Object* ObjectArg) {
            static void* fn = Il2Cpp::GetMethod("mscorlib.dll", "System", "Type", "GetTypeHandle")->methodPointer;
            return reinterpret_cast<intptr_t(*)(Il2Cpp::Object*)>(fn)(ObjectArg);
        }

        static inline Type* GetTypeFromHandle(intptr_t Handle) {
            static void* fn = Il2Cpp::GetMethod("mscorlib.dll", "System", "Type", "GetTypeFromHandle")->methodPointer;
            return reinterpret_cast<Type*(*)(intptr_t)>(fn)(Handle);
        }

        static inline Type* FromClass(Il2Cpp::Class* ClassArg) {
            Il2Cpp::Object* dummy = Il2Cpp::Object::Create(ClassArg);
            intptr_t handle = GetTypeHandle(dummy);
            return GetTypeFromHandle(handle);
        }
    };

    // System.Nullable<T>
    template <Il2Cpp::Traits::ValueType T>
    struct Nullable {
        bool hasValue;
        T value;

        inline T& operator*() {
            return value;
        }

        inline const T& operator*() const {
            return value;
        }

        inline T* operator->() {
            return hasValue ? &value : nullptr;
        }

        inline const T* operator->() const {
            return hasValue ? &value : nullptr;
        }
    };

    // System.String
    struct String : Il2Cpp::String {};
}