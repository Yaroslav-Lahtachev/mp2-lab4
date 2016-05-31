#pragma once
#include <iostream>
#define max_size 1000
using namespace std;

class TabRecord {
protected:
	int key;
	void* data;
public:
	TabRecord(float key, void *data);
	float GetKey() const;
	void* GetData() const;
};

class Table {
protected:
	int Size;
	int count;
	int CurrPos;
public:
	Table(int Size);
	virtual ~Table() {};

	virtual TabRecord *find(float key) = 0;
	virtual int add(float key, void *data) = 0;
	virtual int del(float key) = 0;
	virtual TabRecord* getm() = 0;
	virtual TabRecord* getM() = 0;
	
	int isEmpty() const;
	int isFull() const;
	int getDataCount() const;

	virtual int Reset();
	virtual int GetNext();
	virtual int isTableEnded();
	virtual float GetKey() const = 0;
	virtual void* GetData() const = 0;
};

class ScanTable : public Table {
protected:
	TabRecord** recs;
public:
	ScanTable(int Size);
	virtual ~ScanTable();

	virtual TabRecord *find(float key);
	virtual int add(float key, void* data);
	virtual int del(float key);
	virtual TabRecord* pull(float key);
	virtual TabRecord* getm();
	virtual TabRecord* getM();

	virtual float GetKey() const;
	virtual void* GetData() const;


};

class SortTable : public ScanTable {
public:
	SortTable(int Size);
	virtual ~SortTable() {};

	virtual TabRecord *find(float key);
	virtual int add(float key, void* data);
	virtual int del(float key);
	virtual TabRecord* pull(float key);
	virtual TabRecord* getm();
	virtual TabRecord* getM();

};