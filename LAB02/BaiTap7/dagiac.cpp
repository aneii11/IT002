#include "dagiac.h"
#include <algorithm>
using namespace std;

DaGiac::DaGiac(): n(0), Dinh(nullptr) {}

/* Nhap so dinh cua da giac va n diem dinh cua da giac                            //
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

/* Tinh dien tich cua da giac
* Dau vao: Khong
* Dau ra: so thuc float la dien tich cua da giac tra ve qua gia tri tra ve*/ 
float DaGiac::DienTich(){
  this->SapXepDinh();
  float dien_tich = 0;
  for(int i=0;i<n;i++){
    float x_i = Dinh[i].GetHoanhDo();
    float y_i = Dinh[i].GetTungDo();
    float x_next = Dinh[(i+1) %n].GetHoanhDo();
    float y_next = Dinh[(i+1)%n].GetTungDo();
    dien_tich += (x_i * y_next) - (y_i * x_next);
  }
  return fabs(dien_tich)/2;
}

/* Tra ve 1 Diem la trong tam cua da giac*/
Diem DaGiac::TrongTam(){
  float tt_X = 0, tt_Y = 0;
  for(int i=0;i<n;i++){
    tt_X += Dinh[i].GetHoanhDo();
    tt_Y += Dinh[i].GetTungDo();
  }
  return Diem(tt_X/n, tt_Y/n);
}

/* Sap xep cac dinh theo thu tu goc hop boi tia tao boi dinh va trong tam va tia Ox tang dan*/
void DaGiac::SapXepDinh(){
  Diem trong_tam = this->TrongTam();
  sort(Dinh, Dinh+n, [trong_tam](const Diem &a, const Diem &b){
    return SoSanhGoc(a, b, trong_tam);
  });
}



