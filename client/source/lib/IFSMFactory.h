#pragma once

#include "iunknown_.h"

class IFSMFactory : public IUnknown_
{
    public:
        virtual HRESULT_ __stdcall CreateInstanceWPar(const IID_& iid, void** ppv, int a) = 0;
};
