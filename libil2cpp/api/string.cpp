#include "string.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

int32_t String::GetLength() const
{
    static auto _ApiFunction = Resolver::GetExport<int32_t(*)(const String*)>("il2cpp_string_length");
    return _ApiFunction(this);
}

std::string_view String::GetString() const
{
    std::wstring_view _Wstr = GetWString();
    return std::string(_Wstr.begin(), _Wstr.end());
}

std::wstring_view String::GetWString() const
{
    return std::wstring_view(reinterpret_cast<const wchar_t*>(chars), length);
}

String* String::New(std::string_view str)
{
    static auto _ApiFunction = Resolver::GetExport<String * (*)(const char*)>("il2cpp_string_new");
    return _ApiFunction(str.data());
}

String* String::NewWrapper(std::string_view str)
{
    static auto _ApiFunction = Resolver::GetExport<String * (*)(const char*)>("il2cpp_string_new_wrapper");
    return _ApiFunction(str.data());
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
