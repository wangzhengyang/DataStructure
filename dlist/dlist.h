#ifndef _DLIST_H
#define _DLIST_H

typedef struct dlist_node{
    struct dlist_node *next;
    struct dlist_node *prev;
}dlist_node_t;


#define DLIST_INIT(head)    ((head)->next = head, (head)->prev = head)

#define CONTAINER_OF(p, type, member)   ((type*)((unsigned long)p - (unsigned long)(&((type*)0)->member))) 

void dlist_insert_front(dlist_node_t *head, dlist_node_t *node);
void dlist_insert_tail(dlist_node_t *head, dlist_node_t *node);
void dlist_insert_prev(dlist_node_t *curr, dlist_node_t *node);
void dlist_insert_after(dlist_node_t *curr, dlist_node_t *node);

#define TRAVERSE(p, head)   for((p) = (head)->next; (p) != (head); (p) = (p)->next)
#define RETRAVERSE(p, head) for((p) = (head)->prev; (p) != (head); (p) = (p)->prev)

#endif
