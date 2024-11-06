#include "phanso.cpp"

int main (int argc, char *argv[]) {
  PhanSo a;
  PhanSo b(-3,4);
  cin >> a >> b;
  double c;
  cin >> c;
  cout << "Thuc hien phep tinh phan so voi phan so\n";
  cout << a << " + " << b << " = " << a+b << "\n";
  cout << a << " - " << b << " = " << a-b << "\n";
  cout << a << " * " << b << " = " << a*b << "\n";
  cout << a << " / " << b << " = " << a/b << "\n";
  cout << "Thuc hien phep tinh so thuc voi phan so\n";
  cout << c << " + " << b << " = " << c+b << "\n";
  cout << c << " - " << b << " = " << c-b << "\n";
  cout << c << " * " << b << " = " << c*b << "\n";
  cout << c << " / " << b << " = " << c/b << "\n";
  cout << "Thuc hien phep tinh phan so voi so thuc\n";
  cout << a << " + " << c << " = " << a+c << "\n";
  cout << a << " - " << c << " = " << a-c << "\n";
  cout << a << " * " << c << " = " << a*c << "\n";
  cout << a << " / " << c << " = " << a/c << "\n";
  cout << "So sanh phan so voi phan so\n";
  cout << a << " == " << b << " : " << (a==b ? "True\n":"False\n");
  cout << a << " != " << b << " : " << (a!=b ? "True\n":"False\n");
  cout << a << " <= " << b << " : " << (a<=b ? "True\n":"False\n");
  cout << a << " >= " << b << " : " << (a>=b ? "True\n":"False\n");
  cout << a << " < " << b << " : " << (a<b ? "True\n":"False\n");
  cout << a << " > " << b << " : " << (a>b ? "True\n":"False\n");
  cout << "So sanh so thuc voi phan so\n";
  cout << c << " == " << b << " : " << (c==b ? "True\n":"False\n");
  cout << c << " != " << b << " : " << (c!=b ? "True\n":"False\n");
  cout << c << " <= " << b << " : " << (c<=b ? "True\n":"False\n");
  cout << c << " >= " << b << " : " << (c>=b ? "True\n":"False\n");
  cout << c << " < " << b << " : " << (c<b ? "True\n":"False\n");
  cout << c << " > " << b << " : " << (c>b ? "True\n":"False\n");
  cout << "So sanh phan so voi so thuc\n";
  cout << a << " == " << c << " : " << (a==c ? "True\n":"False\n");
  cout << a << " != " << c << " : " << (a!=c ? "True\n":"False\n");
  cout << a << " <= " << c << " : " << (a<=c ? "True\n":"False\n");
  cout << a << " >= " << c << " : " << (a>=c ? "True\n":"False\n");
  cout << a << " < " << c << " : " << (a<c ? "True\n":"False\n");
  cout << a << " > " << c << " : " << (a>c ? "True\n":"False\n");
  return 0;
}
