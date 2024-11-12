#include "quanly.cpp"
#include "kysu.cpp"

int main (int argc, char *argv[]) {
  QuanLy ql1;
  KySu ks1;
  ql1.Nhap();
  cout << "\n";
  ks1.Nhap();
  cout << "\n";
  cout << "Tien thuong cua quan ly: " << ql1.TienThuong() << "\n";
  cout << "Tien thuong cua ky su: " << ks1.TienThuong() << "\n";
  cout << "\n";
  ql1.Xuat();
  cout << "\n";
  ks1.Xuat();

  return 0;
}
