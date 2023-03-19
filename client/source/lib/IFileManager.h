#pragma once

#include "IUnknown_.h"

class IFileManager: public IUnknown_
{
	public:
		virtual HRESULT_ __stdcall CreateFile(char *name)=0;
		virtual HRESULT_ __stdcall DeleteFile(char *name)=0;
};

 IUnknown_* __stdcall CreateServer_();

 HRESULT_ __stdcall CreateServer(const CLSID_& clsid, const IID_& iid, void** ppv);