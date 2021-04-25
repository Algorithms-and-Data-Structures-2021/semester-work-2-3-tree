# 2-3 Tree

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml)

**_Измените status badge сверху для отображения статуса сборки вашего проекта._**

`Actions > CMake > ... > Create status badge`

_Краткое описание семестрового проекта:_

- Структура данных: 2-3 Tree.
- Основная информация: Это структура данных является В-деревом, каждый узел которого имеет либо два потомка и одно поле, либо три потомка и два поля. 2-3 деревья сбалансированы(все листовые вершины находятся на одной высоте от корня дерева).
- Используется: Linux Kernel, Completely Fair Scheduler
- Операции: поиск ключа, добавление ключа, удаление ключа, слияние и разбиение ключа, очистка.
- Теоретическая сложность операций: поиск за `O(log(n))`, вставка за `O(log(n))` удаление за `O(log(n))`.
- Свойства: 
 1. Листовые вершины находятся на одном уровне и содержат 1 или 2 поля.
 2. Нелистовые вершины содержат одно поле и 2 поддерева или 2 поля и 3 поддереваю
 3. Данные отсортированы (по принципу двоичного дерева поиска). Значение первого поля строго больше наибольшего значения в левом поддереве и меньше или равно наименьшему значению в правом поддереве(или в центральном поддереве). Значение второго поля(если оно есть) строго больше наибольшего значения в центральном поддереве и меньше или равно, чем наименьшее значение в правом поддереве.

## Команда "Bubble Quasar"

| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Бровин Роман  | 57        |       lv.57 Boss      |
| Суреева Анна  | 43        |       lv.43 Hitman    |

**Девиз команды**
> _Мы, конечно, не Гринпис, но деревья обожаем._

## Структура проекта

_Здесь представлено описание основных частей семестрового проекта._


- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 4 ГБ.
5. Свободное дисковое пространство объемом ~ 3 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

_Инструкция по сборке проекта, генерации тестовых данных, запуска контрольных тестов и примеров работы._

#### Сборка проекта (Windows)


Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-2-3-tree
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-2-3-tree

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

_Формат хранения данных, выбранный для этого проекта, - .csv_ 

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

```shell
# переход в папку генерации набора данных
cd dataset
 
# Папка data, должна быть организавана следующим образом(если их нет создайте папки, как показано ниже):

```shell
dataset/data/
  insert/
    01/
      100.csv
      ...
      5000000.csv
    02/ ...
    03/ ...
    ...
    10/ ...
  search/
    01/
      100.csv
      ...
      5000000.csv
    ...
    10/ ...
  ...
```

По названию директории `/dataset/data/insert` можно понять, что здесь хранятся наборы данных для контрольных тестов по
**добавлению** элементов в структуру данных. Названия файлов `100.csv`. `5000000.csv` и т.д. хранят информацию о размере набора данных (т.е. количество элементов). 

#### Контрольные тесты (benchmarks)

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных, а так же стереть данные, которые вы получили в предыдущие разы, они находятся по пути semester-work-2-3-tree/benchmark/result/.

**Примечание**. Ссылка на архив с набором данных, который при необходимости можно скачать.(https://drive.google.com/drive/folders/15mQac1_GYA5MiZmsx76E67E3ZXS56c0G?usp=sharing).

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `benchmark_insert.cpp`    | поиск элементов по случайному индексу   | _время_         |
| `benchmark_remove.cpp`    | добавление элементов в структуру данных | _время_         |
| `benchmark_search.cpp`    | добавление элементов в структуру данных | _время_         |


##### Примеры запуска

_Для запуска просто нажмите run benchmark_<insert or remove or search>.cpp._


## Источники

https://habr.com/ru/post/303374/
https://neerc.ifmo.ru/wiki/index.php?title=2-3_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE#.D0.A1.D0.BC._.D1.82.D0.B0.D0.BA.D0.B6.D0.B5
https://ru.qaz.wiki/wiki/2%E2%80%933_tree
https://www.youtube.com/watch?v=PjlbovFEs0Y
https://medium.com/nuances-of-programming/%D0%B2%D1%81%D0%B5-%D1%87%D1%82%D0%BE-%D0%BD%D1%83%D0%B6%D0%BD%D0%BE-%D0%B7%D0%BD%D0%B0%D1%82%D1%8C-%D0%BE-%D0%B4%D1%80%D0%B5%D0%B2%D0%BE%D0%B2%D0%B8%D0%B4%D0%BD%D1%8B%D1%85-%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B0%D1%85-%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D1%85-d750444a77ec

