#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int grading(char);

typedef struct node{
	int credits;
	char code[8];
	char grade;
	float cgpa;
	struct node * next; 
}node;

float total_creds;
node *head; 

node* createnode(){
	node * newnode =(node*)malloc(sizeof(node));
	printf("Enter the subject code: ");
	scanf("%s",newnode->code);
	printf("Enter grade obtained: ");
	scanf("%s",&newnode->grade);
	printf("Enter the total credits of the subject: ");
	scanf("%d",&newnode->credits);
	return newnode;
}

void insert(){
	node * temp = head; 
	node* newnode = createnode();
	newnode->next = head; 
	head = newnode;
}

void calculate(int n){
	int i,sum=0;
	node*temp = head;
	//summation of credits*grade
	for(i = 0 ; i<n; i++){
		while(temp!=NULL){
			sum+=temp->credits;
			total_creds += temp->credits*grading(temp->grade);
			temp = temp->next;
		}
	}
	free(temp);
	printf("Total cred score obtained: %0.2f",total_creds);

	//total credits:
	head->cgpa = total_creds/sum;
	
	//cgpa obtained
	printf("\n\nObtained cgpa:  %f\n",head->cgpa);
}

int grading(char ch){
	char x= toupper(ch);
	if(x=='O')
		return 10;
	else if(x=='A')
		return 9; 
	else if(x=='B')
		return 8;
	else if(x=='C')
		return 7;
	else
	{
		printf("INVALID grade :%c",x);
		return 0;
	}
}

int main(){
	int i , n;
	head = NULL;
	printf("Enter the total number of subjects:");
	scanf("%d",&n);
	for(i = 0; i < n ; i++){
		insert();
	}
	calculate(n);
	return 0; 
}

