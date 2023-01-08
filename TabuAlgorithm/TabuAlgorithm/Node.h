#pragma once
#include "header.h"

class Node
{
private:
	int Num;
	int Fitness;
	vector<int> Binary;	//¡Øreverse order

public:	//Set
	void SetNum(int _num);
	void SetNum(int _num, int _size);

	void SetBinary(vector<int> _binary);
	void SetBinary(vector<int> _binary, int _size);

public: //Get
	int GetNum() { return Num; }
	int* pGetNum() { return &Num; }

	vector<int> GetBinary() { return Binary; };
	vector<int>* pGetBinary() { return &Binary; };

	int GetFit() { return Fitness; }
	int* pGetFit() { return &Fitness; }

public:	//ect
	void Show();

public:	//init
	Node() : Num(0), Fitness(0), Binary(NULL) {};

	Node(int _num) { SetNum(_num); }
	Node(int _num, int _size) { SetNum(_num, _size); }

	Node(vector<int> _binary) { SetBinary(_binary); }
	Node(vector<int> _binary, int _size) { SetBinary(_binary, _size); }

public:	//sort
	static bool cmp(const Node* _node1, const Node* _node2) { return _node1->Fitness > _node2->Fitness; }

private: //function
	int f(int x) { return (80 + (38 * x) - (x * x)); }
};

