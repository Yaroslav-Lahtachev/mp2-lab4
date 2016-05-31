#include "AVL.h"

char AVLNode::getBalance() const
{
	return balance;
}

void AVLNode::setBalance(const char balance)
{
	this->balance = balance;
}

void AVLTree::add(AVLNode *&node)
{
	node->parent = 0;
	node->pleft = 0;
	node->pright = 0;
	node->setBalance(0);
	if (!root)
	{
		root = node;
		return;
	}
	ins((AVLNode*&)root, node);
}

void AVLTree::ins(AVLNode *&localRoot, AVLNode *&node)
{
	if (node->key < localRoot->key) {
		if (!localRoot->pleft) {
			localRoot->pleft = node;
			node->parent = localRoot;
		}
		else
			ins((AVLNode*&)localRoot->pleft, node);
	}
	else {
		if (!localRoot->pright) {
			localRoot->pright = node;
			node->parent = localRoot;
		}
		else
			ins((AVLNode*&)localRoot->pright, node);
	}

	needBalance(localRoot);
}

void AVLTree::del(float key)
{
	delete remuve((AVLNode*&)root, key);
}

void AVLTree::del(Node* node)
{
	delete remuve((AVLNode*&)root, node->key);
}

Node* AVLTree::pull(float key)
{
	return remuve((AVLNode*&)root, key);
}

Node* AVLTree::pull(Node* node)
{
	return remuve((AVLNode*&)root, node->key);
}

int AVLTree::rotateRight(AVLNode *&node)
{
	AVLNode *A = node;
	AVLNode *B = (AVLNode*)A->pleft;
	AVLNode *t1 = (AVLNode*)B->pleft;
	AVLNode *t2 = (AVLNode*)B->pright;
	AVLNode *t3 = (AVLNode*)A->pright;

	A->pleft = t2;
	B->pright = A;
	B->parent = A->parent;
	A->parent = B;
	if (t2) t2->parent = A;

	int depA, depB;
	balanceDetection(A, depA);
	balanceDetection(B, depB);

	node = B;
	return depB;
}

int AVLTree::rotateLeft(AVLNode *&node)
{
	AVLNode *A = node;
	AVLNode *B = (AVLNode*)A->pright;
	AVLNode *t1 = (AVLNode*)A->pleft;
	AVLNode *t2 = (AVLNode*)B->pleft;
	AVLNode *t3 = (AVLNode*)B->pright;

	A->pright = t2;
	B->pleft = A;
	B->parent = A->parent;
	A->parent = B;
	if (t2) t2->parent = A;

	int depA, depB;
	balanceDetection(A, depA);
	balanceDetection(B, depB);

	node = B;
	return depB;
}

int AVLTree::DRotateRight(AVLNode *&node)
{
	AVLNode *A = node;
	AVLNode *B = (AVLNode*)A->pleft;
	AVLNode *C = (AVLNode*)B->pright;
	AVLNode *t1 = (AVLNode*)B->pleft;
	AVLNode *t2 = (AVLNode*)C->pleft;
	AVLNode *t3 = (AVLNode*)C->pright;
	AVLNode *t4 = (AVLNode*)A->pright;

	C->pright = A;
	C->pleft = B;
	C->parent = A->parent;
	A->parent = C;
	B->parent = C;
	B->pright = t2;
	A->pleft = t3;
	if (t2) t2->parent = B;
	if (t3) t3->parent = A;

	int depA, depB, depC;
	balanceDetection(A, depA);
	balanceDetection(B, depB);
	balanceDetection(C, depC);

	node = C;
	return depC;
}

int AVLTree::DRotateLeft(AVLNode *&node)
{
	AVLNode *A = node;
	AVLNode *B = (AVLNode*)A->pright;
	AVLNode *C = (AVLNode*)B->pleft;
	AVLNode *t1 = (AVLNode*)A->pleft;
	AVLNode *t2 = (AVLNode*)C->pleft;
	AVLNode *t3 = (AVLNode*)C->pright;
	AVLNode *t4 = (AVLNode*)B->pright;

	C->pleft = A;
	C->pright = B;
	C->parent = A->parent;
	A->parent = C;
	B->parent = C;
	B->pleft = t3;
	A->pright = t2;
	if (t2) t2->parent = A;
	if (t3) t3->parent = B;

	int depA, depB, depC;
	balanceDetection(A, depA);
	balanceDetection(B, depB);
	balanceDetection(C, depC);

	node = C;
	return depC;
}

Node* AVLTree::remuve(AVLNode *&localRoot, float key)
{
	Node *tmp;
	if (!localRoot)
		return 0;
	if (key < localRoot->key)
		tmp = remuve((AVLNode*&)localRoot->pleft, key);
	else if (key > localRoot->key)
		tmp = remuve((AVLNode*&)localRoot->pright, key);
	else {
		if (!localRoot->pleft && !localRoot->pright) {
			Node* tmp1 = localRoot;
			if (localRoot->parent)
				if (localRoot->parent->pleft == localRoot)
					localRoot->parent->pleft = 0;
				else
					localRoot->parent->pright = 0;
			else
				root = 0;
			return tmp1;
		}
		else if (localRoot->pleft && !localRoot->pright) {
			Node* son = localRoot->pleft;
			Node* tmp1 = localRoot;
			son->parent = localRoot->parent;
			if (localRoot->parent)
				if (localRoot->parent->pleft == localRoot)
					localRoot->parent->pleft = son;
				else
					localRoot->parent->pright = son;
			else
				root = son;
			return tmp1;
		}
		else if (!localRoot->pleft && localRoot->pright) {
			Node* son = localRoot->pright;
			Node* tmp1 = localRoot;
			son->parent = localRoot->parent;
			if (localRoot->parent)
				if (localRoot->parent->pleft == localRoot)
					localRoot->parent->pleft = son;
				else
					localRoot->parent->pright = son;
			else
				root = son;
			return tmp1;
		}
		else {
			Node *next = searchNext(localRoot);
			remuve((AVLNode*&)localRoot->pright, next->key);
			Node* tmp1 = localRoot;
			next->pleft = localRoot->pleft;
			if (next->pleft)
				next->pleft->parent = next;
			next->pright = localRoot->pright;
			if (next->pright)
				next->pright->parent = next;
			next->parent = localRoot->parent;
			if (localRoot->parent)
				if (localRoot->parent->pleft == localRoot)
					localRoot->parent->pleft = next;
				else
					localRoot->parent->pright = next;
			else
				root = next;
			return tmp1;
		}
	}

	needBalance(localRoot);
	return tmp;
}

int AVLTree::height(AVLNode* node)
{
	if (!node)
		return -1;
	int l = height((AVLNode*)node->pleft);
	int r = height((AVLNode*)node->pright);
	node->setBalance(l - r);
	return r > l ? r + 1 : l + 1;
}

int AVLTree::balanceDetection(AVLNode *node, int &dep)
{
	dep = height(node);
	return node->getBalance();
}

int AVLTree::needBalance(AVLNode *&node)
{
	if (!node)
		return -1;
	int dep;
	char bal = balanceDetection(node, dep);
	if (bal == 2)
		if (((AVLNode*)node->pleft)->getBalance() > 0)
			rotateRight(node);
		else
			DRotateRight(node);
	if (bal == -2)
		if (((AVLNode*)node->pright)->getBalance() < 0)
			rotateLeft(node);
		else
			DRotateLeft(node);
	return dep;
}

