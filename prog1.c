#include <stdio.h>
#include <stdlib.h>

typedef struct List{
	int ind;
	struct List *next;
} List;

int AddEl(List **head, int val){
	List *tmp = (List*) malloc(sizeof(List));
	if(*head == NULL){
		tmp->ind = val;
		tmp->next = NULL;
		(*head) = tmp;
	}else{
		tmp->ind = val;
		tmp->next = *head;
		*head = tmp;
	}
	
	return 0;
}

int DelEl(List **head, int val){
	if (*head ==NULL) return 0;
	List *tmp = *head;
	if(tmp->ind == val){
		*head = tmp->next;
		free(tmp);
		return 0;
	}
	List *tmp1 = tmp->next;
	while(tmp1){
		if(tmp1->ind == val){
			tmp->next = tmp1->next;
			free(tmp1);
			return 0;
		}
		tmp = tmp1;
		tmp1 = tmp1->next;
	}
	return 0;
}

int Output(const List *head){
	printf("\nList: \n");
	while(head){
		printf("%d ", head->ind);
		head = head->next;
	}
	printf("\n");
	return 0;
}

int Menu(){
	printf("\n Menu: \n");
	printf("\n1: Add\n");
	printf("\n2: Delete\n");
	printf("\n3: Print\n");
	printf("\n4: Exit\n");
	return 0;
}
int main(){
	List* head = NULL;
	int fl = 0;
	int val = 0;
	while (fl !=4){
		fl = 0;
		Menu();
		scanf("%d", &fl);
		switch(fl){
			case 1:
				printf("\nInput index to add\n");
				scanf("%d", &val);	
				AddEl(&head, val);
				Output(head);
				break;
			case 2:
				printf("\nInput index to delete\n");
				scanf("%d", &val);
				DelEl(&head, val);
				Output(head);
				break;
			case 3:
				Output(head);
				break;
			case 4: 
				break;
			default:
				printf("\nWrong menu item\n");
		}
	}	
	return 0;
}
