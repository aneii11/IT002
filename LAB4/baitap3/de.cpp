#include "de.h"
#include "nongtrai.h"

De::De(): GiaSuc(DE){}

void De::Keu(){
  cout << "maa\n";
}

float De::ChoSua(){
  return ( (float) rand()/(float) RAND_MAX * 10);
}

void De::SinhCon(NongTrai& n){
  for(int i=0;i<rand()%3 + 1;i++){
    n.ThemGiaSuc(new De());
    n.SoDe++;
    n.TongSo++;
  }
}
