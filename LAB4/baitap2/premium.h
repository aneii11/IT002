#include "phong.h"

class Premium: public Phong{
private:
  long long PhiPhucVu;
public:
  Premium(int dem, long long pv);
  long long DoanhThu(); 
};

