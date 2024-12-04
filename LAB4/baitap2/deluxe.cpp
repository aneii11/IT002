#include "deluxe.h"

// Phuong thuc thiet lap co tham so cua lop Deluxe
Deluxe::Deluxe(int dem, long long dv, long long pv):Phong(dem, "Deluxe"), PhiDichVu(dv), PhiPhucVu(pv){}

// Phuong thuc tinh Doanh thu cua lop Deluxe
long long Deluxe::DoanhThu(){
  return SoDem * 750000 + PhiDichVu + PhiPhucVu;
}
