#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* AND THUS START THE UTILS */

void pop(int * pointer, int size) {
  srand(time(NULL));
  int ctr;

    //init new pointer in order to not mess with given pointer
  int * p;
  p = pointer;
  for (ctr = 0; ctr < size; ctr++) {
    //I know this might throw off uniformity but it's simple and, I believe,
    //suitable for the purpose of just demoing sorting algos
    *p = rand() % 100;
    p++;
  }
}

void printArr(int * pointer, int size) {
  //init new pointer in order to not mess with given pointer
  int * p;
  p = pointer;

  int ctr;
  printf("[");

  //empty list shouldn't backspace b/c only char is "["
  int backspace;
  backspace = 0;

  //print each el @ pointer
  for (ctr = 0; ctr < size; ctr++) {
    printf("%d,", *p);
    p++;
    //if this runs >= 1 time, we should delete the final comma
    backspace++;
  }
  if (backspace) printf("\b]\n");
  else printf("]\n");
}

/* AND THUS END THE UTILS */

void bubbleSort(int * pointer, int size) {
  int runctr;
  int * pos;
  int posctr;
  for (runctr = 0; runctr < size - 1; runctr++) {
    pos = pointer;
    for (posctr = 1; posctr < size; posctr++) {
      if (*pos > *(pos + 1)) {
        int temp = *pos;
        *pos = *(pos + 1);
        *(pos + 1) = temp;
      }
      pos++;
    }
  }
}

int main() {
  int size = 10;
  int arr[10];
  pop(arr, size);
  printf("OG arr:\n\t");
  printArr(arr, size);

  printf("After bubbleSort:\n\t");
  bubbleSort(arr, size);
  printArr(arr, size);
}
