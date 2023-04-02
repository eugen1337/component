#pragma once

#include "IUnknown_.h"

class IFileManager: public IUnknown_
{
	public:
		virtual HRESULT_ __stdcall CreateFile(char *path)=0;
		virtual HRESULT_ __stdcall DeleteFile(char *path)=0;
};
