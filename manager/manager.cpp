#include <windows.h>
#include <iostream>

#include "Interfaces.h"

typedef HRESULT __stdcall (*DllGetClassObjectType) (const CLSID& clsid, const IID& iid, void** ppv);


extern "C" HRESULT __stdcall __declspec(dllexport) CreateInstance(const CLSID& clsid, const IID& iid, void** ppv)
{
    std::cout<<"CreateInstance global"<<std::endl;

    /*IClassFactory *cf = NULL;
    HRESULT res = GetClassObject(clsid, IID_IClassFactory, (void**) &cf);
    
    if (res != S_OK) {
        return res;
    }

    //res = cf -> CreateInstance(iid, (void **) &ppv);
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
    /*if (res != S_OK) {
        ppv = NULL;
        return res;
    }

    return res;*/
    return S_OK;

}

extern "C" HRESULT __stdcall __declspec(dllexport) GetClassObject(const CLSID& clsid, const IID& iid, void** ppv)
{
    std::cout<< "MANAGER:: GetClassObject" << std::endl;
    TCHAR* path = (TCHAR*) "./manager/server.dll";
    HINSTANCE h = LoadLibrary(path);

    if (clsid != CLSID_FSMFactory) {
        return E_NOTIMPL;
    }
    
    if (!h)
    {
        std::cout<<"dll error!!!\n";
        return 3;
    }

    DllGetClassObjectType GetClsObj = (DllGetClassObjectType) GetProcAddress(h,"DllGetClassObject");

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
            std::cout<<"MANAGER DLL CONNECTED"<<std::endl;
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
