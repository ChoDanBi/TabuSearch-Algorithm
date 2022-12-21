#pragma once
/*
#include "header.h"
#include "Factory.h"
#include "ObjectManager.h"

class CrossManager {
public:
	//자손 만들기
	static vector<int> CrossGene(const vector<int>&b1, const vector<int>&b2) {
		int len = ObjectManager::GetInstance()->GetLen();
		int helf = len / 2;

		vector<int> nextBin;

		for (int i = 0; i < len; ++i)
			nextBin.push_back(i <= helf ? b1[i] : b2[i]);

		return nextBin;
	}
	
	//돌연변이 만들기
	static vector<int> MutationGene(vector<int> _binary) {		
		int ind = Factory::GetRandom(
			0,
			(ObjectManager::GetInstance()->GetLen() - 1));
		
		_binary[ind] = _binary[ind] == 0 ? 1 : 0;

		return _binary;
	}

	static void MutationGene(vector<int>* _binary) {		
		int ind = Factory::GetRandom(
			0,
			(ObjectManager::GetInstance()->GetLen() - 1));
		
		vector<int>::iterator iter = _binary->begin();
		*(iter + ind) = *(iter + ind) == 0 ? 1 : 0;
	}
		
};
*/