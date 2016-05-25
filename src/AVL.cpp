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
	recursiveIns((AVLNode*&)root, node);
}

void AVLTree::recursiveIns(AVLNode *&localRoot, AVLNode *&node)
{
	if (node->key < localRoot->key) {
		if (!localRoot->pleft) {
			localRoot->pleft = node;
			node->parent = localRoot;
		}
		else
			recursiveIns((AVLNode*&)localRoot->pleft, node);
	}
	else {
		if (!localRoot->pright) {
			localRoot->pright = node;
			node->parent = localRoot;
		}
		else
			recursiveIns((AVLNode*&)localRoot->pright, node);
	}

	decisionOnBalancing(localRoot);
}

void AVLTree::del(float key)
{
	delete recursiveRem((AVLNode*&)root, key);
}

void AVLTree::del(Node* node)
{
	delete recursiveRem((AVLNode*&)root, node->key);
}

Node* AVLTree::pull(float key)
{
	return recursiveRem((AVLNode*&)root, key);
}

Node* AVLTree::pull(Node* node)
{
	return recursiveRem((AVLNode*&)root, node->key);
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

Node* AVLTree::recursiveRem(AVLNode *&localRoot, float key)
{
	Node *result;
	if (!localRoot)
		return 0;
	if (key < localRoot->key)
		result = recursiveRem((AVLNode*&)localRoot->pleft, key);
	else if (key > localRoot->key)
		result = recursiveRem((AVLNode*&)localRoot->pright, key);
	else {
		if (!localRoot->pleft && !localRoot->pright) {
			if (localRoot->parent)
				if (localRoot->parent->pleft == localRoot)
					localRoot->parent->pleft = 0;
				else
					localRoot->parent->pright = 0;
			else
				root = 0;
			return localRoot;
		}
		else if (localRoot->pleft && !localRoot->pright) {
			Node* son = localRoot->pleft;
			Node* killed = localRoot;
			son->parent = localRoot->parent;
			if (localRoot->parent)
				if (localRoot->parent->pleft == localRoot)
					localRoot->parent->pleft = son;
				else
					localRoot->parent->pright = son;
			else
				root = son;
			return killed;
		}
		else if (!localRoot->pleft && localRoot->pright) {
			Node* son = localRoot->pright;
			Node* killed = localRoot;
			son->parent = localRoot->parent;
			if (localRoot->parent)
				if (localRoot->parent->pleft == localRoot)
					localRoot->parent->pleft = son;
				else
					localRoot->parent->pright = son;
			else
				root = son;
			return killed;
		}
		else {
			Node *next = searchNext(localRoot);
			pull(next);
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
			return localRoot;
		}
	}

	decisionOnBalancing(localRoot);
	return result;
}

int AVLTree::depth(AVLNode* node)
{
	if (!node)
		return -1;
	int l = depth((AVLNode*)node->pleft);
	int r = depth((AVLNode*)node->pright);
	node->setBalance(l - r);
	return r > l ? r + 1 : l + 1;
}

int AVLTree::balanceDetection(AVLNode *node, int &dep)
{
	dep = depth(node);
	return node->getBalance();
}

int AVLTree::decisionOnBalancing(AVLNode *&node)
{
	if (!node)
		return -1;
	int dep;
	char balance = balanceDetection(node, dep);
	if (balance == 2)
		if (((AVLNode*)node->pleft)->getBalance() > 0)
			rotateRight(node);
		else
			DRotateRight(node);
	if (balance == -2)
		if (((AVLNode*)node->pright)->getBalance() < 0)
			rotateLeft(node);
		else
			DRotateLeft(node);
	return dep;
}

