#ifndef interfaces_h
#define interfaces_h

const int IID_IMatrix = 1;
const int IID_IMatrixA = 2;
const int IID_IFactory = 100;
const int IID_IFactoryA = 101;

const int E_OUTOFMEMORY_ = 3;
const int E_DET0_ = 4;

const int CLSID_MATRIX = 1;
const int CLSID_Factory = 1;
const int CLSID_MATRIXA = 2;
const int CLSID_FactoryA = 2;

class IMatrix: public IUnknown_ {
        public:
                virtual HRESULT_ __stdcall AddMatrixNum(double *a, double b, double *c, int n, int m) = 0;
                virtual HRESULT_ __stdcall SubMatrixNum(double *a, double b, double *c, int n, int m) = 0;
                virtual HRESULT_ __stdcall MultMatrixNum(double *a, double b, double *c, int n, int m) = 0;
                virtual HRESULT_ __stdcall DivMatrixNum(double *a, double b, double *c, int n, int m) = 0;
                virtual HRESULT_ __stdcall DetMatrix(double *a, double *det, int n) = 0;
};

class IMatrixA: public IUnknown_ {
        public:
                virtual HRESULT_ __stdcall AddMatrix(double *a, double *b, double *c, int n, int m) = 0;
                virtual HRESULT_ __stdcall MultMatrix(double *a, double *b, double *c, int n, int m, int p) = 0;
                virtual HRESULT_ __stdcall TransMatrix(double *a, double *b, int n) = 0;
                virtual HRESULT_ __stdcall InverseMatrix(double *a, double *b, int n) = 0;
};

class IFactory: public IUnknown_ {
        public:
                virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** ppv) = 0;
};

class IFactoryA: public IUnknown_ {
        public:
                virtual HRESULT_ __stdcall CreateInstanceA(const IID_& iid, void** ppv) = 0;
};

HRESULT_ __stdcall GetClassObject(const CLSID_& clsid, const IID_& iid, void** ppv);
HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv);

#endif