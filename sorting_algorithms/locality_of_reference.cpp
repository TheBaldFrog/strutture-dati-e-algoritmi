#include <ctime>
#include <iostream>

/*
Program to demonstrate the concept of locality.
https://en.wikipedia.org/wiki/Locality_of_reference

Calculating the sum of all elements of 40'000 x 40'000 matrix in two ways:
1. Row by row
2. Column by column

The second method is WAY slower than the first because of locality of reference
and how the matrix (represented by array) is layed out in memory.

-------------

Results on my machine with 40'000 x 40'000 matrix:
$ ./locality_of_reference
Init...
Time taken for initialization: 6 seconds.
Start test with locality...
Result: 3200000000
Time taken with locality: 4 seconds.
Start test without locality...
Result: 3200000000
Time taken without locality: 58 seconds.

-------------

As you can tell, when the size of the matrix gets larger (more than 100 000 x
100 000), this difference becomes dramatic.
*/
int main() {
  const unsigned numRows = 40'000;
  const unsigned numCols = 40'000;

  int *arr = new int[numRows * numCols];

  std::time_t startOfInit = std::time(nullptr);

  std::cout << "Init...\n";
  // initialize all values with 2
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      arr[i * numRows + j] = 2;
    }
  }

  std::cout << "Time taken for initialization: "
            << std::time(nullptr) - startOfInit << " seconds.\n";

  // -----------------
  std::cout << "Start test with locality...\n";

  std::time_t startTestWithLocality = std::time(nullptr);
  unsigned long long sum = 0;
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      sum += arr[i * numCols + j];
    }
  }

  std::cout << "Result: " << sum << std::endl;
  std::cout << "Time taken with locality: "
            << std::time(nullptr) - startTestWithLocality << " seconds.\n";

  // -----------------

  std::cout << "Start test without locality...\n";
  sum = 0;
  std::time_t startTestWithoutLocality = std::time(nullptr);
  for (int i = 0; i < numCols; i++) {
    for (int j = 0; j < numRows; j++) {
      sum += arr[j * numRows + i];
    }
  }

  std::cout << "Result: " << sum << std::endl;
  std::cout << "Time taken without locality: "
            << std::time(nullptr) - startTestWithoutLocality << " seconds.\n";

  return 0;
}