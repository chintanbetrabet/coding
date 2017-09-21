#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int *A, int i, int j) {
  int temp;
  temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

int Partition(int *A, int l, int r, int *count) {
  int i = l, j;
  for(j = l+1; j <= r; j++) {
    (*count)++;
    if(A[j]<A[l]) {
      i++;
      Swap(A, i, j);
    }
  }
  Swap(A, i, l);
  return i;
}

void QuickSort(int *A, int l, int r, int *count) {
  if(l < r) {
    int pivot;
    pivot = Partition(A, l, r, count);
    QuickSort(A, l, pivot-1, count);
    QuickSort(A, pivot+1, r, count);
  }
}

void RandomizedQuickSort(int *A, int l, int r, int *count) {
  if(l < r) {
    int pivot;
    pivot = l+(rand()%(r-l+1));
    Swap(A, pivot, l);
    pivot = Partition(A, l, r, count);
    RandomizedQuickSort(A, l, pivot-1, count);
    RandomizedQuickSort(A, pivot+1, r, count);
  }
}

void NextAssignment(int n, int *B) {
  int i;
  for(i = 0; i < n; i++) {
    B[i] = 1 - B[i];
    if(B[i]) break;
  }
}

int gcnt = 0;
int RecursiveAssignment(int *C, int n, int m, int *counts) {
  if(m) {
    int i;
    for(i = 0; i < m; i++) {
      RecursiveAssignment(C, n, m-1, counts);
      if(m & 1) Swap(C, i, m-1);
      else Swap(C, 0, m-1);
    }
  }
  else {
    gcnt++;
    int i;
    int D[n];
    for(i = 0; i < n; i++) D[i] = C[i];
    int count;
    count = 0;
    QuickSort(D, 0, n-1, &count);
    (counts[count-1])++;
  }
  return gcnt;
}

int RandomizedRecursiveAssignment(int *C, int n, int m, int *counts) {
  if(m) {
    int i;
    for(i = 0; i < m; i++) {
      RandomizedRecursiveAssignment(C, n, m-1, counts);
      if(m & 1) Swap(C, i, m-1);
      else Swap(C, 0, m-1);
    }
  }
  else {
    int i;
    int D[n];
    for(i = 0; i < n; i++) D[i] = C[i];
    int count;
    count = 0;
    RandomizedQuickSort(D, 0, n-1, &count);
    (counts[count-1])++;
  }
  return gcnt;
}

int main(int argc, char *argv[]) {
  printf( "This program seeks to print all possible worst cases for QuickSort\n");
  printf( "for the elements {1,2,...,n}\n");
  printf( "Usage ./%s <n>. n defaults to 8\n", argv[0]);
  int n = 8;
  if(argc > 1) {
    n = atoi(argv[1]);
    if(n < 5) n = 5;
    if(n > 20) printf("n=%d too large. Prepare to wait forever and get your screen or disk flooded.\n", n);
  }

  int i, A[n], B[n], C[n];
  for(i = 0; i < n; i++) {
    A[i] = i+1;
    B[i] = 0;
  }
  for(i = 0; i < (1 << n); i++) {
    int j, l, h;
    l = 0; h = n-1;
    for(j = 0; j < n; j++) C[j]=(B[j]?A[l++]:A[h--]);
    int count;
    count = 0;
    QuickSort(C, 0, n-1, &count);
    for(j = 0; j < n-1; j++) if(C[j]>C[j+1]) {
      printf("QuickSort error!\n");
      break;
    }
    printf(": Comparison Operations %d\n", count);
   
    
    NextAssignment(n, B);
  }
  printf( "Not all were worst cases, right? Were all possible worst cases for QuickSort covered?\n");

  /* Counting runtime frequencies for all permutations */
  int counts[(n*(n-1))/2];
  for(i=0; i<(n*(n-1))/2; i++) counts[i] = 0;
  RecursiveAssignment(C, n, n, counts);
  printf("Among total %d, %d were worst cases\n", gcnt, counts[(n*(n-1))/2-1]);
  for(i = 0; i < (n*(n-1))/2; i++) printf("x(%d)=%d; y(%d)=%d;\n", i+1, i+1, i+1, counts[i]);
  printf("plot(x,y); grid minor on; title \"No. of Permutations y requiring x comparisons in QuickSort on %d distinct elements\"; print -deps qsgraph%d.eps\n", n, n);
	for(i=0; i<(n*(n-1))/2; i++) printf("%d\n",counts[i] );	
  /* Counting runtime frequencies for random arrays */
  srand(time(0));
  for(i=0; i<(n*(n-1))/2; i++) counts[i] = 0;
  int repeats;
  repeats = 1000000;
  for(i = 0; i < repeats; i++) {
    int j;
    for(j = 0; j < n; j++) C[j] = rand();
    int count;
    count = 0;
    QuickSort(C, 0, n-1, &count);
    (counts[count-1])++;
  }
  printf("Among total %d, %d were worst cases: %g in %d\n", repeats, counts[(n*(n-1))/2-1], 1.0*counts[(n*(n-1))/2-1]*gcnt/repeats, gcnt);
  for(i = 0; i < (n*(n-1))/2; i++) printf("z(%d)=%d; w(%d)=%g;\n", i+1, i+1, i+1, 1.0*counts[i]*gcnt/repeats);
  printf("plot(z,w); grid minor on; title \"No. of Permutations w requiring z comparisons in QuickSort on %d distinct elements\"; print -deps qsgraphrandom%d.eps\n", n, n);

  /* Counting runtime frequencies of randomized QuickSort for all permutations */
  for(i=0; i<(n*(n-1))/2; i++) counts[i] = 0;
  RandomizedRecursiveAssignment(C, n, n, counts);
  printf("Among total %d, %d were worst cases\n", gcnt, counts[(n*(n-1))/2-1]);
  for(i = 0; i < (n*(n-1))/2; i++) printf("rx(%d)=%d; ry(%d)=%d;\n", i+1, i+1, i+1, counts[i]);
  printf("plot(x,y); grid minor on; title \"No. of Permutations ry requiring rx comparisons in QuickSort on %d distinct elements\"; print -deps rqsgraph%d.eps\n", n, n);
  return 0;
}


