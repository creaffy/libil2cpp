#pragma once
#include "../base.h"

namespace Il2Cpp {
    template <class T>
    struct Array : Il2CppArray {
        using RealT = Traits::RealT<T>;

#pragma warning(push)
#pragma warning(disable : 4200)
        RealT items[0];
#pragma warning(pop)

        inline RealT* begin() {
            return items;
        }

        inline const RealT* begin() const {
            return items;
        }

        inline RealT* end() {
            return &items[max_length];
        }

        inline const RealT* end() const {
            return &items[max_length];
        }

        inline RealT& At(size_t i) {
            return items[i];
        }

        inline const RealT& At(size_t i) const {
            return items[i];
        }

        static inline Array<T>* New(Class* ClassArg, size_t SizeArg) {
            static void* fn = GetExport("il2cpp_array_new");
            return reinterpret_cast<Array<T>*(*)(Class*, size_t)>(fn)(ClassArg, SizeArg);
        }
    };
}