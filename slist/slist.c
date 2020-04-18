#include "slist.h"

void push_front(slist_node_t *head, slist_node_t *node)
{
    slist_node_t *temp = head->next;
    node->next = temp;
    head->next = node;
}

void push_back(slist_node_t *head, slist_node_t *node)
{
    slist_node_t *temp;
    for(temp = head->next; temp->next != head; temp = temp->next);
    temp->next = node;
    node->next = head;
}

slist_node_t *pop_front(slist_node_t *head)
{
    slist_node_t *temp = (void*)0;
    if(head->next != head)
    {
        temp = head->next;
        head->next = head->next->next;
    }
    return temp;
}

slist_node_t *pop_back(slist_node_t *head)
{
    slist_node_t *temp = (void*)0;
    slist_node_t *prev = (void*)0;
    if(head->next != head){
        for(temp = head->next; temp->next != head; temp = temp->next){
            prev = temp;
        }
    }
    prev->next = head;
    return temp;
}
