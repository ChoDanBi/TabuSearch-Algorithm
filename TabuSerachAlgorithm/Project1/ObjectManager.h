#pragma once
#include "header.h"
#include "Object.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;

public:
	static ObjectManager* GetInstance() {
		if (Instance == NULL)
			Instance = new ObjectManager();
		return Instance;
	}

private:
	int lSize;	//리스트 저장 최대 크기
	int bLength;	//이진법 표기 길이
	Object* curObj;	//현재 값

	vector<Object*> MoveList;	//move한 값들을 모은 리스트
	list<Object*> TabuList;	//타보리스트

	map<int, int> CntList;

public:
	void Init(int _size, int _length, int _x);
	void Init(int _size, int _length, int _min, int _max);

	//리스트 저장 크기
	void SetSize(int _size) { lSize = _size; }
	int GetSize() { return lSize; }

	//이진법 표기 길이
	void SetLength(int _length) { bLength = _length; }
	int GetLength() { return bLength; }

	//현재 오브젝트
	void SetcurObj(Object* obj) { curObj = obj; }
	void SetNextcurObj();
	Object* GetcurObj() { return curObj; }
	void ShowCurObj() { curObj->show(); }

	//Move리스트
	void SetMoveList(Object* obj);
	void SetNearObjMoveList();
	Object* GetMoveList(int _ind);	
	Object* GetBestBFitObj();
	void SortMoveList();
	void ReleaseMoveList();

	void ShowMoveList();

	void Move();
	void Move(int _goal);

	//타보리스트
	void PushTabuList(Object* obj);
	bool CheckListSize();
	void PopList();
	void Release();

	void ShowTabuList();

	//개수 리스트
	int SetCntList(Object* _obj);
	int SetCntList(int _cand);
	

private:
	ObjectManager() {};
	ObjectManager(int _size, int _length, Object* _obj):
		lSize(_size), bLength(_length),curObj(_obj) {};
public:
	~ObjectManager() {};
};

