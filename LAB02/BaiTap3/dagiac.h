#include "diem.cpp"

class DaGiac{
private: 
  int n;
  Diem *Dinh; 
public:
  DaGiac();
  void Nhap();
  void Xuat();
  void TinhTien(float goc, float do_doi);
  void PhongTo(Diem goc, float ti_le);
  void ThuNho(Diem goc, float ti_le);
  void Quay(Diem goc, float goc_quay);
};
