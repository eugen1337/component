#include "./Component.h"
#include <iostream>

InfoFactory::InfoFactory()
{
    std::cout<<"InfoFactory::InfoFactory()"<<std::endl;
    this -> fRefCount = 0;
}

InfoFactory::~InfoFactory()
{
    std::cout<<"InfoFactory::~InfoFactory()"<<std::endl;
}

HRESULT InfoFactory::QueryInterface(const IID& iid, void** ppv)
{
    std::cout<<"InfoFactory::QueryInterface"<<std::endl;

    if (iid == IID_IClassFactory1)
    {
        *ppv = (IUnknown*) (IClassFactory*) this;
    }
    else if (iid == IID_IInfoFactory)
    {
        *ppv = (IUnknown*) (IInfoFactory*) this;
    }
    else
    {
        *ppv = NULL;
        return E_NOINTERFACE;
    }
    
    this->AddRef();
    return S_OK;
}

ULONG InfoFactory::AddRef()
{
    fRefCount++;
    return fRefCount;
}

ULONG InfoFactory::Release()
{
    fRefCount--;
    if (fRefCount == 0)
    {
        delete this;
    }
    return fRefCount;
}

HRESULT InfoFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{
    std::cout<<"InfoFactory::CreateInstance"<<std::endl;
    IUnknown* s = (IUnknown*) (IFSMInfo*) new FSMInfo();
    
    return s -> QueryInterface(iid, ppv);
}

HRESULT InfoFactory::CreateInstance(const IID& iid, void** ppv, int a)
{
    std::cout<<"InfoFactory::CreateInstance with license"<<std::endl;
    HRESULT res = E_NOTIMPL;

    IUnknown* s = (IUnknown*) (IFSMInfo*) new FSMInfo();

    return s -> QueryInterface(iid, ppv);
}

HRESULT InfoFactory::LockServer(BOOL bLock)
{
    return S_OK;
}

// ---------------------------------------------------------------------------

FSMInfo::FSMInfo()
{
    std::cout<<"FSMInfo::FSMInfo()"<<std::endl;
    fRefCount = 0;
}

FSMInfo::~FSMInfo()
{
    std::cout<<"FSMInfo::~FSMInfo()"<<std::endl;
}

HRESULT FSMInfo::QueryInterface(const IID& iid, void** ppv)
{
    std::cout<<"FSMInfo::QueryInterface"<<std::endl;

    if (iid == IID_IUnknown1)
    {
        *ppv = (IUnknown*) (IFSMInfo*) this;
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

ULONG FSMInfo::AddRef()
{
    fRefCount++;
    return fRefCount;
}

ULONG FSMInfo::Release()
{
    fRefCount--;
    if (fRefCount == 0)
    {
        delete this;
    }
    return fRefCount;
}

HRESULT FSMInfo::fileInfo(char *path)
{
    std::cout<<"FSMInfo::fileInfo()"<<std::endl;
    return S_OK;
}