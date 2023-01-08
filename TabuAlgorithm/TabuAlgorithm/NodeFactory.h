#pragma once
#include "Node.h"

class NodeFactory
{
public:	//Create Node
	static Node* CreateNode(const int& _num) { return new Node(_num); }
	static Node* CreateNode(const int& _num, const int& _size) { return new Node(_num, _size); }

	static Node* CreateNode(const vector<int>& _binary) { return new Node(_binary); }
	static Node* CreateNode(const vector<int>& _binary, const int& _size) { return new Node(_binary, _size); }

public:	//Create Near Node
	static Node* CreateNearNode(Node* _node, const int& _ind);
	static Node* CreateNearNode(Node* _node, const int& _ind, const int& _size);

public:	//Release
	static void SafeDelet(Node* _node);

public:	//Get Random number
	static int GetRandom(const int& _max);
	static int GetRandom(const int& _min, const int& _max);
};

