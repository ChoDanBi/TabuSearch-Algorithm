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

public:
	void Init(int _size, int _length, int _x);

	//리스트 저장 크기
	void SetSize(int _size) { lSize = _size; }
	int GetSize() { return lSize; }

	//이진법 표기 길이
	void SetLength(int _length) { bLength = _length; }
	int GetLength() { return bLength; }

	//현재 오브젝트
	void SetcurObj(Object* obj) { delete curObj; curObj = obj; }
	Object* GetcurObj() { return curObj; }

	//Move리스트
	void SetMoveList(Object* obj);
	Object* GetMoveList(int _ind);

	void SortMoveList();
	Object* GetBestBFitObj();

	void ReleaseMoveList();

	//타보리스트
	void PushTabuList(Object* obj);
	//리스트 크기 체크
	bool CheckListSize();
	//리스트 삭제
	void PopList();
	//리스트 전부 삭제
	void Release();

private:
	ObjectManager() {};
public:
	~ObjectManager() {};
};

