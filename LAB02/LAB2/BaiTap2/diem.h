class Diem {
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
  void TinhTien(float Goc, float DoDoi);
  void PhongTo(Diem goc, float ti_le);
  void ThuNho(Diem goc, float ti_le);
  void Quay(Diem goc, float goc_quay);
};

