#include <bits/stdc++.h>

using namespace std;

class NgayThangNam{
  int Ngay;
  int Thang;
  int Nam;
  bool HopLe();
public:
  NgayThangNam();
  NgayThangNam(int ngay_, int thang_, int nam_);
  NgayThangNam(const NgayThangNam& a);
  int TinhNgay();
  NgayThangNam operator -(NgayThangNam );
  NgayThangNam operator +(int );
  NgayThangNam operator -(int );
  NgayThangNam operator ++();
  NgayThangNam operator ++(int);
  NgayThangNam operator --();
  NgayThangNam operator --(int);
  bool operator ==(NgayThangNam );
  bool operator !=(NgayThangNam );
  bool operator >=(NgayThangNam );
  bool operator <=(NgayThangNam );
  bool operator <(NgayThangNam );
  bool operator >(NgayThangNam );
  friend istream& operator >>(istream &is, NgayThangNam &a);
  friend ostream& operator <<(ostream &os, NgayThangNam a);
};
