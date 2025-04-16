#pragma once
#include "system.h"
#include "lib/api/property.h"

namespace Unity {
    template <class T>
    struct Vec2 {
        T x;
        T y;

        constexpr Vec2() noexcept = default;

        template <class X, class Y>
        constexpr Vec2(X _x, Y _y) noexcept
            : x(static_cast<T>(_x)), y(static_cast<T>(_y)) {
        }

        template <class R>
        constexpr Vec2(const Vec2<R>& r) noexcept
            : x(static_cast<T>(r.x)), y(static_cast<T>(r.y)) {
        }

        template <class R>
        constexpr Vec2(Vec2<R>&& r) noexcept
            : x(static_cast<T>(r.x)), y(static_cast<T>(r.y)) {
            r.x = static_cast<R>(0);
            r.y = static_cast<R>(0);
        }

        template <class R>
        constexpr Vec2& operator=(const Vec2<R>& r) noexcept {
            x = static_cast<T>(r.x);
            y = static_cast<T>(r.y);
            return *this;
        }

        template <class R>
        constexpr Vec2& operator=(Vec2<R>&& r) noexcept {
            x = static_cast<T>(r.x);
            y = static_cast<T>(r.y);
            r.x = static_cast<R>(0);
            r.y = static_cast<R>(0);
            return *this;
        }

        template <class R>
        constexpr inline Vec2 operator+(const Vec2<R>& r) const noexcept {
            return { x + r.x, y + r.y };
        }

        template <class R>
        constexpr inline Vec2 operator-(const Vec2<R>& r) const noexcept {
            return { x - r.x, y - r.y };
        }

        template <class R>
        constexpr inline Vec2 operator*(const Vec2<R>& r) const noexcept {
            return { x * r.x, y * r.y };
        }

        template <class R>
        constexpr inline Vec2 operator/(const Vec2<R>& r) const {
            return { x / r.x, y / r.y };
        }

        template <class R>
        constexpr inline Vec2& operator+=(const Vec2<R>& r) noexcept {
            x += r.x;
            y += r.y;
            return *this;
        }

        template <class R>
        constexpr inline Vec2& operator-=(const Vec2<R>& r) noexcept {
            x -= r.x;
            y -= r.y;
            return *this;
        }

        template <class R>
        constexpr inline Vec2& operator*=(const Vec2<R>& r) noexcept {
            x *= r.x;
            y *= r.y;
            return *this;
        }

        template <class R>
        constexpr inline Vec2& operator/=(const Vec2<R>& r) {
            x /= r.x;
            y /= r.y;
            return *this;
        }

        template <class R>
        constexpr inline Vec2 operator*(const R& r) const noexcept {
            return { x * r, y * r };
        }

        template <class R>
        constexpr inline Vec2 operator/(const R& r) const {
            return { x / r, y / r };
        }

        template <class R>
        constexpr inline Vec2& operator*=(const R& r) noexcept {
            x *= r;
            y *= r;
            return *this;
        }

        template <class R>
        constexpr inline Vec2& operator/=(const R& r) {
            x /= r;
            y /= r;
            return *this;
        }

        template <class R>
        constexpr inline bool operator==(const Vec2<R>& r) const noexcept {
            return x == r.x && y == r.y;
        }

        template <class R>
        constexpr inline bool operator!=(const Vec2<R>& r) const noexcept {
            return !(*this == r);
        }

        inline double Magnitude() const noexcept {
            return std::sqrt(static_cast<double>(x * x + y * y));
        }

        inline Vec2<double> Normalized() const noexcept {
            double m = Magnitude();
            return m > 0 ? Vec2<double>{ x / m, y / m } : Vec2<double>{};
        }

        template <class R>
        inline double Distance(const Vec2& r) const {
            T dx = std::abs(x - r.x);
            T dy = std::abs(y - r.y);
            return std::sqrt(dx * dx + dy * dy);
        }
    };

    // UnityEngine.Vector2
    using Vec2f = Vec2<float>;
    // UnityEngine.Vector2Int
    using Vec2i = Vec2<int>;

    template <class T>
    struct Vec3 {
        T x;
        T y;
        T z;

        constexpr Vec3() noexcept = default;

        template <class X, class Y, class Z>
        constexpr Vec3(X _x, Y _y, Z _z) noexcept
            : x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)) {
        }

        template <class R>
        constexpr Vec3(const Vec3<R>& r) noexcept
            : x(static_cast<T>(r.x)), y(static_cast<T>(r.y)), z(static_cast<T>(r.z)) {
        }

        template <class R>
        constexpr Vec3(Vec3<R>&& r) noexcept
            : x(static_cast<T>(r.x)), y(static_cast<T>(r.y)), z(static_cast<T>(r.z)) {
            r.x = static_cast<R>(0);
            r.y = static_cast<R>(0);
            r.z = static_cast<R>(0);
        }

        template <class R>
        constexpr Vec3& operator=(const Vec3<R>& r) noexcept {
            x = static_cast<T>(r.x);
            y = static_cast<T>(r.y);
            z = static_cast<T>(r.z);
            return *this;
        }

        template <class R>
        constexpr Vec3& operator=(Vec3<R>&& r) noexcept {
            x = static_cast<T>(r.x);
            y = static_cast<T>(r.y);
            z = static_cast<T>(r.z);
            r.x = static_cast<R>(0);
            r.y = static_cast<R>(0);
            r.z = static_cast<R>(0);
            return *this;
        }

        template <class R>
        constexpr inline Vec3 operator+(const Vec3<R>& r) const noexcept {
            return { x + r.x, y + r.y, z + r.z };
        }

        template <class R>
        constexpr inline Vec3 operator-(const Vec3<R>& r) const noexcept {
            return { x - r.x, y - r.y, z - r.z };
        }

        template <class R>
        constexpr inline Vec3 operator*(const Vec3<R>& r) const noexcept {
            return { x * r.x, y * r.y, z * r.z };
        }

        template <class R>
        constexpr inline Vec3 operator/(const Vec3<R>& r) const {
            return { x / r.x, y / r.y, z / r.z };
        }

        template <class R>
        constexpr inline Vec3& operator+=(const Vec3<R>& r) noexcept {
            x += r.x;
            y += r.y;
            z += r.z;
            return *this;
        }

        template <class R>
        constexpr inline Vec3& operator-=(const Vec3<R>& r) noexcept {
            x -= r.x;
            y -= r.y;
            z -= r.z;
            return *this;
        }

        template <class R>
        constexpr inline Vec3& operator*=(const Vec3<R>& r) noexcept {
            x *= r.x;
            y *= r.y;
            z *= r.z;
            return *this;
        }

        template <class R>
        constexpr inline Vec3& operator/=(const Vec3<R>& r) {
            x /= r.x;
            y /= r.y;
            z /= r.z;
            return *this;
        }

        template <class R>
        constexpr inline Vec3 operator*(const R& r) const noexcept {
            return { x * r, y * r, z * r };
        }

        template <class R>
        constexpr inline Vec3 operator/(const R& r) const {
            return { x / r, y / r, z / r };
        }

        template <class R>
        constexpr inline Vec3& operator*=(const R& r) noexcept {
            x *= r;
            y *= r;
            z *= r;
            return *this;
        }

        template <class R>
        constexpr inline Vec3& operator/=(const R& r) {
            x /= r;
            y /= r;
            z /= r;
            return *this;
        }

        template <class R>
        constexpr inline bool operator==(const Vec3<R>& r) const noexcept {
            return x == r.x && y == r.y && z == r.z;
        }

        template <class R>
        constexpr inline bool operator!=(const Vec3<R>& r) const noexcept {
            return !(*this == r);
        }

        inline double Magnitude() const noexcept {
            return std::sqrt(static_cast<double>(x * x + y * y + z * z));
        }

        inline Vec3<double> Normalized() const noexcept {
            double m = Magnitude();
            return m > 0 ? Vec3<double>{ x / m, y / m, z / m } : Vec3<double>{};
        }

        template <class R>
        inline double Distance(const Vec3<R>& r) {
            T dx = std::abs(x - r.x);
            T dy = std::abs(y - r.y);
            T dz = std::abs(z - r.z);
            return std::sqrt(dx * dx + dy * dy + dz * dz);
        }
    };

    // UnityEngine.Vector3
    using Vec3f = Vec3<float>;
    // UnityEngine.Vector3Int
    using Vec3i = Vec3<int>;

    template <class T>
    constexpr inline Vec2<T> V3To2(const Vec3<T>& r) noexcept {
        return { r.x, r.y };
    }

    template <class T>
    constexpr inline Vec3<T> V2To3(const Vec2<T>& r) noexcept {
        return { r.x, r.y, static_cast<T>(0) };
    }

    // UnityEngine.Object
    struct Object : Il2Cpp::Object {
        intptr_t cachedPtr;

        inline System::String* GetName() {
            static void* fn = klass->GetMethod("GetName")->methodPointer;
            return reinterpret_cast<System::String*(*)(Object*)>(fn)(this);
        }

        inline void Destroy() {
            static void* fn = klass->GetMethod("Destroy", 1)->methodPointer;
            return reinterpret_cast<void(*)(Object*)>(fn)(this);
        }

        static inline Il2Cpp::Array<Object*>* FindObjectsOfType(System::Type* TypeArg) {
            static void* fn = Il2Cpp::GetMethod("UnityEngine.CoreModule.dll", "UnityEngine", "Object", "FindObjectsOfType", 2)->methodPointer;
            return reinterpret_cast<Il2Cpp::Array<Object*>*(*)(System::Type*, bool)>(fn)(TypeArg, true);
        }
    };

    // UnityEngine.Component
    struct Component : Object {
    };

    // UnityEngine.Quaternion
    struct Quaternion {
        float x;
        float y;
        float z;
        float w;
    };

    // UnityEngine.Transform
    struct Transform : Object {
        inline Transform* GetChild(int32_t i) {
            static void* fn = klass->GetMethod("GetChild")->methodPointer;
            return reinterpret_cast<Transform*(*)(Transform*, int32_t)>(fn)(this, i);
        }

        inline Transform* GetRoot() {
            static void* fn = klass->GetMethod("GetRoot")->methodPointer;
            return reinterpret_cast<Transform*(*)(Transform*)>(fn)(this);
        }
    };

    // UnityEngine.GameObject
    struct GameObject : Object {
        inline void SetActive(bool Value) {
            static void* fn = klass->GetMethod("SetActive")->methodPointer;
            return reinterpret_cast<void(*)(GameObject*, bool)>(fn)(this, Value);
        }

        inline Component* AddComponent(System::Type* TypeArg) {
            static void* fn = klass->GetMethod("AddComponent", 1)->methodPointer;
            return reinterpret_cast<Component*(*)(GameObject*, System::Type*)>(fn)(this, TypeArg);
        }

        template <class T = Component> requires std::is_base_of<Component, T>::value
        inline Il2Cpp::Array<T>* GetComponents(System::Type* TypeArg) {
            static void* fn = klass->GetMethod("GetComponentsInternal")->methodPointer;
            return reinterpret_cast<Il2Cpp::Array<T>*(*)(GameObject*, System::Type*, bool, bool, bool, bool, Il2Cpp::Object*)>(fn)(this, TypeArg, false, false, true, false, nullptr);
        }

        static inline GameObject* Find(Il2Cpp::String* Name) {
            static void* fn = Il2Cpp::GetMethod("UnityEngine.CoreModule.dll", "UnityEngine", "GameObject", "Find")->methodPointer;
            return reinterpret_cast<GameObject*(*)(Il2Cpp::String*)>(fn)(Name);
        }
    };
}