#include "sophuc.h"

/* Phuong thuc thiet lap mac dinh
 * Dau ra: Thiet lap doi tuong SoPhuc voi dThuc = 0, dAo = 0 */
SoPhuc::SoPhuc(): dThuc(0), dAo(0) {}

/* Phuong thuc thiet lap co tham so
 * Dau vao: 
 *  Thuc: Phan thuc cua so phuc 
 *  Ao: Phan ao cua so phuc 
 * Dau ra: Thiet lap doi tuong SoPhuc voi gia tri tu dao vao */
SoPhuc::SoPhuc(double Thuc, double Ao): dThuc(Thuc), dAo(Ao) {}

/* Phuong thuc operator + cho lop SoPhuc
 *  Dau vao: 
 *    SoPhuc a: So phuc thu nhat 
 *    SoPhuc b: So phuc thu hai 
 *  Dau ra: Mot so phuc moi la ket qua cua a + b*/ 
SoPhuc operator +(SoPhuc a, SoPhuc b){
  return SoPhuc(a.dThuc + b.dThuc, a.dAo + b.dAo);
}

/*  Phuong thuc operator - cho lop SoPhuc
 *  Dau vao: 
 *    SoPhuc a: So phuc thu nhat 
 *    SoPhuc b: So phuc thu hai 
 *  Dau ra: Mot so phuc moi la ket qua cua a - b*/
SoPhuc operator -(SoPhuc a, SoPhuc b){
  return SoPhuc(a.dThuc - b.dThuc, a.dAo - b.dAo);
}

/*  Phuong thuc operator * cho lop SoPhuc
 *  Dau vao: 
 *    SoPhuc a: So phuc thu nhat 
 *    SoPhuc b: So phuc thu hai 
 *  Dau ra: Mot so phuc moi la ket qua cua a * b*/
SoPhuc operator *(SoPhuc a, SoPhuc b){
  return SoPhuc(a.dThuc*b.dThuc - a.dAo*b.dAo, a.dThuc*b.dAo + a.dAo*b.dThuc);
}

/*  Phuong thuc operator / cho lop SoPhuc
 *  Dau vao: 
 *    SoPhuc a: So phuc thu nhat 
 *    SoPhuc b: So phuc thu hai 
 *  Dau ra: Mot so phuc moi la ket qua cua a / b*/
optional<SoPhuc> operator /(SoPhuc a, SoPhuc b){
  if (b.dThuc == 0 && b.dAo == 0)
    return {};
  return SoPhuc(
    (a.dThuc * b.dThuc + a.dAo * b.dAo)/(b.dAo * b.dAo + b.dThuc * b.dThuc),
  (a.dAo * b.dThuc - a.dThuc * b.dAo)/(b.dAo * b.dAo + b.dThuc * b.dThuc)
  );
}

/*  Phuong thuc operator == cho lop SoPhuc
 *  Dau vao: 
 *    SoPhuc a: So phuc thu nhat 
 *    SoPhuc b: So phuc thu hai 
 *  Dau ra: true neu a == b, false neu a != b*/
bool operator ==(SoPhuc a, SoPhuc b){
  return a.dThuc == b.dThuc && a.dAo == b.dAo;
}

/*  Phuong thuc operator != cho lop SoPhuc
 *  Dau vao: 
 *    SoPhuc a: So phuc thu nhat 
 *    SoPhuc b: So phuc thu hai 
 *  Dau ra: true neu a != b, false neu a == b*/
bool operator !=(SoPhuc a, SoPhuc b){
  return !(b == a);
}

/*  Phuong thuc operator << cho lop phan so. Xuat ra so thuc a 
 *  Dau vao: 
 *    istream& is: doi tuong thuoc lop istream
 *    SoPhuc sp: So phuc xuat ra 
 *  Dau ra: Tra ve doi tuong is */
istream& operator >>(istream &is, SoPhuc &sp){
  is >> sp.dThuc >> sp.dAo;
  return is;
}

ostream& operator <<(ostream &os, SoPhuc sp){
  os << sp.dThuc << " ";
  if(sp.dAo == 0)
    return os;
  if(sp.dAo < 0)
    os << "- " << abs(sp.dAo) << "i";
  else if(sp.dAo > 0)
    os << "+ " << sp.dAo << "i";
  return os;
}

ostream& operator <<(ostream &os, optional<SoPhuc> sp){
  if(sp==nullopt){
    os << "Khong xac dinh";
    return os;
  }
  os << sp->dThuc << " ";
  if(sp->dAo == 0)
    return os;
  if(sp->dAo < 0)
    os << "- " << abs(sp->dAo) << "i";
  else if(sp->dAo > 0)
    os << "+ " << sp->dAo << "i";
  return os;
}
