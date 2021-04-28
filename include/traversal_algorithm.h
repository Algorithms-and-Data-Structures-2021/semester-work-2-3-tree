//
// Created by Marcusfam on 18.04.2021.
//

#pragma once

#include <ostream>

#include "node.h"

namespace itis {

  struct TraversalAlgorithm { // класс для вывода нашего 2-3 дерева, взят у Рамиля
    virtual ~TraversalAlgorithm() = default;

    virtual void Print(std::ostream &os, TwoThreeNode *node) const = 0;
  };

  struct BreadthFirstTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, TwoThreeNode *node) const override;
  };
}