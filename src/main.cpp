#include<iostream>
#include<string>

template<typename T>
struct Node {
  T value;
  Node<T>* next = nullptr;
};

int32_t main(int argc, char* argv[])
{
  Node<int32_t> head;
  for (int i = 0; i < 10; ++i)
  {
    Node<int32_t>* node = new Node<int32_t>();
    node->value = i;
    if (head.next == nullptr) {
      head.next = node;
    } else {
      Node<int32_t>* current = head.next;
      while(current->next != nullptr) {
        current = current->next;
      }
      current->next = node;
    }
  }

  Node<int32_t>* current = head.next;
  while (current)
  {
    std::cout << current->value << std::endl;
    current = current->next;
  }
  Node<int32_t> prev = nullptr;
  current = head.next;
  while (current) {
    prev = current;
    current = current->next;
  }
  
  int i = 0;
  i ++;
  std::cout << "hello world" << std::endl;   
}