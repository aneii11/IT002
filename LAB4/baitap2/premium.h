#include "phong.h"

class Premium: public Phong{
private:
  long long PhiPhucVu;
public:
  Premium(int dem, int pv);
  long long DoanhThu(); 
};

