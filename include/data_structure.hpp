#pragma once

#include "node.h"
#include "traversal_algorithm.h"
// Заголовочный файл с объявлением структуры данных

namespace itis {

  struct TwoThreeTree{

    void Clear(); // Очистка дерева

    void Insert(int key);// Вставка в дерево;

    TwoThreeNode *Search(int key); // Поиск в дереве;

    void *Remove(int key); // Удаление ключа из дерева

    TwoThreeNode *root(); // Возвращает корень дерева

    int Height(); // Возвращает высоту дерева

    void Traverse(const TraversalAlgorithm &algorithm) const; // Проходит по дереву в ширину


   private:
    TwoThreeNode *root_{nullptr}; // Корень 2-3 дерева

    TwoThreeNode *merge(TwoThreeNode *leaf); // Слияние используется при удалении;

    TwoThreeNode *redistribute(TwoThreeNode *leaf); // Перераспределение также используется при удалении;

    TwoThreeNode *fix(TwoThreeNode *leaf); // Используется после удаления для возвращения свойств дереву (использует merge или redistribute)

    TwoThreeNode *split(TwoThreeNode *item); // Метод для разделение вершины при переполнении;

    void insert(int key, TwoThreeNode *node); // Вспомогательная функция, используется при вставке

    void clear(TwoThreeNode *node); // Вспомогательная функция, используется при очистке

    TwoThreeNode *search(int key, TwoThreeNode *node); // Вспомогательная функция, используется при поиске

    TwoThreeNode *remove(int key, TwoThreeNode *node); // Вспомогательная функуция, используется при удалении

    int height(TwoThreeNode *node); // Вспомогательная функция, используется при вычислении высоты

    TwoThreeNode *findMin(TwoThreeNode *p); // Поиск узла с минимальным значением ключа
  };
}