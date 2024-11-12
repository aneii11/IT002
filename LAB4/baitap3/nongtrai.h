#include "giasuc.h"
#include "bo.h"
#include "de.h" 
#include "cuu.h"

#ifndef NONGTRAI
#define NONGTRAI
class NongTrai{
private:
  GiaSuc** gia_suc;
public:
  int SoCuu;
  int SoBo;
  int SoDe;
  int TongSo;
  NongTrai();
  float ThongKeSua();
  void ThemGiaSuc(GiaSuc* them);
  void LuotSinhCon();
  void Doi();
  ~NongTrai();
};
#endif //NONGTRAI
