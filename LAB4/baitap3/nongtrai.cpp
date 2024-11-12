#include "nongtrai.h"
#include "giasuc.h"
#include <algorithm>

NongTrai::NongTrai():SoBo(0), SoDe(0), SoCuu(0), TongSo(0){
  gia_suc = new GiaSuc*[1000];
}

NongTrai::~NongTrai(){
  for(int i=0;i<SoCuu + SoBo + SoDe; i++){
    delete gia_suc[i];
  }
}

float NongTrai::ThongKeSua(){
  float sua = 0;
  for(int i=0;i<TongSo;i++){
    switch(gia_suc[i]->pl){
      case GiaSuc::BO:
      sua += static_cast<Bo*>(gia_suc[i])->ChoSua();
      break;
      case GiaSuc::CUU:
      sua += static_cast<Cuu*>(gia_suc[i])->ChoSua();
      break;
      case GiaSuc::DE:
      sua += static_cast<De*>(gia_suc[i])->ChoSua();
    }
  }
  return sua;
}

void NongTrai::ThemGiaSuc(GiaSuc *them){
  gia_suc[TongSo] = them;
}

void NongTrai::Doi(){
  random_shuffle(gia_suc, gia_suc+TongSo);
  for(int i=0;i<TongSo;i++){
    switch (gia_suc[i]->pl) {
      case GiaSuc::BO:
      static_cast<Bo*>(gia_suc[i])->Keu();
      break;
      case GiaSuc::CUU:
      static_cast<Cuu*>(gia_suc[i])->Keu();
      break;
      case GiaSuc::DE:
      static_cast<De*>(gia_suc[i])->Keu();
      break;
    }
  }
}

void NongTrai::LuotSinhCon(){
  int tong_hien_tai = TongSo;
  for(int i=0;i<tong_hien_tai;i++){
    switch (gia_suc[i]->pl) {
      case GiaSuc::BO:
      static_cast<Bo*>(gia_suc[i])->SinhCon(*this);
      break;
      case GiaSuc::CUU:
      static_cast<Cuu*>(gia_suc[i])->SinhCon(*this);
      break;
      case GiaSuc::DE:
      static_cast<De*>(gia_suc[i])->SinhCon(*this);
      break;
    }
  }
}
