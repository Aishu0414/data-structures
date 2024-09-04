#include<stdio.h>
#define cap 5
int arr[cap];
int top=-1;
int isfull(){
	if(top==cap-1){
		return 1;
	}
	else{
		return 0;
	}
}
	void push (int data){
		if (isfull()==1){
			printf("overflow error\n");
		}
		else{
			top++;
			arr[top]=data;
		}
	}
	int isempty(){
		if(top==-1){
			return 1;
		}
		else{
			return 0;
		}
	}
	int pop(){
		if(isempty()==1){
			printf("underflow error");
			if(top=-1){
				return -1;
			}
			else{
				return 0;
			}
		}
		else{
			top--;
			return arr[top+1];
		}
	}
	int peek(){
		if(isempty()==1){
			printf("stack is empty");
			return -1;
		}
		else{
			return arr[top];
		}
	}
	void printstack(){
		int i;
		if(isempty()==1){
			printf("stack is empty");
		}
		else{
			for(i=0;i<=top;i++){
				printf("%d",arr[i]);
			}
			printf("\n");
		}
	}
	int main(){
		int choice,data;
    do{
    	printf("stack opearation\n 1,push\n 2,pop\n 3,peek\n 4,display stack\n 5,exit\n");
		scanf("%d",&choice);
		
		
		switch(choice){
			case 1:
			printf("enter the element to be push\n");
			scanf("%d",&data);
			push(data);
			break;
			case 2:
			printf("enter the element of the pop\n %d",pop());
			break;
			case 3:
			printf("enter the top:%d\n",peek());
			break;
			case 4:
			printstack();
		}
	}
	while(choice!=5);
	return 0;
	}