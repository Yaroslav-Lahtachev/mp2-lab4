#include "tree_lib.h"


Tree::Tree(int d)
{
	if (d<=0)
		throw "wrong descendant";
	this->d=d;
	Size=-1;
	key=new Data*[MaxSize];
}
Tree::~Tree()
{
	delete [] key;
}

void Tree::input(Data *&i)
{
	if (isFull())
		throw "heap is overflow";
	Size++;
	key[Size] = i;
	surfacing(Size);
}
void Tree::inputGroup(Data **keys, int num)
{
	if (Size+num>=MaxSize)
		throw "heap is overflow";
	for (int i=0; i<num; i++)
	{
		key[Size+i+1] = keys[i];
	}
	Size+=num;
	hilling();
}
Data* Tree::erase()
{
	if (isEmpty())
		throw "heap is empty";
	Data* tmp=key[Size];
	Size--;
	return tmp;
}
Data* Tree::erase(int i)
{
	if (isEmpty())
		throw "heap is empty";
	if (i<0||i>Size)
		throw "wrong idx";
	Data* tmp=key[i];
	if (i==Size)
	{
		Size--;
		return tmp;
	}
	transposing(i, Size);
	Size--;
	immersion(i);
	return tmp;
}

void Tree::transposing(int i, int j)
{
	if ((i < 0 || j < 0) || (i > Size || j > Size))
		throw "wrong idx";
	Data* tmp;
	tmp=key[i];
	key[i]=key[j];
	key[j]=tmp;
}
void Tree::surfacing(int i)
{
	if (i<0||i>Size)
		throw "wrong idx";
	int p=(i-1)/d;
	while (i>0) 
	{
		if (key[i]->priority>key[p]->priority)
			break;
		transposing(i,p);
		i=p;
		p=(i-1)/d;
	}
}
void Tree::immersion(int i)
{
	if (i<0||i>Size)
		throw "wrong idx";
	int c=minchild(i);
	while (c!=-1&&key[i]->priority>key[c]->priority)
	{
		transposing(i,c);
		i=c;
		c=minchild(i);
	}
}
void Tree::withdrawal(int n)
{
	key[0]=key[n-1];
	n--;
	immersion(0);

}
void Tree::hilling()
{
	for(int i=Size; i>=0; i--)
		immersion(i);
}

int Tree::minchild(int i)
{
	int f=i*d+1;
	if (f>Size) 
		return -1;
	int l=min(i*d+d, Size);
	int c=f;
	Data* minKey=key[f];
	for (int k=f+1; k<=l; k++)
	{
		if (minKey->priority>key[k]->priority)
		{
			minKey=key[k];
			c=k;
		}
	}
	return c;
}
int Tree::isEmpty()
{
	return Size==-1;
}
int Tree::isFull()
{	
	return Size>=MaxSize-1;
}