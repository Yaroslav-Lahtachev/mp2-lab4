#pragma once


class TabRecord {
protected:
	int key;
	tDAta* data;
public:
	TabRecord(int key, tData *data);
	int GetKey() const;
	tData GetData() const;
};

class Table {
protected:
	int sizr;
	int count;
	int CurrPos;
public:
	Table(int size);
	virtual TabRecord *find(int key) = 0;
	virtual int add(int key, tData *data) = 0;
	virtual int del(int key) = 0;
	
	int isEmpty() const;
	int isFull() const;
	int getDataCount() const;
	virtual int Reset();
	virtual int GetNext();
	virtual int isTableEnded();
	virtual int Getkey() const = 0;
	virtual tDate GetData() const = 0;




};