#include <bits/stdc++.h>

using namespace std;
#ifndef PHONG
#define PHONG


class Phong{

protected:
  string Loai;
  int SoDem;
public:
  string loai();
  Phong();
  Phong(int, string);
  long long DoanhThu();
};

#endif //!PHONG
