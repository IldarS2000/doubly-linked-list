#pragma once

#include <iostream>

template <typename T>
class list
{
  using valueType = T;

private:
  struct Node
  {
    T data;
    Node* next;
    Node* prev;

    Node();
    Node(const T&);
  } *head, *tail;
  size_t size;
public:
  list();
  ~list();

  void clear();

  list(const list&);
  list& operator=(const list&);

  void push_back(const T&);
  void push_front(const T&);
  void pop_back();
  void pop_front();

  T front() const;
  T back() const;

  size_t length() const;
  bool empty() const;

  template <typename T>
  friend std::ostream& operator<<(std::ostream& out, const list<T>& list);
};

template <typename T>
list<T>::Node::Node()
{
  next = nullptr;
  prev = nullptr;
  data = T();
}

template <typename T>
list<T>::Node::Node(const T& data)
{
  next = nullptr;
  prev = nullptr;
  this->data = data;
}

template <typename T>
list<T>::list()
{
  head = nullptr;
  tail = nullptr;
  size = 0;
}

template <typename T>
list<T>::~list()
{
  clear();
}

template <typename T>
void list<T>::clear()
{
  while (head) {
    pop_back();
  }
  size = 0;
}

// implementation in developing
template <typename T>
list<T>::list(const list<T>&)
{

}

// implementation in developing
template <typename T>
list<T>& list<T>::operator=(const list<T>&)
{
  return *this;
}

template <typename T>
void list<T>::push_back(const T& data)
{
  if (head) {
    Node* temp = new Node(data);

    temp->next = head;
    head->prev = temp;

    head = temp;
  }
  else {
    head = new Node(data);
    tail = head;
  }
  ++size;
}

template <typename T>
void list<T>::push_front(const T& data)
{
  if (tail) {
    Node* temp = new Node(data);

    temp->prev = tail;
    tail->next = temp;

    tail = temp;
  }
  else {
    tail = new Node(data);
    head = tail;
  }
  ++size;
}

template <typename T>
void list<T>::pop_back()
{
  Node* temp = head;
  head = head->next;
  if (head) {
    head->prev = nullptr;
  }
  else {
    tail = nullptr;
  }
  delete temp;
  --size;
}

template <typename T>
void list<T>::pop_front()
{
  Node* temp = tail;
  tail = tail->prev;
  if (tail) {
    tail->next = nullptr;
  }
  else {
    head = nullptr;
  }
  delete temp;
  --size;
}

template <typename T>
T list<T>::front() const
{
  return tail->data;
}

template <typename T>
T list<T>::back() const
{
  return head->data;
}

template <typename T>
size_t list<T>::length() const
{
  return size;
}

template <typename T>
bool list<T>::empty() const
{
  return size == 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const list<T>& list)
{
  Node* temp = list.tail;
  if (temp) {
    out << '[';
    while (temp->prev) {
      out << temp->data << ", ";
      temp = temp->prev;
    }
    out << temp->data;
    out << ']';
  }

  return out;
}