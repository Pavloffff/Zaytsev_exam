#include "tree.h"
#include "transform.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

Tree delete_expression(Tree t) {
	if (t == NULL) {
		return t;
	}
	delete_expression(t->left);
	delete_expression(t->right);
	if (t->node.type == OPERATOR && t->node.data.operator_name == '+') {
		if (t->left->node.type == INTEGER && t->left->node.data.value_int == 0) {
			Tree tmp = t->right;
			free(t);
			t = tmp;
		}
		if (t->right->node.type == INTEGER && t->right->node.data.value_int == 0) {
			Tree tmp = t->left;
			free(t);
			t = tmp;
		} 
	}
	if (t->node.type == OPERATOR && t->node.data.operator_name == '*') {
		if (t->left->node.type == INTEGER && t->left->node.data.value_int == 1) {
			Tree tmp = t->right;
			free(t);
			t = tmp;
		}
		if (t->right->node.type == INTEGER && t->right->node.data.value_int == 1) {
			Tree tmp = t->left;
			free(t);
			t = tmp;
		} 
	}
	return t;
}
