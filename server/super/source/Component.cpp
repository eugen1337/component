#include "./Component.h"

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
    if (cNames != 1) {return E_NOTIMPL;}

    if (wcscmp(rgszNames[0], L"CreateFolder") == 0)
    {
        rgDispId[0] = 1;
    }

    else if (wcscmp(rgszNames[0], L"DeleteFolder") == 0)
    {
        rgDispId[0] = 2;
    }

    else if (wcscmp(rgszNames[0], L"CreateThisFile") == 0)
    {
        rgDispId[0] = 3;
    }

    else if (wcscmp(rgszNames[0], L"DeleteThisFile") == 0)
    {
        rgDispId[0] = 4;
    }

    else if (wcscmp(rgszNames[0], L"fileInfo") == 0)
    {
        rgDispId[0] = 5;
    }

    else if (wcscmp(rgszNames[0], L"testInt") == 0)
    {
        rgDispId[0] = 6;
    }

    else
    {
        return E_NOTIMPL;
    }

    return S_OK;
}

std::string getStrFromDispparams(DISPPARAMS* pDispParams)
{
    DISPPARAMS param = *pDispParams;
    VARIANT arg = (param.rgvarg)[0];

    std::wstring ws(arg.bstrVal, SysStringLen(arg.bstrVal));
    std::string s(ws.begin(), ws.end());

    return s;
}

HRESULT __stdcall FSManager::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,WORD wFlags, DISPPARAMS* pDispParams,VARIANT* pVarResult,
                             EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
    std::cout<<"FSManager::Invoke()"<<std::endl;

    if (dispIdMember == 1)
    {
        std::cout << "dispIdMember == 1" << std::endl;
        std::string s = getStrFromDispparams(pDispParams);

        CreateFolder(s);
    }
    else if (dispIdMember == 2)
    {
        std::cout << "dispIdMember == 2" << std::endl;
        std::string s = getStrFromDispparams(pDispParams);

        DeleteFolder(s);
    }
    else if (dispIdMember == 3)
    {
        std::cout << "dispIdMember == 3" << std::endl;
        std::string s = getStrFromDispparams(pDispParams);

        CreateThisFile();
    }
    else if (dispIdMember == 4)
    {
        std::cout << "dispIdMember == 4" << std::endl;
        std::string s = getStrFromDispparams(pDispParams);

        DeleteThisFile();
    }
    else if (dispIdMember == 5)
    {
        std::cout << "dispIdMember == 5" << std::endl;
        std::string s = getStrFromDispparams(pDispParams);

        fileInfo();
    } 
    // Property
    else if (dispIdMember == 6)
    {
        if ((wFlags == DISPATCH_PROPERTYGET) || (wFlags == 1) || (wFlags == 3))
        {
            if (pVarResult != NULL)
            {
                pVarResult->vt = VT_INT;
                pVarResult->intVal = testInt;
            }
        }
        else if (wFlags == DISPATCH_PROPERTYPUT)
        {
            DISPPARAMS param = *pDispParams;
            VARIANT arg = (param.rgvarg)[0];
            VariantChangeType(&arg, &arg, 0, VT_INT);
            testInt = arg.intVal;
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

HRESULT FSMFactory::CreateInstance(const IID& iid, void** ppv, std::string path)
{
    std::cout<<"FSMFactory::CreateInstance with license"<<std::endl;
    HRESULT res = E_NOTIMPL;

    IUnknown* s = (IUnknown*) (IFolderManager*) new FSManager(path);

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

    testInt = 5;

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

FSManager::FSManager(std::string lpath)
{
    std::cout<<"FSManager::FSManager(std::string path)"<<std::endl;

    path = lpath;

    testInt = 5;

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
    else if (iid == IID_IDispatch1)
    {
        *ppv = static_cast<IDispatch*>(this);
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