#ifndef _BSTREE_H
#define _BSTREE_H

#include <stdio.h>

typedef struct bstree_node bst_node_t;

struct bstree_node{
	unsigned int key;

	bst_node_t *left;
	bst_node_t *right;
	bst_node_t *parent;
};

typedef struct bstree{
	bst_node_t *root;
}bstree_t;

#define bstree_node_init(node, k) \
        (node)->key = (k); \
        (node)->left = (node)->right = (node)->parent = NULL
           
#define bstree_init(tree) \
        (tree)->root = NULL

void bstree_insert(bstree_t *tree, bst_node_t *node);
bst_node_t *bstree_delete(bstree_t *tree, bst_node_t *node);
bst_node_t *bstree_search(bstree_t *tree, unsigned int k); //以k值查找
bst_node_t *bstree_min(bst_node_t *node);
bst_node_t *bstree_max(bst_node_t *node);
bst_node_t *bstree_successor(bst_node_t *node); //后继
bst_node_t *bstree_predecessor(bst_node_t *node);//前趋
void midorder_traversal(bst_node_t *root); //测试用函数
#endif
