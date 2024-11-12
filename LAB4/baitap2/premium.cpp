#include "premium.h"

Premium::Premium(int dem, int pv): Phong(dem, "Premium"), PhiPhucVu(pv){}

long long Premium::DoanhThu(){
  return SoDem*500000 + PhiPhucVu;
}
