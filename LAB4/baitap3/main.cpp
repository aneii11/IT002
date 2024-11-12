#include "nongtrai.h"

NongTrai nt;

int main (int argc, char *argv[]) {
  int so_bo = 0, so_cuu = 0, so_de = 0;
  cout << "Nhap so con bo: ";
  cin >> so_bo;
  cout << "Nhap so con cuu: ";
  cin >> so_cuu;
  cout << "Nhap so con de: ";
  cin >> so_de;
  for(int i=0;i<so_bo;i++){
    nt.ThemGiaSuc(new Bo());
    nt.TongSo++;
    nt.SoBo++;
  }
  for (int i=0;i<so_cuu;i++) {
    nt.ThemGiaSuc(new Cuu());
    nt.TongSo++;
    nt.SoCuu++;
  }
  for (int i = 0; i < so_de; i++) {
    nt.ThemGiaSuc(new De());
    nt.TongSo++;
    nt.SoDe++;
  }
  nt.Doi();
  nt.LuotSinhCon();
  cout << "So con bo: " << nt.SoBo << "\n";
  cout << "So con cuu: " << nt.SoCuu << "\n";
  cout << "So con de: " << nt.SoDe << "\n";
  cout << "So luong sua: " << nt.ThongKeSua() << "\n";
  return 0;
}
