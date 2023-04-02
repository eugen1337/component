#include "lib/IFileManager.h"
#include "lib/IFolderManager.h"
#include "lib/FSMFactory.h"

#include <iostream>
using namespace std;

int main() {
 	//try
 	//{	    		
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
    res = pf -> CreateInstanceWPar(IID_IFileManager, (void**)&pfileMan, 1);

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