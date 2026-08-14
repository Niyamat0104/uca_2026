#include <stdio.h>
#include <stdlib.h>


int getOddElement(int arr[],int n) {
    int ans = 0;
    for(int i = 0 ;i <32 ; i++) {
        int count = 0;
        for(int j = 0 ; j<n ; j++){
            if(arr[j] & (1<<i)) {
                count++;
            }

        }
        if(count % 3 == 1) {
            ans = ans | (1<<i);
        }

    }
    return ans;
     

}

int main() {
    int arr[] = {
        1, 2, 4,
        1, 2, 4,
        1, 2,
        3, 4, 3, 3,
        5, 5, 5, 5
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = getOddElement(arr, n);
    printf("The elemnt ocuuring for 4 times in the array is :  %d\n",ans);
}
