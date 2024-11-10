#include "thoigian.cpp"

using namespace std;

int main (int argc, char *argv[]) {
  ThoiGian A;
  ThoiGian B;
  int D;
  cin >> A >> B;
  cin >> D;
  cout << A << " + " << B << " = " << A+B << "\n";
  cout << A << " + " << D << " = " << A+D << "\n";
  cout << D << " + " << A << " = " << D+A << "\n";
  cout << A << " - " << B << " = " << A-B << "\n";
  cout << A << " - " << D << " = " << A-D << "\n";
  cout << D << " - " << A << " = " << D-A << "\n";
  ThoiGian C = A++;
  cout << "C = A++:\nA = " << A << "\n";
  cout << "C = " << C << "\n";
  C = ++A;
  cout << "C = ++A:\nA = " << A << "\n";
  cout << "C = " << C << "\n";
  C = A--;
  cout << "C = A--:\nA = " << A << "\n";
  cout << "C = " << C << "\n";
  C = --A;
  cout << "C = --A:\nA = " << A << "\n";
  cout << "C = " << C << "\n";
  cout << "A == B: " << (A == B ? "True":"False") << "\n";
  cout << "A != B: " << (A != B ? "True":"False") << "\n";
  cout << "A <= B: " << (A <= B ? "True":"False") << "\n";
  cout << "A >= B: " << (A >= B ? "True":"False") << "\n";
  cout << "A > B: " << (A > B ? "True":"False") << "\n";
  cout << "A < B: " << (A < B ? "True":"False") << "\n";
  return 0;

}
