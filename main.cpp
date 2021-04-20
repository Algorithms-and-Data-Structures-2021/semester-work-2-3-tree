#include <iostream>

#include "data_structure.hpp"
#include "traversal_algorithm.h"

using namespace itis;
using namespace std;

int main(int argc, char *argv[]) {
  TwoThreeTree tree;

  for(int i = 1; i < 20; i++){
    tree.Insert(i);
  }
  cout << tree.Search(21) << endl;

  TraversalAlgorithm *algorithm = new BreadthFirstTraversalAlgorithm;

  std::cout << "Level-order (BFS): ";
  tree.Traverse(*algorithm);
  std::cout << std::endl;

  delete algorithm;

  for (int index = 0; index < argc; index++) {
    cout << index << ": " << argv[index] << endl;
  }
  return 0;
}