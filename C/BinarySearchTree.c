#include <stdio.h>

typedef struct Node{
    int data, left, right;
    
} NODE;

typedef struct BinarySearchTree{
    NODE root;
} BINARYSEARCHTREE;

int factorial(int num){
    int fact = 1;
    if(num == 0) {   
            return 1;    
    }else {    
        while(num > 1) {    
            fact = fact * num;    
            num--;    
        }    
        return fact;    
    }
}

int numOfBST(int key) {    
        int catalanNumber = factorial(2 * key)/(factorial(key + 1) * factorial(key));    
        return catalanNumber;    
    }

int main() {
    BINARYSEARCHTREE bt;
    bt.root.data = 5;

    printf("Total number of possible Binary Search Trees with given key: %d", numOfBST(bt.root.data));

    return 0;
}