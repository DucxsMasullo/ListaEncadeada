#ifndef listaencadeada
#define listaencadeada

typedef struct node {
    int index;
    struct node *next;
    struct node *prev;
}node;

void insert(node **head);

void insert_order(node **head);

void print_list_forward(node **head);

void print_list_backward(node **head);

void remove_head(node **head);

void remove_tail(node **head);

void remove_by_index(node **head, int remove);

void clean_list(node **head);

void insert_data(node *current);



#endif