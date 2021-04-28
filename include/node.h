//
// Created by annas on 10.04.2021.
//
#pragma once

namespace itis {

  struct TwoThreeNode {
    int size; // количество ключей в узле
    int key_[3]; // массив с ключами
    TwoThreeNode *first{nullptr}; // ссылка на первого ребенка
    TwoThreeNode *second{nullptr}; // ссылка на второго ребенка
    TwoThreeNode *third{nullptr}; // ссылка на третьего ребенка
    TwoThreeNode *fourth{nullptr}; // ссылка на четвертого ребенка
    TwoThreeNode *parent{nullptr}; // ссылка на родителя


    explicit TwoThreeNode (int key, TwoThreeNode *first_ = nullptr, TwoThreeNode *second_ = nullptr,
                                  TwoThreeNode *third_ = nullptr, TwoThreeNode *fourth_ = nullptr,
                                                                  TwoThreeNode *parent_ = nullptr);

    bool find(int key); // поиск ключа в вершине

    void swap(int &x, int &y); // вспомогательная операция, используется в сортировке

    void sort2(int &x, int &y); // вспомогательная операция, используется в сортировке

    void sort3(int &x, int &y, int &z); // вспомогательная операция, используется в сортировке

    void sort(); // сортировка ключей в вершине

    void insert_to_node(int key); // вставка ключа в вершину

    void remove_from_node(int key); // удаление ключа из вершины

    void become_node2(int key, TwoThreeNode *first_, TwoThreeNode *second_); // преобразование в 2-вершину

    bool is_leaf(); // является ли вершина листом
  };
}