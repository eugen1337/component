#pragma once

#include "IClassFactory.h"
#include "IFSMFactory.h"

#include "./lib/interfaces.h"

class FSMFactory : public IClassFactory_, public IFSMFactory
{
    private:
        int fRefCount;


    public:
        FSMFactory();
        ~FSMFactory();

        virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv);
        virtual HRESULT_ __stdcall AddRef();
        virtual HRESULT_ __stdcall Release();

        virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** ppv);
        virtual HRESULT_ __stdcall CreateInstanceWPar(const IID_& iid, void** ppv, int a);

        IMatrix *IM;
        IMatrixA *IMA;

};

extern "C" HRESULT_ __stdcall __declspec(dllexport) GetClassObject(const CLSID_& clsid, const IID_& iid, void** ppv);
