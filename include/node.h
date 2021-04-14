//
// Created by annas on 10.04.2021.
//
#pragma once
#ifndef SEMESTER_WORK_TEMPLATE_NODE_H
#define SEMESTER_WORK_TEMPLATE_NODE_H

#endif  //SEMESTER_WORK_TEMPLATE_NODE_H

namespace itis {

  struct TwoThreeNode {
    // private:
    int size;
    int key[2];
    TwoThreeNode *first{nullptr};
    TwoThreeNode *second{nullptr};
    TwoThreeNode *third{nullptr};
    TwoThreeNode *parent{nullptr};

    explicit TwoThreeNode (int key, TwoThreeNode *p = nullptr);

    bool find(int k);

    void swap(int &x, int &y);

    void sort();

    void insert_to_node(int k);

    void remove_from_node(int k);

    void become_node2(int k, TwoThreeNode *first_, TwoThreeNode *second_);

    bool is_leaf();

//    TwoThreeNode(int k) : size(1), key{k, 0}, first(nullptr), second(nullptr), third(nullptr), parent(nullptr) {}
//
//    TwoThreeNode(int k, TwoThreeNode *first, TwoThreeNode *second, TwoThreeNode *third, TwoThreeNode *parent)
//        : size(1), key{k, 0}, first(first), second(second), third(third), parent(parent) {}

    //  explicit two_three_node( int key[2], two_three_node *p = nullptr);

    //  friend two_three_tree *split(two_three_node *item); // Метод для разделение вершины при переполнении;
    //  friend two_three_node *insert(two_three_node *p, int k); // Вставка в дерево;
    //  friend two_three_node *search(two_three_node *p, int k); // Поиск в дереве;
    //  friend two_three_node *search_min(two_three_node *p); // Поиск минимального элемента в поддереве;
    //  friend two_three_node *merge(two_three_node *leaf); // Слияние используется при удалении;
    //  friend two_three_node *redistribute(two_three_node *leaf); // Перераспределение также используется при удалении;
    //  friend two_three_node *fix(two_three_node *leaf); // Используется после удаления для возвращения свойств дереву (использует merge или redistribute)
    //  friend two_three_node *remove(two_three_node *p, int k);
  };
}