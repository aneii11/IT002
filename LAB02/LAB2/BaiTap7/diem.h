class Diem{
private: 
  float iHoanh;
  float iTung;
public:
  Diem();
  Diem(int Hoanh, int Tung);
  Diem(const Diem &x);
  void Xuat();
  float GetTungDo();
  float GetHoanhDo();
  void SetTungDo(float Tung);
  void SetHoanhDo(float Hoanh);
  friend bool SoSanhGoc(const Diem &a, const Diem &b, const Diem &c);
};
