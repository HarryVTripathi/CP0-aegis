#include <iostream>

class Node
{
  public:

  Node* next;
  int value;

  Node(int val)
  {
    value = val;
    next = NULL;
  }
};

class LinkedList
{
  public:

  Node* head;
  LinkedList()
  {
    head = NULL;
  }

  void Insert(int value, int position)
  {
    Node* newNode = new Node(value);
    if (head == NULL) {
      head = newNode;
    } else if (position == 1) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* traverser = head;

      while(--position > 1 && traverser->next != NULL) {
        traverser = traverser->next;
      }
      newNode->next = traverser->next;
      traverser->next = newNode;
    }
  }

  void Print()
  {
    Node* traverser = head;

    while (traverser != NULL)
    {
      std::cout << traverser->value << " ->  ";
      traverser = traverser->next;
    }
  }
};

int main()
{
  int N;
  std::cout << "Enter the number of nodes" << std::endl;
  std::cin >> N;

  LinkedList* l = new LinkedList();
  l->Insert(4, 1);
  l->Insert(5, 1);
  l->Insert(7, 1);
  l->Insert(6, 1);
  l->Print();
  std::cout << std::endl;


  l->Insert(9, 3);
  l->Print();
  std::cout << std::endl;


  l->Insert(1, 2);
  l->Print();
  std::cout << std::endl;

  l->Insert(13, 23);
  l->Print();
  std::cout << std::endl;
  return 0;
}