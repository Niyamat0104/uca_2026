#include <stdio.h>
#include <stdlib.h>


int maxHeap[1000];
int maxSize = 0;
int minSize = 0;
int minHeap[1000];

void swap(int heap[] , int i , int j) {
    int temp = heap[i] ;
    heap[i] = heap[j];
    heap[j] = temp;


}
void swimMax(int key) {
    if(key == 0) {
        return ;
    }
    int p = (key-1)/2;
    if(maxHeap[p]<maxHeap[key]){
        swap(maxHeap,p,key);
        swimMax(p);
    }
}

void insertMax(int val) {
    maxHeap[maxSize] = val;
    swimMax(maxSize);
    maxSize++;
    

}
void sinkMax(int i ) {
    if(i >= maxSize) return;
    int p = i;
    int L = 2*p+1;
    int R = 2*p+2;
    int maxP = p ;
    if(L<maxSize && maxHeap[L] > maxHeap[maxP]) {
        maxP = L;
    }
    if(R<maxSize && maxHeap[R] > maxHeap[maxP]) {
        maxP = R;
    }
    if(maxP != p) {
      swap(maxHeap,maxP,p);
      sinkMax(maxP);
    }
     

}

int deleteMax() {
    int res = maxHeap[0];
    swap(maxHeap,0,maxSize-1);
    maxSize--;
    sinkMax(0);
    return res;

}


void swimMin(int key) {
    if(key == 0) {
        return ;
    }
    int p = (key-1)/2;
    if(minHeap[p]>minHeap[key]){
        swap(minHeap,p,key);
        swimMin(p);
    }
}

void insertMin(int val) {
    minHeap[minSize] = val;
    swimMin(minSize);
    minSize++;
    

}
void sinkMin(int i ) {
    if(i >= minSize) return;
    int p = i;
    int L = 2*p+1;
    int R = 2*p+2;
    int minP = p ;
    if(L<minSize && minHeap[L] < minHeap[minP]) {
        minP = L;
    }
    if(R<minSize && minHeap[R] < minHeap[minP]) {
        minP = R;
    }
    if(minP != p) {
      swap(minHeap,minP,p);
      sinkMin(minP);
    }
     

}

int deleteMin() {
    int res = minHeap[0];
    swap(minHeap,0,minSize-1);
    minSize--;
    sinkMin(0);
    return res;

}


void insert(int age) {
    if(maxSize == 0 || maxHeap[0] >= age){
        insertMax(age);
    }
    else{
        insertMin(age);
    }

    if(maxSize>minSize+1) {
        int num = deleteMax();
        insertMin(num);

    }
    if(minSize>maxSize) {
        int num = deleteMin();
        insertMax(num);
    }
}

float getMedian() {
    if(maxSize == minSize) {
        return (minHeap[0] + maxHeap[0]) / 2.0;
    }
    else{
        return minHeap[0];
    }
     
}

int main() {
    insert(10);
    insert(34);
    insert(23);
    insert(34);
    printf("%.3f\n",getMedian());
    insert(65);
    insert(23);
    insert(1000);
     printf("%.3f\n",getMedian());




}
