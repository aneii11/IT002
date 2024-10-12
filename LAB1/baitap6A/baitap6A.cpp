#include<bits/stdc++.h>

using namespace std; 

vector<int>ChiSo;

void NhapMang(vector<int> &V, int n){
  /* Nhap tu thiet bi nhap chuan cac phan tu cua mang 
    * Dau vao: 
    * Tham so 1: bien vector de luu mang 
    * Dau ra: Tra ve mang qua tham so thu nhat*/ 
  V.resize(n);
  for(int i=0;i<n;i++){
    scanf("%d", &V[i]);
  }
  puts("");
}

int TanSuat(vector<int> A, vector<int> B){
  /* Dem tan suat mang A xuat hien trong mang B
    * Dau vao 
    * Tham so 1: Mang A 
    * Tham so 2: Mang B 
    * Dau ra: So lan xuat hien cua mang A trong mang B*/
  int DoDaiA = A.size();
  int KetQua = 0;
  if(DoDaiA > B.size())
    return 0;
  for(int i=0;i<=B.size()-DoDaiA;i++){
    vector<int>Tam(B.begin() + i, B.begin() + i + DoDaiA );
    if(Tam == A){
      KetQua++;
      ChiSo.push_back(i);
    }
  }
  return KetQua;
}

int main(){
  int nA, nB;
  scanf("%d", &nA);
  scanf("%d", &nB);
  vector<int> A;
  vector<int> B;
  NhapMang(A,nA);
  NhapMang(B,nB);
  printf("%d\n",TanSuat(A,B));
  for(auto i: ChiSo){
    printf("%d ", i);
  }
  puts("");
}
