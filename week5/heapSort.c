#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


void generateRandom(int a[], int n) {
    for(int i = 0; i< n; i++) {
        a[i] = rand() % n + i;
    }
}

void generateAscending(int a[] , int n) {
    for(int i = 0 ;i<n; i++){
        a[i] = i+1;
    }
}

void generateDescending(int a[] , int n) {
    for(int i = 0 ; i<n ;i++) {
        a[i] = n - i;
    }
}

void swap(int a[] , int i , int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp; 
}

void heapify(int a[] , int i ,int n) {
    int p = i ;
    int L = 2*i +1;
    int R = 2*i + 2;
    int minP = i ;
    if(L<n && a[L] < a[minP]){
        minP = L;
    }
    if(R<n && a[R] < a[minP]) {
        minP = R;
    }
    if(minP != p) {
        swap(a, i ,minP);
        heapify(a,minP,n);
    }
}

void heapSort(int a[] , int n) {
    for(int i = n/2;i>=0;i--) {
        heapify(a,i,n);
    }

    for(int i = n-1; i>=0 ; i--) {
        swap(a,0,i);
        heapify(a,0,i);
    }
}


int main() {
    struct timeval te;
    int size = 8000;
    int step = 4000;
    for(int i = 0; i<8 ; i++){
        int a[size];
        generateDescending(a,size);
        gettimeofday(&te, NULL);
        long long start = te.tv_sec * 1000000LL + te.tv_usec;
        heapSort(a,size);
        gettimeofday(&te,NULL);
        long long end = te.tv_sec * 1000000LL +te.tv_usec;
        printf("%.3f\n",(end-start)/1000.0);
        size+=step;
        printf("\n");
    }
    
}
