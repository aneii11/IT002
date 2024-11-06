#include "ngaythangnam.cpp"

int main (int argc, char *argv[]) {
  NgayThangNam A(31,12,2012);
  NgayThangNam B;
  int so_ngay;
  cin >> B;
  cin >> so_ngay;
  cout << "A + " << so_ngay << " = " << A + so_ngay << "\n";
  cout << "A - " << so_ngay << " = " << A - so_ngay << "\n";
  cout << "A - B = " << A - B << "\n";

  NgayThangNam C = A;
  C = A++;
  cout << "C = A++:\n";
  cout << "A = " << A << "\nC = " << C << "\n";
  C = ++A;
  cout << "C = ++A:\n";
  cout << "A = " << A << "\nC = " << C << "\n";
  C = A--;
  cout << "C = A--:\n";
  cout << "A = " << A << "\nC = " << C << "\n";
  C = --A;
  cout << "C = --A:\n";
  cout << "A = " << A << "\nC = " << C << "\n";

  cout << "A == B: " << (A == B ? "True\n" : "False\n");
  cout << "A != B: " << (A != B ? "True\n" : "False\n");
  cout << "A >= B: " << (A >= B ? "True\n" : "False\n");
  cout << "A <= B: " << (A <= B ? "True\n" : "False\n");
  cout << "A > B: " << (A > B ? "True\n" : "False\n");
  cout << "A < B: " << (A < B ? "True\n" : "False\n");
  return 0;
}
