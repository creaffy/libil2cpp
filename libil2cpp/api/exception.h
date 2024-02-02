#pragma once
#include "../base.h"
#include <string>

namespace Il2Cpp
{
    typedef struct Image Image;

    struct Exception : public Il2CppException
    {
        void Raise();
        void FormatException(char* message, int message_size) const;
        void FormatStackTrace(char* output, int output_size) const;
        void UnhandledException();
        void NativeStackTrace(uintptr_t** addresses, int* num_frames, char* imageUUID) const;
        static Exception* FromNameMsg(const Image* image, std::string_view name_space, std::string_view name, std::string_view msg);
        static Exception* GetArgumentNullException(std::string_view arg);
    };
}