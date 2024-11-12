#include <bits/stdc++.h>

using namespace std;

#ifndef GIASUC
#define GIASUC 
class NongTrai;

class GiaSuc{
public:
  enum Loai{BO = 0, 
            CUU = 1,
            DE = 2};
  Loai pl;
  GiaSuc() = default;
  GiaSuc(Loai);
  void Keu();
  float ChoSua();
  void SinhCon(NongTrai n);
};
#endif //!GIASUC
