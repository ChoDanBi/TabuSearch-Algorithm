#include "NodeManager.h"

NodeManager* NodeManager::Instance = NULL;

void NodeManager::Init(int _scale, int _range)
{
	Scale = _scale;
	Range = _range;
	SetSize();
	Count = 0;
	curNode = NF::CreateNode(NF::GetRandom(Range, Size));
	BestNode = curNode;
}

void NodeManager::Init(int _scale, int _range, int _num)
{
	Scale = _scale;
	Range = _range;
	SetSize();
	Count = 0;
	curNode = NF::CreateNode(_num, Size);
	BestNode = curNode;
}
