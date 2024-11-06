#include <bits/stdc++.h>
#include <ostream>
#include <valarray>

using namespace std; 

class ThoiGian{
  int Gio;
  int Phut;
  int Giay;
public:
  ThoiGian();
  ThoiGian(int gio_, int phut_, int giay_);
  ThoiGian(int giay);
  int TinhGiay();
  void TinhLaiGio(int );
  ThoiGian operator +(ThoiGian );
  ThoiGian operator -(ThoiGian );
  ThoiGian operator +(int );
  friend ThoiGian operator +(int, ThoiGian);
  ThoiGian operator -(int );
  friend ThoiGian operator -(int, ThoiGian);
  ThoiGian operator ++();
  ThoiGian operator ++(int);
  ThoiGian operator --();
  ThoiGian operator --(int);
  bool operator ==(ThoiGian );
  bool operator !=(ThoiGian );
  bool operator >=(ThoiGian );
  bool operator <=(ThoiGian );
  bool operator <(ThoiGian );
  bool operator >(ThoiGian );
  friend istream& operator >>(istream &is, ThoiGian &a);
  friend ostream& operator <<(ostream &os, ThoiGian a);
};
