# libil2cpp

Modern C++ IL2CPP wrappers

## Resolvers

Search for classes, methods, properties, etc. simply using the names!

**Example:**

```cpp
Il2Cpp::Class* klass = Il2Cpp::GetClass("UnityEngine.CoreModule.dll", "UnityEngine", "GameObject");
Unity::GameObject* gameObject = Il2Cpp::Object::Create<Unity::GameObject>(klass);
Unity::Transform* transform = gameObject->GetProperty<Unity::Transform>("transform");
```

## Iterators

Easily iterate any `System::List<T>`, `System::Dictionary<K,V>` and `Il2Cpp::Array<T>` like it's a map or a vector!

**Example:**

```cpp
System::Dictionary<int32_t, System::Type>* someDict = ...;
for (auto&& [i, type] : *someDict) { // int i, System::Type* type
    ...
}
```

## Operators

Operate on Unity Vectors2's and 3's easily thanks to operator implementations!

**Example:**

```cpp
Unity::Vec3f vec = { 111, 222, 333 };
vec *= 2.5f;
vec += Unity::Vec3f{ 1, 2, 3 };
Unity::Vec3f vec2 = vec - Unity::Vec3f{ 7.843f, 12.322f, 0.654f };
Unity::Vec3i vec3 = vec2;
```

## And more :)
