#include <queue>
using namespace std;

#include "bst.h"

static void Tranversal(queue<cyx::bst_node*>& q);

cyx::bst::bst() {
	m_root = NULL;	
}

cyx::bst::~bst() {
	if (m_root != NULL) {
		Clear(m_root->left);
	}
}

void cyx::bst::Insert(const int& value) {
	bst_node* newnode = new bst_node(value);
	Insert(newnode);
}

void cyx::bst::Insert(bst_node* node) {
	if (node == NULL) {
		return;
	}
	if (m_root == NULL) {
		m_root = node;
		return;
	}
	int key = node->key;
	bst_node* tmp = m_root;
	bst_node* pre = m_root;
	while(tmp != NULL) {
		pre = tmp;
		if (key >= tmp->key) {
			tmp = tmp->right;
		}else {
			tmp = tmp->left;
		}
	}
	node->parent = pre;
	if (key >= pre->key) {
		pre->right = node;
	}else {
		pre->left = node;
	}
}

cyx::bst_node* cyx::bst::Find(const int& value) {
	if (m_root == NULL) {
		return NULL;
	}
	bst_node* tmp = m_root;
	while (tmp != NULL) {
		if (tmp->key == value) {
			return tmp;
		}else if (tmp->key < value) {
			tmp = tmp->right;
		}else {
			tmp = tmp->left;
		}
	}
	return NULL;
}

void cyx::bst::Translate(bst_node* src, bst_node* swapnode) {
	if (src->parent == NULL) {
		m_root = swapnode;
	}else if (src == src->parent->left) {
		src->parent->left = swapnode;
	}else {
		src->parent->right = swapnode;
	}
	if (swapnode != NULL) {
		swapnode->parent = src->parent;
	}
}

cyx::bst_node* cyx::bst::TreeMin(bst_node* node) {
	bst_node* tmp = node;
	bst_node* pre = node;
	while (tmp != NULL) {
		pre = tmp;
		tmp = tmp->left;
	}
	return pre;
}

void cyx::bst::Delete(const int& value) {
	bst_node* tmp = Find(value);
	bst_node* y = NULL;
	if (tmp == NULL) {
		return;
	}
	if (tmp->left == NULL) {
		Translate(tmp, tmp->right);
	}else if (tmp->right == NULL) {
		Translate(tmp, tmp->left);
	}else {
		y = TreeMin(tmp->right);
		if (y->parent != tmp) {
			Translate(y, y->right);
			y->right = tmp->right;
			y->right->parent = y;
		}
		Translate(tmp, y);
		y->left = tmp->left;
		y->left->parent = y;
	}
	delete tmp;
	tmp = NULL;
}

void cyx::bst::Clear(bst_node* root) {
	if (root == NULL) {
		return;
	}
	Clear(root->left);
	Clear(root->right);
	delete root;
	root = NULL;
}

void cyx::bst::InorderTraversal(bst_node* node) {
	if (node == NULL) {
		return;
	}
	InorderTraversal(node->left);
	cout << node->key << " ";
	InorderTraversal(node->right);
}

void cyx::bst::PreorderTraversal(bst_node* node) {
	if (node == NULL) {
		return;
	}
	cout << node->key << " ";
	PreorderTraversal(node->left);
	PreorderTraversal(node->right);
}

void cyx::bst::PostorderTraversal(bst_node* node) {
	if (node == NULL) {
		return;
	}
	PostorderTraversal(node->left);
	PostorderTraversal(node->right);
	cout << node->key << " ";
}

void cyx::bst::SequenceTraversal() {
	//每次从队列里取出一个元素，并把它的左右节点入队（如果有的话）
	queue<bst_node*> qbstnodes;
	qbstnodes.push(m_root);
	Tranversal(qbstnodes);
}

static void Tranversal(queue<cyx::bst_node*>& q) {
	if (q.empty()) {
		return;
	}
	cyx::bst_node* tmp = q.front();
	q.pop();
	cout << tmp->key << " ";
	if (tmp->left != NULL) {
		q.push(tmp->left);
	}
	if (tmp->right != NULL) {
		q.push(tmp->right);
	}
	Tranversal(q);
}
