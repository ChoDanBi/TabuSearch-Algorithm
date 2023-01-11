#pragma once
#include "Node.h"
#include "NodeFactory.h"
#include <algorithm>

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
	int Scale;	//TabuSize
	int Range;	//0~Max(Range)
	int Size;	//Binary text length

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

	int GetSize() { return Size; }
	void SetSize() { Size = 1; while (Range > pow(2, Size)) ++Size; }

public: //Node
	Node* GetcNode() { return curNode; }
	Node* GetbNode() { return BestNode; }

	void SetcurNode(Node* _node) { curNode = _node; }
	void SetbestNode(Node* _node) { BestNode = _node; }

	void DelCurNode();
	void DelCurNode(bool _isExist);

	void DelBestNode();
	void DelBestNode(bool _isExist);

public:	//List
	vector<Node*>* GetMoveList() { return &MoveList; }
	list<Node*>* GetTabuList() { return &TabuList; }

	void addMove(Node* _node) { MoveList.push_back(_node); }
	void addTabu(Node* _node) { TabuList.push_back(_node); }

	int GetMoveScale() { return MoveList.size(); }
	int GetTabuScale() { return TabuList.size(); }

	void SortMove() { sort(MoveList.begin(), MoveList.end(), Node::cmp); }

	bool isContainTabu(Node* _node);

	void PopTabu();
	void PopTabu(bool _isExist);

	void ReleaseMove();
	void ReleaseTabu();

private:
	NodeManager() : Scale(0), Range(0), Size(1),
		curNode(nullptr), BestNode(nullptr), MoveList(NULL), TabuList(NULL) {};
public:
	~NodeManager() {};
};

