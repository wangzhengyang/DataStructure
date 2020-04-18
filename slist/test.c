#include "data.h"
#include "stdio.h"
#include "slist.h"


static slist_node_t head;

int main()
{
    SLIST_INIT(&head);
    data_t data1 = { .node = 0, .dt = 1, };
    data_t data2 = { .node = 0, .dt = 2, };
    data_t data3 = { .node = 0, .dt = 3, };
    data_t data4 = { .node = 0, .dt = 4, };
    data_t data5 = { .node = 0, .dt = 5, };
    data_t data6 = { .node = 0, .dt = 6, };
    data_t data7 = { .node = 0, .dt = 7, };
    data_t data8 = { .node = 0, .dt = 8, };
    
    push_front(&head, (slist_node_t*)&data1);
    push_front(&head, (slist_node_t*)&data2);
    push_front(&head, (slist_node_t*)&data3);
    push_front(&head, (slist_node_t*)&data4);
    push_front(&head, (slist_node_t*)&data5);
    push_front(&head, (slist_node_t*)&data6);
    push_front(&head, (slist_node_t*)&data7);
    push_front(&head, (slist_node_t*)&data8);

    slist_node_t *p;
    Traverse(p, &head){
       printf(" %d ", container_of(p, data_t, node)->dt); 
    }
    printf("\r\n");


    return 0;
}
