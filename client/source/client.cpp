#include "lib/IFileManager.h"
#include "lib/IFolderManager.h"

#include <iostream>
using namespace std;

int main() {
 	//try
 	//{	    		
	cout << "Client::Main::Start" << endl;			
	
	
	cout << "Client::Main::CreateServer CServer&IX" << endl;			
	IFileManager* pIFSManager = NULL;
	HRESULT_ res = CreateInstance(CLSID_IFSManager , IID_IFileManager, (void**) &pIFSManager);
	
    if (res == S_OK_)
	{
		pIFSManager -> CreateFile((char*) "AHAHA");
		cout << "Client::Main::Success pIFSManager: " << endl;
	}	
	/*else
    {
	   cout << "Client::Main::Error CServer or IX: " << res << endl;	
	   return 0;		
	}

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