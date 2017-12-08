#include"Bf_pair.h"//class for pairlist
#include"Mypair.h" //class for pair
#include"Source.h"//some define
#include<iostream>
using namespace std;

int main() {
	Bf_pair Pairs;
	Pairs.add_pair(Mypair(0, 4));
	Pairs.add_pair(Mypair(1, 13));
	Pairs.add_pair(Mypair(3, -5));
	Pairs.add_pair(Mypair(6, 12));
	Pairs.add_pair(Mypair(12, -5));
	Pairs.add_pair(Mypair(-3, 23));
	Pairs.add_pair(Mypair(4, 11));
	Pairs.add_pair(Mypair(7, 2));
	Pairs.add_pair(Mypair(8, 34));
	Pairs.add_pair(Mypair(9, 21));

	double a1, a2;
	a1 = Pairs.fast_cal_first();
	a2 = Pairs.bf_cal_first();
	cout << "BF-algorithm ans is " << a1 << " speed algorithm answer is " << a2 << endl;
}