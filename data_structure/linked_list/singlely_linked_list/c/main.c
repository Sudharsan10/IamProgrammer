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
 * Lets create a function to insert after a given node
 */
void insertAfter(struct Node* root, int target_id, int data) {
    while(root){
        if (root->id == target_id) {
            struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
            new_node->id = target_id+1;
            new_node->data = data;
            new_node->next = root->next;
            root->next = new_node;
            autoIncreaseId(new_node->next);
            break;
        }
        else root = root->next;
    }
}

int main() {
    srand(time(0));
    traverse_and_display_node_values(create_n_node(10));
    struct Node* root = create_n_node(10);
    autoIncreaseId(root);
    insertAfter(root, 6, 345);
    traverse_and_display_node_values(root);
    return 0;
}