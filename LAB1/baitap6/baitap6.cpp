#include<bits/stdc++.h>

using namespace std;

struct HocSinh{
    string HoTen;
    float DiemToan;
    float DiemVan;
    float DiemAnh;
    float DiemTrungBinh;
    bool CapNhatDiemTrungBinh;
};

vector<HocSinh> DanhSach;

void menu(){ 
  /* Xuat ra thiet bi xuat chuan menu cua chuong trinh */
    puts("1. Nhap thong tin hoc sinh.");
    puts("2. Tinh diem trung binh moi hoc sinh");
    puts("3. Phan loai hoc sinh");
    puts("4. Xuat thong tin hoc sinh co diem trung binh cao nhat");
    puts("5. Tim kiem hoc sinh theo ten");
    puts("6. Xuat danh sach hoc sinh co diem toan thap nhat");
    puts("7. Thoat");
}

bool KiemTraTen(string Ten){
  /* Kiem tra ten co hop le khong 
    * Dau vao: 
    * Tham so 1: Ten can kiem tra 
    * Dau ra: false neu ten khong hop le, true neu ten hop le*/ 
    return !(Ten.find_first_not_of("abcdefghijklmnopqrstuvwxyzQWWERTYUIOPASDFGHJKLZXCVBNM ") != std::string::npos);
}

void NhapTen(HocSinh &hs){
  /* Nhap tu thiet bi nhap chuan ten hoc sinh. Neu ten khong hop le thi nhap lai.
   * 
  * Dau vao: 
  * Tham so 1: Bien HocSinh chua thong tin hoc sinh
  * Dau ra: Ten hoc sinh duoc tra ve qua tham so 1 */
    getchar();
    do{
        printf("[?] Ho Ten hoc sinh? ");
        getline(cin,hs.HoTen);
    }while(!KiemTraTen(hs.HoTen));
}

void NhapDiem(HocSinh &hs){
  /* Nhap tu thiet bi nhap chuan Diem Van, Diem Toan, Diem Anh. Kiem tra tinh hop le. Neu khong hop le thi yeu cau nhap lai. 
  * Dau vao: 
  * Tham so 1: Bien HocSinh chua thong tin hoc sinh 
  * Dau ra: Diem Van, Diem Toan, Diem Anh tra ve qua tham so 1*/
    do{
        printf("[?] Nhap diem van: ");
        scanf("%f", &hs.DiemVan);
    }while(hs.DiemVan < 0 || hs.DiemVan > 10);
    do {
        printf("[?] Nhap diem toan: ");
        scanf("%f", &hs.DiemToan);
    }while(hs.DiemToan < 0 || hs.DiemToan > 10);
    do{
        printf("[?] Nhap diem anh: ");
        scanf("%f", &hs.DiemAnh);
    }while(hs.DiemAnh < 0 || hs.DiemAnh > 10);
}

void NhapThongTin(){
  /* Nhap thong tin cua n thong tin nhap tu thiet bi nhap chuan 
  * Dau vao: Khong co 
  * Dau ra: n thong tin hoc sinh duoc them vao qua vector<HocSinh>DanhSach*/
    int SoHocSinh;
    printf("[?] So hoc sinh can nhap? ");
    scanf("%d", &SoHocSinh);
    int DoDaiDanhSach = DanhSach.size();
    DanhSach.resize(DoDaiDanhSach+SoHocSinh);
    for(int i=0;i<SoHocSinh;i++){
        printf("Hoc sinh thu %d:\n", i+1);
        NhapTen(DanhSach[i+DoDaiDanhSach]);
        NhapDiem(DanhSach[i+DoDaiDanhSach]);
    }
}

void XuatDiem(int ChiSo){
  /* Xuat ra thiet bi xuat chuan thong tin Diem cua hoc sinh.
    * Dau vao:
    * Tham so 1: chi so cua HocSinh trong DanhSach 
    * Dau ra: Khong co */
    puts("");
    printf("[+] Diem Toan: %.2f\n", DanhSach[ChiSo].DiemToan);
    printf("[+] Diem Van: %.2f\n", DanhSach[ChiSo].DiemVan);
    printf("[+] Diem Anh: %.2f\n", DanhSach[ChiSo].DiemAnh);
    printf("[+] Diem trung binh: %.2f\n", DanhSach[ChiSo].DiemTrungBinh);
}

void TinhDiemTrungBinh(){
  /* Tinh toan diem trung binh cua tat ca hoc sinh 
    * Dau vao: Khong co 
    * Dau ra: Diem trung binh tat ca hoc sinh duoc cap nhat trong DanhSach*/
    int DoDaiDanhSach = DanhSach.size();
    for(int i=0;i<DoDaiDanhSach;i++){
        DanhSach[i].DiemTrungBinh = (float)(DanhSach[i].DiemToan*2 + DanhSach[i].DiemVan + DanhSach[i].DiemAnh)/4;
        DanhSach[i].CapNhatDiemTrungBinh = 1;
        printf("[+] Diem trung binh cua %s la: %.2f \n", DanhSach[i].HoTen.c_str(), DanhSach[i].DiemTrungBinh);
    }
}

void XepLoai(){
  /* Xep loai cac hoc sinh co trong bien toan cuc DanhSach 
    * Dau vao: Khong co  
    * Dau ra: Khong co */
    int DoDaiDanhSach = DanhSach.size();
    for(int i=0;i<DoDaiDanhSach;i++){
        if(DanhSach[i].CapNhatDiemTrungBinh == 0){
            printf("[-] Xep loai cua %s: chua cap nhat.\n", DanhSach[i].HoTen.c_str());
            continue;
        }
        if(DanhSach[i].DiemTrungBinh >= 9){
            printf("[+] Xep loai cua %s: Xuat sac.\n", DanhSach[i].HoTen.c_str());
        }
        else if(DanhSach[i].DiemTrungBinh < 9 && DanhSach[i].DiemTrungBinh >= 8){
            printf("[+] Xep loai cua %s: Gioi.\n", DanhSach[i].HoTen.c_str());
        }
        else if(DanhSach[i].DiemTrungBinh >= 6.5 && DanhSach[i].DiemTrungBinh < 8){
            printf("[+] Xep loai cua %s: Kha.\n", DanhSach[i].HoTen.c_str());
        }
        else if(DanhSach[i].DiemTrungBinh >=5 && DanhSach[i].DiemTrungBinh < 6.5){
            printf("[+] Xep loai cua %s: Trung binh.\n", DanhSach[i].HoTen.c_str());
        }
        else {
            printf("[+] Xep loai cua %s: Yeu.\n", DanhSach[i].HoTen.c_str());
        }
    }
}

void DTBCaoNhat(){
  /* Xuat ra thiet bi xuat chuan thong tin hoc sinh co diem trung binh cao nhat trong bien toan cuc DanhSach
  * Dau vao: Khong co 
  * Dau ra: Khong co */
    int DoDaiDanhSach = DanhSach.size();
    int ChiSo;
    float DiemCaoNhat = -1;
    for(int i=0;i<DoDaiDanhSach;i++){
        if(DanhSach[i].DiemTrungBinh > DiemCaoNhat){
            DiemCaoNhat = DanhSach[i].DiemTrungBinh;
            ChiSo = i;
        }
    }
    printf("[+] Sinh vien co diem trung binh cao nhat la %s. \n",DanhSach[ChiSo].HoTen.c_str());
    XuatDiem(ChiSo);
}

bool DoiSanh(string a, string b){ 
  /* Kiem tra chuoi A co cac tu phan biet boi dau cach co trung voi cac tu cuoi cung voi chuoi B khong 
    * Vi du: A := Van An, B := Nguyen Van An -> true 
    * Dau vao:
    * Tham so 1: chuoi A
    * Tham so 2: chuoi B 
    * Dau ra: true neu ket qua doi sanh dung, false neu ket qua doi sanh sai*/ 
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    vector<string> TuA;
    vector<string> TuB;
    stringstream ssA(a);
    stringstream ssB(b);
    string Tam;
    while(ssA >> Tam){
        TuA.push_back(Tam);
    }
    while(ssB >> Tam){
        TuB.push_back(Tam);
    }
    if(TuA.size() > TuB.size()){
        return false;
    }
    int SoTuCuaA = TuA.size();
    for(int i=0;i<SoTuCuaA;i++){
        if( TuB[TuB.size() - 1 -i] != TuA[TuA.size() - 1 -i] ){
            return false;
        }
    }
    return true;
}

void TimKiem(){
  /* Doc tu thiet bi xuat chuan ten hoc sinh, tim kiem ten hoc sinh do trong danh sach.
    * Neu tim thay thi xuat thong tin hoc sinh do ra thiet bi xuat chuan  
    * Dau vao: Khong co 
    * Dau ra: Khong co */
    string TuKhoa;
    int ChiSo = -1;
    puts("");
    printf("[?] Ten hoc sinh can tim? ");
    getchar();
    getline(cin,TuKhoa);
    int DoDaiDanhSach = DanhSach.size();
    for(int i=0;i<DoDaiDanhSach;i++){
        if(DoiSanh(TuKhoa, DanhSach[i].HoTen)){
            ChiSo = i;
            break;
        }
    }
    if(ChiSo == -1){
        printf("[+] Khong tim thay hoc sinh %s.\n", TuKhoa.c_str());
        return;
    }
    printf("[+] Tim thay hoc sinh %s.\n", DanhSach[ChiSo].HoTen.c_str());
    XuatDiem(ChiSo);
}

void DiemToanThapNhat(){
  /* Xuat ra thiet bi xuat chuan danh sach hoc sinh co diem toan thap nhat
  * Dau vao: Khong co 
  * Dau ra: Khong co */
    vector<int>DSToanThap;
    int DoDaiDanhSach = DanhSach.size();
    float DiemTThapNhat = 11;
    puts("");
    for(int i=0;i<DoDaiDanhSach;i++){
        if(DiemTThapNhat > DanhSach[i].DiemToan)
            DiemTThapNhat = DanhSach[i].DiemToan;
    }
    for(int i=0;i<DoDaiDanhSach;i++){
        if(DiemTThapNhat == DanhSach[i].DiemToan)
            DSToanThap.push_back(i);
    }
    for(auto i:DSToanThap){
        printf("[+] Hoc sinh %s co diem toan thap nhat.\n",DanhSach[i].HoTen.c_str());
        printf("[+] Diem toan: %.2f\n", DanhSach[i].DiemToan);
    }
}

int main(){
    NhapThongTin();
    TinhDiemTrungBinh();
    XepLoai();
    TimKiem();
    DiemToanThapNhat();    
}
