#include "ObjectManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = NULL;

void ObjectManager::Init(int _size, int _length, int _x)
{
	lSize = _size;
	bLength = _length;
	curObj = ObjectFactory::CreateObj(_x);
	TabuList.push_back(curObj);
	cout << "초기값: " << curObj->GetCand() << endl;
}

void ObjectManager::Init(int _size, int _length, int _min, int _max)
{
	lSize = _size;
	bLength = _length;
	int x = ObjectFactory::GetRandom(_min, _max);
	curObj = ObjectFactory::CreateObj(x);
	TabuList.push_back(curObj);
	cout << "초기값: " << curObj->GetCand() << endl;
}

void ObjectManager::Move()
{
	cout << "Move()\n";
	SetNearObjMoveList();
	SetNextcurObj();
	ReleaseMoveList();
}

void ObjectManager::Move(int _goal)
{
	for (int i = 1;; ++i) {
		if (curObj == nullptr) break;

		cout << i << "번째: ";
		Move();

		int cnt = SetCntList(curObj);
		if (cnt >= _goal) {
			cout << "최종: " << curObj->GetCand() << endl;
			break;
		}
	}
}

void ObjectManager::SetNextcurObj()
{
	cout << "SetNextcurObj()\n";
	Object* obj = GetBestBFitObj();

	if (obj == nullptr) {
		cout << "막혔습니다!\n";
		return;
	}
	
	SetcurObj(obj);
	PushTabuList(obj);
	cout << curObj->GetCand() << endl;
}

void ObjectManager::SetMoveList(Object* obj) { MoveList.push_back(obj); }
Object* ObjectManager::GetMoveList(int _ind){return MoveList[_ind];}
Object* ObjectManager::GetBestBFitObj()
{
	SortMoveList();
	ShowMoveList();
	for (vector<Object*>::iterator it = MoveList.begin();
		it != MoveList.end(); ++it) {
		bool none = true;
		for (list<Object*>::iterator iter = TabuList.begin();
			iter != TabuList.end(); ++iter) {
			if ((*it)->GetFit() == (*iter)->GetFit()){
				none = false; break; }
		}
		if (none)return (*it);
	}
	return nullptr;
}
void ObjectManager::SetNearObjMoveList()
{
	cout << "NearObjMoveList()\n";
	for (int i = 0; i < bLength; ++i) {
		SetMoveList(
			ObjectFactory::CreateNearObj(curObj, i)
		);
	}
}
void ObjectManager::SortMoveList(){
	sort(MoveList.begin(), MoveList.end(), Object::cmp);
}

void ObjectManager::ReleaseMoveList(){
	cout << "ReleaseMoveList()\n";
	while (MoveList.size() > 1){
		delete MoveList.back();
		MoveList.back() = nullptr;
		MoveList.pop_back();
	}
	MoveList.clear();
}

void ObjectManager::ShowMoveList()
{
	cout << "\n*****MoveList*****\n";
	for (vector<Object*>::iterator it = MoveList.begin();
		it != MoveList.end(); ++it) {
		(*it)->show();
	}
}



void ObjectManager::PushTabuList(Object* obj){
	cout << "PushTabuList()\n";
	TabuList.push_back(obj);
	if (CheckListSize()) PopList();
}

bool ObjectManager::CheckListSize() { return TabuList.size() > lSize; }

void ObjectManager::PopList()
{
	if (TabuList.empty()) return;
	cout << "PopList()\n";
	delete TabuList.front();
	TabuList.front() = nullptr;
	TabuList.pop_front();
}

void ObjectManager::Release() {
	cout << "Release()\n";
	while (!TabuList.empty())
		PopList();
}

void ObjectManager::ShowTabuList()
{
	cout << "\n*****TabuList*****\n";
	for (list<Object*>::iterator it = TabuList.begin();
		it != TabuList.end(); ++it) {
		(*it)->show();
	}
}

int ObjectManager::SetCntList(Object* _obj)
{
	return SetCntList(_obj->GetCand());
}

int ObjectManager::SetCntList(int _cand)
{
	if (CntList.find(_cand) == CntList.end())
		CntList.insert(make_pair(_cand, 0));
	CntList[_cand]++;
	
	return CntList[_cand];
}
