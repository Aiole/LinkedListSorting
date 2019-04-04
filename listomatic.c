#include<stdio.h>
#include<stdlib.h>


typedef struct dll_node {
    int value;
    struct dll_node *prev;
    struct dll_node *next;
} dll_node_t;

typedef struct dll_node *node, *count, *back;

node createNode() {
  node temp; 
  temp = (node)malloc(sizeof(struct dll_node));//space
    temp->next = NULL;
    return temp;
}


node addNode(node head, int val){
  node temp,p;
    temp = createNode();
    temp->value = val;//add element's value to value
    if (head == NULL){
        head = temp;//empty
    }
    else {
        p  = head;//assign head to p
	
        while(p->next != NULL) {
            p = p->next;
	    
        }
        p->next = temp;


    }
    return head;
}

void printList(node node) {
 
  while (node != NULL) {
     printf("%d\n", node->value); //Iterates and prints
     node = node->next;
  }
  

}

int printInputs(node node) {
  int f = 1;
 
  while (node->next != NULL) {
     // printf("%d\n", node->value);
     node->next->prev = node;
     node = node->next;
     f++;
  }
  

  printf("Read %d integers\n",f);
 
  return f;
  
 

}



void ascList(node count, node node) { //orders the list based on value
  
  while(node->next != NULL) {
    
    for(count = node->next; count != NULL; count = count->next) { 
	
      if(node->value > count->value){ //iterating and comparing
       int temp = node->value;
       node->value = count->value;
       count->value = temp;
       }
       
      }
    
      node = node->next;
     }
   
}


void backList(node node) { //no u
 
  while (node->next != NULL) { // reaches end point
     // printf("%d\n", node->value);
     node->next->prev = node;
     node = node->next;
  }
  
  printf("%d\n", node->value);
  
  while(node->prev != NULL) { //prints backwards
     node = node->prev;
     printf("%d\n", node->value);
  }

}



int isHeadOfList(node head, node node) {
  return node == head;
}


node scanList(node temphead, node node){ //bad idea
  
  temphead = node;
  
  while (node->next != NULL) {
    //printf("%d\n", node->value);
     node->next->prev = node;
     temphead->next->prev = temphead;
     node = node->next;
     temphead = node;
 
  }
  
  return temphead;

}


struct arrWrap { 
    int a[100]; 
}; 

struct arrWrap back2(node node) { 
    struct arrWrap x;
    int i = 0;
    
    while (node->next != NULL) {//bascially a psuedo linked list copy
     x.a[i] = node->value;
     node = node->next;
     i++;
     }

      x.a[i] = node->value;
     
    return x; 
} 

int main(void) {
  node head = NULL;
  int curnum, f;
  
  while (scanf("%d", &curnum) == 1) {
    head = addNode(head, curnum);
    
  }
  //magic  |
  //      \|/
  //       v
  struct arrWrap x = back2(head);
  f = printInputs(head);
  ascList(head,head);
  backList(head);
  printList(head);
  f--;
  while (f>=0){
    printf("%d\n",x.a[f]);
    f--;
  }



  
}
