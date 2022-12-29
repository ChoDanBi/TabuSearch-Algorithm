#include "ObjectManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = NULL;

void ObjectManager::Init(int _size, int _length, int _x)
{
	lSize = _size;
	bLength = _length;

	curObj = ObjectFactory::CreateObj(_x);
	SetBestObj(curObj);

	TabuList.push_back(curObj);

	cout << "초기값: "; curObj->show(); cout << endl;
}

void ObjectManager::Init(int _size, int _length, int _min, int _max)
{
	lSize = _size;
	bLength = _length;

	int x = ObjectFactory::GetRandom(_min, _max);
	curObj = ObjectFactory::CreateObj(x);
	SetBestObj(curObj);

	TabuList.push_back(curObj);

	cout << "초기값: "; curObj->show(); cout << endl;
}

void ObjectManager::Move()
{
	CreateNearObj();
	SetNextcurObj();
	cmpBestObj();

	ReleaseMoveList();
}

void ObjectManager::Move(int _goal)
{
	while (true)
	{
		if (curObj == nullptr) break;
		Move();
		if (BestCnt >= _goal)
			break;		
	}
	cout << "최종: "; BestObj->show(); cout << endl;
}

void ObjectManager::SetNextcurObj()
{
	Object* obj = GetNextObj();

	if (obj == nullptr) {
		cout << "막혔습니다!\n";
		SetcurObj(nullptr);
		return;
	}	
	SetcurObj(obj);
	PushTabuList(obj);
}

void ObjectManager::SetBestObj(Object* obj)
{
	if (!CheckTabu(obj) && BestObj != nullptr) delete BestObj;
	BestObj = obj;
	BestCnt = 0;
}

int ObjectManager::cmpBestObj()
{
	if (GetBestObjFit() < GetcurObjFit())
		SetBestObj(curObj);
	else BestCnt++;

	cout << "현재 베스트 값: " << GetBestObjCand() <<
		", 카운팅: " << BestCnt << endl;

	return BestCnt;
}

void ObjectManager::SetMoveList(Object* obj) { MoveList.push_back(obj); }
Object* ObjectManager::GetMoveList(int _ind){return MoveList[_ind];}
Object* ObjectManager::GetNextObj()
{
	SortMoveList();
	for (vector<Object*>::iterator it = MoveList.begin();
		it != MoveList.end(); ++it)
	{
		if (!CheckTabu(*it)) return *it;
	}
	return nullptr;
}
void ObjectManager::CreateNearObj()
{
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
	while (!MoveList.empty()){

		if (MoveList.back()->GetCand() == GetcurObjCand()
			|| MoveList.back()->GetCand() == GetcurObjCand())
		{
			MoveList.pop_back();
			continue;
		}

		delete MoveList.back();
		MoveList.back() = nullptr;
		MoveList.pop_back();
	}
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
	TabuList.push_back(obj);
	if (CheckListSize()) PopList();
}

bool ObjectManager::CheckTabu(Object* obj)
{
	int cand = obj->GetCand();
	for (list<Object*>::iterator iter = TabuList.begin();
		iter != TabuList.end(); ++iter) {

		if (cand == (*iter)->GetCand())
			return true;
	}
	return false;
}

bool ObjectManager::CheckListSize() { return TabuList.size() > lSize; }

void ObjectManager::PopList()
{
	if (TabuList.empty()) return;

	if (TabuList.front()->GetCand() == GetBestObjFit())
	{
		TabuList.pop_front(); return;
	}

	delete TabuList.front();
	TabuList.front() = nullptr;
	TabuList.pop_front();
}

void ObjectManager::TabuRelease() {
	while (!TabuList.empty())PopList();
}

void ObjectManager::ShowTabuList()
{
	cout << "\n*****TabuList*****\n";
	for (list<Object*>::iterator it = TabuList.begin();
		it != TabuList.end(); ++it) {
		(*it)->show();
	}
}

