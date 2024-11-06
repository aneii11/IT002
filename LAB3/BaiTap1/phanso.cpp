#include "phanso.h"
#include <math.h>
/* Phuong thuc thiet lap mac dinh
 * Dau ra: Thiet lap doi tuong thuoc lop PhanSo voi gia tri 0/1*/
PhanSo::PhanSo(): iTu(0), iMau(1) {}

/* Phuong thuc thiet lap co tham so 
 * long long Tu: Tu so
 * long long Mau: Mau so 
 * Dau ra: Thiet lap doi tuong thuoc lop PhanSo voi gia tri t dau vao */
PhanSo::PhanSo(long long Tu, long long Mau): iTu(Tu), iMau(Mau) {}

/* Phuong thuc thiet lap phan so tu so thuc
 * double thap_phan: so thuc se chuyen ve phan so
 * Dau ra: Thiet lap doi tuong thuoc lop PhanSo co gia tri bang voi tham so dau vao*/
PhanSo::PhanSo(double thap_phan){
  long long tu = round(thap_phan * 1e9 );
  long long mau = 1e9;
  iTu = tu;
  iMau = mau;
  RutGon();
}

/* Rut gon phan so 
 * Dau ra: Doi tuong thuoc lop phan so da duoc rut gon*/
void PhanSo::RutGon(){
  long long gcd = __gcd(iTu, iMau);
  iTu/=gcd;
  iMau/=gcd;
}

/* Phuong thuc operator + cho lop phan so.
 * Dau vao:
 *  PhanSo a: Phan so thu nhat
 *  PhanSo b: Phan so thu hai
 * Dau ra: Mot doi tuong PhanSo moi la ket qua cua phep a + b, da toi gian*/
PhanSo operator +(PhanSo a, PhanSo b ){
  PhanSo kq(a.iTu * b.iMau + b.iTu * a.iMau, a.iMau * b.iMau);
  kq.RutGon();
  return kq;
}

/* Phuong thuc operator - cho lop phan so.
 * Dau vao:
 *  PhanSo a: Phan so thu nhat
 *  PhanSo b: Phan so thu hai
 * Dau ra: Mot doi tuong PhanSo moi la ket qua cua phep a - b, da toi gian*/
PhanSo operator -(PhanSo a, PhanSo b ){
  PhanSo kq(a.iTu * b.iMau - b.iTu * a.iMau, b.iMau * a.iMau);
  kq.RutGon();
  return kq;
}

/* Phuong thuc operator * cho lop phan so.
 * Dau vao:
 *  PhanSo a: Phan so thu nhat
 *  PhanSo b: Phan so thu hai
 * Dau ra: Mot doi tuong PhanSo moi la ket qua cua phep a * b, da toi gian*/
PhanSo operator *(PhanSo a, PhanSo b ){
  PhanSo kq(b.iTu * a.iTu, b.iMau * a.iMau);
  kq.RutGon();
  return kq;
}

/* Phuong thuc operator / cho lop phan so.
 * Dau vao:
 *  PhanSo a: Phan so thu nhat
 *  PhanSo b: Phan so thu hai
 * Dau ra: Mot doi tuong std::optional<PhanSo>{} neu tu so la 0, doi tuong PhanSo moi la ket qua cua phep a / b, da toi gian*/
optional <PhanSo>operator /(PhanSo a, PhanSo b ){
  if(b.iTu == 0 || (float)b.iTu/b.iMau==0 ){
    return {};
  }
  else{
    PhanSo kq(a.iTu * b.iMau, a.iMau * b.iTu);
    kq.RutGon();
    return kq;
  }
}

/* Phuong thuc operator == cho lop phan so.
 * Dau vao:
 *  PhanSo a: Phan so thu nhat
 *  PhanSo b: Phan so thu hai
 * Dau ra: true neu a == b, false neu a!=b*/
bool operator ==(PhanSo a, PhanSo b ){
  return (float)a.iTu/a.iMau == (float)b.iTu/b.iMau;
}

/* Phuong thuc operator != cho lop phan so.
 * Dau vao:
 *  PhanSo a: Phan so thu nhat
 *  PhanSo b: Phan so thu hai
 * Dau ra: true neu a != b, false neu a==b*/
bool operator !=(PhanSo a, PhanSo b ){
  return (float)b.iTu/b.iMau != (float)a.iTu/a.iMau;
}

/* Phuong thuc operator >= cho lop phan so.
 * Dau vao:
 *  PhanSo a: Phan so thu nhat
 *  PhanSo b: Phan so thu hai
 * Dau ra: true neu a >= b, false neu nguoc lai*/
bool operator >=(PhanSo a, PhanSo b ){
  return (float)a.iTu/a.iMau >= (float)b.iTu/b.iMau;
}

/* Phuong thuc operator <= cho lop phan so.
 * Dau vao:
 *  PhanSo a: Phan so thu nhat
 *  PhanSo b: Phan so thu hai
 * Dau ra: true neu a <= b, false neu nguoc lai*/
bool operator <=(PhanSo a, PhanSo b){
  return (float)a.iTu/a.iMau <= (float)b.iTu/b.iMau;
}

/* Phuong thuc operator < cho lop phan so.
 * Dau vao:
 *  PhanSo a: Phan so thu nhat
 *  PhanSo b: Phan so thu hai
 * Dau ra: true neu a < b, false neu nguoc lai*/
bool operator <(PhanSo a, PhanSo b ){
  return (float)a.iTu/a.iMau < (float)b.iTu/b.iMau;
}

/* Phuong thuc operator > cho lop phan so.
 * Dau vao:
 *  PhanSo a: Phan so thu nhat
 *  PhanSo b: Phan so thu hai
 * Dau ra: true neu a > b, false neu nguoc lai*/
bool operator >(PhanSo a, PhanSo b ){
  return (float)a.iTu/a.iMau > (float)b.iTu/b.iMau;
}

/* Phuong thuc operator >> cho lop phan so. Nhap vao phan so 
 * Dau vao:
 *  istream &is: doi tuong thuoc lop istream
 *  PhanSo &a: Phan so nhap vao
 * Dau ra: Tra ve doi tuong istream.*/
istream& operator >>(istream &is, PhanSo &a){
  is >> a.iTu >> a.iMau ;
  assert(a.iMau != 0);
  return is;
} 

/* Phuong thuc operator << cho lop phan so. Xuat ra phan so a
 * Dau vao:
 *  ostream &os: doi tuong thuoc lop ostream
 *  PhanSo a: Phan so xuat ra
 * Dau ra: Tra ve doi tuong ostream.*/
ostream& operator <<(ostream &os, PhanSo a){
  if((float)a.iTu/a.iMau < 0){
    os << "-" << abs(a.iTu) << "/" << abs(a.iMau);
    return os;
  }
  if((float)a.iTu/a.iMau >= 0){
    os << abs(a.iTu) << "/" << abs(a.iMau);
    return os;
  }
  return os;
}

/* Phuong thuc operator >> cho lop phan so. Xuat ra "Khong xac dinh" neu a rong, xuat ra phan so neu a khac rong.
 * Dau vao:
 *  ostream &os: doi tuong thuoc lop ostream
 *  optional<PhanSo> a: doi tuong thuoc std::optional<PhanSo>
 * Dau ra: Tra ve doi tuong ostream.*/
ostream& operator <<(ostream &os, optional<PhanSo> a){
  if (a){
    if((float)a->iTu/a->iMau < 0){
      os << "-" << abs(a->iTu) << "/" << abs(a->iMau);
      return os;
    }
    if((float)a->iTu/a->iMau >= 0){
      os << abs(a->iTu) << "/" << abs(a->iMau);
      return os;
    }
    return os;
  }
  os << "Khong xac dinh";
  return os;
}

