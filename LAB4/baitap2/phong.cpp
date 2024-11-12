#include "phong.h"

Phong::Phong():SoDem(0), Loai(""){}

Phong::Phong(int dem, string loai_): SoDem(dem), Loai(loai_){}

string Phong::loai(){return Loai;}
