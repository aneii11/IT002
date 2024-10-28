#include "diem.cpp"

class TamGiac{
private: 
  Diem A;
  Diem B;
  Diem C;
public:
  void Nhap();
  void Xuat();
  void TinhTien(float Goc, float DoDoi);
  void PhongTo(Diem goc, float ti_le);
  void ThuNho(Diem goc, float ti_le);
  void Quay(Diem goc, float goc_quay);  
};  
