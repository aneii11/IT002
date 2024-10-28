#include "tamgiac.h"

using namespace std;

/* Nhap vao 3 diem cua tam giac 
 * Dau vao: Khong*/
void TamGiac::Nhap(){
  float h, t;
  cout << "[?] Nhap diem A?\n";
  cin >> h >> t;
  A.SetHoanhDo(h), A.SetTungDo(t);
  cout << "[?] Nhap diem B?\n";
  cin >> h >> t;
  B.SetHoanhDo(h), B.SetTungDo(t);
  cout << "[?] Nhap diem C\n";
  cin >> h >> t;
  C.SetHoanhDo(h), C.SetTungDo(t);
}

/* Xuat ra tam giac*/
void TamGiac::Xuat(){
  A.Xuat();
  cout << "; ";
  B.Xuat();
  cout << "; ";
  C.Xuat();
}

/* Tinh tien tam giac
 * Dau vao: 
 * Tham so 1: goc tinh tien
 * Tham so 2: do doi
 * Dau ra: Khong*/
void TamGiac::TinhTien(float Goc, float DoDoi){
  A.TinhTien(Goc, DoDoi);
  B.TinhTien(Goc, DoDoi);
  C.TinhTien(Goc, DoDoi);
}

/* Phong to tam giac
 * Dau vao: 
 * Tham so 1: Diem goc
 * Tham so 2: Ti le phong to
 * Dau ra: Khong*/
void TamGiac::PhongTo(Diem goc, float ti_le){
  A.PhongTo(goc, ti_le);
  B.PhongTo(goc, ti_le);
  C.PhongTo(goc, ti_le);
}

/* Thu nho tam giac 
 * Dau vao:
 * Tham so 1: Diem goc
 * Tham so 2: Ti le thu nho
 * Dau ra: Khong*/
void TamGiac::ThuNho(Diem goc, float ti_le){
  A.ThuNho(goc, ti_le);
  B.ThuNho(goc, ti_le);
  C.ThuNho(goc, ti_le);
}

/* Quay tam giac
 * Dau vao:
 * Tham so 1: Diem goc
 * Tham so 2: Goc quay*/
void TamGiac::Quay(Diem goc, float goc_quay){
  A.Quay(goc, goc_quay);
  B.Quay(goc, goc_quay);
  C.Quay(goc, goc_quay);
}
