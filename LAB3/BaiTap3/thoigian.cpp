#include "thoigian.h"

/*  Phuong thuc thiet lap mac dinh
 *  Dau ra: Thiet lap doi tuong ThoiGian voi gia tri 0:0:0*/
ThoiGian::ThoiGian(): Gio(0), Phut(0), Giay(0) {}

/*  Phuong thuc thiet lap co tham so 
 *  Dau vao: 
 *    int gio_: thiet lap thuoc tinh Gio
 *    int phut_: thiet lap thuoc tinh Phut 
 *    int nam_: thiet lap thuoc tinh Nam 
 *  Dau ra: Thiet lap doi tuong thoi gian voi cac gia tri tu dau vao*/
ThoiGian::ThoiGian(int gio_, int phut_, int giay_): Gio(gio_), Phut(phut_), Giay(giay_) {}

/*  Tinh so giay da qua tu doi tuong thoi gian 
 *  Dau ra: Tra ve so nguyen la so giay da qua*/
int ThoiGian::TinhGiay(){
  return Gio*3600+Phut*60+Giay;
}

/*  Cap nhat doi tuong ThoiGian voi gia tri bang so giay da qua
 *  Dau vao:
 *    int giay: So giay da qua 
 *  Dau ra: doi tuong ThoiGian da duoc cap nhat */
void ThoiGian::TinhLaiGio(int giay){
  *this = ThoiGian(giay/3600, (giay%3600)/60, giay%60  );
}

/*  Phuong thuc operator + cho ThoiGian + ThoiGian. Neu ket qua vuot qua 24h, thoi gian duoc cap nhat qua ngay moi. 
 *  Dau vao:
 *    ThoiGian tg: toan tu thu 2
 *  Dau ra: Mot doi tuong ThoiGian moi la ket qua cua phep cong.*/
ThoiGian ThoiGian::operator +(ThoiGian tg){
  ThoiGian C;
  C.TinhLaiGio( (this->TinhGiay() + tg.TinhGiay()) % 86400);
  return C;
}

/*  Phuong thuc operator - cho ThoiGian - ThoiGian. Neu ket qua nho hon 0h, thoi gian duoc cap nhat qua ngay cu. 
 *  Dau vao:
 *    ThoiGian tg: toan tu thu 2
 *  Dau ra: Mot doi tuong ThoiGian moi la ket qua cua phep truu.*/
ThoiGian ThoiGian::operator -(ThoiGian tg){
  ThoiGian C;
  C.TinhLaiGio( (this->TinhGiay() + 86400 - tg.TinhGiay()) % 86400);
  return C;
}

/*  Phuong thuc operator + cho ThoiGian + int. Neu ket qua vuot qua 24h, thoi gian duoc cap nhat qua ngay moi. 
 *  Dau vao:
 *    int giay: So giay cong vao
 *  Dau ra: Mot doi tuong ThoiGian moi la ket qua cua phep cong.*/
ThoiGian ThoiGian::operator +(int giay ){
  ThoiGian C;
  C.TinhLaiGio((this->TinhGiay() + giay ) % 86400);
  return C;
}


ThoiGian operator +(int giay, ThoiGian tg){
  ThoiGian C;
  C.TinhLaiGio( (tg.TinhGiay() + giay) % 86400);
  return C;
}

/*  Phuong thuc operator - cho ThoiGian - int. Neu ket qua nho hon 0h, thoi gian duoc cap nhat qua ngay cu. 
 *  Dau vao:
 *    int giay: So giay cong vao
 *  Dau ra: Mot doi tuong ThoiGian moi la ket qua cua phep cong.*/
ThoiGian ThoiGian::operator -(int giay){
  ThoiGian C;
  C.TinhLaiGio((this->TinhGiay() + 86400 - giay )  % 86400);
  return C;
}

ThoiGian operator -(int giay, ThoiGian tg){
  ThoiGian C;
  C.TinhLaiGio((tg.TinhGiay() - giay + 86400) % 86400);
  return C;
}

ThoiGian ThoiGian::operator ++(){
  *this = *this + 1;
  return *this;
}

ThoiGian ThoiGian::operator ++(int){
  ThoiGian t = *this;
  *this = *this + 1;
  return t;
}

ThoiGian ThoiGian::operator --(){
  *this = *this - 1;
  return *this;
}

ThoiGian ThoiGian::operator --(int){
  ThoiGian t = *this; 
  *this = *this - 1;
  return t;
}

bool ThoiGian::operator ==(ThoiGian tg){
  return this->TinhGiay() == tg.TinhGiay();
}

bool ThoiGian::operator !=(ThoiGian tg){
  return !(*this == tg);
}

bool ThoiGian::operator <=(ThoiGian tg){
  return this->TinhGiay() <= tg.TinhGiay();
}

bool ThoiGian::operator >= (ThoiGian tg){
  return this->TinhGiay() >= tg.TinhGiay();
}

bool ThoiGian::operator > (ThoiGian tg){
  return this->TinhGiay() > tg.TinhGiay();
}

bool ThoiGian::operator < (ThoiGian tg){
  return this->TinhGiay() < tg.TinhGiay();
}

istream& operator >>(istream &is, ThoiGian &a){
  is >> a.Gio >> a.Phut >> a.Giay;
  if(a.Gio < 24 && a.Phut < 60 && a.Giay < 60)
    return is;
  cerr << "Khong hop le\n";
  exit(-1);
}

ostream& operator <<(ostream &os, ThoiGian a){
  os << a.Gio << ":" << a.Phut << ":" << a.Giay; 
  return os;
}

