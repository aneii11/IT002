#include "tamgiac.h"

using namespace std;

/* Nhap vao 3 diem cua tam giac                                                   //
 * Dau vao: Khong*/
void TamGiac::Nhap(){
  float h, t;
  //cout << "[?] Nhap diem A?\n";
  cin >> h >> t;
  A.SetHoanhDo(h), A.SetTungDo(t);
  //cout << "[?] Nhap diem B?\n";
  cin >> h >> t;
  B.SetHoanhDo(h), B.SetTungDo(t);
  ///cout << "[?] Nhap diem C\n";
  cin >> h >> t;
  C.SetHoanhDo(h), C.SetTungDo(t);
}

/* Xuat ra tam giac*/
void TamGiac::Xuat(){
  A.Xuat();
  cout << "\n";
  B.Xuat();
  cout << "\n";
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
