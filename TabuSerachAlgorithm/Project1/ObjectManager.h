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
	int bLength;		//이진법 표기 길이
	int BestCnt;
	Object* curObj;		//현재 값
	Object* BestObj;	//베스트값 넣기

	vector<Object*> MoveList;	//move한 값들을 모은 리스트
	list<Object*> TabuList;	//타보리스트

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
	int GetcurObjCand() { return curObj->GetCand(); }
	int GetcurObjFit() { return curObj->GetFit(); }
	Object* GetcurObj() { return curObj; }

	void ShowBestObj() { BestObj->show(); }

	//베스트 오브젝트
	void SetBestObj(Object* obj);
	int GetBestObjCand() { return BestObj->GetCand(); }
	int GetBestObjFit() { return BestObj->GetFit(); }
	Object* GetBestObj() { return BestObj; }

	void ShowCurObj() { curObj->show(); }

	int cmpBestObj();

	//Move리스트
	void SetMoveList(Object* obj);
	Object* GetMoveList(int _ind);	

	void ShowMoveList();
	void ReleaseMoveList();

	//Move
	void CreateNearObj();
	void SortMoveList();
	Object* GetNextObj();
	void SetNextcurObj();

	void Move();
	void Move(int _goal);

	//타보리스트
	void PushTabuList(Object* obj);
	bool CheckTabu(Object* obj);
	bool CheckListSize();

	void ShowTabuList();
	void PopList();
	void TabuRelease();
	

private:
	ObjectManager() {};
	ObjectManager(int _size, int _length, Object* _obj):
		lSize(_size), bLength(_length),curObj(_obj) {};
public:
	~ObjectManager() {};
};

