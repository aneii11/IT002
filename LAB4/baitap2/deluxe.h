#include "phong.h"

class Deluxe: public Phong{
private:
  long long PhiDichVu;
  long long PhiPhucVu;
public:
  Deluxe(int dem, long long dv, long long pv);
  long long DoanhThu();
};
