#pragma once
#include "Node.h"
#include "NodeFactory.h"

class Node;
class NodeManager
{
private:
	static NodeManager* Instance;
public:
	static NodeManager* GetInstance() {
		if (Instance == NULL)
			Instance = new NodeManager();
		return Instance;
	}

private:
	int Scale;
	int Range;

	int Count;
	int Size;

	Node* curNode;
	Node* BestNode;

	vector<Node*> MoveList;
	list<Node*> TabuList;

public:	//Init
	void Init(int _scale, int _range);
	void Init(int _scale, int _range, int _num);
	
public:	//Get&Set
	int GetScale() { return Scale; }
	void SetScale(int _scale) { Scale = _scale; }

	int GetRange() { return Range; }
	void SetRange(int _range) { Range = _range; }

	int GetCount() { return Count; }

	int GetSize() { return Size; }
	void SetSize() { Size = 1; while (Range > pow(2, Size)) ++Size; }

public: //Node
	Node* GetcNode() { return curNode; }
	Node* GetbNode() { return BestNode; }

	void SetcNode(Node* _node) { curNode = _node; }
	void SetbNode(Node* _node) { BestNode = _node; }

	void DelcNode() { DEL(curNode); }
	void DelbNode() { DEL(BestNode); }

public:	//List
	vector<Node*>* GetMoveList() { return &MoveList; }
	list<Node*>* GetTabuList() { return &TabuList; }

	void SetMoveList(Node* _node) { MoveList.push_back(_node); }
	void SetTabuList(Node* _node) { TabuList.push_back(_node); }

private:
	NodeManager() : Scale(0), Range(0), Count(0), Size(1),
		curNode(nullptr), BestNode(nullptr), MoveList(NULL), TabuList(NULL) {};
public:
	~NodeManager() {};
};

