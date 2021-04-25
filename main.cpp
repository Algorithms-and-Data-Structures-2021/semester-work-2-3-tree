#include <iostream>

#include "data_structure.hpp"
#include "traversal_algorithm.h"

using namespace itis;
using namespace std;

int main(int argc, char *argv[]) {
  // здесь проводились тесты дерева
  TwoThreeTree tree;

  // делаем вставку 4 элементов в пустое дерево
  for(int i = 1; i < 5; i++){
    tree.Insert(i);
  }

  // удаляем 3 элемента
  tree.Remove(2);
  tree.Remove(4);
  tree.Remove(3);

  // печатаем наше дерево(правда в нем всего одна вершина)
  TraversalAlgorithm *algorithm = new BreadthFirstTraversalAlgorithm;

  std::cout << "Level-order (BFS): ";
  tree.Traverse(*algorithm);
  std::cout << std::endl;

  delete [] algorithm;

  for (int index = 0; index < argc; index++) {
    cout << index << ": " << argv[index] << endl;
  }
  return 0;
}