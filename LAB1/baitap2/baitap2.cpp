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
  /* Xuat ra thiet bi xuat chuan phan so duoc truyen tu dau vao
  *  Dau vao:
  *  Tham so 1: Tu so  
  *  Tham so 2: Mau so
  *  Dau ra: Khong co */
  if(tu == 0){
    printf("0\n");
    return;
  }
  if(mau == 1){
    printf("%d\n", (int)tu);
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
  /* Toi gian phan so truyen vao, tra ve qua chinh phan so do 
    * Dau vao: 
    * Tham so 1: Tu so
    * Tham so 2: Mau so 
    * Dau ra: Phan so da duoc toi gian */
  int gcd = __gcd(mau, tu);
  tu /= gcd;
  mau /= gcd;
}

int main(){
  int tu1, mau1, tu2, mau2;
  do{
    printf("[+] Nhap phan so thu nhat\n");
    printf("[?] Nhap tu so: ");
    NhapInt(&tu1);
    printf("[?] Nhap mau so: ");
    NhapInt(&mau1);
    ToiGian(tu1,mau1);
  }while(mau1 == 0);

  do{
    printf("[+] Nhap phan so thu hai\n");
    printf("[?] Nhap tu so: ");
    NhapInt(&tu2);
    printf("[?] Nhap mau so: ");
    NhapInt(&mau2);
    ToiGian(tu2,mau2);
  }while(mau2==0);

  if((float)tu1/mau1 < (float)tu2/mau2){
    printf("[+] Phan so lon hon: ");
    Xuat(tu2, mau2);
  }
  else if((float)tu1/mau1 > (float)tu2/mau2){
    printf("[+] Phan so lon hon: ");
    Xuat(tu1, mau1);
  }
  else {
    printf("[-] Hai phan so bang nhau ");
  }
  puts("");
}
