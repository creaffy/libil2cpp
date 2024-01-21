#include "exception.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

void Exception::Raise()
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(Exception*)>("il2cpp_raise_exception");
    return _ApiFunction(this);
}

void Exception::FormatException(char* message, int message_size) const
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(const Exception*, char*, int)>("il2cpp_format_exception");
    return _ApiFunction(this, message, message_size);
}

void Exception::FormatStackTrace(char* output, int output_size) const
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(const Exception*, char*, int)>("il2cpp_format_stack_trace");
    return _ApiFunction(this, output, output_size);
}

void Exception::UnhandledException()
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(Exception*)>("il2cpp_unhandled_exception");
    return _ApiFunction(this);
}

void Exception::NativeStackTrace(uintptr_t** addresses, int* num_frames, char* imageUUID) const
{
    static auto _ApiFunction = Resolver::GetExport<void(*)(const Exception*, uintptr_t**, int*, char*)>("il2cpp_native_stack_trace");
    return _ApiFunction(this, addresses, num_frames, imageUUID);
}

Exception* Exception::FromNameMsg(const Image* image, const std::string name_space, const std::string name, const std::string msg)
{
    static auto _ApiFunction = Resolver::GetExport<Exception * (*)(const Image*, const char*, const char*, const char*)>("il2cpp_exception_from_name_msg");
    return _ApiFunction(image, name_space.c_str(), name.c_str(), msg.c_str());
}

Exception* Exception::GetArgumentNullException(const std::string arg)
{
    static auto _ApiFunction = Resolver::GetExport<Exception * (*)(const char*)>("il2cpp_get_exception_argument_null");
    return _ApiFunction(arg.c_str());
}
