#include <iostream>

using namespace std;

class ThiSinh{
private: 
  string Ten;
  string MSSV;
  int iNgay;
  int iThang;
  int iNam;
  float fToan;
  float fVan;
  float fAnh;
public:
  void Nhap();
  void Xuat();
  float Tong();
};
