#include <iostream>
#include <algorithm> // std::swap
#include <vector>

// #define DEBUG

#include "utils.cpp"
#include "sorts/bubble.cpp"
#include "sorts/selection.cpp"
#include "sorts/insertion.cpp"
#include "sorts/shell.cpp"
#include "sorts/quick.cpp"
#include "sorts/merge.cpp"

using namespace std;

// func :: vector<int>& -> void  <=>  void (*sort_func)(std::vector<int>&)
void test_sort(void (*sort_func)(std::vector<int>&), string func_name)
{
  vector<int> vect{5,1,5,3,7,9,4,2};
  sort_func(vect);
  cout << func_name;
  for (int x : vect) { cout << x << " "; }
  cout << endl;
}

int main() {
  // vector<int> vect(3, 0); // [0, 0, 0]
  cout << "initial array: " << "5 1 5 3 7 9 4 2" << endl;
  // swap(vect[0], vect[1]); // test swap
  test_sort(quick_sort, "quick sort: \t");
  test_sort(merge_sort, "merge sort: \t");
  test_sort(shell_sort, "shell sort: \t");
  test_sort(bubble_sort, "bubble sort: \t");
  test_sort(insert_sort, "insertion sort: ");
  test_sort(selection_sort, "selection sort: ");
}
