//
// Created by annas on 10.04.2021.
//
#pragma once
#ifndef SEMESTER_WORK_TEMPLATE_NODE_H
#define SEMESTER_WORK_TEMPLATE_NODE_H

#endif  //SEMESTER_WORK_TEMPLATE_NODE_H

namespace itis {

  struct TwoThreeNode {
    int size;
    int key[3];
    TwoThreeNode *first{nullptr};
    TwoThreeNode *second{nullptr};
    TwoThreeNode *third{nullptr};
    TwoThreeNode *fourth{nullptr};
    TwoThreeNode *parent{nullptr};


    explicit TwoThreeNode (int k, TwoThreeNode *first_ = nullptr, TwoThreeNode *second_ = nullptr,
                                  TwoThreeNode *third_ = nullptr, TwoThreeNode *fourth_ = nullptr,
                                                                  TwoThreeNode *parent_ = nullptr);

    bool find(int k); // поиск ключа в вершине

    void swap(int &x, int &y); // вспомогательная операция, используется в сортировке

    void sort2(int &x, int &y); // вспомогательная операция, используется в сортировке

    void sort3(int &x, int &y, int &z); // вспомогательная операция, используется в сортировке

    void sort(); // сортировка ключей в вершине

    void insert_to_node(int k); // вставка ключа в вершину

    void remove_from_node(int k); // удаление ключа из вершины

    void become_node2(int k, TwoThreeNode *first_, TwoThreeNode *second_); // преобразование в 2-вершину

    bool is_leaf(); // является ли вершина листом
  };
}