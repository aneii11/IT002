#include<bits/stdc++.h>
using namespace std;

class SoPhuc{
private:
  double dThuc;
  double dAo;
public:
  SoPhuc(double Thuc , double Ao = 0);
  SoPhuc();
  friend SoPhuc operator +(SoPhuc a, SoPhuc b );
  friend SoPhuc operator -(SoPhuc a, SoPhuc b);
  friend SoPhuc operator *(SoPhuc a, SoPhuc b);
  friend optional<SoPhuc> operator /(SoPhuc a, SoPhuc b);
  friend bool operator ==(SoPhuc a, SoPhuc b);
  friend bool operator !=(SoPhuc a, SoPhuc b);
  friend istream& operator >>(istream &is, SoPhuc &sp);
  friend ostream& operator <<(ostream &os, SoPhuc sp);
  friend ostream& operator <<(ostream &os, optional<SoPhuc> sp);
};

