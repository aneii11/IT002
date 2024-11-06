#include "thoigian.h"

ThoiGian::ThoiGian(): Gio(0), Phut(0), Giay(0) {}

ThoiGian::ThoiGian(int gio_, int phut_, int giay_): Gio(gio_), Phut(phut_), Giay(giay_) {}

int ThoiGian::TinhGiay(){
  return Gio*3600+Phut*60+Giay;
}

void ThoiGian::TinhLaiGio(int giay){
  *this = ThoiGian(giay/3600, (giay%3600)/60, giay%60  );
}

ThoiGian ThoiGian::operator +(ThoiGian tg){
  ThoiGian C;
  C.TinhLaiGio( (this->TinhGiay() + tg.TinhGiay()) % 86400);
  return C;
}


ThoiGian ThoiGian::operator -(ThoiGian tg){
  ThoiGian C;
  C.TinhLaiGio( (this->TinhGiay() + 86400 - tg.TinhGiay()) % 86400);
  return C;
}

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
  return is;
}

ostream& operator <<(ostream &os, ThoiGian a){
  os << a.Gio << ":" << a.Phut << ":" << a.Giay; 
  return os;
}

