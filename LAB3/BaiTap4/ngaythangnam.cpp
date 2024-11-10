#include "ngaythangnam.h"

const int ngay[2][13] = {{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/*  Phuong thuc thiet lap mac dinh 
 *  Dau ra: Thiet lap 1 doi tuong NgayThangNam voi gia tri 1/1/1*/
NgayThangNam::NgayThangNam(): Ngay(1), Thang(1), Nam(1) {}

/*  Phuong thuc thiet lap co tham so 
 *  Dau vao: 
 *    int ngay_: gia tri Ngay duoc thiet lap 
 *    int thang_: gia tri Thang duoc thiet lap 
 *    int nam_: gia tri Nam duoc thiet lap 
 *  Dau ra: Thiet lap 1 doi tuong NgayThangNam voi gia tri tu tham so dau vao*/
NgayThangNam::NgayThangNam(int ngay_, int thang_, int nam_): Ngay(ngay_), Thang(thang_), Nam(nam_) {}

/*  Phuong thuc thiet lap sao chep
 *  Dau vao: 
 *    const NgayThangNam& a: Doi tuong sao chep 
 *  Dau ra: Thiet lap 1 doi tuong NgayThangNam*/
NgayThangNam::NgayThangNam(const NgayThangNam &a): Ngay(a.Ngay), Thang(a.Thang), Nam(a.Nam) {}

/*  Kiem tra tinh hop le cua NgayThangNam 
 *  Dau ra: True neu doi tuong hop le, false neu khong hop le*/
bool NgayThangNam::HopLe(){
  if(Ngay > ngay[Nam%4 != 0][Thang] || Thang > 12 || Thang < 0)
    return false;
  return true;
}

/*  Tinh toan so ngay da qua trong nam 
 *  Dau ra: Tra ve so nguyen la so ngay da qua cua nam*/
int NgayThangNam::TinhNgay(){
  return accumulate(ngay[Nam%4], ngay[Nam%4] + Thang + 1, 0);
}

/*  Phuong thuc operator -(NgayThangNam a). 
 *  Dau vao: 
 *    NgayThangNam a: Toan tu thu 2 
 *  Dau ra: Tra ve 1 doi tuong NgayThangNam la ket qua cua phep -*/
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
  if(KQ.Thang < 1){
    KQ.Nam = KQ.Nam + (-12 + KQ.Thang)/12;
    KQ.Thang = 12 + (KQ.Thang % 12);
  }
  return KQ;
}

/*  Phuong thuc operator +(int so_ngay). 
 *  Dau vao: 
 *    int so_ngay: Toan tu thu 2 la so ngay cong them 
 *  Dau ra: Tra ve 1 doi tuong NgayThangNam la ket qua cua phep +*/
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

/*  Phuong thuc operator -(int so_ngay). 
 *  Dau vao: 
 *    int so_ngay: Toan tu thu 2 la so ngay tru di 
 *  Dau ra: Tra ve 1 doi tuong NgayThangNam la ket qua cua phep -*/
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

/*  Phuong thuc operator ++()
 *  Dau ra: Tang doi tuong len 1 don vi ngay va tra ve doi tuong moi da tang*/
NgayThangNam NgayThangNam::operator ++(){
  *this = *this + 1;
  return *this;
}

/*  Phuong thuc operator ++(int)
 *  Dau ra: Tang doi tuong len 1 don vi ngay va tra ve doi tuong ban dau*/
NgayThangNam NgayThangNam::operator ++(int){
  NgayThangNam t = *this;
  *this = *this + 1;
  return t;
}

/*  Phuong thuc operator --()
 *  Dau ra: Giam doi tuong len 1 don vi ngay va tra ve doi tuong moi da giam*/
NgayThangNam NgayThangNam::operator --(){
  *this = *this - 1;
  return *this;
}

/*  Phuong thuc operator --()
 *  Dau ra: Giam doi tuong len 1 don vi ngay va tra ve doi tuong ban dau*/
NgayThangNam NgayThangNam::operator --(int){
  NgayThangNam t = *this;
  *this = *this + 1;
  return t;
}

/*  Phuong thuc operator == 
 *  Dau vao: 
 *    NgayThangNam a: Toan tu thu 2 
 *  Dau ra: true neu *this == a, false neu nguoc lai*/
bool NgayThangNam::operator ==(NgayThangNam a){
  return Nam == a.Nam && TinhNgay() == a.TinhNgay();
}

/*  Phuong thuc operator != 
 *  Dau vao: 
 *    NgayThangNam a: Toan tu thu 2 
 *  Dau ra: true neu *this != a, false neu nguoc lai*/
bool NgayThangNam::operator !=(NgayThangNam a){
  return !(*this == a);
}

/*  Phuong thuc operator >= 
 *  Dau vao: 
 *    NgayThangNam a: Toan tu thu 2 
 *  Dau ra: true neu *this >= a, false neu nguoc lai*/
bool NgayThangNam::operator >=(NgayThangNam a){
  if(Nam > a.Nam)
    return true;
  return TinhNgay() >= a.TinhNgay();
}

/*  Phuong thuc operator <= 
 *  Dau vao: 
 *    NgayThangNam a: Toan tu thu 2 
 *  Dau ra: true neu *this <= a, false neu nguoc lai*/
bool NgayThangNam::operator <=(NgayThangNam a){
  if(Nam < a.Nam)
    return true;
  return TinhNgay() <= a.TinhNgay();
}

/*  Phuong thuc operator > 
 *  Dau vao: 
 *    NgayThangNam a: Toan tu thu 2 
 *  Dau ra: true neu *this > a, false neu nguoc lai*/
bool NgayThangNam::operator >(NgayThangNam a){
  return !(*this <= a);
}

/*  Phuong thuc operator < 
 *  Dau vao: 
 *    NgayThangNam a: Toan tu thu 2 
 *  Dau ra: true neu *this < a, false neu nguoc lai*/
bool NgayThangNam::operator <(NgayThangNam a){
  return !(*this >= a);
}

/*  Phuong thuc operator >>. Nhap vao 1 doi tuong NgayThangNam
 *  Dau vao: 
 *    istream& is: Doi tuong istream 
 *    NgayThangNam &a: Doi tuong NgayThangNam can nhap
 *  Dau ra: tra ve doi tuong istream*/
istream& operator >>(istream &is, NgayThangNam &a){
  is >> a.Ngay >> a.Thang >> a.Nam;
  if(a.HopLe())
    return is;
  cerr << "Khong hop le\n";
  exit(-1);
}

/*  Phuong thuc operator <<. Xuat ra 1 doi tuong NgayThangNam
 *  Dau vao:
 *    ostream& os: doi tuong ostream 
 *    NgayThangNam a: Doi tuong NgayThangNam can xuat 
 *  Dau ra: Tra ve doi tuong ostream*/
ostream& operator <<(ostream &os, NgayThangNam a){
  os << a.Ngay << "/" << a.Thang << "/";
  if(a.Nam < 1)
    cout << abs(a.Nam-1) << " TCN";
  else cout << a.Nam;
  return os;
}
