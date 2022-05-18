#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5

int userswitch;
char arr[MAX], user;
int front = -1 , rear = -1; 

void enqueue(char c[], char usr), dequeue(char c[]), printQueue(char c[]);

int main(){

  while(userswitch != 4){
    
		printf("\nEnter your Choice");
		printf("\n  1 to print queue");
		printf("\n  2 to enqueue a character");
		printf("\n  3 to dequeue a character");
    printf("\n  4 to exit");
 
		printf("\nEnter Your Choice:");
		scanf("%i",&userswitch);
 
		switch(userswitch) {
			case 1:
				printQueue(arr);
				break;
			case 2:
        printf("Input the character to queue: ");
        scanf(" %c", &user);
        enqueue(arr, user);
				 break;
			case 3:
        dequeue(arr);
				break;
      case 4:
        break;
      default:
        printf("Select a valid option");
        break;
        }
	}
  return 0;
}

void printQueue(char c[]){

  if(rear == -1){
    printf("\nThe queue is empty\n");
    return;
  }
  else
    for (int i = front; i <= rear; i++){
      printf("%c", c[i]);
    }
}  

void enqueue(char c[], char b){
  if (rear == -1){
    rear += 1;
    c[0] = b;
    front = 0; 
    return;
  }

  else if(rear < MAX){
    rear += 1;
    c[rear] = b;
    return;
  }
  else
    printf("\nQueue overflow\n");
    return;
}


void dequeue(char c[]){

  if(front == -1){
		printf("\nThe queue is empty\n");
		return;
	}
	else if(front == rear){  
		front = -1;
		rear = -1;
	}

	else{		
		front += 1;
  }
}
