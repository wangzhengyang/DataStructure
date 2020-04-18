#include "dlist.h"

static void _insert(dlist_node_t *prev, dlist_node_t *next, dlist_node_t *node)
{
    prev->next = node;
    next->prev = node;
    node->prev = prev;
    node->next = next;
}

void dlist_insert_front(dlist_node_t *head, dlist_node_t *node)
{
    _insert(head, head->next, node);
}

void dlist_insert_tail(dlist_node_t *head, dlist_node_t *node)
{
    _insert(head->prev, head, node);    
}

void dlist_insert_prev(dlist_node_t *curr, dlist_node_t *node)
{
    _insert(curr->prev, curr, node);
}

void dlist_insert_after(dlist_node_t *curr, dlist_node_t *node)
{
    _insert(curr, curr->next, node);
}


