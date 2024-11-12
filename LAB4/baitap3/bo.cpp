#include "bo.h"
#include "nongtrai.h"

Bo::Bo(): GiaSuc(BO){}

void Bo::Keu(){
  cout << "moo\n";
}

float Bo::ChoSua(){
  return ((float)rand() /(float) RAND_MAX ) * 20;
}

void Bo::SinhCon(NongTrai &n){
  for(int i=0;i<rand()%3 + 1;i++){
    n.ThemGiaSuc(new Bo());
    n.TongSo++;
    n.SoBo++;
  }
}


