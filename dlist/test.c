#include <stdio.h>
#include "data.h"

int main(void)
{
    static dlist_node_t head;
    DLIST_INIT(&head);

    data_t data1 = { .node = 0, .dt = 1};
    data_t data2 = { .node = 0, .dt = 2};
    data_t data3 = { .node = 0, .dt = 3};
    data_t data4 = { .node = 0, .dt = 4};
    data_t data5 = { .node = 0, .dt = 5};
    data_t data6 = { .node = 0, .dt = 6};
    data_t data7 = { .node = 0, .dt = 7};
    data_t data8 = { .node = 0, .dt = 8};

    dlist_insert_front(&head, (dlist_node_t*)&data1);
    dlist_insert_front(&head, (dlist_node_t*)&data2);
    dlist_insert_front(&head, (dlist_node_t*)&data3);
    dlist_insert_front(&head, (dlist_node_t*)&data4);
    dlist_insert_front(&head, (dlist_node_t*)&data5);
    dlist_insert_front(&head, (dlist_node_t*)&data6);
    dlist_insert_front(&head, (dlist_node_t*)&data7);
    dlist_insert_front(&head, (dlist_node_t*)&data8);

    dlist_node_t *p;
    TRAVERSE(p, &head){
        printf(" %d ", CONTAINER_OF(p, data_t, node)->dt);
    }
    printf("\r\n");
    RETRAVERSE(p, &head){
        printf(" %d ", CONTAINER_OF(p, data_t, node)->dt);
    }
    printf("\r\n");

    
    return 0;
}
