#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to display the contents of the list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) { //traversing a linked list
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated for the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int size_list(struct Node* head){
    int size;
    struct Node* temp = head;
    size = 0;
    while(temp->next != NULL){
        size++;
        temp = temp->next;
    }
    return ++size;
}

// Function to create an empty linked list
struct Node* createEmptyLinkedList() {
    return NULL; // Return NULL to indicate an empty list
}

// Function to add an element to the end of the linked list
struct Node* append(struct Node* head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // Traverse the list to find the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Append the new node to the end of the list
    temp->next = newNode;
    return head;
}

void append_2(struct Node* head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
      //  return head;
    }

    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        head = newNode;
      //  return head;
    }

    // Traverse the list to find the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Append the new node to the end of the list
    temp->next = newNode;
//    return head;
}


void append_at_pos(struct Node* head, int pos, int elem) {
    int size;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
       // return head;
    }
    newNode->data = elem;
    newNode->next = NULL;
    size = size_list(head);
    struct Node* temp = head;
    for(int i = 0; i<pos; i++){
        temp = temp->next;
    }
    struct Node* temp_next = temp->next;
    temp->next = newNode;
    newNode->next = temp_next;
}

//struct Node* 
void delete_element(struct Node* head, int elem){
    struct Node* temp = head;
    struct Node* prev_temp = head;
    struct Node* next_temp = head;

    while(temp->next != NULL){
        prev_temp = temp;
        temp = temp->next;
        next_temp = temp-> next;
        if(temp->data == elem){
            prev_temp->next = next_temp;
        }
    }
    
 //   return head;
}

int main() {
    // Create an empty linked list
    struct Node* head = createEmptyLinkedList();

    // Append elements to the end of the linked list
    //head = 
    append_2(head, 10);
    head = append(head, 20);
    //head = 
    append_2(head, 30);
    //head = 
    append_2(head, 40);

    //head = 
    append_at_pos(head, 1, 25);

    // Display the contents of the list
    printf("Linked List: ");
    display(head);

    printf("Size: %0d \n" ,size_list(head));

    delete_element(head, 20);
    
    printf("Linked List: ");
    display(head);
    printf("Size: %0d" ,size_list(head));

    // Free memory allocated for the list
    freeList(head);

    return 0;
}
