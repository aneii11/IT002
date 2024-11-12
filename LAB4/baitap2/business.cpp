#include "business.h"

Business::Business(int dem): Phong(dem,"business"){}

long long Business::DoanhThu(){
  return SoDem * 300000;
}

