#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Lets define a Node template using struct
 */
struct Node {
    int id;
    int data;
    struct Node* next;
};

/*
 * Lets create a function to create 'n' nodes with data of the order they have been created
 */
struct Node* create_n_node(int N){
    // Create root node
    struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    root -> id = 0;
    root -> data = rand();
    root -> next = NULL;

    // Create a crawler to traverse through the chain of nodes
    struct Node* crawler;
    crawler = root;

    for(int i=1; i<=N-1; i++){
        // create new node
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node -> id = i;
        new_node -> data = rand();
        new_node -> next = NULL;

        crawler -> next = new_node; // Assign new node to crawler's next pointer
        crawler = crawler -> next;  // Move the crawler to point to its next node
    }
    crawler = NULL; // Point crawler to NULL
    return root;
}

/*
 * Lets create a function to traverse the given head node and display each node's value
 */
void traverse_and_display_node_values(struct Node* crawler){
    while (crawler!=NULL){
        printf("# %d -> Data: %d\n", crawler -> id, crawler -> data);
        crawler = crawler -> next;
    }
}

/*
 * Lets create a function to Increase the ID of the node
 */
void autoIncreaseId(struct Node* start) {
    while(start){
        start->id++;
        start = start->next;
    }
}

/*
 * Lets create a function to decrease the ID of the node
 */
void autoDecreaseId(struct Node* start) {
    while(start){
        start->id--;
        start = start->next;
    }
}

/*
 * Lets create a function to insert after a desired node
 */
void insertAfter(struct Node* root, int target_id, int data) {
    while(root){
        if (root->id == target_id) {
            /* Create new node and assign data and ID */
            struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
            new_node->id = target_id+1;
            new_node->data = data;
            new_node->next = NULL;

            /* point new node's pointer to the next in line
             * and point the node before insertion's pointer to new node
             */
            new_node->next = root->next;
            root->next = new_node;

            /* Auto update the ID of rest of the linklist nodes */
            autoIncreaseId(new_node->next);
            break;
        }
        else root = root->next;
    }
}

/*
 * Lets create a function to insert before a desired node
 */
void insertBefore(struct Node** crawler, int target_id, int data) {
    while(*crawler){
        if ((*crawler)->id == target_id) {
            /* Create new node and assign data and ID */
            struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
            new_node->id = target_id;
            new_node->data = data;

            /* point new node's pointer to the next in line
             * and point the node before insertion's pointer to new node
             */
            new_node->next = *crawler;
            *crawler = new_node;

            /* Auto update the ID of rest of the linklist nodes */
            autoIncreaseId((*crawler)->next);
            break;
        }
        else crawler = &(*crawler)->next;
    }
}

/*
 * Push node after last node
 */
void push(struct Node** crawler, int id, int data) {
    /* get to the end of the linked list */
    while(*crawler) crawler = &(*crawler)->next;

    /* create a new node with given data and id */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->id = id;
    new_node->data = data;
    new_node->next = NULL;

    /* create a new node with given data and id */
    (*crawler) = new_node;
}

/*
 * Pop top node
 */
struct Node pop(struct Node** crawler) {
    struct Node* popped_node = *crawler;
    *crawler = (*crawler)->next;
    return *popped_node;
}

/*
 * Delete node by Id
 */
void deleteNodeById(struct Node** crawler, int target_id) {
    struct Node* head = NULL;
    while(*crawler){
        if ((*crawler)->id == target_id) {
            head = *crawler;
            (*crawler) = (*crawler)->next;
            free(head);

            /* Auto update the ID of rest of the linklist nodes */
            autoDecreaseId((*crawler));
            break;
        }
        else crawler = &(*crawler)->next;
    }
}

int main() {
    srand(time(0));
    printf("Create 10 node Singly linked list: \n");
    traverse_and_display_node_values(create_n_node(10));

    struct Node* root = create_n_node(10);
    autoIncreaseId(root);

    printf("\nBefore Insertion: \n");
    traverse_and_display_node_values(root);

    printf("\nAfter Insertion: \n");
    insertBefore(&root, 1, 345);
    insertAfter(root, 6, 465);
    traverse_and_display_node_values(root);

    printf("\nAfter Delete: \n");
    deleteNodeById(&root, 5);
    traverse_and_display_node_values(root);

    printf("\nAfter Push: \n");
    push(&root, 15, 5468);
    traverse_and_display_node_values(root);

    struct Node popped = pop(&root);
    printf("\nI popped it, its Id: %d, data %d\n", popped.id, popped.data);
    traverse_and_display_node_values(root);
    return 0;
}