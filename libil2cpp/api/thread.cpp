#include "thread.h"
#include "../il2cpp.h"

using namespace Il2Cpp;

void Thread::Detach()
{
    static auto _ApiFunction = Resolver::GetExport<void (*)(Thread*)>("il2cpp_thread_detach");
    return _ApiFunction(this);
}

bool Thread::IsVM() const
{
    static auto _ApiFunction = Resolver::GetExport<bool (*)(const Thread*)>("il2cpp_is_vm_thread");
    return _ApiFunction(this);
}

Thread* Thread::GetCurrent()
{
    static auto _ApiFunction = Resolver::GetExport<Thread * (*)()>("il2cpp_thread_current");
    return _ApiFunction();
}

Thread* Thread::Attach(Domain* domain)
{
    static auto _ApiFunction = Resolver::GetExport<Thread * (*)(Domain*)>("il2cpp_thread_attach");
    return _ApiFunction(domain);
}

std::vector<Thread*> Thread::GetAllAttached()
{
    static auto _ApiFunction = Resolver::GetExport<Thread * *(*)(size_t*)>("il2cpp_thread_get_all_attached_threads");
    size_t _Size = 0;
    Thread** _Array = _ApiFunction(&_Size);
    return std::vector<Thread*>(_Array, _Array + _Size);
}
