#include "Node.h"

void Node::SetNum(int _num)
{
	Num = _num;
	Fitness = f(Num);
	do { Binary.push_back(_num % 2); _num /= 2; } while (_num != 0);
}

void Node::SetNum(int _num, int _size)
{
	Num = _num;
	Fitness = f(Num);
	for (int i = 0; i < _size; ++i) { Binary.push_back(_num % 2); _num /= 2; }
}

void Node::SetBinary(vector<int> _binary)
{
	Num = 0;
	int size = _binary.size();
	for (int i = 0; i < size; ++i)
		Num += _binary[i] * (int)pow(2, i);
	Fitness = f(Num);
	Binary = _binary;
}

void Node::SetBinary(vector<int> _binary, int _size)
{
	Num = 0;
	for (int i = 0; i < _binary.size(); ++i) Num += (_binary[i] * (int)pow(2, i));
	Fitness = f(Num);
	for (int i = 0; i < _size; ++i)
		Binary.push_back(_binary.size() > i ? _binary[i] : 0);
}

void Node::Show()
{
	cout << "Num: " << Num
		<< ", Fit: " << Fitness
		<< ", Binary: ";
	for (int i = (Binary.size() - 1); i >= 0; --i)
		cout << Binary[i];

	cout << "\n";
}