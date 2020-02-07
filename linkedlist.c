#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int val;
  struct node *next, *prev;
}node;

node* getTail(node* x){
  if(x==NULL){
    return NULL;
  }
  while(x -> next != NULL){
    return getTail(x->next);
  }
  return x;
}

node* getHead(node* x){
  if(x==NULL){
    return NULL;
  }
  while(x -> prev != NULL){
    return getHead(x->prev);
  }
  return x;
}

void removeTail(node* b){
  b = getTail(b);
  if(b == NULL){
    
  }
  else if(b-> prev != NULL){
    b -> prev -> next = NULL;
    b -> prev = NULL;
    free(b);
  }
  else{
    b -> next = NULL;
    free(b);
  }
}
void insertBack(int x,node* b){
  b = getTail(b);
  node* temp = malloc(sizeof(node*));
  temp->val = x;
  b->next = temp;
  temp->prev = b;
  temp->next = NULL;
}


int main(){
  node* storage;
  int size = 0;
  int i = 0;
  int value = 0;
  printf("Enter how many values to input: ");
  scanf("%d", &size);
  storage = malloc(size);
  while(i < size){
    printf("Enter value %d: ",i);
    scanf("%d", &value);
    if(i == 0){
      storage -> val = value;
      storage -> prev = NULL;
      storage -> next = NULL;
    }
    else{   
      insertBack(value,storage);
    }
    i++;
  }
  storage = getTail(storage);
  while(storage != NULL){
    printf("%d \n",storage->val);
    storage = storage->prev;
  }
  while(size>0){
    size--;
    storage = getHead(storage);
    removeTail(storage);
  }
  free(storage);
  return 0;
}
