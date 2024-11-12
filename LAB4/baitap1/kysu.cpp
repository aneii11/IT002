#include "kysu.h"

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

void KySu::Xuat(){
  cout << "Ma nhan vien: " << MaNV << "\n";
  cout << "Ten nhan vien: " << Ten << "\n";
  cout << "Luong co ban: " << LuongCB << "\n";
  cout << "Tien thuong: " << setprecision(2) << TienThuong() << "\n";
}

long long KySu::TienThuong(){
  return GioLamThem * 100000;
}
