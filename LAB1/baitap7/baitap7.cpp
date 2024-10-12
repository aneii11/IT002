#include<bits/stdc++.h>

using namespace std;


struct NgayThangNam{
    unsigned int Ngay;
    unsigned int  Thang;
    unsigned int Nam;
};

struct ThoiGian{
    unsigned int Gio;
    unsigned int Phut;
};

struct ChuyenBay{
    char MaChuyenBay[6];
    NgayThangNam NgayBay;
    ThoiGian GioBay;
    char NoiDi[21];
    char NoiDen[21];
};

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

vector<ChuyenBay>DSChuyenBay;

bool KiemTraMaChuyen(const char* MCB){  
  /* Kiem tra tinh hop le cua ma chuyen bay
    * Dau vao: 
    * Tham so 1: Ma chuyen bay 
    * Dau ra: true neu ma chuyen bay hop le, false neu ma chuyen bay khong hop le*/  
    string MCB_str(MCB);
    return !(MCB_str.find_first_not_of("abcdefghijklmnopqrstuvwxyzQWWERTYUIOPASDFGHJKLZXCVBNM1234567890") != std::string::npos);
}

bool KiemTraDiaDiem(const char *DiaDiem){
  /* Kiem tra tinh hop le cua dia diem 
    * Dau vao: 
    * Tham so 1: dia diem 
    * Dau ra: true neu dia diem hop le, false neu dia diem khong hop le*/
    string DiaDiem_str(DiaDiem);
    return !(DiaDiem_str.find_first_not_of("abcdefghijklmnopqrstuvwxyzQWWERTYUIOPASDFGHJKLZXCVBNM ") != std::string::npos);
}

bool KiemTraThoiGian(ThoiGian tg){
  /* Kiem tra tinh hop le cua gio phut 
    * Dau vao:
    * Tham so 1: Gio phut luu trong ThoiGian 
    * Dau ra: true neu thoi gian hop le, false neu thoi gian khong hop le */ 
    if(tg.Gio > 23 || tg.Phut >= 60)
        return false;
    return true;
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

void Menu(){ 
  /* Xuat ra thiet bi xuat chuan menu cua chuong trinh */ 
    puts("1. Nhap chuyen bay");
    puts("2. Xuat thong tin tat ca chuyen bay");
    puts("3. Tim kiem chuyen bay");
    puts("4. Tim kiem chuyen bay theo noi di va ngay khoi hanh");
    puts("5. Dem so chuyen bay theo noi di va noi den");
    puts("6. Sap xep");
    puts("7. Thoat");
}

void MenuTimKiem(){
  /* Xuat ra thiet bi xuat chuan menu cua tim kiem*/
    puts("1. Ma chuyen bay");
    puts("2. Noi di");
    puts("3. Noi den");
    printf("> ");
}

void NhapChuyenBay(){
  /* Nhap tu thiet bi nhap chuan cac thong tin cua chuyen bay. Kiem tra tinh hop le cua cac thong tin 
  * Dau vao: Khong co 
  * Dau ra: Chuyen bay moi duoc luu vao DSChuyenBay */  
    ChuyenBay Moi;
    while(1){
        printf("[?] Nhap ma chuyen bay: ");
        scanf("%5s", Moi.MaChuyenBay);
        if(!KiemTraMaChuyen(Moi.MaChuyenBay)){
            printf("[-] Ma chuyen bay khong dung dinh dang. Moi nhap lai\n");
            continue;
        }
        break;
    }

    while(1){
        printf("[?] Nhap ngay bay\n");
        printf("[?] Nhap ngay: ");
        scanf("%d", &Moi.NgayBay.Ngay);
        printf("[?] Nhap thang: ");
        scanf("%d", &Moi.NgayBay.Thang);
        printf("[?] Nhap nam: ");
        scanf("%d", &Moi.NgayBay.Nam);
        if(!KiemTraNgay(Moi.NgayBay)){
            printf("[-] Ngay bay khong dung dinh dang. Moi nhap lai\n");
            continue;
        }
        break;
    }

    while(1){
        printf("[?] Nhap thoi gian bay: \n");
        printf("[?] Nhap gio: ");
        scanf("%d", &Moi.GioBay.Gio);
        printf("[?] Nhap phut: ");
        scanf("%d", &Moi.GioBay.Phut);
        if(!KiemTraThoiGian(Moi.GioBay)){
            puts("[-] Gio bay khong dung dinh dang. Moi nhap lai");
            continue;
        }
        break;
    };

    while(1){
        getchar();
        printf("[?] Nhap noi di: ");
        fgets(Moi.NoiDi,21,stdin);
        Moi.NoiDi[strcspn(Moi.NoiDi, "\n")] = 0;
        if(!KiemTraDiaDiem(Moi.NoiDi)){
            printf("[-] Noi di khong dung dinh dang. Moi nhap lai\n");
            continue;
        }
        break;
    }

    while(1){
        printf("[?] Nhap noi den: ");
        fgets(Moi.NoiDen,21,stdin);
        Moi.NoiDen[strcspn(Moi.NoiDen, "\n")] = 0;
        if(!KiemTraDiaDiem(Moi.NoiDen)){
            printf("[-] Noi den khong dung dinh dang. Moi nhap lai\n");
            continue;
        }
        break;
    }

    DSChuyenBay.push_back(Moi);
}

void XuatTTChuyenBay(ChuyenBay CB){ 
  /* Xuat thong tin cua chuyen bay tu du lieu dau vao  
    * Dau vao: 
    * Tham so 1: Chuyen bay 
    * Dau ra: Khong co */
    printf("Chuyen bay co so hieu: %s\n", CB.MaChuyenBay);
    printf("Di tu %s den %s\n", CB.NoiDi, CB.NoiDen);
    printf("Khoi hanh luc: %02d/%02d/%d - %02d:%02d\n", CB.NgayBay.Ngay, CB.NgayBay.Thang, CB.NgayBay.Nam, CB.GioBay.Gio, CB.GioBay.Phut);
}

vector<int> DoiSanh(const char* A, int ThaoTac){ 
  /* Doi sanh tu khoa tu du lieu dau vao voi thong tin cac chuyen bay 
  * Dau vao: 
  * Tham so 1: Tu khoa tim kiem 
  * Tham so 2: Thuoc tinh tim kiem 
  * Dau ra: Mot vector gom nhung chi so trong DSChuyenBay cua cac chuyen bay duoc tim thay */
    vector<int> KetQua;
    for(int i=0;i<DSChuyenBay.size();i++){
        if(ThaoTac == 1){
            if(!strcmp(A, DSChuyenBay[i].MaChuyenBay))
                KetQua.push_back(i);
        }
        else if(ThaoTac == 2){
            if(!strcmp(A,DSChuyenBay[i].NoiDi))
                KetQua.push_back(i);
        }
        else if(ThaoTac == 3){
            if(!strcmp(A,DSChuyenBay[i].NoiDen))
                KetQua.push_back(i);
        }
    }
    return KetQua;
}


void TimKiem(){  
  /* Giao dien cua tim kiem, nhan du lieu cua nguoi dung ve thuoc tinh tim kiem va tu khoa tim Kiem. Xuat ra cac chuyen bay phu hop voi ket qua tim kiem
    * Dau vao: Khong co 
    * Dau ra: Khong co */
    unsigned int ThaoTac;
    char TuKhoa[21];
    int ChiSo = -1; 


    puts("[?] Tim kiem theo dinh dang nao?");
    MenuTimKiem();
    scanf("%d", &ThaoTac);
    if(ThaoTac > 3){
        puts("[-] Thao tac khong hop le");
        return;
    }

    printf("[?] Nhap tu khoa tim kiem: ");
    getchar();
    fgets(TuKhoa,20,stdin);
    TuKhoa[strcspn(TuKhoa,"\n")] = 0;
    int SoChuyenBay = DSChuyenBay.size();
    vector<int> KetQua = DoiSanh(TuKhoa, ThaoTac);

    if(KetQua.size()==0){
        printf("Khong tim thay chuyen bay co thong tin ");
        if(ThaoTac == 1) printf("ma chuyen bay ");
        else if(ThaoTac == 2) printf("noi di ");
        else printf("noi den ");
        printf("%s", TuKhoa);
        return;
    }
    for(auto i:KetQua)
        XuatTTChuyenBay(DSChuyenBay[i]);
    puts("");
    return;
}

int ChuyenVeSoNgay(NgayThangNam ntn){
  /* Chuyen ngay thang nam thanh ngay thu bao nhieu trong nam 
  * Dau vao: 
  * Tham so 1: Ngay Thang nam 
  * Dau ra: tra ve gia tri cho biet ngay tu dau vao la ngay thu may trong nam*/
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

int ChuyenVeSoPhut(ThoiGian tg){ 
  /* Chuyen du lieu thoi gian tu dau vao thanh phut thu bao nhieu trong ngay 
    * Dau vao: 
    * Tham so 1: Thoi gian the hien gio phu 
    * Dau ra: tra ve gia tri cho biet thoi gian tu dau vao la phut thu may trong ngay*/
    return tg.Gio*60 + tg.Phut;
}

bool SoSanh(ChuyenBay A, ChuyenBay B){
  /* So sanh thoi gian cat canh cua hai chuyen bay 
  * Dau vao: 
  * Tham so 1: Chuyen bay A 
  * Tham so 2: Chuyen bay B 
  * Dau ra: true neu chuyen bay A cat canh som hon chuyen bay B, false khi nguoc lai*/
    if(A.NgayBay.Nam < B.NgayBay.Nam){
        return true;
    }
    if(A.NgayBay.Nam > B.NgayBay.Nam){
        return false;
    }
    int NgayThuN_A = ChuyenVeSoNgay(A.NgayBay);
    int NgayThuN_B = ChuyenVeSoNgay(B.NgayBay);
    if(NgayThuN_A < NgayThuN_B){
        return true;
    }
    if(NgayThuN_A > NgayThuN_B){
        return false;
    }
    int PhutThuN_A = ChuyenVeSoPhut(A.GioBay);
    int PhutThuN_B = ChuyenVeSoPhut(B.GioBay);
    return PhutThuN_A < PhutThuN_B;
}

bool SoSanhNgayThangNam(NgayThangNam A, NgayThangNam B){
  /* So sanh 2 moc thoi gian NgayThangNam co bang nhau khong 
    * Dau vao: 
    * Tham so 1: Ngay Thang Nam A 
    * Tham so 2: Ngay Thang Nam B 
    * Dau ra: true neu 2 Ngay A, B trung nhau, false neu A, B khac ngay nhau */
  return A.Nam == B.Nam && A.Ngay == B.Ngay && A.Thang == B.Thang;
}

void TimChuyenBayTheoNgayVaXuatPhat(){
  /* Tim kiem chuyen bay co ngay bay va noi di theo du lieu nhap vao. Xuat ra man hinh thong tin cac chuyen bay tim duoc  
    * Dau vao: Khong co 
    * Dau ra: Khong co */
    char TuKhoa[20];
    NgayThangNam NgayDi;
    getchar();
    while(1){
        printf("[?] Nhap noi di can tim: ");
        fgets(TuKhoa,20,stdin);
        TuKhoa[strcspn(TuKhoa, "\n")] = 0;
        if(!KiemTraDiaDiem(TuKhoa)){
            printf("[-] Noi di khong dung dinh dang. Moi nhap lai\n");
            continue;
        }
        break;
    }

    while(1){
        printf("[?] Nhap ngay bay can tim:\n");
        printf("[?] Nhap ngay: ");
        scanf("%d", &NgayDi.Ngay);
        printf("[?] Nhap thang: ");
        scanf("%d", &NgayDi.Thang);
        printf("[?] Nhap nam: ");
        scanf("%d", &NgayDi.Nam);
        if(!KiemTraNgay(NgayDi)){
            printf("[-] Ngay bay khong dung dinh dang. Moi nhap lai\n");
            continue;
        }
        break;
    }

    vector<int> DSCungNoiDi = DoiSanh(TuKhoa, 2);
    if(DSCungNoiDi.size() == 0){
        puts("[-] Khong tim thay chuyen bay nao");
        return;
    }
    vector<int> KetQua;
    for(auto i: DSCungNoiDi){
        if( SoSanhNgayThangNam(NgayDi, DSChuyenBay[i].NgayBay ))
            KetQua.push_back(i);
    }

    if(KetQua.size() == 0){
        puts("[-] Khong tim thay chuyen bay nao");
        return;        
    }

    for(auto i: KetQua){
        printf("[+] Tim thay chuyen bay %s.\n", DSChuyenBay[i].MaChuyenBay);
    }
}

void TimChuyenBayTheoDiDen(){ 
  /* Tim kiem cac chuyen bay co noi di va noi den duoc nhap vao tu thiet bi xuat chuan. 
  * Xuat ra thiet bi xuat chuan so chuyen bay tim duoc 
  * Dau vao: Khong co 
  * Dau ra: Khong co */ 
    char NoiDi[20];
    char NoiDen[20];
    int KetQua=0;
    while(1){
        getchar();
        printf("[?] Nhap noi di: ");
        fgets(NoiDi,20,stdin);
        NoiDi[strcspn(NoiDi, "\n")] = 0;
        if(!KiemTraDiaDiem(NoiDi)){
            printf("[-] Noi di khong dung dinh dang. Moi nhap lai\n");
            continue;
        }
        break;
    }

    while(1){
        printf("[?] Nhap noi den: ");
        fgets(NoiDen,20,stdin);
        NoiDen[strcspn(NoiDen, "\n")] = 0;
        if(!KiemTraDiaDiem(NoiDen)){
            printf("[-] Noi den khong dung dinh dang. Moi nhap lai\n");
            continue;
        }
        break;
    }

    for(int i=0;i<DSChuyenBay.size();i++){
        if(!strcmp(NoiDen, DSChuyenBay[i].NoiDen) && !strcmp(NoiDi,DSChuyenBay[i].NoiDi))
            KetQua++;
    }
    printf("Tim thay %d chuyen bay tu %s den %s\n", KetQua, NoiDi, NoiDen);
}


int main(){
    while(1){
        int ThaoTac;
        puts("");
        Menu();
        printf("[?] Chon thao tac: ");
        scanf("%d", &ThaoTac);
        switch(ThaoTac){
            case 1:
            NhapChuyenBay();
            break;
            case 2:
            for(auto i:DSChuyenBay)
                XuatTTChuyenBay(i);
            break;
            case 3:
            TimKiem();
            break;
            case 4:
            TimChuyenBayTheoNgayVaXuatPhat();
            break;
            case 5:
            TimChuyenBayTheoDiDen();
            break;
            case 6:
            sort(DSChuyenBay.begin(),DSChuyenBay.end(),SoSanh);
            break;
            case 7:
            puts("[+] Thoat chuong trinh");
            return 0;
            break;
            default:
            puts("[+] Thao tac khong hop le\n");
        }
    }
}
