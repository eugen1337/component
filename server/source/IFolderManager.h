#pragma once

#include "IUnknown_.h"

class IFolderManager: public IUnknown_
{
	public:
		virtual HRESULT_ __stdcall CreateFolder(char *path)=0;
		virtual HRESULT_ __stdcall DeleteFolder(char *path)=0;
};