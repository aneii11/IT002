#include "diem.h"
#include <math.h>
#include <iostream>

/*
* Dau vao: Khong co 
* Dau ra: Thiet lap doi tuong mac dinh.*/
Diem::Diem(){
  iHoanh = 0;
  iTung = 0;
}

/* Dau vao: Tham so thiet lap
* Dau ra: Doi tuong duoc thiet lap theo tham so*/
Diem::Diem(int Hoanh, int Tung): iHoanh(Hoanh), iTung(Tung){}

/* Phuong thuc thiet lap sao chep.
 * Dau vao: doi tuong thuoc lop Diem 
 * Dau ra: doi tuong duoc sao chep tu dau vao
 * */
Diem::Diem(const Diem &x): iHoanh(x.iHoanh), iTung(x.iTung){}

/* Xuat ra doi tuong diem duoi dang (iHoanh, iTung)*/
void Diem::Xuat(){
  printf("(%.2f, %.2f)\n", iHoanh, iTung);
}

/* Tra ve hoanh do cua doi tuong*/
float Diem::GetHoanhDo(){return iHoanh;}

/* Tra ve tung do cua doi tuong*/
float Diem::GetTungDo(){return iTung;}

/* Gan gia tri iTung cua duoi tuong voi tham so 1*/
void Diem::SetTungDo(float Tung){iTung = Tung;}

/* Gan gia tri iHoanh cua do tuong voi tham so 1.*/
void Diem::SetHoanhDo(float Hoanh){iHoanh = Hoanh;}

void Diem::TinhTien(float Goc, float DoDoi){
  Goc = Goc*3.14/180;
  iHoanh += DoDoi * cos(Goc);
  iTung += DoDoi * sin(Goc);
}
