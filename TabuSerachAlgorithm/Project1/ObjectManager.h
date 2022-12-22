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
	int bLength;	//������ ǥ�� ����
	Object* curObj;	//���� ��

	vector<Object*> MoveList;	//move�� ������ ���� ����Ʈ
	list<Object*> TabuList;	//Ÿ������Ʈ

	map<int, int> CntList;

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
	void SetNextcurObj();
	Object* GetcurObj() { return curObj; }
	void ShowCurObj() { curObj->show(); }

	//Move����Ʈ
	void SetMoveList(Object* obj);
	void SetNearObjMoveList();
	Object* GetMoveList(int _ind);	
	Object* GetBestBFitObj();
	void SortMoveList();
	void ReleaseMoveList();

	void ShowMoveList();

	void Move();
	void Move(int _goal);

	//Ÿ������Ʈ
	void PushTabuList(Object* obj);
	bool CheckListSize();
	void PopList();
	void Release();

	void ShowTabuList();

	//���� ����Ʈ
	int SetCntList(Object* _obj);
	int SetCntList(int _cand);
	

private:
	ObjectManager() {};
	ObjectManager(int _size, int _length, Object* _obj):
		lSize(_size), bLength(_length),curObj(_obj) {};
public:
	~ObjectManager() {};
};

