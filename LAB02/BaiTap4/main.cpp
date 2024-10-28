#include "thisinh.cpp"
#include <vector> 

int main (int argc, char *argv[]) {
  vector<ThiSinh> ds;
  int n;
  cout << "Nhap so thi sinh: ";
  cin >> n;
  ds.resize(n);
  for(int i=0;i<n;i++){
    ds[i].Nhap();
  }
  puts("\nDanh sach cac sinh vien co diem lon hon 15: ");
  for(int i=0;i<n;i++){
    if( ds[i].Tong() > 15){
      ds[i].Xuat();
    }
  }
  float diem_lon_nhat = -1;
  int chi_so_lon_nhat;
  puts("\nSinh vien co diem cao nhat");
  for(int i=0;i<n;i++){
   if(ds[i].Tong() > diem_lon_nhat){
      chi_so_lon_nhat = i;
      diem_lon_nhat = ds[i].Tong();
    }
  }
  ds[chi_so_lon_nhat].Xuat();
  return 0;
} 
