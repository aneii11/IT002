#include "ngaythangnam.h"

const int ngay[2][13] = {{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};


NgayThangNam::NgayThangNam(): Ngay(1), Thang(1), Nam(1) {}

NgayThangNam::NgayThangNam(int ngay_, int thang_, int nam_): Ngay(ngay_), Thang(thang_), Nam(nam_) {}

NgayThangNam::NgayThangNam(const NgayThangNam &a): Ngay(a.Ngay), Thang(a.Thang), Nam(a.Nam) {}

int NgayThangNam::TinhNgay(){
  return accumulate(ngay[Nam%4], ngay[Nam%4] + Thang + 1, 0);
}

NgayThangNam NgayThangNam::operator -(NgayThangNam a){
  NgayThangNam KQ = *this;
  KQ.Nam-=a.Nam;
  KQ.Thang -= a.Thang;
  KQ.Ngay -= a.Ngay;
  while(KQ.Ngay < 1){
    KQ.Thang--;
    if(KQ.Thang < 1){
      KQ.Nam = KQ.Nam + (-12 + KQ.Thang)/12;
      KQ.Thang = 12 + (KQ.Thang % 12);
    }
    KQ.Ngay += ngay[KQ.Nam%4!=0][KQ.Thang];
  }
  return KQ;
}

NgayThangNam NgayThangNam::operator +(int so_ngay){
  NgayThangNam KQ = *this;
  KQ.Ngay += so_ngay;
  while(KQ.Ngay >= 365){
    KQ.Ngay -= 365;
    if(KQ.Nam % 4==0)
      KQ.Ngay--;
    KQ.Nam++;
  }
  while(KQ.Ngay > ngay[KQ.Nam % 4 != 0][KQ.Thang]){
    KQ.Ngay -= ngay[KQ.Nam%4 != 0][KQ.Thang];
    KQ.Thang++;
    if(KQ.Thang == 13){
      KQ.Thang = 1;
      KQ.Nam++;
    }
  }
  return KQ;
}

NgayThangNam NgayThangNam::operator -(int so_ngay){
  NgayThangNam KQ = *this;
  KQ.Ngay -= so_ngay;
  while(KQ.Ngay <= -365){
    KQ.Ngay += 365;
    if(KQ.Nam%4==0)
      KQ.Ngay++;
    KQ.Nam--;
  }
  while(KQ.Ngay < 1){
    KQ.Thang--;
    if(KQ.Thang == 0){
      KQ.Thang = 12;
      KQ.Nam --;
    }
    KQ.Ngay += ngay[KQ.Nam%4!=0][KQ.Thang];
  }
  return KQ;
}

NgayThangNam NgayThangNam::operator ++(){
  *this = *this + 1;
  return *this;
}

NgayThangNam NgayThangNam::operator ++(int){
  NgayThangNam t = *this;
  *this = *this + 1;
  return t;
}

NgayThangNam NgayThangNam::operator --(){
  *this = *this - 1;
  return *this;
}

NgayThangNam NgayThangNam::operator --(int){
  NgayThangNam t = *this;
  *this = *this + 1;
  return t;
}

bool NgayThangNam::operator ==(NgayThangNam a){
  return Nam == a.Nam && TinhNgay() == a.TinhNgay();
}

bool NgayThangNam::operator !=(NgayThangNam a){
  return !(*this == a);
}

bool NgayThangNam::operator >=(NgayThangNam a){
  if(Nam > a.Nam)
    return true;
  return TinhNgay() >= a.TinhNgay();
}

bool NgayThangNam::operator <=(NgayThangNam a){
  if(Nam < a.Nam)
    return true;
  return TinhNgay() <= a.TinhNgay();
}

bool NgayThangNam::operator >(NgayThangNam a){
  return !(*this <= a);
}

bool NgayThangNam::operator <(NgayThangNam a){
  return !(*this >= a);
}

istream& operator >>(istream &is, NgayThangNam &a){
  is >> a.Ngay >> a.Thang >> a.Nam;
  return is;
}

ostream& operator <<(ostream &os, NgayThangNam a){
  os << a.Ngay << "/" << a.Thang << "/";
  if(a.Nam < 1)
    cout << abs(a.Nam-1) << " TCN";
  else cout << a.Nam;
  return os;
}
