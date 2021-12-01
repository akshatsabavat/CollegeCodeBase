#include<stdio.h>



int main(){
    int N;
    int value,loop;
    int i = 0;


    FILE *file_pointer1;

    file_pointer1 = fopen("employee.txt","r");

    if(file_pointer1 == NULL){
        puts("file not found");
    } 

    fscanf(file_pointer1,"%d",&N);
    printf("%d",N);

    int EMP_id[N];
    int EMP_category[N];
    int EMP_hours[N];

    for ( i = 0; i < N; i++)
    {
        fscanf(file_pointer1,"%d",&EMP_id[i]);
    }

       for ( i = 0; i < N; i++)
    {
        fscanf(file_pointer1,"%d",&EMP_category[i]);
    }

       for ( i = 0; i < N; i++)
    {
        fscanf(file_pointer1,"%d",&EMP_hours[i]);
    }

    printf("\n");
     printf("\n");
     printf("Employee ids : \n");
    for(loop = 0; loop < N; loop++)
      printf("%d ", EMP_id[loop]);
      
      printf("\n");
      printf("\n");
     printf("Employee categpries : \n");
    for(loop = 0; loop < N; loop++)
      printf("%d ", EMP_category[loop]);

      printf("\n");
      printf("\n");
     printf("Employee hours : \n");
    for(loop = 0; loop < N; loop++)
      printf("%d ", EMP_hours[loop]);


      int position_TBD = 2;
      int count = 0;

      for ( int p = position_TBD - 1 ; p < N - 1; p++)
      {
          count++;
          EMP_id[p] = EMP_id[p+1];
          EMP_hours[p] = EMP_hours[p+1];
          EMP_category[p] = EMP_category[p+1];
      }

      printf("New Records");

      printf("\n");
     printf("\n");
     printf("Employee ids : \n");
    for(loop = 0; loop < N; loop++)
      printf("%d ", EMP_id[loop]);
      
      printf("\n");
      printf("\n");
     printf("Employee categpries : \n");
    for(loop = 0; loop < N; loop++)
      printf("%d ", EMP_category[loop]);

      printf("\n");
      printf("\n");
     printf("Employee hours : \n");
    for(loop = 0; loop < N; loop++)
      printf("%d ", EMP_hours[loop]);


      printf("\n Number of shifts = %d",count);

      
    
}



/*
Program for question 3

int main(){
    int N;
    int value,loop;
    int i = 0;


    FILE *file_pointer1;

    file_pointer1 = fopen("arrayadd.txt","r");

    if(file_pointer1 == NULL){
        puts("file not found");
    } 

    fscanf(file_pointer1,"%d",&N);
    printf("%d",N);

    int arr1[N];
    int arr2[N];


    for ( i = 0; i < N; i++)
    {
        fscanf(file_pointer1,"%d",&arr1[i]);
        
        }

         for ( i = 0; i < N; i++)
        {
           fscanf(file_pointer1,"%d",&arr2[i]);
        }

    printf("\n");

    for(loop = 0; loop < N; loop++)
      printf("%d ", arr1[loop]);

      
    printf("\n");

    for(loop = 0; loop < N; loop++)
      printf("%d ", arr2[loop]);

    int result_array[N];

    for ( loop = 0; loop < N; loop++)
    {
        result_array[loop] = arr1[loop] + arr2[loop];
    }

    printf("\n");

    for(loop = 0; loop < N; loop++)
      printf("%d ", result_array[loop]);
    
    
    
}

*/

/*
Program for question 1 and 2 

int squareFunction(int X){
    int square = X*X;
    return square;
}

void assign_main(){

    int S1,S2,P,Q;

    printf("\nEnter value for P: ");
    scanf("%d",&P);

    printf("\nEnter value for Q: ");
    scanf("%d",&Q);

    S1 = squareFunction(P);
    S2 = squareFunction(Q);

    printf("\n%d's square = %d",P,S1);
    printf("\n%d's square = %d",Q,S2);
}


int main() {
    int n;
    int m;

    printf("\nEnter a number: ");
    scanf("%d",&n);

    for ( m = 1; m <= n; m++)
    {
        if((m*m) >= n){
            break;
        }
    }

    m = m-1;

    printf("\nfinal answers -> %d,%d",m,n);

    assign_main();
    
}

*/