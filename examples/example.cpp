//
// Created by Marcusfam on 25.04.2021.
//

#include <iostream>

#include "data_structure.hpp"
#include "traversal_algorithm.h"

using namespace std;
using namespace itis;

int main() {

  // здесь проводились тесты дерева
  TwoThreeTree tree;

  // делаем вставку 4 элементов в пустое дерево(вставляем 1, 2, 3, 4)
  for (int i = 1; i < 5; i++) {
    tree.Insert(i);
  }

  // ищем в дереве вершины с ключами 2 и 6, если не нащлось, то вернет 0
  cout << tree.Search(2) << endl;
  cout << tree.Search(6) << endl;

  // удаляем 2 элемента, если элемент не найден, то ничего не произойдет
  tree.Remove(2);
  tree.Remove(6);

  // печатаем наше дерево (учтите, что у кажой вершины может быть два ключа, если на втором месте стоит ноль,
  // значит второй ключ отсутствует
  TraversalAlgorithm *algorithm = new BreadthFirstTraversalAlgorithm;

  std::cout << "Level-order (BFS): ";
  tree.Traverse(*algorithm);
  std::cout << std::endl;

  delete[] algorithm;

  // очищаем дерево
  tree.Clear();
  return 0;
}