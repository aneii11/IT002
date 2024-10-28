#include "node.h"

class List{
private: 
  Node *head;
  unsigned int size;
public:
  List();
  void Add(double value);
  bool Delete(double value);
  void Set(unsigned int index, double value);
  double Get(unsigned int index);
  unsigned int Size();
};
