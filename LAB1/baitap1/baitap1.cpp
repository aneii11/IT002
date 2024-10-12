#include<iostream>
#include<algorithm>

using namespace std;

void NhapInt(int *x){
  /* Doc so integer vao tu thiet bi nhap chuan qua tham so 1 
    * Dau vao: 
    * Tham so 1: bien luu so integer 
    * Dau ra: so integer nhap vao tu thiet bi nhap chuan tra ve qua tham so 1*/
    if(scanf("%d", x) != 1){
        cerr << "[!] Loi nhap int!\n";
        exit(-1);
    }
}

void Xuat(int tu, int mau){
  /* Xuat ra thiet  bi xuat chuan phan so tu dau vao
  *  Dau vao:
  *  Tham so 1: Tu so
  *  Tham so 2: Mau so 
  *  Dau ra: Khong co*/
  if(tu == 0){
    printf("0\n");
    return;
  }
  if(abs(mau) == 1 ){
    printf("%d\n", (int)tu * (mau) / abs(mau) );
    return;
  }
  if((float)tu/mau < 0){
    printf("-%d/%d\n", abs(tu), abs(mau));
    return;
  }
  if((float)tu/mau > 0){
    printf("%d/%d\n", abs(tu), abs(mau));
    return;
  }
}

void ToiGian(int &tu, int &mau){
  /* toi gian phan so nhap vao tu arg1 va arg2
    * input:
    * arg1: Tu so
    * arg2: Mau so */
  int gcd = __gcd(mau, tu);
  tu /= gcd;
  mau /= gcd;
}

int main(){
  int tu1, mau1;
  do{
    printf("[+] Nhap phan so \n");
    printf("[?] Nhap tu so: ");
    NhapInt(&tu1);
    printf("[?] Nhap mau so: ");
    NhapInt(&mau1);
  }while(mau1 == 0);

  ToiGian(tu1, mau1);

  printf("[+] Phan so vua nhap: ");
  Xuat(tu1,mau1);
}

