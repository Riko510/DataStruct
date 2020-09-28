#include <stdio.h>


void getMagicMatrix(int n) {
    
    int square[n][n];
    for(int row = 0; row < n; row++){
        for(int column = 0; column < n; column++){
            square[row][column] = 0;
        }
    }
    int i = 0, j = (n-1)/2;
    square[i][j] = 1;
    
    for(int key = 2; key <= n*n; key++){
        int temp1 = i,
            temp2 = j;
        
        if(i - 1 >= 0){
            if(j+1 < n){
                i -= 1;
                j += 1;
            }else{
                i -= 1;
                j = 0;
            }
        }else{
            if(j+1 < n){
                i = n - 1;
                j += 1;
            }else{
                i = n - 1;
                j = 0;
            }
        }
        
        if(square[i][j] != 0){
            i = temp1 + 1;
            j = temp2;
        }
        square[i][j] = key;
    }
    
    for(int row = 0; row < n; row++){
        for(int column = 0; column < n; column++){
            printf("%d ",square[row][column]);
        }
        printf("\n");
    }
}


int main(void) {
    
    getMagicMatrix(5);
    return 0;
}

