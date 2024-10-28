#include "diem.cpp"

using namespace std;

int main (int argc, char *argv[]) {
  Diem A;
  Diem B(-5.1,4.5);
  Diem C = B;
  C.Xuat();
  puts("");
  printf("xC: %.2f\n", C.GetHoanhDo());
  printf("yC: %.2f\n", C.GetTungDo());
  puts("");
  B.SetHoanhDo(-1);
  B.SetTungDo(4);
  B.Xuat();
  puts("");
  A.TinhTien(10, 5.87);
  A.Xuat();
  return 0;
}
