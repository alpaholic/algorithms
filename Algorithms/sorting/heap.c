////
////  heap.c
////  algorithms
////
////  Created by mindol on 2016. 11. 26..
////  Copyright © 2016년 mindol. All rights reserved.
////
//
//#include <stdio.h>
//
//void heapSort(int A[], int n);
//void buildHeap(int A[], int n);
//void heapify(int A[], int k, int n);
//void display(int A[], int n, int reverse);
//
//int main(void)
//{
//    int A[] = { 0, 6, 5, 4, 3, 2, 1 };
//    display(A, 6, 0);
//    heapSort(A, 6);
//    display(A, 6, 1);
//    //buildHeap(A, 6);
//    //display(A, 6);
//}
//
//void heapSort(int A[], int n) {
//    int temp;
//    
//    buildHeap(A, n);
//    // A[1]과 A[정렬되지 않은 배열중의 끝]을 교환하면서, 맨 마지막 배열 요소부터 정렬
//    // SWAP 후에 힙 성질이 꺠질 수 있으므로, 다시 heapify를 호출
//    // 그러나, 교환한 값은 정렬이 된 상태이므로 i-1개로 저장.
//    for (int i=n; i>=2; i--) {
//        temp = A[i];
//        A[i] = A[1];
//        A[1] = temp;
//        
//        heapify(A, 1, i-1);
//    }
//}
//
//void buildHeap(int A[], int n) {
//    for (int k=n/2; k>=1; k--)
//        heapify(A, k, n);
//}
//
//void heapify(int A[], int k, int n) {
//    int left = k * 2;
//    int right = (k * 2) + 1;
//    int smaller;
//    
//    if (right <= n) { // 자식이 두 개
//        smaller = (A[left] > A[right]) ? right: left;
//    } else if (left <= n) { // 자식이 한 개
//        smaller = left;
//    } else {
//        return; // leaf node
//    }
//    
//    // 만약 부모가 더 큰수이면 부모와 자식의 위치를 변경한다.
//    // 여기서 자식의 위치에 대해서 다시 힙을 재정렬
//    if (A[k] > A[smaller]) {
//        int temp = A[k];
//        A[k] = A[smaller];
//        A[smaller] = temp;
//        
//        heapify(A, smaller, n);
//    }
//}
//
//void display(int A[], int n, int reverse) {
//    if (reverse == 0) {
//        for (int i=1; i<=n; i++) {
//            printf("%d ", A[i]);
//        }
//    } else {
//        for (int i=n; i>=1; i--) {
//            printf("%d ", A[i]);
//        }
//    }
//    
//    printf("\n");
//}
