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

public:
	void Init(int _size, int _length, int _x);

	//����Ʈ ���� ũ��
	void SetSize(int _size) { lSize = _size; }
	int GetSize() { return lSize; }

	//������ ǥ�� ����
	void SetLength(int _length) { bLength = _length; }
	int GetLength() { return bLength; }

	//���� ������Ʈ
	void SetcurObj(Object* obj) { delete curObj; curObj = obj; }
	Object* GetcurObj() { return curObj; }

	//Move����Ʈ
	void SetMoveList(Object* obj);
	Object* GetMoveList(int _ind);

	void SortMoveList();
	Object* GetBestBFitObj();

	void ReleaseMoveList();

	//Ÿ������Ʈ
	void PushTabuList(Object* obj);
	//����Ʈ ũ�� üũ
	bool CheckListSize();
	//����Ʈ ����
	void PopList();
	//����Ʈ ���� ����
	void Release();

private:
	ObjectManager() {};
public:
	~ObjectManager() {};
};

