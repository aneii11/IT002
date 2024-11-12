#include "cuu.h"
#include "nongtrai.h"
#include <cstdlib>

Cuu::Cuu(): GiaSuc(CUU){}

void Cuu::Keu(){
  cout << "bee\n";
}

float Cuu::ChoSua(){
  return ( (float) rand()/(float)RAND_MAX * 5);
}

void Cuu::SinhCon(NongTrai& n){
  for(int i=0;i<rand()%3 + 1;i++){
    n.ThemGiaSuc(new Cuu());
    n.TongSo++;
    n.SoCuu++;
  }
}
