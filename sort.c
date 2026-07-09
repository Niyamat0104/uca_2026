#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void generateRandom(int a[] , int s){
    int i;
    for(int i = 0 ; i < s ; i++){
        a[i] = rand() % s + 1 ;
    }
}


void generateAscending(int a[] , int s){
    int i;
    for(int i = 0 ; i < s ; i++){
        a[i] = i ;
    }
}


void generateDescending(int a[] , int s){
    int i;
    for(int i = 0; i < s; i++){
        a[i] = s - i ;
    }
}


void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j] ;
    a[j] = temp ;
}


void bubbleSort(int a[] , int n){
    int i ;
    int j ;
    for(int i = 0; i < n-1 ; i++){
        int swapped = 0;
        for(int j = 0 ; j < n-i-1 ; j++){
            if(a[j] > a[j+1]){
                swap(a , j , j+1) ;
                swapped = 1 ;
            }
        }
        if(swapped == 0){
            break ;
        }
    }
        
        
}


void selectionSort(int a[] , int n){
     for(int i = 0 ; i < n-1 ; i++){
        int min_index = i;
        for(int j = i+1 ; j < n; j++){
            if(a[j] < a[min_index]){
                min_index = j;
            }
        }
        swap(a , min_index , i);
       }
}



void insertionSort(int a[] , int n){
    for(int i = 1 ; i < n ; i++){
        int ele = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > ele){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = ele;

    }

}


int partition(int a[] , int low , int high){
    int pivot = a[high];
    int i = low-1;
    for(int j = low; j< high ; j++){
        if(a[j] < pivot){
            i++;
            swap(a, i ,j);
        }
    }
    swap(a , i+1 , high);
    return i+1;


}


void quick(int a[], int low, int high){
    if(low < high){
        int pi=partition(a,low, high);
        quick(a, low , pi-1);
        quick(a , pi+1 ,high);
    }
}


void quickSort(int a[] , int n){
    quick(a,0,n-1);

}


void merge(int a[] , int left , int mid ,int right){
    int n1= mid- left +1;
    int n2=right - mid;
    int L[n1],R[n2];
    for(int i = 0 ; i<n1 ; i++){
        L[i] = a[left+i];
    }
    for(int i = 0 ; i < n2; i++){
        R[i]=a[mid + 1 + i];
    }
    int i =0 , j = 0, k=left;
    while(i< n1 && j < n2){
        if(L[i] <= R[j]){
            a[k++] = L[i++];
        }
        else{
            a[k++] = R[j++];
        }
    }
    while(i < n1)
        a[k++] = L[i++];

    while(j < n2)
        a[k++] = R[j++];

}


void mergeRec(int a[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeRec(a, left, mid);
        mergeRec(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}


void mergeSort(int a[], int n)
{
    mergeRec(a, 0, n - 1);
}


void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[largest])
        largest = left;

    if(right < n && a[right] > a[largest])
        largest = right;

    if(largest != i)
    {
        swap(a , i ,largest);
        heapify(a, n, largest);
    }
} 

void heapSort(int a[], int n)
{
    
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

   
    for(int i = n - 1; i > 0; i--)
    {
        swap(a , 0 , i);
        heapify(a, i, 0);
    }
}


void print(int a[] , int s){
    int i ; 
    for(int i = 0 ; i < s ; i++){
        printf("%d " , a[i]);
    }
    printf("\n");
}


int main(){
    struct timeval te;
    int size = 8000;
    int step = 4000;
    int i;
    for(i = 0 ; i < 8 ; i++){
        int a[size] ;
        generateRandom(a , size);
        gettimeofday( &te , NULL);
        long long start = te.tv_sec * 1000000LL + te.tv_usec;
        heapSort( a , size);
        gettimeofday(&te , NULL);
        long long end = te.tv_sec * 1000000LL + te.tv_usec;
        printf("%.3f\n", (end - start) / 1000.0);
        size += step;
    }
    printf("\n");
    return 0;
}