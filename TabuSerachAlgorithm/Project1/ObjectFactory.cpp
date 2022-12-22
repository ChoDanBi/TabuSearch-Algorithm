#include "ObjectFactory.h"

int ObjectFactory::GetRandom(int _min, int _max)
{
	random_device rd;	//시드값을 얻기 위한 rd 생성
	mt19937 gen(rd());	//난수 생성 엔진 초기화

	//min~max까지의 난수 생성
	uniform_int_distribution<int> dis(_min, _max);
	return dis(gen);
}

//오브젝트 만들기
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

Object* ObjectFactory::CreateNearObj(Object* _obj, int _ind)
{
	vector<int> binary = _obj->GetBinary();
	binary[_ind] = binary[_ind] == 0 ? 1 : 0;
	return CreateObj(binary);	
}



