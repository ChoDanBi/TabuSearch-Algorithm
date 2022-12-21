#include "Object.h"
#include "ObjectManager.h"

void Object::SetInit(int _Cand)
{
	this->Cand = _Cand;
	this->Fit = f(Cand);
	this->Len = ObjectManager::GetInstance()->GetLength();
	for (int i = 0; i < Len; ++i) {
		this->Binary.push_back(_Cand % 2);
		_Cand /= 2;
	}
}

void Object::SetInit(int _Cand, int _len)
{
	this->Cand = _Cand;
	this->Fit = f(Cand);
	this->Len = _len;
	for (int i = 0; i < Len; ++i) {
		this->Binary.push_back(_Cand % 2);
		_Cand /= 2;
	}
}

void Object::SetInit(vector<int> _Binary)
{
	int size = _Binary.size();
	for (int i = 0; i < size; ++i)
		Cand += _Binary[i] * (int)pow(2, i);
	this->Fit = f(Cand);
	this->Len = ObjectManager::GetInstance()->GetLength();
	for (int i = 0; i < Len; ++i)
			this->Binary.push_back(i < size ? _Binary[i] : 0);
}

void Object::SetInit(vector<int> _Binary, int _len)
{
	int size = _Binary.size();
	for (int i = 0; i < size; ++i)
		Cand += _Binary[i] * (int)pow(2, i);
	this->Fit = f(Cand);
	this->Len = _len;
	for (int i = 0; i < Len; ++i)
		this->Binary.push_back(i < size ? _Binary[i] : 0);
}

