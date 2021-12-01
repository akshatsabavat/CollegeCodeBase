#include<stdio.h>

//Program written in C
//Akshat Sabavat 2010110063
//I have not copied from anyone or any source

void ITV_Fibonacci(int n){

    int a = 1;
    int b = 1;
    int count = 0;
    int c;

    for(int i = 2; i <= n; i++){  // we start from 1 instead of 0,1 hence we iterate from i = 2 till n
        count++;
        c = a+b;
        a = b;
        b = c;
        printf(" %d ",count);
    }

    printf("\nFibonacci(%d) = %d\n\n",n,a);    
}

int REC_Fibonnaci(int n){

    static int count = 0;
    count++;
    printf(" %d ",count);

    if (n == 1)
    {
        return 1;
    }else if(n == 0){
        return 0;
    }
    else {
        return REC_Fibonnaci(n-1) + REC_Fibonnaci(n-2);
    }
}

int main(){

    int value;
    printf("Enter a value to compare iteration and recursion = ");
    scanf("%d",&value);
    printf("\n\n");


    printf("Counts with iteration\n");
    ITV_Fibonacci(value);
    
    printf("Counts with Recursion\n");
    printf("\nFibonnaci(%d) = %d",value,REC_Fibonnaci(value));
}