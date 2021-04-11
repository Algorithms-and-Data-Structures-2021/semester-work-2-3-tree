//
// Created by annas on 10.04.2021.
//
#pragma once
#ifndef SEMESTER_WORK_TEMPLATE_NODE_H
#define SEMESTER_WORK_TEMPLATE_NODE_H

#endif  //SEMESTER_WORK_TEMPLATE_NODE_H

struct two_three_node {
 private:
  int size;
  int key[2];
  two_three_node *first;
  two_three_node *second;
  two_three_node *third;
  two_three_node *parent;
//  SinglyNode(Element e, SinglyNode *ptr) : data{e}, next{ptr} {}

  bool find(int k) { // Этот метод возвращает true, если ключ k находится в вершине, иначе false.
    for (int i = 0; i < size; ++i) {
      if (key[i] == k) {
        return true;
      }
    }
      return false;
  }

  void swap(int &x, int &y) {
    int r = x;
    x = y;
    y = r;
  }

  void sort() { // Ключи в вершинах должны быть отсортированы
    if (size == 1) {
      return;}
    if (size == 2) {
      if (x > y) swap(x, y);
    }
  }

  void insert_to_node(int k) {  // Вставляем ключ k в вершину (не в дерево)
    key[size] = k;
    size++;
    sort();
  }

  void remove_from_node(int k) { // Удаляем ключ k из вершины (не из дерева)
    if (size >= 1 && key[0] == k) {
      auto new_element = *key[1];
      key[0] = new_element;
      delete [] new_element;
      size--;
    } else if (size == 2 && key[1] == k) {
       delete [] key[1]
      size--;
    }
  }

  void become_node2(int k, two_three_node *first_, two_three_node *second_) {  // Преобразовать в 2-вершину.
    key[0] = k;
    first = first_;
    second = second_;
    third = nullptr;
    parent = nullptr;
    size = 1;
  }

  bool is_leaf() { // Является ли узел листом; проверка используется при вставке и удалении.
    return (first == nullptr) && (second == nullptr) && (third == nullptr);
  }


 public:
  two_three_node (int k, two_three_node *first, two_three_node *second, two_three_node *third, two_three_node *parent):
      size(1), key{k, 0}, first(first), second(second), third(third), parent(parent) {}
};
