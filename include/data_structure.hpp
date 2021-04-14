#pragma once

#include "node.h"
// Заголовочный файл с объявлением структуры данных

namespace itis {


  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct TwoThreeTree{

   private:
    TwoThreeNode *root_{nullptr};

    void clear(TwoThreeNode *node);
    TwoThreeNode *insert(int key, TwoThreeNode *node);
    void remove(int key, TwoThreeNode *node);
    TwoThreeNode *search(int key, TwoThreeNode *node) const;

    TwoThreeNode *findMin(TwoThreeNode *node) const;


    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.
   // создание дерева,



  };

}  // namespace itis