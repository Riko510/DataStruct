#include <stdio.h>

int getNumber(int n){
    
    int lohif=0;
    int hilif=1;
    int temp;
    
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        for(int floor = 2; floor <= n ; floor++){
            temp = hilif;
            hilif += lohif;
            lohif = temp;
        }
        return hilif;
    }
    
}

int recursiveGetNumber(int n){
    
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return recursiveGetNumber(n - 1) + recursiveGetNumber(n - 2);
    }
}

int main(int argc, const char * argv[]) {
    
    int end1 = getNumber(7);
    int end2 = recursiveGetNumber(6);
    printf("非遞回答案為%d，則遞迴為%d\n",end1,end2);
    return 0;
}
