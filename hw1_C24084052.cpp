#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <map>
using namespace std;

template <class T>

T insertionSort(int counterArr[], int size) {

  // create another 2D array to store [row: index] and [column: numbers of 'c']
  int rowCounterArr[size][size + 1];
  for (int k = 0; k < size; k++) {
    for (int j = 0; j < size + 1; j++) {
      rowCounterArr[k][j] = 0;
    }
  }


  //--- trial 1: array map + pointer array ---
  // map <int*, int> rowMap;
  // int *arrPtr[size];
  // for (int i = 1; i <= Ssize; i++) {
  //   arrPtr[i - 1] = &counterArr[i - 1];
  //   rowMap[arrPtr[i - 1]] = i;
  // }


  //--- trial 2: vector make_pair() ---
  // vector <int> counterVec(counterArr, counterArr + size);
  // vector <pair <int, int>> vp;
  // for (int i = 0; i < size; i++) {
  //   vp.push_back(make_pair(counterVec[i], i + 1));
  // }


  // bind [row index] and [numbers of 'c'] together
  for (int i = 1; i <= size; i++) {
    rowCounterArr[i - 1][counterArr[i - 1]] = 1;    
  }

  // insertion sort for numbers of 'c' from large to small
  for (int i = 1; i < size; i++) {
    int value = counterArr[i];
    int preValue = i - 1;
    while (value > counterArr[preValue]) {
      counterArr[preValue + 1] = counterArr[preValue];
      preValue--;
      if (preValue < 0) {
        break;
      }
    }
    counterArr[preValue + 1] = value;
  }

  // print out the index after sorting
  while (true) {
    for (int j = 0; j < size + 1; j++) {
      for (int i = 0; i < size; i++) {
        if (rowCounterArr[i][counterArr[j]] == 1 && counterArr[j] != counterArr[j - 1]) {
          cout << i + 1 << " ";
        }
      }
    }
    break;
  }

  //--- trial 1: pointer ---
  // for (jnt i = 0; i < size; i++) {
  //   cout << rowMap[arrPtr[i]] << " " ;
  // }

  //--- trial 2: vector make_pair ---
  // for (int i = 0; i < vp.size(); i++) {
  //   cout << vp[i].first << '\t' << vp[i].second << endl;
  // }

}


int main() {

  // every executions could get different results
  double seed = time(NULL);
  srand(seed);

  int n;
  char charset[] = "abcde";
  cout << "Input the number 'n' to generate n*n array(n => 10~20): ";
  while (cin >> n) {
    string arr[n][n];
    if (n >= 10 && n <= 20) {

      // generate 'a'~'e' randomly
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          arr[i][j] = charset[rand() % 5];
          cout << arr[i][j] << "\t";
        }
        cout << "\n";
      }

      // calculate numbers of 'c' per row
      int row, col;
      int counter = 0;
      int counterArr[n];
      for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
          if (arr[row][col] == "c") {
            counter++;
          }
        }
        counterArr[row] = counter;
        cout << "Row" << row + 1 << '\t' << counter << endl;
        counter = 0;
      }

      // template for insertion sort
      insertionSort<void> (counterArr, n);

      break;

    } else {
      cout << "Please input the number between 10 and 20: ";
    }
  }

  system("pause");

  return 0;
  
}