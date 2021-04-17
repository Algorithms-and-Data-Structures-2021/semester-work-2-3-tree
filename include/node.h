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
    int key[3];
    TwoThreeNode *first{nullptr};
    TwoThreeNode *second{nullptr};
    TwoThreeNode *third{nullptr};
    TwoThreeNode *fourth{nullptr};
    TwoThreeNode *parent{nullptr};


    explicit TwoThreeNode (int k, TwoThreeNode *first_ = nullptr, TwoThreeNode *second_ = nullptr,
                                  TwoThreeNode *third_ = nullptr, TwoThreeNode *fourth_ = nullptr,
                                                                  TwoThreeNode *parent_ = nullptr);

    bool find(int k);

    void swap(int &x, int &y);

    void sort2(int &x, int &y);

    void sort3(int &x, int &y, int &z);

    void sort();

    void insert_to_node(int k);

    void remove_from_node(int k);

    void become_node2(int k, TwoThreeNode *first_, TwoThreeNode *second_);

    bool is_leaf();
  };
}