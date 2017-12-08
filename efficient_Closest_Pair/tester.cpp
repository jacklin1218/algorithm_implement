#include"Bf_pair.h"
#include"Mypair.h"
#include"Source.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
using namespace std;

int main() {
	unsigned seed;
	seed = (unsigned)time(NULL);
	srand(seed);
	Bf_pair Pairs;
	double a1 = 1, a2 = 1;
	int state = 1;
	for (int j = 0; j < TEST_time; j++) {
		cout << "begin " << j << " times test\n";
		for (int i = 0; i < TEST_x; i++) {
			Pairs.add_pair(Mypair(i, rand() % TEST_y));
		}

		a1 = Pairs.fast_cal_first();
		a2 = Pairs.bf_cal_first();
		if (a1 != a2) {
			cout << "My ans is " << a1 << " currect answer is " << a2<<endl;
			state = 0;
			Pairs.print();
			break;

		}
		Pairs.clear();
	}
	if(state)puts("CURRECT");
	else puts("ERROR");
}