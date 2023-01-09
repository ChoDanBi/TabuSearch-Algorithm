#include "NodeManager.h"

NodeManager* NodeManager::Instance = NULL;

void NodeManager::Init(int _scale, int _range)
{
	Scale = _scale;
	Range = _range;
	SetSize();
	curNode = NF::CreateNode(NF::GetRandom(Range));
	BestNode = curNode;
}

void NodeManager::Init(int _scale, int _range, int _num)
{
	Scale = _scale;
	Range = _range;
	SetSize();
	curNode = NF::CreateNode(_num, Size);
	BestNode = curNode;
}

void NodeManager::DelCurNode() { DEL(curNode); }

void NodeManager::DelCurNode(bool _isExist)
{
	if (!_isExist) delete curNode;
	curNode = nullptr;
}

void NodeManager::DelBestNode() { DEL(BestNode); }

void NodeManager::DelBestNode(bool _isExist)
{
	if (!_isExist) delete curNode;
	BestNode = nullptr;
}

bool NodeManager::isContainTabu(Node* _node)
{
	for (list<Node*>IT it = TabuList.begin(); it != TabuList.end(); ++it) {
		if (_node->GetNum() == (*it)->GetNum())
			return true;
	}
	return false;
}

void NodeManager::PopTabu()
{
	DEL(TabuList.front());
	TabuList.pop_front();
}

void NodeManager::PopTabu(bool _isExist)
{
	if(!_isExist) DEL(TabuList.front());
	TabuList.pop_front();
}

void NodeManager::ReleaseMove()
{
	for (vector<Node*>IT it = MoveList.begin();
		it != MoveList.end(); ++it)
			DEL(*it);
	MoveList.clear();
}

void NodeManager::ReleaseTabu()
{
	for (list<Node*>IT it = TabuList.begin(); it != TabuList.end(); ++it)
		DEL(*it);
	TabuList.clear();
}
