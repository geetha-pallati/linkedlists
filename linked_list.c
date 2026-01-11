#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
 int data;
 struct Node* next;
}Node;
Node* create_node(int value){
    Node* n = (Node*) malloc(sizeof(Node));
    n->data = value;
    n->next = NULL;
    return n;

}
int insert_node_beganing(Node** head, int value){
    Node* n = create_node(value);
    n->next = *head;
    *head =  n; 
}
void insert_node_end(Node** head, int value){
        Node* n = create_node(value);
        if(*head == NULL){
            *head= n;
            return ;
        }
        Node* curr = *head;
        while (curr->next != NULL)
        {
            curr = curr->next ;
        }
        curr->next = n;
        

}
// int insert_node_at_position(Node** head, int value, int pos){
//     if(pos <= 0 && *head == NULL){
//         insert_node_beganing(*head,value);
//         return
//     }
//     Node* curr = *head;
//     int idx = 1;
//     while (curr->next !=NULL && idx< pos)
//     {
//         curr = curr->next;
//         idx++;
//         /* code */
//     }
    
    
    

// }
int insert_node_at_position(Node** head, int value, int pos){
    int id = 1;
    Node* n = (Node*)malloc(sizeof(Node));
    if(n){
        printf("error creating a node");
        return 0;
    }
    Node* curr = *head;
    if(pos == 1){
        curr->next = *head;
        *head = n;
    }
    else{
        while(curr != NULL && id<pos){
            id++;
            curr = curr->next;
        }
        
    }

}
int reverse_linked_list(Node** head){
    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    
}   

int remove_node(Node **head, int pos){
    Node *curr = *head, *prev = NULL;
    if( curr == NULL && pos == NULL)
        return -1;
    if(pos == 1){
        *head = curr->next;
        free(curr);
        return -1; 
    }
    for(int i = 0; curr != NULL && i<pos; i++){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        printf("invalid postion");
        return -1;
    }
    prev->next = curr->next;
    free(curr); 
}

void print_link(Node* head){
    Node* curr =  head;
    while(curr != NULL)
    {
        printf("%d",curr->data);
        curr = curr->next;
    }

}
int main(){
    Node* head = NULL;
    insert_node_beganing(&head, 10);
    insert_node_beganing(&head, 20);
    insert_node_beganing(&head, 30);
    insert_node_end(&head,90);
    print_link(head);
    remove_node(&head, 4);
    printf("\n");
    print_link(head);    

    
}