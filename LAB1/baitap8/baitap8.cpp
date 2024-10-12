#include<bits/stdc++.h>

using namespace std;

const int SoNgayThang[12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const int SoNgayThangNhuan[12] = {
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const int SoNgay[13]={
  0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
};

const int SoNgayNhuan[13] = {
  0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366
};

struct NgayThangNam{
    unsigned int Ngay;
    unsigned int  Thang;
    unsigned int Nam;
};

struct SoTietKiem{
  char MaSo[6];
  char LoaiTietKiem[11];
  char HoTenKH[31];
  char CMND[13];
  NgayThangNam NgayMoSo;
  double TienGui;
  float LaiSuat = 3.4;
};

vector<SoTietKiem> DSSTK;

bool KiemTraMa(const char* Ma){
  /* Kiem tra tinh hop le cua Ma so 
    * Dau vao: 
    * Tham so 1: Ma so 
    * Dau ra: true neu ma so hop le, false neu ma so khong hop le */
    string Ma_str(Ma);
    return !(Ma_str.find_first_not_of("abcdefghijklmnopqrstuvwxyzQWWERTYUIOPASDFGHJKLZXCVBNM1234567890") != std::string::npos);
}

bool KiemTraTen(const char *Ten){
    string Ten_str(Ten);
    return !(Ten_str.find_first_not_of("abcdefghijklmnopqrstuvwxyzQWWERTYUIOPASDFGHJKLZXCVBNM ") != std::string::npos);
}

bool KiemTraNgay(NgayThangNam ntn){
  /* Kiem tra tinh hop le cua ngay thang nam 
    * Dau vao:
    * Tham so 1: Ngay thang nam 
    * Dau ra: true neu ngay thang nam hop le, false neu ngay thang nam khong hop le*/
    if(ntn.Thang > 12)
      return false;
    if(ntn.Nam % 4){
        if(ntn.Ngay > SoNgayThang[ntn.Thang-1])
            return false;
        return true;
    }
    else{
        if(ntn.Ngay > SoNgayThangNhuan[ntn.Thang-1])
            return false;
        return true;
    }
}

bool KiemTraCMND(const char *CMND){
  /* Kiem tra tinh hop le cua CMND 
    * Dau vao: 
    * Tham so 1: so Chung minh nhan dan 
    * Dau ra: true neu CMND hop le, false neu CMND khong hop le */

  string CMND_str(CMND);
  if(strlen(CMND) != 9 && strlen(CMND) != 12)
    return false ;
  return !(CMND_str.find_first_not_of("1234567890") != std::string::npos);
}

void NhapSTK(){
  /* Nhap thong tin so tiet kiem tu thiet bi nhap chuan. Kiem tra cac thong tin, bao loi neu co loi va yeu cau nhap lai. 
  * Dau vao: Khong 
  * Dau ra: Mot so tiet kiem moi duoc luu vao DSSTK (Danh sach so tiet kiem)*/
  SoTietKiem Moi;
  while(1){
    printf("[?] Nhap Ma So? ");
    getchar();
    fgets(Moi.MaSo, 6, stdin);
    Moi.MaSo[strcspn(Moi.MaSo,"\n")] = 0;
    if(!KiemTraMa(Moi.MaSo)){
      printf("[-] Ma So khong dung dinh dang:\n");
      continue;
    }
    break;
  }


  printf("[?] Nhap loai tiet kiem: ");
  getchar();
  fgets(Moi.LoaiTietKiem, 11, stdin);
  Moi.LoaiTietKiem[strcspn(Moi.LoaiTietKiem,"\n")] = 0;
    
  while(1){
    printf("[?] Nhap ngay mo so: \n");
    printf("[?] Nhap ngay: ");
    scanf("%d", &Moi.NgayMoSo.Ngay);
    printf("[?] Nhap thang: ");
    scanf("%d", &Moi.NgayMoSo.Thang);
    printf("[?] Nhap nam: ");
    scanf("%d", &Moi.NgayMoSo.Nam);
    if(!KiemTraNgay(Moi.NgayMoSo)){
      puts("[-] Ngay thang nam khong dung dinh dang.");
      continue;
    }
    break;
  }

  while(1){
    printf("[?] Nhap CMND: ");
    getchar();
    fgets(Moi.CMND,13,stdin);
    Moi.CMND[strcspn(Moi.CMND,"\n")] = 0;
    if(!KiemTraCMND(Moi.CMND)){
      puts("[-] So CMND khong dung dinh dang.");
      continue;
    }
    break;
  }

  while(1){
    printf("[?] Nhap so tien gui: ");
    scanf("%lf",&Moi.TienGui);
    if(Moi.TienGui <= 0){
      puts("[-] So tien gui khong hop le");
      continue;
    }
    break;
  }
  DSSTK.push_back(Moi);

}

void XuatSTK(SoTietKiem stk){
  /* Xuat thong tin so tiet kiem cua so tiet kiem dau vao
    * Dau vao: 
    * Tham so 1: So tiet kiem 
    * Dau ra: Khong co */
  puts("[+] Thong tin so tiet kiem:");
  printf("[+] Ma so: %s\n",stk.MaSo);
  printf("[+] Loai tiet kiem: %s\n", stk.LoaiTietKiem);
  printf("[+] So CMND: %s\n", stk.CMND);
  printf("[+] Ngay mo so: %02d/%02d/%d\n", stk.NgayMoSo.Ngay, stk.NgayMoSo.Thang, stk.NgayMoSo.Nam);
  printf("[+] So tien gui: %.2f\n", stk.TienGui);
}

bool TimKiem(string TuKhoa, bool CMND, SoTietKiem& KetQua){
  int DoDaiDS = DSSTK.size();
  for(int i=0;i<DoDaiDS;i++){
    if(CMND){
      if(!strcmp(TuKhoa.c_str(), DSSTK[i].CMND)){
        KetQua = DSSTK[i];
        return 1;
      }
    }
    else{
      if(!strcmp(TuKhoa.c_str(), DSSTK[i].MaSo)){
        KetQua = DSSTK[i];
        return 1;
      }
    }
  }
  return 0;
}

void MenuTinhNang(){
  /* Xuat ra thiet bi xuat chuan cua menu cac tinh nang dac biet */
  puts("1. Cap nhat lai suat");
  puts("2. Tinh toan lai suat");
  puts("3. Rut tien");
}

void CapNhatLaiSuat(SoTietKiem& SoHienTai){
  /* Giao dien cua cap nhat lai suat. Doc du lieu tu thiet bi nhap chuan thong tin lai suat.
  * Xuat ra man hinh tien lai voi lai suat vua duoc nhap vao voi hai loai tiet kiem.
  * Dau vao: So tiet kiem dang xu ly  
  * Dau ra: Khong co*/ 
  float LaiSuat;
  printf("[?] Nhap lai suat: ");
  scanf("%f", &LaiSuat);
  if(LaiSuat > 10 || LaiSuat < 1.5){
    LaiSuat = 0;
    puts("[-] Lai suat khong hop le");
    return;
  }
  double TienLaiNgan = SoHienTai.TienGui * (LaiSuat )/12 *1;
  printf("[+] Lai suat theo tiet kiem ngan han den het ky han: %.2lf/thang\n",TienLaiNgan );
  double TienLaiDai = SoHienTai.TienGui * (LaiSuat)/12 * 6;
  printf("[+] Lai suat theo tiet kiem dai han den het ky han: %.2lf/6thang\n", TienLaiDai);
}

void TinhToanLai(SoTietKiem SoHienTai){
  /* Tinh toan lai suat cua mot so tiet kiem tu luc mo so den hien tai. 
  * Dau vao: So tiet kiem dang xu ly 
  * Dau ra: Khong co */
  if(SoHienTai.LaiSuat == 0){
    printf("[-] Chua cap nhat lai suat\n");
    return;
  }
  int SoThang = (2024 - SoHienTai.NgayMoSo.Nam)*12 + 10 - SoHienTai.NgayMoSo.Thang;
  printf("So thang: %d\n", SoThang);
  double SoTienLai = SoHienTai.TienGui * (SoHienTai.LaiSuat)/12 * SoThang;
  printf("[+] Tien lai thu thoi diem mo so: %.2lf\n",SoTienLai);
}

void RutTien(SoTietKiem SoHienTai){
  /* Thuc hien thao tac rut tien. Canh bao neu chua den ky han. Bao loi neu so tien rut lon hon so tien trong so tiet kiem. 
  * Dau vao: So tiet kiem dang xu ly
  * Dau ra: Khong co */
  int SoThang = (2024 - SoHienTai.NgayMoSo.Nam) * 12 + 10 - SoHienTai.NgayMoSo.Thang;
  double SoTienRut;
  printf("[?] So tien ban muon rut?");
  scanf("%lf", &SoTienRut);
  if(SoTienRut < 0 || SoTienRut > SoHienTai.TienGui){
    printf("[!] So tien khong hop le:\n");
    return;
  }
  if(!strcmp(SoHienTai.LoaiTietKiem, "Dai han")){
    if(SoThang < 6){
      puts("[!] Chua den ky han rut tien");
      double SoTienLai = SoHienTai.TienGui * (0.5)/12 * SoThang;
      printf("[!] Lai suat nhan duoc neu rut: %.2f\n", SoTienLai);
    }
  }
  else {
    puts("[+] Rut tien thanh cong.");
    SoHienTai.TienGui -= SoTienRut;
    printf("[+] So tien trong so tiet kiem: %.2lf\n", SoHienTai.TienGui);
  }
}

void TinhNangDacBiet(){
  /* Giao dien cua cac tinh nang nang cao */
  SoTietKiem SoHienTai;
  string TuKhoa;
  int ThaoTac;
  printf("[?] Nhap ma so tiet kiem: ");
  cin >> TuKhoa;
  if(!TimKiem(TuKhoa, false, SoHienTai)){
    puts("[!] Khong tim thay so tiet kiem:");
    return;
  }
  MenuTinhNang();
  printf("[?] Chon thao tac: ");
  scanf("%d", &ThaoTac);
  switch(ThaoTac){
    case 1:
    CapNhatLaiSuat(SoHienTai);
    break;
    case 2:
    TinhToanLai(SoHienTai);
    break;
    case 3:
    RutTien(SoHienTai);
    break;
    default:
    puts("[-] Thao tac khong hop le:\n");
    return;
  }
}


int ChuyenVeSoNgay(NgayThangNam ntn){
  /* Chuyen tu ngay thang nam thanh so ngay thu bao nhieu trong nam 
  * Dau vao: 
  * Tham so 1: ngay thang nam 
  * Dau ra: Mot so nguyen cho biet ngay thang nam tu dau vao la ngay thu bao nhieu trong nam*/
  int KetQua;
  if(ntn.Nam % 4){
    KetQua = SoNgay[ntn.Thang-1] + ntn.Ngay;
    return KetQua;
  }
  else{
    KetQua = SoNgayNhuan[ntn.Thang-1] + ntn.Ngay;
    return KetQua;
  }
} 

void LietKeSoTietKiem(NgayThangNam A, NgayThangNam B){
  /* Liet ke cac so tiet kiem duoc mo trong khoang thoi gian xac dinh. Xuat ra thiet bi xuat chuan cac ket qua tim duoc  
   * Dau vao: 
   * Tham so 1: Ngay bat dau 
   * Tham so 2: Ngay ket thuc 
   * Dau ra: Khong co */ 
  int NgayA = ChuyenVeSoNgay(A) + A.Nam * 366 ;
  int NgayB = ChuyenVeSoNgay(B) + B.Nam * 366;
  int DoDaiDS = DSSTK.size();
  for(int i=0;i<DoDaiDS;i++){ 
    int NgayMo = ChuyenVeSoNgay(DSSTK[i].NgayMoSo) + DSSTK[i].NgayMoSo.Nam * 366;
    if( NgayMo >= NgayA && NgayMo <= NgayB ){
      XuatSTK(DSSTK[i]);
    }
  }
}

bool SoSanhTienGui(SoTietKiem A, SoTietKiem B){
  /* So sanh tien gui giua 2 so tiet kiem A, B. Ham nay lam comparator cho ham std::sort() 
  * Dau vao: 
  * Tham so 1: So tiet kiem A 
  * Tham so 2: So tiet kiem B 
  * Dau ra: true neu tien gui cua A lon hon tien gui cua B, false neu nguoc lai*/
  return A.TienGui > B.TienGui;
}

bool SoSanhNgayMo(SoTietKiem A, SoTietKiem B){
  /* So sanh ngay mo so giua 2 so tiet kiem A, B. Ham nay lam comparator cho ham std::sort()
     * Dau vao: 
     * Tham so 1: So tiet kiem A 
     * Tham so 2: So tiet kiem B 
     * Dau ra: true neu so tiet kiem A duoc mo son hon so tiet kiem B, false neu nguoc lai*/
  if(A.NgayMoSo.Nam < B.NgayMoSo.Nam)
    return true;
  if(A.NgayMoSo.Nam > B.NgayMoSo.Nam)
    return false;
  int NgayMo_A = ChuyenVeSoNgay(A.NgayMoSo);
  int NgayMo_B = ChuyenVeSoNgay(B.NgayMoSo);
  return NgayMo_A < NgayMo_B;
}

void Menu(){
  /* Menu chuong trinh*/
  puts("1. Nhap thong tin so tiet kiem");
  puts("2. Xuat thong tin tat ca so tiet kiem");
  puts("3. Tim kiem theo CMND/MaSo");
  puts("4. Liet ke cac so tiet kiem duoc mo trong khoang thoi gian");
  puts("5. Sap xep so tien gui giam dan");
  puts("6. Sap xep ngay mo so tang dan");
  puts("7. Cac tinh nang nang cao");
  puts("8. Exit");
}

int main(){
  int ThaoTac;
  string TuKhoa;

  while(1){
    puts("");
    Menu();
    printf("[?] Chon thao tac: ");
    scanf("%d", &ThaoTac);
    switch (ThaoTac) {
      case 1:
        NhapSTK();
        break;
      case 2:
        for(auto i:DSSTK)
          XuatSTK(i);
        break;
      case 3:{
        int LuaChonTimKiem;
        SoTietKiem KetQua;
        puts("1. Tim kiem theo ma so");
        puts("2. Tim kiem theo CMND");
        printf("[?] ");
        scanf("%d", &LuaChonTimKiem);
        if(LuaChonTimKiem > 2){
          puts("[!] Lua chon khong hop le");
          continue;
        }
        printf("[?] Nhap tu khoa");
        cin >> TuKhoa;
        if(!TimKiem(TuKhoa, (LuaChonTimKiem == 2 ? 1:0), KetQua )){
          puts("[!] Khong tim thay so tiet kiem");
          continue;
        }
        XuatSTK(KetQua);
        break;
      }
      case 4:{
        NgayThangNam A, B; 
        while(1){
          printf("[?] Nhap ngay bat dau: \n");
          printf("[?] Nhap ngay: ");
          scanf("%d", &A.Ngay);
          printf("[?] Nhap thang: ");
          scanf("%d", &A.Thang);
          printf("[?] Nhap nam: ");
          scanf("%d", &A.Nam);
          if(!KiemTraNgay(A)){
            puts("[-] Ngay thang nam khong dung dinh dang.");
            continue;
          }
          break;
        }
        while(1){
          printf("[?] Nhap ngay ket thuc: \n");
          printf("[?] Nhap ngay: ");
          scanf("%d", &B.Ngay);
          printf("[?] Nhap thang: ");
          scanf("%d", &B.Thang);
          printf("[?] Nhap nam: ");
          scanf("%d", &B.Nam);
          if(!KiemTraNgay(B)){
            puts("[-] Ngay thang nam khong dung dinh dang.");
            continue;
          }
          break;
        }
        LietKeSoTietKiem(A,B);
      }
      case 5:
        sort(DSSTK.begin(),DSSTK.end(), SoSanhTienGui);
        break;
      case 6:
        sort(DSSTK.begin(),DSSTK.end(),SoSanhNgayMo);
        break;
      case 7:
        TinhNangDacBiet();
        break;
      case 8:
        puts("[+] Thoat chuong trinh");
        return 0;
      default:
        puts("[!] Thao tac khong hop le");
    }
  }
}
