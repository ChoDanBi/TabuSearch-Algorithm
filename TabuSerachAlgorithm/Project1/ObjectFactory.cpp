#include "ObjectFactory.h"

int ObjectFactory::GetRandom(int _min, int _max)
{
	random_device rd;	//�õ尪�� ��� ���� rd ����
	mt19937 gen(rd());	//���� ���� ���� �ʱ�ȭ

	//min~max������ ���� ����
	uniform_int_distribution<int> dis(_min, _max);
	return dis(gen);
}

//������Ʈ �����
Object* ObjectFactory::CreateObj(int _cand)
{
	Object* Obj = new Object;
	Obj->SetInit(_cand);
	return Obj;
}

Object* ObjectFactory::CreateObj(vector<int> _binary)
{
	Object* Obj = new Object;
	Obj->SetInit(_binary);
	return Obj;
}



