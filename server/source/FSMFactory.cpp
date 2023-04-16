#include "FSMFactory.h"
#include "FSManager.h"

#include <windows.h>
#include <iostream>

/*HRESULT_ CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv)
{
    std::cout<<"CreateInstance global"<<std::endl;

    IClassFactory_ *cf = NULL;
    HRESULT_ res = GetClassObject(clsid, IID_IClassFactory_, (void**) &cf);
    
    if (res != S_OK_) {
        return res;
    }

    res = cf -> CreateInstance(iid, (void **) &ppv);
    
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

    if (res != S_OK_) {
        ppv = NULL;
        return res;
    }

    return res;

}*/

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



extern "C" HRESULT_ __stdcall __declspec(dllexport) GetClassObject(const CLSID_ &clsid, const IID_ &iid, void **ppv)
{
    std::cout << "GetClassObject" << std::endl;
    IUnknown_ *s = NULL;

    if (clsid == CLSID_FSMFactory)
    {
        s = (IUnknown_ *)(IClassFactory_ *)new FSMFactory();
    }
    else
    {
        *ppv = NULL;
        return E_NOCOMPONENT_;
    }

    s->AddRef();
    HRESULT_ res = s->QueryInterface(iid, ppv);

    s->Release();
    return res;
}

HRESULT_ FSMFactory::CreateInstance(const IID_& iid, void** ppv)
{
    std::cout << "FSMFactory CreateInstance" << std::endl;
    FSManager* s = new FSManager();

    s -> AddRef();
    HRESULT_ res =  s -> QueryInterface(iid, ppv);
    s -> Release();
    
    return res;
}

HRESULT_ FSMFactory::CreateInstanceWPar(const IID_& iid, void** ppv, int a)
{
    std::cout << "FSManager CreateInstanceWPar" << std::endl;
    FSManager* s = new FSManager(a);

    s -> AddRef();
    HRESULT_ res =  s -> QueryInterface(iid, ppv);
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

HRESULT_ FSMFactory::QueryInterface(const IID_& iid, void** ppv)
{
    if (iid == IID_IUnknown_)
    {
        *ppv = (IUnknown_*) (IClassFactory_*) this;
    }
    else if (iid == IID_IClassFactory_)
    {
        *ppv = static_cast<IClassFactory_*>(this);
    }
    else if (iid == IID_IFSMFactory)
    {
        *ppv = static_cast<IFSMFactory*>(this);
    }
    else
    {
        *ppv = NULL;
        return E_NOINTERFACE_;
    }
    
    this->AddRef();

    return S_OK_;
}

ULONG_ FSMFactory::AddRef()
{
    std::cout<<"FSMFactory AddRef"<<std::endl;
    fRefCount++;

    return fRefCount;
}

ULONG_ FSMFactory::Release()
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