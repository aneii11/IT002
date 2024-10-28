#include <bits/stdc++.h>

using namespace std;

struct PhanSo {
  int Tu;
  int Mau;
};

vector<PhanSo> ps;

void Xuat(PhanSo ps){
  /* Xuat ra thiet bi xuat chuan phan so truyen vao tu dau vao 
    * Dau vao: 
    * Tham so 1: Phan so 
    * Dau ra: Khong co */ 
  if(ps.Tu == 0){
    printf("0");
    return;
  }
  if(ps.Mau == 1){
    printf("%d", (int)ps.Tu);
    return;
  }
  if((float)ps.Tu/ps.Mau < 0){
    printf("-%d/%d", abs(ps.Tu), abs(ps.Mau));
    return;
  }
  if((float)ps.Tu/ps.Mau > 0){
    printf("%d/%d", abs(ps.Tu), abs(ps.Mau));
    return;
  }
}

/* Kiem tra xem phan so thu nhat co nho hon phan so thu 2. Ham nay lam comparator cho std::sort
 * Dau vao: phan so a, phan so b 
 * Dau ra: True neu a < b, false neu a >= b*/
bool SoSanh(PhanSo a, PhanSo b){
  return (float)a.Tu/a.Mau < (float)b.Tu/b.Mau;
}

/* Sap xep cac phan so trong mang ps theo thu tu tang dan
 * Dau ra: Mang ps da duoc sap xep*/
void SapXep(){
  sort(ps.begin(), ps.end(), SoSanh);
}

int main(){
  int n, k;
  cout << "So phan so trong mang: ";
  cin >> n;
  ps.resize(n);
  for(int i=0; i<n; i++){
    while(ps[i].Mau == 0){
      cout << "Phan so thu " << i << ": ";
      cin >> ps[i].Tu;
      cin >> ps[i].Mau;
    }
  }
  cout << "Phan so be/lon thu: ";
  cin >> k;
  SapXep();
  cout << "Phan so be thu " << k << ": ";
  Xuat(ps[k-1]);
  cout << "\nPhan so lon thu " << k << ": ";
  Xuat(ps[ps.size()-k]);
}
