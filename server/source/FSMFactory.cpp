#include "FSMFactory.h"
#include "FSManager.h"
#include <iostream>

// DLL --------------------------

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            std::cout<<"FSM::DLL CONNECTED"<<std::endl;
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }

    return TRUE; // succesful
}

extern "C" HRESULT __stdcall __declspec(dllexport) DllGetClassObject(const CLSID &clsid, const IID &iid, void **ppv)
{
    std::cout << "GetClassObject" << std::endl;
    IUnknown *s = NULL;

    if (clsid == CLSID_FSMFactory)
    {
        s = (IUnknown *)(IClassFactory *)new FSMFactory();
    }
    else
    {
        *ppv = NULL;
        return E_NOTIMPL;
    }

    s->AddRef();
    HRESULT res = s->QueryInterface(iid, ppv);

    s->Release();
    return res;
}

HRESULT FSMFactory::CreateInstance(const IID& iid, void** ppv)
{
    std::cout << "FSMFactory CreateInstance" << std::endl;
    FSManager* s = new FSManager();

    s -> AddRef();
    HRESULT res =  s -> QueryInterface(iid, ppv);
    s -> Release();
    
    return res;
}

HRESULT FSMFactory::CreateInstance(IUnknown *pUnkOuter, const IID& iid, void** ppv)
{
    std::cout << "FSMFactory CreateInstance" << std::endl;
    FSManager* s = new FSManager();

    s -> AddRef();
    HRESULT res =  s -> QueryInterface(iid, ppv);
    s -> Release();
    
    return res;
}

HRESULT FSMFactory::CreateInstanceWPar(const IID& iid, void** ppv, int a)
{
    std::cout << "FSManager CreateInstanceWPar" << std::endl;
    FSManager* s = new FSManager(a);

    s -> AddRef();
    HRESULT res =  s -> QueryInterface(iid, ppv);
    s -> Release();
    
    return res;
}

FSMFactory::FSMFactory()
{
    std::cout<<"FSMFactory Consructor"<<std::endl;
    fRefCount = 0;
}

FSMFactory::~FSMFactory()
{
    std::cout<<"FSMFactory Destruct"<<std::endl;
}

HRESULT FSMFactory::QueryInterface(const IID& iid, void** ppv)
{
    if (iid == IID_IUnknown)
    {
        *ppv = (IUnknown*) (IClassFactory*) this;
    }
    else if (iid == IID_IClassFactory)
    {
        *ppv = static_cast<IClassFactory*>(this);
    }
    else if (iid == IID_IFSMFactory)
    {
        *ppv = static_cast<IFSMFactory*>(this);
    }
    else
    {
        *ppv = NULL;
        return E_NOINTERFACE;
    }
    
    this->AddRef();

    return S_OK;
}

ULONG FSMFactory::AddRef()
{
    std::cout<<"FSMFactory AddRef"<<std::endl;
    fRefCount++;

    return fRefCount;
}

ULONG FSMFactory::Release()
{
    std::cout<<"FSMFactory Release"<<std::endl;
    fRefCount--;

    if (fRefCount == 0)
    {
        delete this;
        std::cout<<"Delete object"<<std::endl;
    }
    
    return fRefCount;
}

HRESULT FSMFactory::LockServer(BOOL bLock)
{
    return S_OK;
}
