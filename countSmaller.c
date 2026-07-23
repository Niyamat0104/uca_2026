#include <stdio.h>
#include <stdlib.h>



void merge(int arr[] ,int index[], int s , int mid , int e,int ans[]){
    int l = e-s+1;
    int temp[l];
    int tempIndex[l];
    int k = 0;
    int i = s;
    int j = mid+1;
    int rightCount = 0;
    while(i <=mid && j<=e){
        if(arr[i]<=arr[j]){
            ans[index[i]]+=rightCount;
            temp[k] = arr[i];
            tempIndex[k] = index[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            tempIndex[k] =index[j];
            rightCount++;
            j++;
            k++;
        }
    }
    while(i<=mid){
        ans[index[i]] += rightCount;

        temp[k] = arr[i];
        tempIndex[k] = index[i];

        i++;
        k++;
    }
    while(j<=e){
        temp[k] = arr[j];
        tempIndex[k] = index[j];

        j++;
        k++;
    }
    for(int i = 0 ; i < l ;i++ ){
        arr[s+i] = temp[i];
        index[s + i] = tempIndex[i];
    }
}

 




void mergeSort(int arr[] ,int index[], int s , int e,int ans[]) {
    
    
    if(s>=e) return ;
     
    int mid = s+(e-s)/2;
    mergeSort(arr, index,s,mid,ans);
    mergeSort(arr, index,mid+1,e,ans);
     
    merge(arr ,index,s, mid, e,ans);
     


}


int main(){
    int arr[] = {5,2,6,1,0};
    int ans[5];
    int index[5];
    for(int i =0 ;i<5; i++){
        ans[i] = 0;
        index[i] = i;
    }
    mergeSort(arr,index,0,4,ans);
    
    for(int i =0 ;i<5;i++){
        printf("%d\n",ans[i]);
    }
}
