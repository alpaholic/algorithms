////
////  quick.c
////  algorithms
////
////  Created by mindol on 2016. 11. 26..
////  Copyright © 2016년 mindol. All rights reserved.
////
//
//#include <stdio.h>
//#define SIZE 10
//
//void quicksort(int A[], int p, int r);
//int partition(int A[], int p, int r);
//void display(int A[], int n);
//
//int main(void) {
//    int A[] =  {31, 8, 48, 73, 11, 3, 20, 29, 65, 15};
//    display(A, SIZE);
//    quicksort(A, 0, SIZE-1);
//    display(A, SIZE);
//}
//
//void quicksort(int A[], int p, int r) {
//    int q;
//    if (p < r) {
//        q = partition(A, p, r);
//        quicksort(A, p, q-1);
//        quicksort(A, q+1, r);
//    }
//}
//
//int partition(int A[], int p, int r) {
//    int x = A[r]; // 끝 부분을 pivot으로 잡는다.
//    int i = p-1;
//    
//    for (int j=p; j<r; j++) {
//        if (A[j] < x) {
//            i++;
//            int temp = A[j];
//            A[j] = A[i];
//            A[i] = temp;
//        }
//    }
//    
//    int temp = A[r];
//    A[r] = A[i+1];
//    A[i+1] = temp;
//    return i+1;
//}
//
//void display(int A[], int n) {
//    for (int i=0; i<n; i++)
//        printf("%d ", A[i]);
//    printf("\n");
//}
//
