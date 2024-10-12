#include<iostream>
#include<algorithm>

using namespace std;

struct PhanSo{
    int tu;
    int mau;
};

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

void Xuat(PhanSo ps){
  /* Xuat ra thiet bi xuat chuan phan so truyen vao tu dau vao 
    * Dau vao: 
    * Tham so 1: Phan so 
    * Dau ra: Khong co */ 
  if(ps.tu == 0){
    printf("0");
    return;
  }
  if(ps.mau == 1){
    printf("%d", (int)ps.tu);
    return;
  }
  if((float)ps.tu/ps.mau < 0){
    printf("-%d/%d", abs(ps.tu), abs(ps.mau));
    return;
  }
  if((float)ps.tu/ps.mau > 0){
    printf("%d/%d", abs(ps.tu), abs(ps.mau));
    return;
  }
}

void ToiGian(PhanSo &ps){
  /* Toi gian phan so duoc truyen vao tu dau vao
    * Dau vao: 
    * Tham so 1:Phan so truyen vao de toi gian
    * Dau ra: Phan so da duoc toi gian, tra ve qua tham so 1*/
  int gcd = __gcd(ps.mau, ps.tu);
  ps.tu /= gcd;
  ps.mau /= gcd;
}

PhanSo Cong(PhanSo ps1, PhanSo ps2){
  /* Cong hai phan so dau vao
    * Dau vao: 
    * Tham so 1: Phan so lam toan hang thu nhat 
    * Tham so 2: Phan so lam toan hang thu hai
    * Dau ra: Tra ve ket qua phep cong phan so qua gia tri tra ve */
    int TuKq = ps1.tu*ps2.mau + ps1.mau*ps2.tu;
    int MauKq = ps1.mau * ps2.mau;
    PhanSo KetQua = {TuKq, MauKq};
    return KetQua;
}

PhanSo Tru(PhanSo ps1, PhanSo ps2){
  /* Tru hai phan so dau vao
    * Dau vao: 
    * Tham so 1: Phan so lam toan hang thu nhat 
    * Tham so 2: Phan so lam toan hang thu hai
    * Dau ra: Tra ve ket qua phep tru phan so qua gia tri tra ve */
    int TuKq = ps1.tu*ps2.mau - ps1.mau*ps2.tu;
    int MauKq = ps1.mau * ps2.mau;
    PhanSo KetQua = {TuKq, MauKq};
    return KetQua;
}

PhanSo Nhan(PhanSo ps1, PhanSo ps2){
  /* Nhan hai phan so dau vao
    * Dau vao: 
    * Tham so 1: Phan so lam toan hang thu nhat 
    * Tham so 2: Phan so lam toan hang thu hai
    * Dau ra: Tra ve ket qua phep nhan phan so qua gia tri tra ve */
    int TuKq = ps1.tu * ps2.tu;
    int MauKq = ps1.mau * ps2.mau;
    PhanSo KetQua = {TuKq, MauKq};
    return KetQua;
}

PhanSo Chia(PhanSo ps1, PhanSo ps2){
  /* Chia hai phan so dau vao
    * Dau vao: 
    * Tham so 1: Phan so lam toan hang thu nhat 
    * Tham so 2: Phan so lam toan hang thu hai
    * Dau ra: Tra ve ket qua phep chia phan so qua gia tri tra ve */
    int TuKq = ps1.tu * ps2.mau;
    int MauKq = ps1.mau * ps2.tu;
    PhanSo KetQua = {TuKq, MauKq};
    return KetQua;
}

int main(){
  PhanSo A, B;
  do{
    printf("[+] Nhap phan so thu nhat\n");
    printf("[?] Nhap tu so: ");
    NhapInt(&A.tu);
    printf("[?] Nhap mau so: ");
    NhapInt(&A.mau);
  }while(A.mau == 0);

  do{
    printf("[+] Nhap phan so thu hai\n");
    printf("[?] Nhap tu so: ");
    NhapInt(&B.tu);
    printf("[?] Nhap mau so: ");
    NhapInt(&B.mau);
  }while(B.mau == 0);

  PhanSo C;
  printf("[+] "), Xuat(A), printf(" + "), Xuat(B), printf(" = ");
  C = Cong(A,B), ToiGian(C);
  Xuat(C);
  puts("");

  printf("[+] "), Xuat(A), printf(" - "), Xuat(B), printf(" = ");
  C = Tru(A,B), ToiGian(C);
  Xuat(C);
  puts("");

  printf("[+] "), Xuat(A), printf(" * "), Xuat(B), printf(" = ");
  C = Nhan(A,B), ToiGian(C);
  Xuat(C);
  puts("");

  if(B.tu == 0){
    puts("Khong the thuc hien phep chia cho 0.");
    return 0;
  }
  printf("[+] "), Xuat(A), printf(" / "), Xuat(B), printf(" = ");
  C = Chia(A,B), ToiGian(C);
  Xuat(C);
  puts("");
}
