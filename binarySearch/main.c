#include <stdio.h>


void binarySearch(int data[],int length,int target){ //一版寫法

    int left = 0;
    int right = length - 1;
    int middle = (left + right)/2;
    
    while(right > left){
        if(target == data[middle]){
            printf("第%d個數找到目標\n",middle + 1);
            return;
        }else if(target > data[middle]){
            left = middle + 1;
        }else if(target < data[middle]){
            right = middle - 1;
        }
        middle = (left + right) / 2;
    }
    
    printf("Not found the target\n");
}


int recursiveBinarySearch(int data[],int length,int target,int left, int right){ //遞迴寫法
    
    int middle = (left + right)/2;
    
    while(right > left){
        if(target == data[middle]){
            return middle;
        }else if(target > data[middle]){
            left = middle + 1;
            return recursiveBinarySearch(data, length, target, left, right);
        }else if(target < data[middle]){
            right = middle - 1;
            return recursiveBinarySearch(data, length, target, left, right);
        }
        middle = (left + right) / 2;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int data[] = {1,3,5,7,9};
    int length = sizeof(data)/sizeof(int);
    int target = 8;

    binarySearch(data, length, target);
    
    int result = recursiveBinarySearch(data, length, target, 0, length - 1);
    if(result == -1){
        printf("Not found the target\n");
    }else{
        printf("在第%d個數找到目標\n",result + 1);
    }
    return 0;
}
