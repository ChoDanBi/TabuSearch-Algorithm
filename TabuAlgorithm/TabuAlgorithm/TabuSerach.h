#pragma once
#include "header.h"
#include "NodeManager.h"

class TabuSerach
{
private:
	static TabuSerach* Instance;
public:
	static TabuSerach* GetInstance() {
		if (Instance == NULL)
			Instance = new TabuSerach();
		return Instance;
	}


};

