#include "separatedSet.h"


separatedSet::separatedSet(int Size)
{
	if (Size<0)
		throw "wrong size";
	arr = new int [Size];
	for (int i=0; i<Size; i++)
		arr[i]=-1;
	this->Size=Size;
}
separatedSet::~separatedSet()
{
	delete [] arr;
}

void separatedSet::singelton(int i)
{
	if(i<0||i>Size)
		throw "wrong idx";
	if (arr[i]!=-1)
		return ;
	arr[i]=i;
}
void separatedSet::unionS(int i, int j)
{
	if((i<0 || j<0)||(i>Size || j>Size))
		throw "wrong idx";
	int bossArr = subDef(i);
	for(int k=0; k<Size; k++)
		if(arr[k]==j)
			arr[k] = bossArr;
}
int separatedSet::subDef(int i)
{
	if(i<0||i>Size)
		throw "wrong idx";
	return arr[i];
}
int separatedSet::getSize(int i)
{
	if(i<0||i>Size)
		throw "wrong idx";
	int setSize=0;
	int bossArr=arr[i];
	for(int j=0; j<Size; j++)
		if(arr[j]==bossArr)
			setSize++;
	return setSize;
}
