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
	int lSize;	//����Ʈ ���� �ִ� ũ��
	int bLength;		//������ ǥ�� ����
	int BestCnt;
	Object* curObj;		//���� ��
	Object* BestObj;	//����Ʈ�� �ֱ�

	vector<Object*> MoveList;	//move�� ������ ���� ����Ʈ
	list<Object*> TabuList;	//Ÿ������Ʈ

public:
	void Init(int _size, int _length, int _x);
	void Init(int _size, int _length, int _min, int _max);

	//����Ʈ ���� ũ��
	void SetSize(int _size) { lSize = _size; }
	int GetSize() { return lSize; }

	//������ ǥ�� ����
	void SetLength(int _length) { bLength = _length; }
	int GetLength() { return bLength; }

	//���� ������Ʈ
	void SetcurObj(Object* obj) { curObj = obj; }
	int GetcurObjCand() { return curObj->GetCand(); }
	int GetcurObjFit() { return curObj->GetFit(); }
	Object* GetcurObj() { return curObj; }

	void ShowBestObj() { BestObj->show(); }

	//����Ʈ ������Ʈ
	void SetBestObj(Object* obj);
	int GetBestObjCand() { return BestObj->GetCand(); }
	int GetBestObjFit() { return BestObj->GetFit(); }
	Object* GetBestObj() { return BestObj; }

	void ShowCurObj() { curObj->show(); }

	int cmpBestObj();

	//Move����Ʈ
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

	//Ÿ������Ʈ
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

