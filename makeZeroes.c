#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void makeZeroes(int arr[3][3] , int n ) {
    bool firstColZero = false;
    for(int i=0 ;i<3;i++ ) {
        if(arr[i][0] == 0) {
            firstColZero = true;
        }
        for(int j = 0; j <3; j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }

    }

    for(int i = n-1 ; i>=0; i--) {
        for(int j = n-1; j>=1 ; j--) {
            if(firstColZero) {
                arr[i][0] = 0;
            }
            if(arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

}



int main() {
  int arr[3][3] = {
  {1,1,1},
  {1,0,1},
  {1,1,1}
  };

  makeZeroes(arr,3);
  for(int i = 0 ;i<3; i++) {
    for(int j = 0;j<3;j++) {
        printf("%d ",arr[i][j]);
    }
    printf("\n");
  }


}
