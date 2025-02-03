//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,d,*head;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8

/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    b.next = &d;
    d.value = 11; 
    // b.next->value = 11;
    // a.next->next->value = 11;
    // head->next->next->value = 11;
    d.next = NULL;
    printf("%d\n", head->next->next->value);
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    struct node f;
    f.next = &a;
    head = &f;
    f.value = 2;
    printf("%d\n", head->value);

    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    //  Exercise III Use loop to print everything
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    
   // Exercise IV change to while loop!! (you can use NULL to help)
         tmp = head;
         while(tmp != NULL){
            printf("%3d", tmp->value);
            tmp = tmp->next;
        }
    
 //  Exercise V Use malloc to create all nodes, instead of create a struct!!

    // typedef struct node* nodePtr;
    //NodePtr Head, temp;  struct node *head, *temp;

    head = (NodePtr)malloc(sizeof(struct node));
    tmp = head;
    printf("\n");

    for(int i=0; i<3; i++){
        tmp->value = i + 3;
        tmp->next = (NodePtr)malloc(sizeof(struct node));
        tmp = tmp->next;
    }

    tmp->value = i + 3;
    tmp->next = NULL;

    tmp = head;
         while(tmp != NULL){
            printf("%3d", tmp->value);
            tmp = tmp->next;
        }

    //  Exercise VI Free all node !!
    
    printf("\n");
    tmp = head;
    while(head != NULL){
        head = head->next;
        printf("Free!\n");
        free(tmp);
        tmp = head;
    }      
    
    return 0;
}
