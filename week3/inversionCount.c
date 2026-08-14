#include<stdio.h>
#include<stdlib.h>



int merge(int a[] , int L ,int mid, int R ,int aux[]){
    int k = L;
    int i = L;
    int j = mid+1;
    int c = 0;
    while(k<=R){
        if(i>mid) aux[k++] = a[j++];
        else if(j>R) aux[k++] = a[i++];
        else if (a[i] <= a[j]) aux[k++] = a[i++];
        else {
            aux[k++] = a[j++];
            c += (mid - i + 1);;

        };
    }
    /*this is cost n of merging */
    k = L;
    while(k<=R){
        a[k] = aux [k];
        k++;
    }
    return c;



 
}


int merge_sort(int a[],int L,int R,int aux[]){
    int c=0;
    if(L>=R) return c;
    int mid = (L+R)/2;
     
    c+=merge_sort(a,L,mid,aux);
    c+=merge_sort(a,mid+1,R,aux);
    c+=merge(a,L,mid,R,aux);
    /* this merge is called after log n times*/
    return c;

}
/*totalcomplexity is this nlogn(called n times) + log n*/
int Sort(int a[], int n){
    int aux[n];
     
    return merge_sort(a,0,n-1,aux);
}
int main(){
    int arr[]={2,3,4,5,6};
    int swaps = Sort(arr,5);
     printf("%d\n", swaps);
}
