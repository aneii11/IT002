#include "phong.h"

// Phuong thuc thiet lap mac dinh
Phong::Phong():SoDem(0), Loai(""){}

// Phuong thuc thiet lap co tham so cua lop Phong
Phong::Phong(int dem, string loai_): SoDem(dem), Loai(loai_){}

string Phong::loai(){return Loai;}
