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

public:	//Init
	void Init(int _scale, int _range);
	void Init(int _scale, int _range, int _num);

public:	//TabuSerach
	void Start(int _goal);
	void Finish(bool _isgoal);
	int Simulating();

public:	//function
	void NeighborSearch();
	bool isEdgeContain();
	void AddEdgeinTabu();
	int CompareEdge();


private:
	TabuSerach() :Count(0) {};
public:
	~TabuSerach() {};
};

