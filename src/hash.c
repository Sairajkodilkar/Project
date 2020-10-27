#include "hash.h"

void inithash(hashtable *h){
	int i;
	*h = (num_node **)malloc(sizeof(num_node *) * SIZE_T);
	for(i = 0; i < SIZE_T; i++){
		(*h)[i] = NULL;
	}
	return;
}

int hashfuct(char *str){
	int i = 0, k = 0, l = strlen(str), prime = 631;
	for(i = 0; i < l; i++){
		k += str[i];
	}
	k = ((10 * k + 1000) % prime) % SIZE_T; //to bring somewhat randomness in k
	return k;
}

	
void insertnum(hashtable *h, char *str, num one){
	int index, flag;
	num_node *temp;
	index = hashfuct(str);

	if((*h)[index] != NULL){
		temp = (*h)[index];

		while(temp->next != NULL){
			if(strcmp(temp->string, str) == 0){
				erasenum(&(temp->one));
				temp->one = one;
				flag = 0;
				break;
			}
			temp = temp->next;
		}
		if(flag && strcmp(temp->string, str) == 0){
			erasenum(&(temp->one));
			temp->one = one;
			flag = 0;
		}
		if(flag){
			temp->next = (num_node *)malloc(sizeof(num_node));
			temp = temp->next;
			strcpy(temp->string, str);
			temp->one = one;
			temp->next = NULL;
		}
	}
	else{
		(*h)[index] =  (num_node *)malloc(sizeof(num_node));
		temp = (*h)[index];
		strcpy(temp->string, str);
		temp->one = one;
		temp->next = NULL;
	}
	return;
}

num search(hashtable h, char *str){
	int key;
	num_node *temp;
	num error;
	initnum(&error);
	error.sign = 2;

	key = hashfuct(str);
	temp = h[key];

	while(temp != NULL){
		if(strcmp(temp->string, str) == 0){
			return temp->one;
		}
		temp = temp->next;
	}
	return error;
}



















