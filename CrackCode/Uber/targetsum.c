#include <stdio.h>

int targetSum(int array[], int size, int target) {
  //sort(array); // sort array if not already sorted. 
  int i=0, j=size-1;
  while (i<j) {
    int sum = array[i] + array[j];
    if (sum == target) {
      return 1;
    } else if (sum > target) {
      j--;
    } else { 
      i++;
    }
  }
  return 0;
}

int main () {

  int array[] = {-3, -2, 6, 8, 10, 12};
  int target = 3;
  printf("Target sum exists: %d\n", targetSum(array, sizeof(array)/sizeof(array[0]), target));
}
