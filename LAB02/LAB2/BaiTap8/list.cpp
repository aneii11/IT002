#include "list.h"

List::List(): size(0), head(nullptr){}

void List::Add(double value){
  Node *new_node = new Node;
  new_node->value = value;
  new_node->next =  nullptr;
  if(size == 0 || head == nullptr){
    head = new_node;
    size++;
  }
  else{
    Node *last = head;
    for(int i=1;i<size;i++){
      last = last->next;
    }
    last->next = new_node;
    size++;
  }
}

bool List::Delete(double value){
  Node *curr = head;
  Node *prev = nullptr;
  for(int i=1;i<size && curr->value != value && curr->next != nullptr;i++){
    prev = curr;
    curr = curr->next;
  }
  if(curr == head && value == curr->value){
    head = head->next;
    delete curr;
    size--;
    return 1;
  }
  if(curr != nullptr && curr->value == value){
    prev->next = curr->next;
    delete curr;
    size--;
    return 1;
  }
  return 0;
}

void List::Set(unsigned int index, double value){
  if (index >= size)
    return;
  Node *curr = head;
  for(int i=0;i<size && i != index;i++){
    if(curr->next == nullptr)
      break;
    curr = curr->next;
  }
  if(curr != nullptr){
    curr->value = value;
  }
}

double List::Get(unsigned int index){
  Node *curr = head;
  for(int i=0;i<size && i != index;i++){
    if(curr->next == nullptr)
      break;
    curr = curr->next;
  }
  if(curr != nullptr)
    return curr->value;
  return 0xDEADBEEF;
}

unsigned int List::Size(){return size;}
