#include <bits/stdc++.h>

using namespace std;

class PhanSo{
  long long iTu;
  long long iMau;
  void RutGon();
public:
  PhanSo();
  PhanSo(long long Tu, long long Mau);
  PhanSo(double thap_phan);
  friend PhanSo operator +(PhanSo a, PhanSo b);
  friend PhanSo operator -(PhanSo a, PhanSo b);
  friend PhanSo operator *(PhanSo a, PhanSo b);
  friend optional<PhanSo> operator /(PhanSo a, PhanSo b );
  friend bool operator ==(PhanSo a, PhanSo b);
  friend bool operator !=(PhanSo a, PhanSo b);
  friend bool operator >=(PhanSo a, PhanSo b);
  friend bool operator <=(PhanSo a, PhanSo b);
  friend bool operator <(PhanSo a, PhanSo b);
  friend bool operator >(PhanSo a, PhanSo b);
  friend istream& operator >>(istream &is, PhanSo &a);
  friend ostream& operator <<(ostream &os, PhanSo a);
  friend ostream& operator <<(ostream &os, optional<PhanSo> a);
};
