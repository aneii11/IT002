#include<iostream>

using namespace std;

const int SoNgay[13]={
  0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
};

const int SoNgayNhuan[13] = {
  0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366
};


int ChuyenVeSoNgay(int Ngay, int Thang, int Nam){
  /* Tinh ngay tu dao vao la ngay thu may trong nam 
  * Dau vao: 
  * Tham so 1: Ngay trong thang 
  * Tham so 2: Thang 
  * Tham so 3: Nam 
  * Dau ra: Tra ve gia tri KetQua la ngay thu 'KetQua' trong nam*/
  int KetQua;
  if(Nam % 4){
    KetQua = SoNgay[Thang-1] + Ngay;
    return KetQua;
  }
  else{
    KetQua = SoNgayNhuan[Thang-1] + Ngay;
    return KetQua;
  }
}

void NgayKeTiep(int Ngay, int Thang, int Nam){
  /* Xuat ra thiet bi xuat chuan ngay ke tiep cua ngay duoc dau vao
    * Dau vao: 
    * Tham so 1: Ngay trong thang 
    * Tham so 2: Thang 
    * Tham so 3: Nam 
    * Dau ra: Khong co */
  int NgayThuN = ChuyenVeSoNgay(Ngay, Thang, Nam) + 1;
  int ThangMoi=13;
  int NgayMoi;
  int NamMoi;
  if(Nam % 4){
    if(NgayThuN == 366){
      NamMoi = Nam + 1;
      ThangMoi = 1;
      NgayMoi = 1;
      printf("[+] Ngay ke tiep: %d/%d/%d\n",NgayMoi, ThangMoi, NamMoi);
      return;
    }
    for(;ThangMoi > 1 ;ThangMoi--){
      if(SoNgay[ThangMoi-1] < NgayThuN)
        break;
    }
    NgayMoi = NgayThuN - SoNgay[ThangMoi - 1];
    NamMoi = Nam;
    printf("[+] Ngay ke tiep: %d/%d/%d\n", NgayMoi, ThangMoi, NamMoi);
  }
  else{
    if(NgayThuN == 367){
      NamMoi = Nam+1;
      ThangMoi = 1;
      NgayMoi = 1;
      printf("[+] Ngay ke tiep: %d/%d/%d\n",NgayMoi, ThangMoi, NamMoi);
      return;
    }
    for(;ThangMoi > 1;ThangMoi--){
      if(SoNgayNhuan[ThangMoi-1] < NgayThuN)
        break;
    }
    NgayMoi = NgayThuN - SoNgayNhuan[ThangMoi - 1];
    NamMoi = Nam;
    printf("[+] Ngay ke tiep: %d/%d/%d\n", NgayMoi, ThangMoi, NamMoi);
  }
}

void NgayTruocDo(int Ngay, int Thang, int Nam){
  /* Xuat ra thiet bi xuat chuan ngay truoc do cua ngay duoc dua vao tu dau vao 
    * Dau vao:
    * Tham so 1: Ngay trong thang 
    * Tham so 2: Thang 
    * Tham so 3: Nam 
    * Dau ra: Khong co*/
  int NgayThuN = ChuyenVeSoNgay(Ngay, Thang, Nam) - 1;
  int ThangMoi=13;
  int NgayMoi;
  int NamMoi;
  if(Nam % 4){
    if(NgayThuN == 0){
      NamMoi = Nam - 1;
      ThangMoi = 12;
      NgayMoi = 31;
      printf("[+] Ngay truoc do: %d/%d/%d\n",NgayMoi, ThangMoi, NamMoi);
      return;
    }
    for(;ThangMoi > 1 ;ThangMoi--){
      if(SoNgay[ThangMoi-1] < NgayThuN)
        break;
    }
    NgayMoi = NgayThuN - SoNgay[ThangMoi - 1];
    NamMoi = Nam;
    printf("[+] Ngay truoc do: %d/%d/%d\n", NgayMoi, ThangMoi, NamMoi);
  }
  else{
    if(NgayThuN == 0){
      NamMoi = Nam-1;
      ThangMoi = 12;
      NgayMoi = 31;
      printf("[+] Ngay truoc do: %d/%d/%d\n",NgayMoi, ThangMoi, NamMoi);
      return;
    }
    for(;ThangMoi > 1;ThangMoi--){
      if(SoNgayNhuan[ThangMoi-1] < NgayThuN)
        break;
    }
    NgayMoi = NgayThuN - SoNgayNhuan[ThangMoi - 1];
    NamMoi = Nam;
    printf("[+] Ngay truoc do: %d/%d/%d\n", NgayMoi, ThangMoi, NamMoi);
  }
}

int main(){
  int Ngay;
  int Thang;
  int Nam;
  int NgayThuN;
  do{
    printf("[?] Nhap ngay: ");
    scanf("%d", &Ngay);
    printf("[?] Nhap thang: ");
    scanf("%d", &Thang);
    printf("[?] Nhap nam: ");
    scanf("%d", &Nam);
  } while((Ngay <= 0 && Ngay > 31) || (Thang <= 0 && Thang > 12) || Nam <= 0);
  NgayKeTiep(Ngay, Thang, Nam);
  NgayTruocDo(Ngay, Thang, Nam);
  printf("[+] La ngay thu %d trong nam\n",ChuyenVeSoNgay(Ngay,Thang,Nam));
}
