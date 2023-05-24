#include "./Component.h"
#include <iostream>

//IDispatch (Begin)
HRESULT __stdcall FSManager::GetTypeInfoCount(UINT* pctinfo)
{
    std::cout<<"FSManager::GetTypeInfoCount()"<<std::endl;
    return S_OK;
}

HRESULT __stdcall FSManager::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo)
{
    std::cout<<"FSManager::GetTypeInfo()"<<std::endl;
    return S_OK;
}

HRESULT __stdcall FSManager::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
                                    LCID lcid, DISPID* rgDispId)
{
    std::cout<<"FSManager::GetIDsOfNames"<<std::endl;
    if (cNames!=1) {return E_NOTIMPL;}

    //const wchar_t* src = rgszNames[0];
    //char* dest = new char[32];
    //wcstombs(dest,src,32);
    //printf(dest); printf("\n");

if (wcscmp(rgszNames[0],L"Fx1")==0)
    {
      rgDispId[0] = 1;
    }
    else if (wcscmp(rgszNames[0],L"Fy1")==0)
    {
      rgDispId[0] = 2;
    }


    //Property
    else if (wcscmp(rgszNames[0],L"Px1")==0)
    {
      rgDispId[0] = 3;
    }
    else
    {
       return E_NOTIMPL;
    }
    return S_OK;
}

HRESULT __stdcall FSManager::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,WORD wFlags, DISPPARAMS* pDispParams,VARIANT* pVarResult,
                             EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
    std::cout<<"FSManager::Invoke()"<<std::endl;
    if (dispIdMember==1)
    {
       CreateFolder((char*) 'path');
    }
    else if (dispIdMember==2)
    {
       CreateThisFile((char*) 'path');
    }
    /*
    //Property
    else if (dispIdMember==3)
    {
       //printf("%d\n",wFlags);
       if ( (wFlags==DISPATCH_PROPERTYGET) || (wFlags==1) || (wFlags==3) )
       {
          if (pVarResult!=NULL)
          {
            pVarResult->vt = VT_INT;
            pVarResult->intVal = px1;
          }
       }
       else if (wFlags==DISPATCH_PROPERTYPUT)
       {
          DISPPARAMS param = *pDispParams;
          VARIANT arg = (param.rgvarg)[0];
          //printf("%d\n",arg.vt);
          VariantChangeType(&arg,&arg,0,VT_INT);
          //printf("%d\n",arg.vt);
          px1 = arg.intVal;
       }
       else
       {
         return E_NOTIMPL;
       }
    }
    else
    {
      return E_NOTIMPL;
    }
    return S_OK;
    */
}
//IDispatch (End)

FSMFactory::FSMFactory()
{
    std::cout<<"FSMFactory::FSMFactory()"<<std::endl;
    this -> fRefCount = 0;
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
    fRefCount++;
    return fRefCount;
}

ULONG FSMFactory::Release()
{
    fRefCount--;
    if (fRefCount == 0)
    {
        delete this;
    }
    return fRefCount;
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

    fRefCount = 0;

    CoInitialize(NULL);

    IClassFactory* PCF = NULL;

    HRESULT resFactory = CoGetClassObject(CLSID_FSMInfo, CLSCTX_INPROC_SERVER, NULL, IID_IClassFactory1, (void**) &PCF);

    if (!SUCCEEDED(resFactory))
    {
        std::cout<<"No factory"<<std::endl;
    }

    HRESULT resInstance = PCF->CreateInstance(NULL, IID_IFSMInfo, (void**) &pinfo);

    if (!SUCCEEDED(resInstance))
    {
        std::cout<<"No instance"<<std::endl;
    }

    PCF->Release();

    CoUninitialize();
}

FSManager::~FSManager()
{
    std::cout<<"FSManager::~FSManager()"<<std::endl;
    pinfo -> Release();
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
    fRefCount++;
    return fRefCount;
}

ULONG FSManager::Release()
{
    fRefCount--;
    if (fRefCount == 0)
    {
        delete this;
    }
    return fRefCount;
}

HRESULT FSManager::fileInfo(char *path)
{
    std::cout<<"FSManager::fileInfo()"<<std::endl;
    return pinfo -> fileInfo(path);
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