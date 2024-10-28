#include <bits/stdc++.h>

using namespace std;

struct PhanSo {
  int Tu;
  int Mau;
};

vector<PhanSo> ps;

void Xuat(PhanSo ps){
  /* Xuat ra thiet bi xuat chuan phan so truyen vao tu dau vao                //
    * Dau vao: 
    * Tham so 1: Phan so 
    * Dau ra: Khong co */ 
  if((float)ps.Tu/ps.Mau < 0){
    printf("-%d/%d", abs(ps.Tu), abs(ps.Mau));
    return;
  }
  if((float)ps.Tu/ps.Mau >= 0){
    printf("%d/%d", abs(ps.Tu), abs(ps.Mau));
    return;
  }
}

/*
 * Tim phan so lon nhat, nho nhat trong mang ps 
 * Dau vao: Khong 
 * Dau ra: Phan so lon nhat, nho nhat tra ve qua gia tri tra ve*/
void PSLonNhatNhoNhat(PhanSo &lon_nhat, PhanSo &nho_nhat){
  nho_nhat = ps[0];
  lon_nhat = ps[0];
  int n = ps.size();
  for(int i=1; i<n;i++){
    if((float)nho_nhat.Tu/nho_nhat.Mau > (float)ps[i].Tu/ps[i].Mau)
      nho_nhat = ps[i];
    if((float)lon_nhat.Tu/lon_nhat.Mau < (float)ps[i].Tu/ps[i].Mau)
      lon_nhat = ps[i];
  }
}

int main(){                                                                    //
  int n;
  cout << "So phan so trong mang: ";
  cin >> n;
  ps.resize(n);
  for(int i=0;i<n;i++){
    while(ps[i].Mau == 0){
      cout << "Phan so thu " << i << ": ";
      cin >> ps[i].Tu;
      cin >> ps[i].Mau;
    }
  }
  PhanSo lon_nhat;
  PhanSo nho_nhat;
  PSLonNhatNhoNhat(lon_nhat, nho_nhat);
  cout << "Phan so lon nhat: ";
  Xuat(lon_nhat);
  cout << "\n";
  cout << "Phan so nho nhat: ";
  Xuat(nho_nhat);
  cout << "\n";
}
