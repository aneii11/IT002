#include "business.h"

// Phuong thuc thiet lap co tham so cua lop business
Business::Business(int dem): Phong(dem,"business"){}

// Phuong thuc tinh doanh thu cua lop business
long long Business::DoanhThu(){
  return SoDem * 300000;
}

