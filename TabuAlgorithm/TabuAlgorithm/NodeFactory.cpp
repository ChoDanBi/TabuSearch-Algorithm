#include "NodeFactory.h"
#include <random>

Node* NodeFactory::CreateNearNode(Node* _node, const int& _ind)
{
	vector<int> Binary = _node->GetBinary();
	Binary[_ind] = Binary[_ind] == 0 ? 1 : 0;
	return new Node(Binary);
}

Node* NodeFactory::CreateNearNode(Node* _node, const int& _ind, const int& _size)
{
	vector<int> Binary = _node->GetBinary();
	Binary[_ind] = Binary[_ind] == 0 ? 1 : 0;
	return new Node(Binary, _size);
}

void NodeFactory::SafeDelet(Node* _node)
{
	if (_node == nullptr) return;
	delete _node; _node = nullptr;
}

int NodeFactory::GetRandom(const int& _max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, _max);
	return dis(gen);
}

int NodeFactory::GetRandom(const int& _min, const int& _max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(_min, _max);
	return dis(gen);
}
