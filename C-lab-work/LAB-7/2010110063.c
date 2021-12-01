#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node
{
  int date;
  char member_name[20];
  struct node *next;
} *Qfront = NULL, *Qrear = NULL;

//dates exist between 15 to 30
int limit;


int
limitChecker (int counter)
{
  if (counter > limit)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

void
makeReservation (int DD, char namePerson[20])
{
  int counter = 0;

  struct node *Reservation = malloc (sizeof (struct node));
  Reservation->date = DD;
  strcpy (Reservation->member_name, namePerson);

  if (Qfront == NULL)
    {
      Qfront = Reservation;
      Qrear = Reservation;
    }

  else
    {
      struct node *pointer = Qfront;
      while (pointer != NULL)
	{
	  pointer = pointer->next;
	  counter++;
	}
      if (limitChecker (counter))
	{
	  Qrear->next = Reservation;
	  Qrear = Reservation;
	}
      else
	{
	  printf ("\nSORRY,NO FREE QUOTA");
	  return;
	}
    }
}



void
PrintList ()
{
  struct node *pointer;
  pointer = Qfront;

  while (pointer != NULL)
    {
      printf (" %s ", pointer->member_name);
      pointer = pointer->next;
    }
}


void
printReservation(int DD)
{
  struct node *pointer;
  pointer = Qfront;
  int flag = 0;
  printf("\n");
  printf ("%d: ", DD);
  while(pointer != NULL){
      if(flag > limit){
          printf("QUOTA OVER");
          break;
      }
      if(pointer -> date == DD){
          printf(" %s ",pointer -> member_name);
          flag++;
      }
      
      pointer = pointer -> next;
  }
  
  if(flag == 0){
      printf("NO GUESTS");
  }
}


struct node *
List (int DD, char name[20], struct node *specialDateList)
{
  struct node *Qnewrear;
  struct node *newNode = malloc (sizeof (struct node));
  newNode->date = DD;
  strcpy (newNode->member_name, name);

  if (specialDateList == NULL)
    {
      specialDateList = newNode;
    }
  else
    {
      struct node *pointer = specialDateList;
      while (pointer != NULL)
	{
	  pointer = pointer->next;
	}
      pointer->next = newNode;
    }

  return specialDateList;
}


void
changeReservation (int DD, char name[20], int new_DD)
{
  struct node *tracker_ptr = Qfront;
  while (tracker_ptr != NULL)
    {
      tracker_ptr = tracker_ptr->next;
      if (strcmp (tracker_ptr->member_name, name) == 0
	  && tracker_ptr->date == DD)
	{
	  tracker_ptr->date = new_DD;
	  break;
	}
    }
}

void
cancelReservation (int DD, char name[20])
{
  struct node *delTemp = Qfront;
  struct node *temp;
  
  if(!strcmp(Qfront -> member_name,name) && Qfront -> date == DD){
      temp = Qfront;
      Qfront = Qfront -> next;
      free(temp);
      printf("Reservation Cancelled");
      printf("\n");
      return;
  }
  

    while (strcmp(delTemp -> next -> member_name,name) && delTemp -> next -> date){
          delTemp = delTemp -> next;
      }
      
      temp = delTemp -> next;
      delTemp -> next = delTemp -> next -> next;
      free(temp);
    
}



int
main ()
{
    int selector;
    printf("Enter Limit of people per day = ");
    scanf("%d",&limit);
    while(1){
        printf("\n");
        printf("\n 1. Make your Reservation \n 2. Change Date of Reservation \n 3. Cancel your Reservation \n 4. Print Reservations of a certain day \n 5. Exit Program");
    printf("\nEnter your choice = ");
    scanf("%d",&selector);
    
    if(selector > 5 || selector < 1){
        printf("\nInvalid input");
        return 0;
    }else{
            if (selector == 1)
        {
            int date;
            char name[20];
            printf("Enter the date of your stay = ");
            scanf("%d", &date);
            printf("Enter your name = ");
            scanf("%s", &name);
            makeReservation(date,name);
        }
        else if (selector == 2)
        {
            int old_date;
            char name[20];
            int new_date;
            printf("Enter the previous date of your stay = ");
            scanf("%d", &old_date);
            printf("Enter your name = ");
            scanf("%s", &name);
            printf("Enter the new date of your stay = ");
            scanf("%d", &new_date);
            changeReservation(old_date,name,new_date);
        }
        else if (selector == 3)
        {
            int date_TBD;
            printf("To Cancel Enter the date of your stay = ");
            scanf("%d", &date_TBD);
            char name[20];
            printf("Enter your name = ");
            scanf("%s", &name);
            cancelReservation(date_TBD,name);
        }
        else if (selector == 4)
        {
            int date;
            printf("Enter the specified date to acesses records = ");
            scanf("%d", &date);
            printReservation(date);
        }
        else if (selector == 5)
        {
            exit(0);
        }
    }
    }
    
    
    
    
    /*    fp = fopen("data.txt", "r");
    fscanf(fp, "%d", &limit);

    while (1)
    {
        int i;
        fscanf(fp, "%d", &i);
        if (i == 1)
        {
            int date;
            char name[20];
            fscanf(fp, "%d", &date);
            fscanf(fp, "%s", &name);
            makeReservation(date,name);
        }
        else if (i == 2)
        {
            int old_date;
            char name[20];
            int new_date;
            fscanf(fp, "%d", &old_date);
            fscanf(fp, "%s", &name);
            fscanf(fp, "%d", &new_date);
            changeReservation(old_date,name,new_date);
        }
        else if (i == 3)
        {
            int date_TBD;
            fscanf(fp, "%d", &date_TBD);
            char name[20];
            fscanf(fp, "%s", &name);
            cancelReservation(date_TBD,name);
        }
        else if (i == 4)
        {
            int date;
            fscanf(fp, "%d", &date);
            printReservation(date);
        }
        else if (i == 5)
        {
            exit(0);
        }
    }*/
}