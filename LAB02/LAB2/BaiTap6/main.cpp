#include "tamgiac.cpp"                                    //

int main (int argc, char *argv[]) {
  TamGiac A;
  A.Nhap();
  //A.Xuat();
  float goc, do_doi;
  cin >> goc >> do_doi;
  A.TinhTien(goc, do_doi);
  //puts("\nTam giac A sau tinh tien: ");
  A.Xuat();
  
  return 0;
}
