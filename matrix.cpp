/**********************************
* Автор:    Карнаухов Фёдор       *
* Название: Обработка массивов    *
* Вариант:  7                     *
***********************************/

#include <iostream>

using namespace std;

int main() {

  const int maxSize = 20;
  const int minValue = -1000;
  const int maxValue = 1000;
  int matrixV[maxSize][maxSize];
  int matrixW[maxSize][maxSize];
  int rowCount;
  int columnCount;
  int removedIndex;

  if (!(cin >> rowCount >> columnCount) ||
      rowCount < 1 || rowCount > maxSize ||
      columnCount < 1 || columnCount > maxSize) {
      cout << "INVALID\n";
      return 1;
  }

  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
          if (!(cin >> matrixV[rowIndex][columnIndex]) ||
              matrixV[rowIndex][columnIndex] < minValue ||
              matrixV[rowIndex][columnIndex] > maxValue) {
              cout << "INVALID\n";
              return 1;
          }
      }
  }

  if (!(cin >> removedIndex) ||
      removedIndex < 1 ||
      removedIndex > rowCount ||
      removedIndex > columnCount) {
      cout << "INVALID\n";
      return 1;
  }

  int targetIndex = removedIndex - 1;

  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
          if (columnIndex > 0) {
              cout << " ";
          }
          cout << matrixV[rowIndex][columnIndex];
      }
      cout << "\n";
  }

  int newRowIndex = 0;

  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
      if (rowIndex == targetIndex) {
          continue;
      }

      int newColumnIndex = 0;

      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
          if (columnIndex == targetIndex) {
              continue;
          }

          matrixW[newRowIndex][newColumnIndex] = matrixV[rowIndex][columnIndex];
          ++newColumnIndex;
      }
      ++newRowIndex;
  }

  for (int rowIndex = 0; rowIndex < rowCount - 1; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < columnCount - 1; ++columnIndex) {
          if (columnIndex > 0) {
              cout << " ";
          }
          cout << matrixW[rowIndex][columnIndex];
      }
      cout << "\n";
  }
  return 0;
}