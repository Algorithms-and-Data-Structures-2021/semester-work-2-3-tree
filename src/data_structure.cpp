#include "data_structure.hpp"
// файл с определениями

namespace itis {

  TwoThreeNode *TwoThreeTree::insert(int k, TwoThreeNode *p) { // вставка ключа k в дерево с корнем p; всегда возвращаем корень дерева, т.к. он может меняться
    if (root_ == nullptr){
      root_ = new TwoThreeNode(k);
    }// если дерево пусто, то создаем первую 2-3-вершину (корень)

    if (p->is_leaf()) {
      p->insert_to_node(k);
    } else if (k <= p->key[0]) {
      insert(k, p->first);
    } else if ((p->size == 1) || ((p->size == 2) && k <= p->key[1])) {
      insert(k, p->second);
    } else {
      insert(k, p->third);
    }

    return split(p);
  }
  
  TwoThreeNode *TwoThreeTree::search(int key, TwoThreeNode *node) const {

  }
  void TwoThreeTree::clear(TwoThreeNode *node){

  }
  void TwoThreeTree::remove(int key, TwoThreeNode *node){

  }
  TwoThreeNode *TwoThreeTree::findMin(TwoThreeNode *node) const {

  }

  // здесь должны быть определения методов вашей структуры

}  // namespace itis