#include "./Component.h"
#include <iostream>

FSMFactory::FSMFactory()
{
    std::cout<<"FSMFactory::FSMFactory()"<<std::endl;
    this -> refCount = 0;
}

FSMFactory::~FSMFactory()
{
    std::cout<<"FSMFactory::~FSMFactory()"<<std::endl;
}

HRESULT FSMFactory::QueryInterface(const IID& iid, void** ppv)
{
    std::cout<<"FSMFactory::QueryInterface"<<std::endl;

    if (iid == IID_IClassFactory1)
    {
        *ppv = (IUnknown*) (IClassFactory*) this;
    }
    else if (iid == IID_IFSMFactory)
    {
        *ppv = (IUnknown*) (IFSMFactory*) this;
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
    refCount++;
    return refCount;
}

ULONG FSMFactory::Release()
{
    refCount--;
    if (refCount == 0)
    {
        delete this;
    }
    return refCount;
}

HRESULT FSMFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{
    std::cout<<"FSMFactory::CreateInstance"<<std::endl;
    IUnknown* s = (IUnknown*) (IFolderManager*) new FSManager();
    
    return s -> QueryInterface(iid, ppv);
}

HRESULT FSMFactory::CreateInstance(const IID& iid, void** ppv, int a)
{
    std::cout<<"FSMFactory::CreateInstance with license"<<std::endl;
    HRESULT res = E_NOTIMPL;

    IUnknown* s = (IUnknown*) (IFolderManager*) new FSManager();

    return s -> QueryInterface(iid, ppv);
}

HRESULT FSMFactory::LockServer(BOOL bLock)
{
    return S_OK;
}

// ---------------------------------------------------------------------------

FSManager::FSManager()
{
    std::cout<<"FSManager::FSManager()"<<std::endl;
    refCount = 0;
}

FSManager::~FSManager()
{
    std::cout<<"FSManager::~FSManager()"<<std::endl;
}

HRESULT FSManager::QueryInterface(const IID& iid, void** ppv)
{
    std::cout<<"FSManager::QueryInterface"<<std::endl;

    if (iid == IID_IUnknown1)
    {
        *ppv = (IUnknown*) (IFolderManager*) this;
    }
    else if (iid == IID_IFolderManager)
    {
        *ppv = static_cast<IFolderManager*>(this);
    }
    else if (iid == IID_IFileManager)
    {
        *ppv = static_cast<IFileManager*>(this);
    }
    else if (iid == IID_IFSMInfo)
    {
        *ppv = static_cast<IFSMInfo*>(this);
    }
    else
    {
        *ppv = NULL;
        return E_NOINTERFACE;
    }
    
    this->AddRef();
    return S_OK;
}

ULONG FSManager::AddRef()
{
    refCount++;
    return refCount;
}

ULONG FSManager::Release()
{
    refCount--;
    if (refCount == 0)
    {
        delete this;
    }
    return refCount;
}

HRESULT FSManager::fileInfo(char *path)
{
    std::cout<<"FSManager::fileInfo()"<<std::endl;
    return S_OK;
}

HRESULT FSManager::CreateThisFile(char *path)
{ 
    std::cout<<"FSManager::CreateFile"<<std::endl;
    return S_OK; 
}

HRESULT FSManager::DeleteThisFile(char *path)
{
    std::cout<<"FSManager::CreateFile"<<std::endl;
    return S_OK;  
}
HRESULT FSManager::CreateFolder(char *path)
{
    std::cout<<"FSManager::CreateFolder"<<std::endl;
    return S_OK;  
}
HRESULT FSManager::DeleteFolder(char *path)
{
    std::cout<<"FSManager::DeleteFolder"<<std::endl;
    return S_OK;  
}