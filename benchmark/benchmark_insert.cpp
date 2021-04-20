//
// Created by Marcusfam on 20.04.2021.
//
#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  // Tip 1: входные аргументы позволяют более гибко контролировать параметры вашей программы
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  // Tip 2: для перевода строки в число можете использовать функцию stoi (string to integer)

  // работа с набором данных
  vector <string> folders = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};
  vector <string> files = {"100", "500", "1000", "5000", "10000", "50000", "100000", "500000", "1000000", "5000000"};
  TwoThreeTree tree;
  for (string folder : folders) {
    for (string file : files) {
      string line = "1";
      auto input_file = ifstream(path + "/"+ "insert/" + folder + "/" + file + ".csv");
      cout << (path + "/"+ "insert/" + folder + "/" + file) << endl;
      const auto time_point_before_insert = chrono::steady_clock::now();
      // здесь находится участок кода, время которого необходимо замерить

      if (input_file) {
        while (line != "") {
          getline(input_file, line);
          if (line == "") {
            break;
          }
          tree.Insert(stoi(line));
        }
      }

      const auto time_point_after_insert = chrono::steady_clock::now();
      const auto time_diff_insert = time_point_after_insert - time_point_before_insert;
      const auto time_elapsed_ns_insert = chrono::duration_cast<chrono::nanoseconds>(time_diff_insert).count();
      cout << time_elapsed_ns_insert << endl;

      tree.Clear();
      input_file.close();
    }
  }
  return 0;
}