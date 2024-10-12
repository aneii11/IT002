#include<iostream>
#include<math.h>
using namespace std;

const double precision = 0.00001;

long long factorial(int n){
  /* Tinh toan giai thua cua n 
    * Dau vao: 
    * Tham so 1: gia tri n
    * Dau ra: Ket qua phep tinh n! */ 
  long long result=1;
  for(long long i=1;i<=n;i++){
    result *= i;
  }
  return result;
}

double F(double x, long long n){
  /* Tinh gia tri tuyet doi cac hang tu trong chuoi Maclaurin cua sin(x) x^(2n+1)/(2n+1)!
    * Dau vao: 
    * Tham so 1: gia tri x
    * Tham so 2: gia tri n 
    * Dau ra: tra ve gia tri cua hang tu qua gia tri tra ve */
  double result= pow(x,2*n+1)/factorial(2*n+1);
  return result;
}


double Maclaurin(double x){
  /* Tinh sin(x) qua chuoi Maclaurin voi do chinh xac 0.00001 
    * Dau vao:
    * Tham so 1: gia tri x 
    * Dau ra: ket qua cua sin(x) theo khai trien Maclaurin. */
  double result = 0;
  double tmp;
  for(int i=0;;i++){
    tmp = F(x,i);
    if(tmp < precision)
      break;
    if(i%2==0)
      result += tmp;
    else
      result -= tmp;
  }
  return result;
}

void simplify(double &x){
  /* Toi gian gia tri radian x ve gia tri co cung cung voi x thuoc khoang (0, 2*pie)
    * Dau vao:
    * Tham so 1: gia tri x 
    * Dau ra: gia tri x da toi gian tra ve qua x*/ 
  if(x > 6.28){
    for(;x>=6.28;x-=6.28){}
    return;
  }
  else if( x<0){
    for(;x<0;x+=6.28){}
    return;
  }
  else{
    return;
  }
}

int main(){
  printf("Enter x: ");
  double x;
  scanf("%lf", &x);
  simplify(x);
  printf("Calculate sin using Maclaurin: %.5f\n",Maclaurin(x));
  printf("Calculate sin using sin: %.5f\n", sin(x));
} 
