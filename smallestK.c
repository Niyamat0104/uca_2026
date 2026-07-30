#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>

void generateRandom(int a[] , int s){
    int i;
    for(int i = 0 ; i < s ; i++){
        a[i] = rand() % s + 1 ;
    }
}


void swap(int a[],int i ,int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void QuickSort(int a[], int R, int k, int L,int result[]) {
    if(L>R) {
        
        return ;
    }
    int p = L;
    int x = L;
    int i = L+1;
    int pivot = a[p];
    while(i<=R){
        if(a[i]<pivot){
            swap(a,i,++x);
        }
        i++;
    }
    swap(a,p,x);
   

    if(x == k-1){
        for(int i =0 ;i< k;i++){
            result[i]=a[i];
            
             
        }
        return ;

    }
    else if(k-1>x){
        QuickSort(a,R,k,x+1,result);
    }
    else{
        QuickSort(a,x-1,k,L,result);

    }


}
int main(){
     

    struct timeval te;
    int size = 8000;
    int step = 4000;
    
    int i;
    for(i = 0 ; i < 8 ; i++){
        int a[size] ;
        int k = size - 3000;
        generateRandom(a , size);
        int result[size];
        gettimeofday( &te , NULL);
        long long start = te.tv_sec * 1000000LL + te.tv_usec;
        QuickSort( a , size-1,k,0,result);
        gettimeofday(&te , NULL);
        long long end = te.tv_sec * 1000000LL + te.tv_usec;
        printf("%.3f\n", (end - start) / 1000.0);
        size += step;
    }
    printf("\n");
    return 0;
}