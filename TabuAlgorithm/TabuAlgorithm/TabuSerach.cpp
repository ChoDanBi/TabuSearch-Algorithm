#include "TabuSerach.h"
#include "NodeFactory.h"

TabuSerach* TabuSerach::Instance = NULL;

void TabuSerach::Init(int _scale, int _range)
{
	Count = 0;
	isBlock = false;
	NM->Init(_scale, _range);
}

void TabuSerach::Init(int _scale, int _range, int _num)
{
	Count = 0;
	isBlock = false;
	NM->Init(_scale, _range, _num);
}

void TabuSerach::Start(int _goal)
{
	while (!isBlock)
	{
		Simulating();
		if (_goal <= Count)
			break;
	}
	Finish(isBlock);
}

void TabuSerach::Finish(bool _isblock)
{
	if (_isblock)
		cout << "¡ØBreak!\n";
	cout << "Final "; BEST->Show();
}

void TabuSerach::Simulating()
{
	NeighborSearch();
	NM->SortMove();

	if (isEdgeContain()) {
		isBlock = true;
		return;
	}

	NM->ReleaseMove();
	AddEdgeinTabu();
	CompareEdge();
}

void TabuSerach::NeighborSearch()
{
	cout << "Current "; ShowNode(CUR);

	int size = CUR->GetBinary().size();
	for (int i = 0; i < size; ++i) {
		NM->addMove(NF::CreateNearNode(
			CUR, i, size));

		cout << "Create Neighbor "; ShowNode(MOVE->back());
	}
}

bool TabuSerach::isEdgeContain()
{
	bool isContain = true;
	for (vector<Node*>IT i = MOVE->begin();
		i != MOVE->end(); ++i) {
		if (NM->isContainTabu(*i)) continue;

		NM->SetcurNode(*i);
		MOVE->erase(i);

		isContain = false; break;
	}
	return isContain;
}

void TabuSerach::AddEdgeinTabu()
{
	int scale = NM->GetScale();
	TABU->push_back(CUR);

	if (scale < TABU->size()) {
		int num = TABU->front()->GetNum();
		NM->PopTabu(
			(num == CUR->GetNum() || num == BEST->GetNum())
			? true : false);
	}
}

void TabuSerach::CompareEdge()
{
	if (CUR->GetFit() > BEST->GetFit()) {
		NM->DelBestNode(NM->isContainTabu(BEST));
		NM->SetbestNode(CUR);
		Count = 0;
	}
	else Count++;

	cout << "\n Best "; ShowNode(BEST);
	cout << "Count: " << Count << "\n\n";
}

void TabuSerach::ShowNode(Node* _node){cout << "Node "; _node->Show();}
