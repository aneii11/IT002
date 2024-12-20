#include "quanly.h"

// Nhap thong tin quan ly
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

// Xuat thong tin quan ly gom MaNV, Ten, LuongCB va Tien thuong tinh duoc
void QuanLy::Xuat(){
  cout << "Ma nhan vien: " << MaNV << "\n";
  cout << "Ten nhan vien: " << Ten << "\n";
  cout << "Luong co ban: " << LuongCB << "\n";
  cout << "Tien thuong: " << setprecision(2) << TienThuong() << "\n";
}

// Tinh tien thuong cua quan ly
long long QuanLy::TienThuong(){
  return LuongCB * TyLeThuong;
}
