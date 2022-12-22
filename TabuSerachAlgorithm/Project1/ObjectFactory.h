#pragma once
#include <random>
#include "ObjectManager.h"

class ObjectFactory
{
public:
	//랜덤 값 가져오기
	static int GetRandom(int _min, int _max);

	//일반 오브젝트 만들기
	static Object* CreateObj(int _cand);
	static Object* CreateObj(vector<int> _binary);

	static Object* CreateNearObj(Object* _obj, int _ind);
};

