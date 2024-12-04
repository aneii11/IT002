#include "premium.h"

// Phuong thuc thiet lap co tham so cua lop Premium
Premium::Premium(int dem, long long pv): Phong(dem, "Premium"), PhiPhucVu(pv){}

// Phuong thuc tinh doanh thu cua lop Premium
long long Premium::DoanhThu(){
  return SoDem*500000 + PhiPhucVu;
}
