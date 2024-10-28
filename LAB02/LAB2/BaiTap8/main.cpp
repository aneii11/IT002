#include "list.cpp"
#include <iostream> 

using namespace std;

int main (int argc, char *argv[]) {                                              //
  List A;
  while(true){
    int option;
    cin >> option;
    switch (option) {
      case 0:{
        double x;
        cin >> x;
        A.Add(x);
        break;
      }
      case 1:{
        double x;
        cin >> x;
        A.Delete(x);
        break;
      }
      case 2:{
        double x;
        cin >> x;
        while(A.Delete(x));
        break;
      }
      case 3:{
        double y;
        unsigned int x;
        cin >> x >> y;
        A.Set(x,y);
        break;
      }
      case -1:{
        printf("[");
        for(int i=0;i<A.Size();i++){
          printf("%.2f,", A.Get(i));
        }
        printf("]");
        return 0;
        break;
      }
      default:
        break;
    }
  }
  return 0;
} 
