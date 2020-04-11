#include "rbtree.h"

static inline void rbtree_left_rotate(rbtree_t *tree, rbtree_node_t *node)
{
	rbtree_node_t *temp = node->right;

	node->right = temp->left;
	if(temp->left != tree->sentinel)
		temp->left->parent = node;

	temp->parent = node->parent;
	if(node->parent == tree->sentinel){
		tree->root = temp;
	}else if(node->parent->left == node){
		node->parent->left = temp;
	}else{
		node->parent->right = temp;
	}

	temp->left = node;
	node->parent = temp;
}

static inline void rbtree_right_rotate(rbtree_t *tree, rbtree_node_t *node)
{
	rbtree_node_t *temp = node->left;

	node->left = temp->right;
	if(temp->right != tree->sentinel)
		temp->right->parent = node;

	temp->parent = node->parent;
	if(node->parent == tree->sentinel){
		tree->root = temp;
	}else if(node->parent->left == node){
		node->parent->left = temp;
	}else{
		node->parent->right = temp;
	}

	temp->right = node;
	node->parent = temp;
}

void rbtree_insert(rbtree_t *tree, rbtree_node_t *node)
{
	rbtree_node_t *temp = tree->root;
	rbtree_node_t *p = NULL;

	if(temp == tree->sentinel){
		node->parent = tree->sentinel;
		node->left = tree->sentinel;
		node->right = tree->sentinel;
		rbt_set_black(node);
		tree->root = node;
		return;
	}
	//right here, the root node is existed
	while(temp != tree->sentinel){
		p = temp;
		if(node->key < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}

	node->parent = p;
	if(node->key < p->key)
		p->left = node;
	else
		p->right = node;

	node->left = tree->sentinel;
	node->right = tree->sentinel;
	rbt_set_red(node);

	//re-balance the rbtree
	while(rbt_is_red(node->parent)){ //parent of the node is red?
		if(node->parent == node->parent->parent->left){ //parent on the left? 
			temp = node->parent->parent->right; //uncle node

			if(rbt_is_red(temp)){ //uncle is red?
				rbt_set_black(node->parent); //recolor
				rbt_set_black(temp);
				rbt_set_red(node->parent->parent);
				node = node->parent->parent; //node point to grandparent
			}else{ //uncle is black
				if(node == node->parent->right){ //node on the right?
					node = node->parent;  //node point to parent
					rbtree_left_rotate(tree, node); //left rotate
				}
				//node on the left
				rbt_set_black(node->parent); //recolor
				rbt_set_red(node->parent->parent);
				rbtree_right_rotate(tree, node->parent->parent); //right rotate by grandparent
			}
		}else{ //parent on the right
			temp = node->parent->parent->left; //uncle node

			if(rbt_is_red(temp)){ //uncle is red?
				rbt_set_black(node->parent);//recolor
				rbt_set_black(temp);
				rbt_set_red(node->parent->parent);
				node = node->parent->parent; //node point to grandparent
			}else{
				if(node == node->parent->left){//node on the left?
					node = node->parent; //node point to parent
					rbtree_right_rotate(tree, node); //right rotate 
				}
				//node on the right
				rbt_set_black(node->parent); //recolor
				rbt_set_red(node->parent->parent);
				rbtree_left_rotate(tree, node->parent->parent); //left rotate by grandparent
			}
		}
	}

	rbt_set_black(tree->root); //set root black
}

static inline rbtree_node_t *rbtree_min(rbtree_t *tree, rbtree_node_t *node)
{
	rbtree_node_t *temp = node;
	while(temp != tree->sentinel && temp->left != tree->sentinel){
		temp = temp->left;
	}
	return temp;
}


static void rbtree_node_subst(rbtree_node_t *old, rbtree_node_t *nw)
{
	nw->parent = old->parent;
	if(old->parent != NULL){
		if(old->parent->left == old)
			old->parent->left = nw;
		else
			old->parent->right = nw;
	}
}


rbtree_node_t *rbtree_delete(rbtree_t *tree, rbtree_node_t *node)
{
	rbtree_node_t *temp = NULL;
	if(node == NULL)
		return NULL;

	if(node->left == NULL){
		temp = node->right;
		rbtree_node_subst(node, temp);
	}else if(node->right == NULL){
		temp = node->left;
		rbtree_node_subst(node, temp);
	}else{
		temp = rbtree_min(node->right);
		rbtree_node_subst(temp, temp->right);
		
	}

	return node;
}

