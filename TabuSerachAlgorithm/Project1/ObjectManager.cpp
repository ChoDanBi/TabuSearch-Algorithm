#include "ObjectManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = NULL;

void ObjectManager::Init(int _size, int _length, int _x)
{
	lSize = _size;
	bLength = _length;
	curObj = ObjectFactory::CreateObj(_x);
	TabuList.push_back(curObj);
}

void ObjectManager::SetMoveList(Object* obj) { MoveList.push_back(obj); }

Object* ObjectManager::GetMoveList(int _ind){return MoveList[_ind];}

Object* ObjectManager::GetBestBFitObj()
{
	SortMoveList();
	for (vector<Object*>::iterator it = MoveList.begin();
		it != MoveList.end(); ++it) {
		for (list<Object*>::iterator iter = TabuList.begin();
			iter != TabuList.end(); ++iter) {
			if ((*it)->GetFit() != (*iter)->GetFit()) return (*it);
			else break;
		}
	}
	return nullptr;
}

void ObjectManager::SortMoveList(){
	sort(MoveList.begin(), MoveList.end(), Object::cmp);
}

void ObjectManager::ReleaseMoveList(){
	while (!MoveList.empty()){
		delete MoveList.back();
		MoveList.back() = nullptr;
		MoveList.pop_back();
	}
}

void ObjectManager::PushTabuList(Object* obj){
	TabuList.push_back(obj);
	if (CheckListSize()) PopList();
}

bool ObjectManager::CheckListSize() { return TabuList.size() > lSize; }

void ObjectManager::PopList()
{
	if (TabuList.empty()) return;
	delete TabuList.front();
	TabuList.front() = nullptr;
	TabuList.pop_front();
}

void ObjectManager::Release() {
	while (!TabuList.empty())
		PopList();
}
