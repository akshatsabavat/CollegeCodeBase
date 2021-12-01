#include<stdio.h>

//Program written in C
//Akshat Sabavat 2010110063
//I have not copied from anyone or any source

int RecursiveAdd(int position,int array[],int limit){
    if (position > limit-1)
    {
        return 0;

    } else {
        position++;
        return array[position] + RecursiveAdd(position,array, limit);
    }
    
}

int main () {

    int size;
    FILE *fp = fopen("dat2.txt","r");
    fscanf(fp,"%d",&size);

    printf("%d\n",size);

    int arr[size];

    for(int i = 0; i < size; i ++){
        fscanf(fp,"%d",&arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }

    int answer = RecursiveAdd(-1,arr,5);
    printf("\n%d",answer);
    
}