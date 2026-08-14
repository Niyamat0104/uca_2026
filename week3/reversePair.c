#include <stdio.h>
#include <stdlib.h>



void merge(int arr[] , int s , int mid , int e){
    int l = e-s+1;
    int temp[l];
    int k = 0;
    int i = s;
    int j = mid+1;
    while(i <=mid && j<=e){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    for(int i = 0 ; i < l ;i++ ){
        arr[s+i] = temp[i];
    }
}

int countPairs(int arr[] ,int s , int mid , int e){
    int c = 0;
    
    int j = mid + 1;
    for( int i = s ; i<= mid ; i++){
        int a = arr[i];
        while(j<= e && (long long)a > 2LL * arr[j]){
            j++;
        }
        c+=j-(mid+1);
    }
    return c;

}





int countReversePairs(int arr[] , int s , int e) {
    
    
    if(s>=e) return 0;
     int count = 0;
    int mid = s+(e-s)/2;

    count += countReversePairs(arr,s,mid);
    count += countReversePairs(arr,mid+1,e);
    count += countPairs(arr, s, mid , e);
    merge(arr , s, mid, e);
    return count;


}


int main(){
    int arr[] = {1,3,2,3,1};
    long int result = countReversePairs(arr,0,4);
    printf("Total number of reverse pairs %ld\n", result);
}
