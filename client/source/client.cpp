#include "lib/IFileManager.h"
#include "lib/IFolderManager.h"
#include "lib/FSMFactory.h"

#include <windows.h>
#include <iostream>
using namespace std;

typedef HRESULT_ __stdcall (*DllGetClassObjectType) (const CLSID_& clsid, const IID_& iid, void** ppv);

int main() {
	cout << "Client::Main::Start" << endl;	
	TCHAR* path = (TCHAR*) "./lib/manager.dll";
    HINSTANCE h = LoadLibrary(path);

	if (!h)
    {
        std::cout<<"Cliene::Main::dll error!!!\n";
        return 3;
    }

	cout << "Client::Main::GetProcAddress(h,'GetClassObject');" << endl;	
	DllGetClassObjectType GetClsObj = (DllGetClassObjectType) GetProcAddress(h,"GetClassObject");

    if (!GetClsObj)
    {
        std::cout<<"dll error!!!\n";
        return 3;
    }

	FSMFactory* pf = NULL;
	HRESULT_ res = GetClsObj(CLSID_IFSManager, IID_IFSMFactory, (void**) &pf);

	if (res != S_OK_)
	{
		cout << "Client::Main::Error Factory for CServer or IClassFactory_: " << res << endl;	
		return 0;	
	}

	IFileManager *pfileMan = NULL;
	res = pf->CreateInstance(IID_IFileManager, (void **)&pfileMan);

	// CreateInstanceWpar doesn't invoke

	if (res == S_OK_)
	{
		pfileMan -> CreateThisFile((char *)"AHAHA");
		cout << "Client::Main::Success pIFSManager: " << endl;
	}
	else
	{
		cout << "Client::Main::Error" << res << endl;
		return 0;
	}

	cout << "Client::Main QueryInterface" << endl;
	IFolderManager *pfoldMan = NULL;
	res = pfileMan->QueryInterface(IID_IFolderManager, (void **)&pfoldMan);
	pfileMan->Release();
	if (res == S_OK_)
	{
		cout << "Client::Main Success IFolderManager: " << endl;
		pfoldMan -> CreateFolder((char *)"C:/myfold");
	}
	else
	{
		cout << "Client::Main::Error IFolderManager: " << res << endl;
	}


	cout << "Client::Main::CreateInstance Test" << endl;	
	path = (TCHAR*) "./lib/manager.dll";
    h = LoadLibrary(path);

	if (!h)
    {
        std::cout<<"Cliene::Main::dll error!!!\n";
        return 3;
    }

	if (!h)
    {
        std::cout<<"Cliene::Main::dll error!!!\n";
        return 3;
    }

	cout << "Client::Main::GetProcAddress(h,'CreateInstance');" << endl;	
	DllGetClassObjectType CreateInst = (DllGetClassObjectType) GetProcAddress(h,"CreateInstance");

    if (!GetClsObj)
    {
        std::cout<<"dll error!!!\n";
        return 3;
    }

	res = CreateInst(CLSID_IFSManager, IID_IFSMFactory, (void**) &pfileMan);	

	pfileMan -> CreateThisFile((char *)"NEW FILE");
	/*
 	try
 	{	    		
		cout << "Client::Main::Start" << endl;			
		
		cout << "Client::Main GetClassObject FSMFactory" << endl;			
		FSMFactory* pf = NULL;

		HRESULT_ res = GetClassObject(CLSID_IFSManager, IID_IFSMFactory, (void**) &pf);
		if (res != S_OK_)
		{
			cout << "Client::Main::Error Factory for CServer or IClassFactory_: " << res << endl;	
			return 0;		
		}

		
		IFileManager* pfileMan= NULL;
		res = pf -> CreateInstance(IID_IFileManager, (void**)&pfileMan);
		
		// CreateInstanceWpar doesn't invoke

		if (res == S_OK_)
		{
			pfileMan -> CreateFile((char*) "AHAHA");
			cout << "Client::Main::Success pIFSManager: " << endl;
		}	
		else
		{
		cout << "Client::Main::Error" << res << endl;	
		return 0;		
		}

		cout << "Client::Main QueryInterface" << endl;			
		IFolderManager* pfoldMan = NULL;
		res = pfileMan -> QueryInterface(IID_IFolderManager, (void**)& pfoldMan);			
		pfileMan -> Release();
		if (res==S_OK_)
		{
			cout << "Client::Main Success IFolderManager: " << endl;			
			pfoldMan -> CreateFolder((char*) "C:/myfold");
		}	
		else
		{
		cout << "Client::Main::Error IFolderManager: " << res << endl;			
		}
    }
    catch(...) {
        cout << "Client::Main::Error" << endl;
    }*/
/*
    cout << "Client::Main::QueryInterface IX->IY" << endl;			
	IY* pIY = NULL;
    res = pIX->QueryInterface(IID_IY,(void**)&pIY);
	cout << "Client::Main::IX->Release" << endl;			
	pIX->Release();
    if (res==S_OK_)
	{
		cout << "Client::Main::Success IY: " << endl;			
		pIY->Fy1();
		pIY->Fy2();
	}	
	else
    {
	   cout << "Client::Main::Error IY: " << res << endl;			
	}
	
	cout << "Client::Main::IY->Release" << endl;			
	pIY->Release();
	*/
    cout << "Client::Main::Finish" << endl;	
 	//}		
}