#include "deluxe.h"

Deluxe::Deluxe(int dem, long long dv, long long pv):Phong(dem, "Deluxe"), PhiDichVu(dv), PhiPhucVu(pv){}

long long Deluxe::DoanhThu(){
  return SoDem * 750000 + PhiDichVu + PhiPhucVu;
}
