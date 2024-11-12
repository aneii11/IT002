#include "nhanvien.h"

class KySu:public NhanVien{
private:
  float GioLamThem;
public:
  void Nhap();
  void Xuat();
  long long TienThuong();
};
