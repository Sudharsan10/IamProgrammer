#include <stdio.h>
#include <stdlib.h>

/*
 * Lets define a Node template using struct
 */
struct Node {
    int data;
    struct Node* next;
};

/*
 * Lets create a function to create 'n' nodes with data of the order they have been created
 */
struct Node* create_n_node(int N){
    // Create root node
    struct Node* root = (struct Node*) malloc(sizeof(struct Node));
    root -> data = 0;
    root -> next = NULL;

    // Create a crawler to traverse through the chain of nodes
    struct Node* crawler;
    crawler = root;

    for(int i=1; i<=N-1; i++){
        // create new node
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node -> data = i;
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
        printf("Data: %d\n", crawler -> data);
        crawler = crawler -> next;
    }
}

int main() {
    traverse_and_display_node_values(create_n_node(10));
    return 0;
}