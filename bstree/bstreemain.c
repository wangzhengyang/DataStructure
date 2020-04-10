#include <bstree.h>

int main()
{
    bst_node_t node1, node2, node3, node4, node5, node6, node7, node8, node9, node10, node11, node12;
    bstree_t bstree;
    bstree_node_init(&node1, 15);
    bstree_node_init(&node2, 5);
    bstree_node_init(&node3, 3);
    bstree_node_init(&node4, 12);
    bstree_node_init(&node5, 10);
    bstree_node_init(&node6, 13);
    bstree_node_init(&node7, 6);
    bstree_node_init(&node8, 7);
    bstree_node_init(&node9, 16);
    bstree_node_init(&node10, 20);
    bstree_node_init(&node11, 18);
    bstree_node_init(&node12, 23);
    bstree_init(&bstree);
    
    bstree_insert(&bstree, &node1);
    bstree_insert(&bstree, &node2);
    bstree_insert(&bstree, &node3);
    bstree_insert(&bstree, &node4);
    bstree_insert(&bstree, &node5);
    bstree_insert(&bstree, &node6);
    bstree_insert(&bstree, &node7);
    bstree_insert(&bstree, &node8);
    bstree_insert(&bstree, &node9);
    bstree_insert(&bstree, &node10);
    bstree_insert(&bstree, &node11);
    bstree_insert(&bstree, &node12);
    
    midorder_traversal(bstree.root);
    
    printf("\r\n");
    printf("min is %d\r\n", bstree_min(bstree.root)->key);
    printf("max is %d\r\n", bstree_max(bstree.root)->key);
    
    printf("given key is 7, find next is %d\r\n", bstree_successor(bstree_search(&bstree, 7))->key);
    printf("given key is 7, find prev is %d\r\n", bstree_predecessor(bstree_search(&bstree, 7))->key);
    
    printf("given key is 15, find next is %d\r\n", bstree_successor(bstree_search(&bstree, 15))->key);
    printf("given key is 15, find prev is %d\r\n", bstree_predecessor(bstree_search(&bstree, 15))->key);
 
    printf("given key is 12, find next is %d\r\n", bstree_successor(bstree_search(&bstree, 12))->key);
    printf("given key is 12, find prev is %d\r\n", bstree_predecessor(bstree_search(&bstree, 12))->key);
    
    
    printf("delete the key is 13\r\n");
    bstree_delete(&bstree, bstree_search(&bstree, 13));
    midorder_traversal(bstree.root);
    printf("\r\n"); 
    
    printf("delete the key is 15\r\n");
    bstree_delete(&bstree, bstree_search(&bstree, 15));
    midorder_traversal(bstree.root);
    printf("\r\n"); 
    
    printf("delete the key is 16\r\n");
    bstree_delete(&bstree, bstree_search(&bstree, 16));
    midorder_traversal(bstree.root);
    printf("\r\n"); 
    
    printf("delete the key is 1\r\n");
    bstree_delete(&bstree, bstree_search(&bstree, 1));
    midorder_traversal(bstree.root);
    printf("\r\n"); 
    
    printf("delete the key is 5\r\n");
    bstree_delete(&bstree, bstree_search(&bstree, 5));
    midorder_traversal(bstree.root);
    printf("\r\n"); 
  
    printf("delete the key is 20\r\n");
    bstree_delete(&bstree, bstree_search(&bstree, 20));
    midorder_traversal(bstree.root);
    printf("\r\n"); 
    return 0;
}


