#include <windows.h>
#include <iostream>

#include "IClassFactory.h"

typedef HRESULT_ __stdcall (*DllGetClassObjectType) (const CLSID_& clsid, const IID_& iid, void** ppv);


extern "C" HRESULT_ __stdcall __declspec(dllexport) CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv)
{
    std::cout<<"CreateInstance global"<<std::endl;

    IClassFactory_ *cf = NULL;
    HRESULT_ res = GetClassObject(clsid, IID_IClassFactory_, (void**) &cf);
    
    if (res != S_OK_) {
        return res;
    }

    res = cf -> CreateInstance(iid, (void **) &ppv);
    /*
    if (iid == IID_IFileManager)
    {
        res = cf -> CreateInstance(iid, (void **) &o);
        *ppv = (IUnknown_*)(IFileManager*) o;

    }
    else if (iid == IID_IFolderManager)
    {
        res = cf -> CreateInstance(iid, (void **) &o);
        *ppv = (IUnknown_*)(IFolderManager*) o;
    }
    */
    if (res != S_OK_) {
        ppv = NULL;
        return res;
    }

    return res;

}

extern "C" HRESULT_ __stdcall __declspec(dllexport) GetClassObject(const CLSID_& clsid, const IID_& iid, void** ppv)
{
    TCHAR* path = (TCHAR*) "./manager/server.dll";
    HINSTANCE h = LoadLibrary(path);

    if (clsid != CLSID_FSMFactory) {
        return E_NOCOMPONENT_;
    }
    
    if (!h)
    {
        std::cout<<"dll error!!!\n";
        return 3;
    }

    DllGetClassObjectType GetClsObj = (DllGetClassObjectType) GetProcAddress(h,"GetClassObject");

    if (!GetClsObj)
    {
        std::cout<<"dll error!!!\n";
        return 3;
    }

    return GetClsObj(clsid, iid, ppv);
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            std::cout<<"DLL CONNECTED"<<std::endl;
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
