#include "component.h"
#include <iostream>

extern "C" HRESULT __stdcall __declspec(dllexport) DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv)
{
    std::cout<<"DllGetClassObject"<<std::endl;

    IUnknown* s = NULL;

    if (clsid == CLSID_IFSManager)
    {
        s = (IUnknown*) (IClassFactory*) new FSMFactory();
    }
    else
    {
        *ppv = NULL;
        return E_NOTIMPL;
    }

    HRESULT res = s->QueryInterface(iid, ppv);
    
    return S_OK;
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            std::cout<<"FSM DLL CONNECTED"<<std::endl;
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