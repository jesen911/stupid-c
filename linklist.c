/*what's wronge with these code?*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t ** head, int val) {
    node_t * current;
    node_t * privious;
    current = *head;
    privious = *head; 
    if (current-> val == val) return pop(head);
    if (head == NULL) return -1;
    while(current->val != val){
    	privious = current;
        current = current->next;
    }
    privious->next = current->next;
    free(current);
    return -1;
    /* TODO: fill in your code here */
}
int recreat_list(node_t ** head1,int times){
    node_t *temp;
    temp = *head1;
    int n ;
    for(n=1;n<=times;n++){
    	temp->val = n;
        temp->next = malloc(sizeof(node_t));
        temp = temp->next;
        temp->next = NULL;
        
        
    }
    free(temp);
    return 1;
}

int main() {

    node_t * test_list = malloc(sizeof(node_t));
    
    /*test_list->val = 1;
    test_list->next = malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;*/
    recreat_list(&test_list,5);
    remove_by_value(&test_list, 3);

    print_list(test_list);
}
