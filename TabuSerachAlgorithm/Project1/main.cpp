#include "header.h"
#include "ObjectManager.h"

int main() {
	ObjectManager::GetInstance()->Init(20, 7, 0, 127);
	ObjectManager::GetInstance()->Move(5);

	return 0;
}