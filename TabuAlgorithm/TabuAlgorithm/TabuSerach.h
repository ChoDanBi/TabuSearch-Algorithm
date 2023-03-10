#pragma once
#include "header.h"
#include "NodeManager.h"

class TabuSerach
{
private:
	static TabuSerach* Instance;
public:
	static TabuSerach* GetInstance() {
		if (Instance == NULL)
			Instance = new TabuSerach();
		return Instance;
	}

private:
	int Count;
	bool isBlock;

public:	//Init
	void Init(int _scale, int _range);
	void Init(int _scale, int _range, int _num);

public:	//TabuSerach
	void Start(int _goal);
	void Finish(bool _isblock);
	void Simulating();

public:	//function
	void NeighborSearch();
	bool isEdgeContain();
	void AddEdgeinTabu();
	void CompareEdge();

	void ShowNode(Node* _node);

private:
	TabuSerach() :Count(0) {};
public:
	~TabuSerach() {};
};

