#pragma once
#include <random>
#include "ObjectManager.h"

class ObjectFactory
{
public:
	//���� �� ��������
	static int GetRandom(int _min, int _max);

	//�Ϲ� ������Ʈ �����
	static Object* CreateObj(int _cand);
	static Object* CreateObj(vector<int> _binary);

	static Object* CreateNearObj(Object* _obj, int _ind);
};

