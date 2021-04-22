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
  const auto output_path = string(kProjectPath) + "/benchmark/result/benchmark_remove_result.csv";
  cout << "Path to the 'dataset/' folder: " << path << endl;

  // Tip 2: для перевода строки в число можете использовать функцию stoi (string to integer)

  // работа с набором данных
  vector <string> folders = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};
  vector <string> files = {"100", "500", "1000", "5000", "10000", "50000", "100000", "500000", "1000000", "5000000"};
  TwoThreeTree tree;

  for (string file : files) { // Проходим по всем 10 .csv файлам
    for (string folder : folders) { // Проходим по всем 10 папкам с файлами
      for (int i = 1; i < 11; i++) { // Запускаем замерку времени 10 раз
        string line = "1";
        auto input_file = ifstream(path + "/" + "remove/" + folder + "/" + file + ".csv");
        cout << (path + "/" + "remove/" + folder + "/" + file) << endl;
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
        input_file = ifstream(path + "/" + "remove/" + folder + "/" + file + ".csv");
        const auto time_point_before_remove = chrono::steady_clock::now();

        // здесь находится участок кода, время которого необходимо замерить
        if (input_file) {
          while (line != "") {
            getline(input_file, line);
            if (line == "") {
              break;
            }
            tree.Remove(stoi(line));
          }
        }

        const auto time_point_after_remove = chrono::steady_clock::now();
        const auto time_diff_remove = time_point_after_remove - time_point_before_remove;
        const auto time_elapsed_ns_remove = chrono::duration_cast<chrono::nanoseconds>(time_diff_remove).count();
        cout << time_elapsed_ns_remove << endl;

        tree.Clear();
        input_file.close();

        // Открываем файл для записи и вносим полученые данные
        auto output_file = fstream(output_path, ios::app);
        output_file << folder << "," << file << "," <<  i << "," << time_elapsed_ns_remove << endl;
        output_file.close();
      }
    }
  }
  return 0;
}