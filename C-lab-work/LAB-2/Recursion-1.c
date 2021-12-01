#include<stdio.h>


//Program written in C
//Akshat Sabavat 2010110063
//I have not copied from anyone or any source


int checker(int a , int b){
    if (a > b)
    {
        return 0;
    } else {
        return 1;
    }
    
}

int squareFunction(int X){
    int square = X*X;
    return square;
}

int SUMOFSERIES(int m,int n){
    int count = 0;
        if (m == n){
            return squareFunction(n);
        }else {
            count++;
            return squareFunction(m) + SUMOFSERIES(m + count ,n);
        }
    
}

int main () {

    FILE *file_pointer1 = fopen("dat1.txt","r");
    int test;
    int test2;

    int m,n;

    fscanf(file_pointer1,"%d",&m);

    fscanf(file_pointer1,"%d",&n);

    int answer = SUMOFSERIES(m,n);
    printf("\n%d",answer);
}