#include "diem.cpp"                                                    //

using namespace std;

int main (int argc, char *argv[]) {
  int n;
  Diem A;
  float h, t;
  cout << "Nhap diem: ";
  cin >> h >> t;
  A.SetHoanhDo(h), A.SetTungDo(t);
  cout  << "Nhap so luong chi thi: \n";
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    switch (x) {
      case 1: 
        A.SetHoanhDo(A.GetHoanhDo()*2);
        A.SetTungDo(A.GetTungDo()*2);
        break;
      case 2: 
        A.SetHoanhDo(0);
        A.SetTungDo(0);
        break;
      case 3: 
        float k, d;
        cin >> k >> d;
        k = (k != 0 ? 90 : 0);
        A.TinhTien(k, d);
        break;
      default:
        break;
    }
  }
  A.Xuat(); 
  return 0;
}


