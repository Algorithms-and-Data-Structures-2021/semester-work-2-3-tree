//
// Created by Marcusfam on 18.04.2021.
//

#ifndef SEMESTER_WORK_TEMPLATE_TRAVERSAL_ALGORITHM_H
#define SEMESTER_WORK_TEMPLATE_TRAVERSAL_ALGORITHM_H

#endif  //SEMESTER_WORK_TEMPLATE_TRAVERSAL_ALGORITHM_H

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