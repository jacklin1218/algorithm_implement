#include "Mypair.h"
#include"Source.h"
#include <vector>

using namespace std;
class Bf_pair
{
private:
	vector<Mypair> pairs;
	vector<Mypair> xsort;
	vector<Mypair> ysort;
	void quick_sort(int, int, int);
	int partition(int, int, int);
	int bf_cal(vector<Mypair>);
	int fast_cal(vector<Mypair>, vector<Mypair>);
	void sort_pair();

public:

	Bf_pair();
	void add_pair(Mypair);
	void print();
	double bf_cal_first(vector<Mypair>);
	double bf_cal_first();
	double fast_cal_first();
	void clear();

};
