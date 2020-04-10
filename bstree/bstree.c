#include "bstree.h"

bst_node_t *bstree_search(bstree_t *tree, unsigned int k) //使用循环查找
{
	bst_node_t *temp = tree->root;
	while((temp != NULL) && (temp->key != k)){
		if (k < temp->key)
			temp = temp->left;
		else 
			temp = temp->right;
	}
	return temp;
}

void bstree_insert(bstree_t *tree, bst_node_t *node)
{
	bst_node_t *temp = tree->root;
	bst_node_t *p = NULL;
	while(temp != NULL){
		p = temp;
		if(node->key < temp->key)
			temp = temp->left;
		else 
			temp = temp->right;
	}
	node->parent = p;
	if(p == NULL)
		tree->root = node;
	else if(node->key < p->key)
		p->left = node;
	else
		p->right = node;
}

bst_node_t *bstree_min(bst_node_t * node)
{
	bst_node_t *temp = node;
	while(temp != NULL && temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

bst_node_t *bstree_max(bst_node_t * node)
{
	bst_node_t *temp = node;
	while(temp != NULL && temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

bst_node_t *bstree_successor(bst_node_t * node)
{
	bst_node_t *temp = node;
	bst_node_t *p = NULL;
	if(temp->right != NULL)
		return bstree_min(temp->right);

	p = node->parent;
	while(p != NULL && p->right == temp){
		temp = p;
		p = p->parent;
	}
	return p;
}

bst_node_t *bstree_predecessor(bst_node_t * node)
{
	bst_node_t *temp = node;
	bst_node_t *p = NULL;
	if(temp->left != NULL)
		return bstree_max(temp->left);
	p = temp->parent;
	while(p != NULL && p->left == temp){
		temp = p;
		p = p->parent;
	}
	return p;
}

static void bstree_node_replace(bst_node_t *old, bst_node_t *nw)
{
    nw->parent = old->parent;
    if(old->parent != NULL){
        if(old->parent->left == old)
            old->parent->left = nw;
        else
            old->parent->right = nw;
    }
}

bst_node_t *bstree_delete(bstree_t *tree, bst_node_t *node)
{
	bst_node_t *temp = NULL;
    if(node == NULL)
        return NULL;
    
    if(node->left == NULL){
        temp = node->right;
        bstree_node_replace(node, temp);
    }else if(node->right == NULL){
        temp = node->left;
        bstree_node_replace(node, temp);
    }else{
        temp = bstree_successor(node);
        bstree_node_replace(temp, temp->right);
        temp->parent = node->parent;
        if(node->parent != NULL){
            if(node->parent->left == node)
                node->parent->left = temp;
            else
                node->parent->right = temp;
        }
        temp->left = node->left;
        node->left->parent = temp;
        temp->right = node->right;
        temp->right->parent = temp;
    }
    if(temp->parent == NULL)
        tree->root = temp;
	return node;
}


//test
void midorder_traversal(bst_node_t *root)
{
	bst_node_t *temp = root;
	if(temp != NULL){
		midorder_traversal(temp->left);
		printf(" %d ", temp->key);
		midorder_traversal(temp->right);
	}
}