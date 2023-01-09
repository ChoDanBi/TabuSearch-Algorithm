#include "TabuSerach.h"
#include "NodeFactory.h"

TabuSerach* TabuSerach::Instance = NULL;

void TabuSerach::Init(int _scale, int _range)
{
	Count = 0; NM->Init(_scale, _range);
}

void TabuSerach::Init(int _scale, int _range, int _num)
{
	Count = 0; NM->Init(_scale, _range, _num);
}

void TabuSerach::Start(int _goal)
{
}

void TabuSerach::Finish(bool _isgoal)
{
	if (!_isgoal)
		cout << "¡ØBreak!\n";
	cout << "Final Num: "; BEST->Show();
}

int TabuSerach::Simulating()
{
	NeighborSearch();
	NM->SortMove();
	isEdgeContain();
	NM->ReleaseMove();
	AddEdgeinTabu();
	return CompareEdge();
}

void TabuSerach::NeighborSearch()
{
	int size = NM->GetSize();
	for (int i = 0; i < size; ++i)
		NM->addMove(NF::CreateNearNode(
			NM->GetcNode(), i, size));
}

bool TabuSerach::isEdgeContain()
{
	for (vector<Node*>IT i = MOVE->begin();
		i != MOVE->end(); ++i) {
		if (NM->isContainTabu(*i)) continue;

		NM->SetcNode(*i);
		MOVE->erase(i);
		return false;
	}
	Finish(false);
	return true;
}

void TabuSerach::AddEdgeinTabu()
{
	int scale = NM->GetScale();
	TABU->push_back(CUR);

	if (scale < TABU->size()) {
		int num = TABU->front()->GetNum();
		NM->PopTabu(
			(num == CUR->GetNum() || num == BEST->GetNum())
			? true : false
		);
	}
}

int TabuSerach::CompareEdge()
{
	if (CUR > BEST) {
		NM->DelBestNode(NM->isContainTabu(BEST));
		NM->SetbNode(CUR);
		Count = 0;
	}
	else Count++;
	return Count;
}
