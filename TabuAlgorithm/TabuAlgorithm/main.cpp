#include "header.h"
#include "TabuSerach.h"
#include <time.h>

void duration(clock_t start, clock_t finish);


int main(void) {
	cout << "+    TabuSerachAlgorithm    +\n";

	clock_t start, finish;
	start = clock();
	//==========================

	
	TB->Init(10, 31);
	TB->Start(5);


	//==========================
	finish = clock(); duration(start, finish); return 0;
}

void duration(clock_t start, clock_t finish) {
	double dur = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n\n걸린 시간: " << dur << endl;
}