#ifndef _RBTREE_H
#define _RBTREE_H

#include <stdio.h>

typedef struct rbtree_node rbtree_node_t;
typedef struct rbtree rbtree_t;

#define rbt_set_red(node) ((node)->color = 1)
#define rbt_set_black(node) ((node)->color = 0)
#define rbt_is_red(node) ((node)->color)
#define rbt_is_black(node)	(!rbt_is_red(node))
#define rbt_copy_color(n1, n2) ((n1)->color = (n2)->color)

#define rbt_sentinel_init(node) (rbt_set_black(node))

#define rbtree_init(tree, s) \
	rbt_sentinel_init(s); \
	(tree)->root = s; \
	(tree)->sentinel = s
	

struct rbtree_node{
	unsigned int key;
	unsigned char color;

	rbtree_node_t *left;
	rbtree_node_t *right;
	rbtree_node_t *parent;
};

struct rbtree{
	rbtree_node_t *root;
	rbtree_node_t *sentinel;
};



#endif
