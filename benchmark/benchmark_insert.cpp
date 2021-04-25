//
// Created by Marcusfam on 20.04.2021.
//
#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>       // vector

// подключаем структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  // пути для файлов с входными данными и файла, куда мы запишем полученный результат
  const auto input_path = string(kDatasetPath);
  const auto output_path = string(kProjectPath) + "/benchmark/result/benchmark_insert_result.csv";

  // два массива с номером папки и количеством входных данных(по совместительству это название файлов в каждой из папок)
  vector <string> folders = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};
  vector <string> files = {"100", "500", "1000", "5000", "10000", "50000", "100000", "500000", "1000000", "5000000"};
  TwoThreeTree tree;

  for (string file : files) { // Проходим по всем 10 .csv файлам
    for (string folder : folders) { // Проходим по всем 10 папкам с файлами
      for (int i = 1; i < 11; i++) { // Запускаем замерку времени 10 раз

        string line = "1"; // сюда будут считываться данные из .csv файла
        auto input_file = ifstream(input_path + "/" + "insert/" + folder + "/" + file + ".csv"); // файл с входными данными
        auto time_diff_insert = chrono::nanoseconds::zero(); // здесь будет храниться время, за которое прошла операция

        // работа с набором данных
        if (input_file) {
          while (line != "") {
            getline(input_file, line);
            if (line == "") {
              break;
            }

            // здесь находится участок кода, время которого необходимо замерить
            const auto time_point_before_insert = chrono::steady_clock::now();
            tree.Insert(stoi(line));
            const auto time_point_after_insert = chrono::steady_clock::now();
            time_diff_insert += time_point_after_insert - time_point_before_insert; // прибавляем полученное время к общему
          }
        }

        // преобразуем время в наносекунды, очищаем дерево, закрываем входной файл
        const auto time_elapsed_ns_insert = chrono::duration_cast<chrono::nanoseconds>(time_diff_insert).count();
        tree.Clear();
        input_file.close();

        // вывод пути до файла, из которого брали данные, и времени, за которое эти данные были обработаны
        cout << (input_path + "/" + "insert/" + folder + "/" + file) << endl;
        cout << time_elapsed_ns_insert << endl;

        // Открываем файл для записи и вносим полученые данные
        auto output_file = fstream(output_path, ios::app);
        output_file << folder << "," << file << "," << i << "," << time_elapsed_ns_insert << endl;
        output_file.close();
      }
    }
  }
  return 0;
}