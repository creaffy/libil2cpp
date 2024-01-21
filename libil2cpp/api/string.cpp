#include "string.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

int32_t String::GetLength() const
{
    static auto _ApiFunction = Resolver::GetExport<int32_t(*)(const String*)>("il2cpp_string_length");
    return _ApiFunction(this);
}

std::string String::GetString() const
{
    std::wstring _Wstr = GetWString();
    return std::string(_Wstr.begin(), _Wstr.end());
}

std::wstring String::GetWString() const
{
    return std::wstring(reinterpret_cast<const wchar_t*>(chars), length);
}

String* String::New(const std::string str)
{
    static auto _ApiFunction = Resolver::GetExport<String * (*)(const char*)>("il2cpp_string_new");
    return _ApiFunction(str.c_str());
}

String* String::NewWrapper(const std::string str)
{
    static auto _ApiFunction = Resolver::GetExport<String * (*)(const char*)>("il2cpp_string_new_wrapper");
    return _ApiFunction(str.c_str());
}

String* String::NewLen(const char* str, uint32_t length)
{
    static auto _ApiFunction = Resolver::GetExport<String * (*)(const char*, uint32_t)>("il2cpp_string_new_len");
    return _ApiFunction(str, length);
}

String* String::NewUtf16(const Il2CppChar* str, int32_t len)
{
    static auto _ApiFunction = Resolver::GetExport<String * (*)(const Il2CppChar*, int32_t)>("il2cpp_string_new_utf16");
    return _ApiFunction(str, len);
}
