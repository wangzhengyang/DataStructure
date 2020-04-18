#ifndef _SLIST_H
#define _SLIST_H

typedef struct slist_node{
    struct slist_node *next;
}slist_node_t;

void push_front(slist_node_t *head, slist_node_t *node);
void push_back(slist_node_t *head, slist_node_t *node);
slist_node_t *pop_front(slist_node_t *head);
slist_node_t *pop_back(slist_node_t *head);

#define container_of(p, type, member)   ((type*)((unsigned long)(p) - (unsigned long)(&(((type*)0)->member))))

#define SLIST_INIT(head)    ((head)->next = (head))

#define Traverse(p, head)   for((p) = (head)->next; (p) != (head); (p) = (p)->next)

#endif
