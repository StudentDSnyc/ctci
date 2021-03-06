#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
  this->head = NULL;
}

LinkedList::~LinkedList()
{
  Node* current = head;
  while (current != 0)
  { 
    Node* next = current->next;
    delete current;
    current = next;
  }
  head = NULL;
  std::cout << "List successfully deleted from memory" << std::endl;
}

void LinkedList::insert(int value)
{

  if (head == NULL)
  {
    head = new Node();
    tail = head;
    head->next = NULL;
    head->data = value;
  }
  else
  {
    tail->next = new Node();
    tail = tail->next;
    tail->data = value;
    tail->next = NULL;
  }

}

void LinkedList::createCycle()
{
  tail->next = head->next;  
}

void LinkedList::display()
{
  Node* temp;

  if (head == NULL)
  {
    return;
  }
  else
  {
    temp = head;
    while (temp != NULL)
    {
      std::cout << temp->data << ' ';
      temp = temp->next;
    }
    std::cout << std::endl;
  }

}