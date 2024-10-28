#include "thisinh.h"

/* Nhap thong tin thi sinh*/
void ThiSinh::Nhap(){
  cout << "[?] Nhap ten: ";
  cin.ignore();
  getline(cin, Ten);
  cout << "[?] Nhap MSSV: ";
  cin >> MSSV ;
  cout << "[?] Nhap ngay thang nam sinh (dd/mm/yyyy): ";
  scanf("%d/%d/%d", &iNgay, &iThang, &iNam);
  cout << "[?] Nhap diem toan, van, anh: ";
  cin >> fToan >> fVan >> fAnh;
}

/* Xuat thong tin thi sinh*/
void ThiSinh::Xuat(){
  printf("Ten: %s\n" 
"MSSV: %s\n" 
"Ngay sinh: %02d/%02d/%04d\n" 
"Diem toan: %.2f\n" 
"Diem van: %.2f\n" 
"Diem anh: %.2f\n", Ten.c_str(), MSSV.c_str(), iNgay, iThang, iNam, fToan, fVan, fAnh );
}

/* Dau ra: Tong diem cua thi sinh*/
float ThiSinh::Tong(){
  return fToan + fVan + fAnh;
}


