#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

void insert(node **head){
    if(*head == NULL){
        *head = (node*)malloc(sizeof(node));
        insert_data(*head);
        (*head)->next = NULL;
        (*head)->prev = NULL;
    }
    else{
        node *temp = *head;
        node *new_data = (node*)malloc(sizeof(node));
        insert_data(new_data);
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_data;
        new_data->prev = temp;
        new_data->next = NULL;
    }
}

void insert_order(node **head){
    node *new_data = (node*)malloc(sizeof(node));
    insert_data(new_data);
    new_data->next = NULL;
    new_data->prev = NULL;
    if(*head == NULL){
        *head = new_data;
    }

    if(new_data->index < (*head)->index){
        new_data->next = *head;
        (*head)->prev = new_data;
        new_data->prev = NULL;
        *head = new_data;
    }
    else{
        node *temp = *head;
        while(temp != NULL && temp != new_data){
            if(temp->next == NULL){
                temp->next = new_data;
                new_data->prev = temp;
                new_data->next = NULL;

                temp = temp->next;
            }
            else if(new_data->index < temp->next->index){
                new_data->next = temp->next;
                new_data->next->prev = new_data;
                new_data->prev = temp;
                temp->next = new_data;

                temp = temp->next;
            }
            else{
                temp = temp->next;
            }
        }
    }
}

void print_list_forward(node **head){
    if(*head != NULL){
        node *temp = *head;
        printf("index : %d\n", temp->index);
        if(temp->next != NULL){
            print_list_forward(&temp->next);
        }
    }
    else{
        printf("lista vazia");
    }
}

void print_list_backward(node **head){
    if(*head != NULL){
        node *temp = *head;
        if(temp->next != NULL){
            print_list_backward(&temp->next);
        }
        printf("index : %d\n", temp->index);
    }
}

void remove_by_index(node **head, int remove){
    if(*head != NULL){
        node *temp = *head;
        while(temp != NULL){
            if(temp == *head && temp->index == remove){
                remove_head(head);
                temp = NULL;
            }
            else if(temp->next == NULL){
                remove_tail(&temp);
                temp = NULL;
            }
            else if(temp->index == remove){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                temp = NULL;
            }
            else{
                temp = temp->next;
            }
        }
    }
}

void remove_head(node **head){
    node *temp = *head;
    if(temp->next != NULL){
        temp->next->prev = NULL;
        *head = temp->next;
        free(temp);
    }
    else{
        free(temp);
    }
}

void remove_tail(node **head){
    node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->next == NULL && temp->prev != NULL){
        temp->prev->next = NULL;
        free(temp);
    }
    else{
        printf("\n===Use remove_head===\n");
    }
}

void clean_list(node **head){
    if((*head)->next != NULL){
        clean_list(&(*head)->next);
    }
    free(*head);
    *head = NULL;
}

void insert_data(node *current){
    printf("index:");
    scanf("%d", &current->index);
    while (getchar() != '\n');
}
