#include "kysu.h"

// Nhap vao thong tin cua ky su 
void KySu::Nhap(){
  cout << "Nhap ma nhan vien: ";
  cin >> MaNV;
  cin.ignore();
  cout << "Nhap ten nhan vien: ";
  getline(cin,Ten);
  cout << "Nhap luong co ban: ";
  cin >> LuongCB; 
  cout << "Nhap so gio lam them: ";
  cin >> GioLamThem; 
}

// Xuat ra thong tin cua ky su gom MaNV, Ten, LuongCB va TienThuong tinh duoc
void KySu::Xuat(){
  cout << "Ma nhan vien: " << MaNV << "\n";
  cout << "Ten nhan vien: " << Ten << "\n";
  cout << "Luong co ban: " << LuongCB << "\n";
  cout << "Tien thuong: " << setprecision(2) << TienThuong() << "\n";
}

// Tinh tien thuong cua 1 ky su
long long KySu::TienThuong(){
  return GioLamThem * 100000;
}
