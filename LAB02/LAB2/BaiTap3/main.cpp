#include "dagiac.cpp"

using namespace std;

int main (int argc, char *argv[]) {
  DaGiac A;
  A.Nhap();
  A.Xuat();
  A.TinhTien(45, 2);
  puts("\nDa giac A sau tinh tien: ");
  A.Xuat();
  A.PhongTo(Diem(0,0), 3);
  puts("\nDa giac A sau phong to:");
  A.Xuat();
  A.ThuNho(Diem(0,-1), 2);
  puts("\nDa giac A sau thu nho:");
  A.Xuat();
  A.Quay(Diem(2,2), 45);
  puts("\nDa giac A sau quay: ");
  A.Xuat();
  return 0;
}


