#include "quanly.h"

void QuanLy::Nhap(){
  cout << "Nhap ma nhan vien: ";
  cin >> MaNV;
  cin.ignore();
  cout << "Nhap ten nhan vien: ";
  getline(cin,Ten);
  cout << "Nhap luong co ban: ";
  cin >> LuongCB; 
  cout << "Nhap ty le thuong: ";
  cin >> TyLeThuong;
}

void QuanLy::Xuat(){
  cout << "Ma nhan vien: " << MaNV << "\n";
  cout << "Ten nhan vien: " << Ten << "\n";
  cout << "Luong co ban: " << LuongCB << "\n";
  cout << "Tien thuong: " << setprecision(2) << TienThuong() << "\n";
}

long long QuanLy::TienThuong(){
  return LuongCB * TyLeThuong;
}
