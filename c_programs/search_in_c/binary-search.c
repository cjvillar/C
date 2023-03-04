#include <stdio.h>
#include <ctype.h>

int binarySearch(int array[], int x, int low, int high);

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(array) / sizeof(array[0]);
  int x;
  printf("Enter number to be found: \n");
  scanf("%i", &x);
  if (isalnum(x))
  {
    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
      printf("Not found\n");
    else
      printf("Element is found at index %d\n", result);
  }
  else
  {
     printf("Please enter a numer\n");
  }
}


int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

