////
////  merge.c
////  algorithms
////
////  Created by mindol on 2016. 11. 26..
////  Copyright © 2016년 mindol. All rights reserved.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 6
//
//void mergeSort(int A[], int p, int r);
//void merge(int A[], int p, int q, int r);
//void display(int A[], int n);
//
//
//int main(void)
//{
//    int A[] = {6, 5, 3, 9, 10, 15};
//    display(A, SIZE);
//    mergeSort(A, 0, SIZE-1);
//    display(A, SIZE);
//}
//
//void mergeSort(int A[], int p, int r) {
//    int q;a
//    
//    if (p < r) {
//        q = (p + r) / 2;
//        mergeSort(A, p, q);
//        mergeSort(A, q+1, r);
//        merge(A, p, q, r);
//    }
//    
//}
//void merge(int A[], int p, int q, int r) {
//    int *temp = (int *) malloc (sizeof(int) * r);
//    int i = p;
//    int j = q+1;
//    int t = 0;
//    
//    while (i<=q && j<=r) {
//        if (A[i] > A[j]) { // 뒤의 배열 이동
//            temp[t++] = A[j++];
//        } else {
//            temp[t++] = A[i++];
//        }
//    }
//    
//    while (i<=q)
//        temp[t++] = A[i++];
//    while (j<=r)
//        temp[t++] = A[j++];
//    
//    i = p;
//    t = 0;
//    while (i<=r)
//        A[i++] = temp[t++];
//}
//
//void display(int A[], int n) {
//    for (int i=0; i<n; i++)
//        printf("%d ", A[i]);
//    printf("\n");
//}
