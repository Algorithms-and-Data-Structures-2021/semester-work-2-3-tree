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
      auto input_file = ifstream(path + "/"+ "search/" + folder + "/" + file + ".csv");
      cout << (path + "/"+ "search/" + folder + "/" + file) << endl;
      if (input_file) {
        while (line != "") {
          getline(input_file, line);
          if (line == "") {
            break;
          }
          tree.Insert(stoi(line));
        }
      }
      input_file.close();

      line = "1";
      input_file = ifstream(path + "/"+ "search/" + folder + "/" + file + ".csv");
      const auto time_point_before_search = chrono::steady_clock::now();
      // здесь находится участок кода, время которого необходимо замерить

      if (input_file) {
        while (line != "") {
          getline(input_file, line);
          if (line == "") {
            break;
          }
          tree.Search(stoi(line));
        }
      }
      input_file.close();

      const auto time_point_after_search = chrono::steady_clock::now();
      const auto time_diff_search = time_point_after_search - time_point_before_search;
      const auto time_elapsed_ns_search = chrono::duration_cast<chrono::nanoseconds>(time_diff_search).count();
      cout << time_elapsed_ns_search << endl;

      tree.Clear();
    }
  }
  return 0;
}