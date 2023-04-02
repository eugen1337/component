#pragma once

#include "IUnknown_.h"

class IClassFactory_ : public IUnknown_
{
    public:
        virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** ppv) = 0;
};


