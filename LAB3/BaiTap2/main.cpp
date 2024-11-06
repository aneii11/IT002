#include "sophuc.cpp"

int main (int argc, char *argv[]) {
  SoPhuc a, b;
  float c;
  cin >> a >> b;
  cin >> c;
  cout << "Thuc hien phep tinh so phuc voi so phuc\n";
  cout << a << " + " << b << " = " << a+b << "\n";
  cout << a << " - " << b << " = " << a-b << "\n";
  cout << a << " * " << b << " = " << a*b << "\n";
  cout << a << " / " << b << " = " << a/b << "\n";
  cout << "Thuc hien phep tinh so thuc voi so phuc\n";
  cout << c << " + " << b << " = " << c+b << "\n";
  cout << c << " - " << b << " = " << c-b << "\n";
  cout << c << " * " << b << " = " << c*b << "\n";
  cout << c << " / " << b << " = " << c/b << "\n";
  cout << "Thuc hien phep tinh so phuc voi so thuc\n";
  cout << a << " + " << c << " = " << a+c << "\n";
  cout << a << " - " << c << " = " << a-c << "\n";
  cout << a << " * " << c << " = " << a*c << "\n";
  cout << a << " / " << c << " = " << a/c << "\n";
  cout << "So sanh so phuc voi so phuc\n";
  cout << a << " == " << b << " : " << (a==b ? "True\n":"False\n");
  cout << a << " != " << b << " : " << (a!=b ? "True\n":"False\n");
  cout << "So sanh so thuc voi so phuc\n";
  cout << c << " == " << b << " : " << (c==b ? "True\n":"False\n");
  cout << c << " != " << b << " : " << (c!=b ? "True\n":"False\n");
  cout << "So Sanh so phuc voi so thuc\n";
  cout << a << " == " << c << " : " << (a==c ? "True\n":"False\n");
  cout << a << " != " << c << " : " << (a!=c ? "True\n":"False\n");
  return 0;
}

