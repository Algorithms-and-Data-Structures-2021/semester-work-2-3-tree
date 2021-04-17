//
// Created by Marcusfam on 18.04.2021.
//

#include "traversal_algorithm.h"

#include <queue>

namespace itis {
  void BreadthFirstTraversalAlgorithm::Print(std::ostream &os, TwoThreeNode *node) const {
    std::queue<TwoThreeNode *> nodes_queue;
    nodes_queue.push(node);

    while (!nodes_queue.empty()) {
      const auto *curr_node = nodes_queue.front();
      nodes_queue.pop();

      os << curr_node->key[0]<<curr_node->key[1] << '\t';

      if (curr_node->first != nullptr) {
        nodes_queue.push(curr_node->first);
      }

      if (curr_node->second != nullptr) {
        nodes_queue.push(curr_node->second);
      }

      if (curr_node->third != nullptr) {
        nodes_queue.push(curr_node->third);
      }
    }
  }
}