#include "dagiac.h"
using namespace std;

DaGiac::DaGiac(): n(0), Dinh(nullptr) {}

/* Nhap so dinh cua da giac va n diem dinh cua da giac
*/
void DaGiac::Nhap(){
  do{
    printf("Nhap so dinh cua da giac: ");
    cin >> n;
  }while(n <= 2);
  if (Dinh != nullptr)
    delete[] Dinh;
  Dinh = new Diem[n];
  for(int i=0;i<n;i++){
    float h, t;
    cin >> h >> t;
    Dinh[i].SetHoanhDo(h);
    Dinh[i].SetTungDo(t);
  }
}

/* Xuat ra n dinh cua da giac */
void DaGiac::Xuat(){
  printf("Cac dinh cua da giac:\n");
  for(int i=0;i<n;i++){
    Dinh[i].Xuat();
  }
}

/* Tinh tien da giac
 * Dau vao: 
 * Tham so 1: goc tinh tien
 * Tham so 2: do doi
 * Dau ra: Khong*/
void DaGiac::TinhTien(float goc, float do_doi){
  for(int i=0;i<n;i++){
    Dinh[i].TinhTien(goc, do_doi);
  }
}

/* Phong to da giac
 * Dau vao: 
 * Tham so 1: diem goc
 * Tham so 2: ti le phong to
 * Dau ra: Khong*/
void DaGiac::PhongTo(Diem goc, float ti_le){
  for(int i=0;i<n;i++){
    Dinh[i].PhongTo(goc, ti_le);
  }
}

/* Thu nho da giac
 * Dau vao: 
 * Tham so 1: diem goc
 * Tham so 2: ti le thu nho
 * Dau ra: Khong*/
void DaGiac::ThuNho(Diem goc, float ti_le){
  for(int i=0;i<n;i++){
    Dinh[i].ThuNho(goc, ti_le);
  }
}

/* Quay da giac
 * Dau vao: 
 * Tham so 1: diem goc
 * Tham so 2: ti le phong to
 * Dau ra: Khong*/
void DaGiac::Quay(Diem goc, float goc_quay){
  for(int i=0;i<n;i++){
    Dinh[i].Quay(goc, goc_quay);
  }
}
