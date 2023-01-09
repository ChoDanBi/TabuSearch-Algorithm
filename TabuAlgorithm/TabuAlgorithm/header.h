#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>


#define NF NodeFactory
#define DEL NodeFactory::SafeDelet

#define NM NodeManager::GetInstance()
#define CUR NodeManager::GetInstance()->GetcNode()
#define BEST NodeManager::GetInstance()->GetbNode()
#define MOVE NodeManager::GetInstance()->GetMoveList()
#define TABU NodeManager::GetInstance()->GetTabuList()

#define TB TabuSerach::GetInstance()

#define IT ::iterator


using namespace std;