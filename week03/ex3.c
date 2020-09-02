//Andrey Khoroshavin BS19_02 01/09/20

#include <stdio.h>

typedef struct nod {
    int value;
    struct nod *next;
} node;

typedef struct l_list
{ node* head;} linkedlist;

//print all nodes value
void print_list(linkedlist* llist) {
    if (llist->head == NULL) return;    //empty list => ignore
    node *current = llist->head;
    while (current != NULL) {           //until end is found
        printf("%i ", current->value);
        current = current->next;
    }
    printf("\n"); 
    return;
}

//Put node to index-th place.
//If index is negative or 0, put at begin
//If index > size of list, put at the end
void insert_node(linkedlist* llist, int index, int val){
    if (llist->head == NULL){           //empty list => put at begin
        node* n = malloc(sizeof(node));
        n->value = val;
        n->next = NULL;
        llist->head = n;
        return;
    }
    if (index <= 0){                    //put at begin
        node* n = malloc(sizeof(node));
        n->value = val;
        n->next = llist->head;
        llist->head = n;
        return;
    }
    node *current = llist->head;
    for (int i = 0; i < index - 1; i++){
        if (current->next != NULL)      
            current = current->next;
        else {                          //end is found => put at the end
            node* n = malloc(sizeof(node));
            n->value = val;
            n->next = NULL;
            current->next = n;
            return;
        }
    }
    node* n = malloc(sizeof(node));
    n->value = val;
    n->next = current->next;
    current->next = n;
    return;
}

//delete node by elements value
//If there is no element with such value, do not change list
void delete_node(linkedlist* llist, int val){
    if (llist->head == NULL) return;    //empty list => ignore
    if (llist->head->value == val){     //needed element is first
        node* temp = malloc(sizeof(node));
        temp = llist->head;
        llist->head = llist->head->next;
        free(temp);
        
    }
    node *current = llist->head;
    while (current->next != NULL) {     //until end is found
        if (current->next->value == val){
            free(current->next);
            current->next = current->next->next;
            return;
        }
        else current = current->next;
    }
    return;
}


int main(){
    linkedlist l;
    insert_node(&l, 0, 100);
    insert_node(&l, 5, 10);
    insert_node(&l, -1, 1000);
    print_list(&l); //output: 1000 100 10
    delete_node(&l, 1000);
    print_list(&l); //output: 100 10
 return 0;
}