#include "business.h"
#include "premium.h"
#include "deluxe.h"

int main (int argc, char *argv[]) {
  Phong *danh_sach[5] = {};
  danh_sach[0] = new Deluxe (5, 3000000, 2000000);
  danh_sach[1] = new Deluxe (21, 3100000, 2500000);
  danh_sach[2] = new Business (18);
  danh_sach[3] = new Business (13);
  danh_sach[4] = new Premium (17, 4320000);
  long long dt_deluxe = 0;
  long long dt_premium = 0;
  long long dt_business = 0;
  for(int i=0;i<5;i++){
    if(danh_sach[i]->loai() == "Deluxe"){
      dt_deluxe += static_cast<Deluxe*>(danh_sach[i])->DoanhThu();
    }
    else if(danh_sach[i]->loai() == "Premium"){
      dt_premium += static_cast<Premium*>(danh_sach[i])->DoanhThu();
    }
    else if(danh_sach[i]->loai() == "Business"){
      dt_business += static_cast<Business*>(danh_sach[i])->DoanhThu();
    }
  }
  if(dt_premium > dt_deluxe && dt_premium > dt_business){
    cout << "Phong premium co doanh thu cao nhat: " << dt_premium;
  }
  else if(dt_business > dt_deluxe && dt_business > dt_premium){
    cout << "Phong business co doanh thu cao nhat: " << dt_business;
  }
  else{
    cout << "Phong deluxe co doanh thu cao nhat: " << dt_deluxe;
  }
  cout << "\n";
  return 0;
}
