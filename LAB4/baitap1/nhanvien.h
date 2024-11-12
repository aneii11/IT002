#include <bits/stdc++.h>
using namespace std;

#ifndef NHANVIEN
#define NHANVIEN

class NhanVien{
protected:
  string MaNV;
  string Ten;
  long long LuongCB;
public:
  void Nhap();
  void Xuat();
  long long TienThuong();
};

#endif //!NHANVIEN

