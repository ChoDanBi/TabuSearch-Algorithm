#include "header.h"
#include "ObjectManager.h"
#include <time.h>

int main() {
	clock_t start, finish;
	double duration;
	start = clock();

	ObjectManager::GetInstance()->Init(20, 7, 0, 127);
	ObjectManager::GetInstance()->Move(10);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "걸린시간: "  << duration;

	return 0;
}