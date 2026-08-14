#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAX 10000


int villages[MAX];
int cost[MAX][MAX];
int memo[MAX][MAX];

int n;

int min(int a , int b) {
    return a<b?a:b;
}

int compare(const void*a, const void *b) {
    return (*(int*)a)-(*(int*)b);
}

void buildCost(){
    memset(cost,0,sizeof(cost));
    for(int i=0 ; i<n ; i++) {
        for(int j =0 ; j<n;j++) {
            int mid = (i+j)/2;
            for(int p = i;p<=j;p++){
                cost[i][j]+= abs(villages[p]-villages[mid]);
            }
        }
    }

}

int solve(int index,int k) {
    if(index==n){
        return 0;
    }
    if(k==0){
        return INT_MAX/2;

    }
    if(memo[index][k]!=-1) {
        return memo[index][k];
    }
    int ans = INT_MAX;
    for(int end= index; end<n;end++) {
        ans = min(ans,cost[index][end]+solve(end+1,k-1));
    }
    memo[index][k]=ans;
    return ans;

}
int allocateClinics(int arr[],int size,int k) {
    n = size;
    for(int i = 0; i<n; i++){
        villages[i] = arr[i];
    }
    qsort(villages,n,sizeof(int),compare);
    buildCost();
    memset(memo,-1,sizeof(memo));
    return solve(0,k);
}

int main() {
    int arr[] ={200,20,50,80};
    int k =2;
    printf("Minimum distance = %d\n",allocateClinics(arr,4,k));
    return 0;
}



