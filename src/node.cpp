//
// Created by annas on 14.04.2021.
//
#include "node.h"

namespace itis {

  TwoThreeNode::TwoThreeNode(int k, TwoThreeNode* p) : size(1), key{k, 0}, parent{p} {}

  bool TwoThreeNode::find(int k) {  // Этот метод возвращает true, если ключ k находится в вершине, иначе false.
    for (int i = 0; i < size; ++i) {
      if (key[i] == k) {
        return true;
      }
    }
    return false;
  }

  void TwoThreeNode::swap(int &x, int &y) {
    int r = x;
    x = y;
    y = r;
  }

  void TwoThreeNode::sort() {  // Ключи в вершинах должны быть отсортированы
    if (size == 1) {
      return;
    }
    if (size == 2) {
      if (key[0] > key[1]) {
        swap(key[0], key[1]);
      }
    }
  }

  void TwoThreeNode::insert_to_node(int k) {  // Вставляем ключ k в вершину (не в дерево)
    key[size] = k;
    size++;
    sort();
  }

  void TwoThreeNode::remove_from_node(int k) {  // Удаляем ключ k из вершины (не из дерева)
    if (size >= 1 && key[0] == k) {
      key[0] = key[1];
      size--;
    } else if (size == 2 && key[1] == k) {
      size--;
    }
  }

  void TwoThreeNode::become_node2(int k, TwoThreeNode *first_, TwoThreeNode *second_) {  // Преобразовать в 2-вершину.
    key[0] = k;
    first = first_;
    second = second_;
    third = nullptr;
    parent = nullptr;
    size = 1;
  }

  bool TwoThreeNode::is_leaf() {  // Является ли узел листом; проверка используется при вставке и удалении.
    return (first == nullptr) && (second == nullptr) && (third == nullptr);
  }
};