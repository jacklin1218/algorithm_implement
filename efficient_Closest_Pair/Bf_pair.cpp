#include"Bf_pair.h"
#include<algorithm>
#include<math.h>
Bf_pair::Bf_pair()
{
	
}

void Bf_pair::add_pair(Mypair in)
{
	pairs.push_back(in);
}

void Bf_pair::print()
{
	for (size_t  i = 0; i < pairs.size(); i++) {
		printf("node %d:(%d, %d)\n",i, pairs[i].get(1), pairs[i].get(2));
	}
	puts("");
	return;

}


void Bf_pair::sort_pair()
{
	int last = 0, end = pairs.size();
	xsort.clear();
	ysort.clear();

	quick_sort(0, end, 1);
	for (size_t  i = 0; i < pairs.size(); i++) {
		pairs[i].set_count(i);
		xsort.push_back(pairs[i]);
	}
	quick_sort(0, end, 2);
	for (size_t  i = 0; i < pairs.size(); i++)
		ysort.push_back(pairs[i]);
	for (size_t  i = 0; i < pairs.size(); i++)
		xsort[ysort[i].get_count()].set_count(i);
}

double Bf_pair::bf_cal_first(vector<Mypair> pairs)
{
	return sqrt(bf_cal(pairs));
}

double Bf_pair::bf_cal_first()
{
	return sqrt(bf_cal(pairs));
}

int Bf_pair::bf_cal(vector<Mypair> pairs)
{
	if (pairs.size() <2) {
		printf("need > 2 pair");
		return 0;
	}
	Mypair *tmp1=&pairs[0],*tmp2=&pairs[1];
	int min_Distance = pairs[0].no_sqrt_distance(pairs[1]);
	for (size_t  i = 0; i < pairs.size() - 1; i++) {
		for (size_t  j = i + 1; j < pairs.size(); j++) {
			int tmp = pairs[i].no_sqrt_distance(pairs[j]);
			if (tmp < min_Distance) {
				tmp1 = &pairs[i];
				tmp2 = &pairs[j];
				min_Distance = tmp;
			}
		}
	}
	return min_Distance;
}

double Bf_pair::fast_cal_first()
{
	sort_pair();
	vector<Mypair> P,Q;

	for (size_t  i = 0; i < pairs.size(); i++)P.push_back(xsort[i]);
	for (size_t  i = 0; i < pairs.size(); i++)Q.push_back(ysort[i]);
	double ans = fast_cal(P, Q);

	return sqrt(ans);
}

void Bf_pair::clear()
{
	pairs.clear();
	xsort.clear();
	ysort.clear();
}
int Bf_pair::fast_cal(vector<Mypair> P, vector<Mypair> Q)

{
	if (P.size() <= 3) { // if nodes count <= 3 use bf-algorithm
		return bf_cal(P);
	}
	else {
		int n = P.size();
		vector<Mypair> pL,pR,qL,qR,S;
		int dictionary[TEST_x] = { 0 };
		int count = n;
		
		for (int i = 0; i < n / 2; i++) {
			pL.push_back(P[i]);
			dictionary[P[i].get_count()] = 1;

		}
		for (int i = n / 2; i < n; i++) {
			pR.push_back(P[i]);
			dictionary[P[i].get_count()] = 2;

		}


		for (int i = 0; count; i++) { // !!! this for-loop is not a good solution
			if (dictionary[i] != 0)count--;
			if (dictionary[i]==1)qL.push_back(ysort[i]);
			else if(dictionary[i]==2)qR.push_back(ysort[i]);
		}//end for

		int dL = fast_cal(pL, qL);
	    int dR = fast_cal(pR, qR);

		int d = min(dL, dR);
		int m = P[n / 2 - 1].get(1);
		for (size_t i = 0; i < Q.size(); i++) {
			if (abs(Q[i].get(1) - m) < d) {
				S.push_back(Q[i]);
			}
		}
		int dminsq = d;

		for (size_t i = 0; i < S.size() - 1; i++) {
			size_t  k = i + 1;
			int dis = S[k].no_sqrt_distance(S[i]);
			while (k < S.size() && S[k].get(2) - S[i].get(2) < dminsq) {
				dminsq = min(S[k].no_sqrt_distance(S[i]), dminsq);
				k++;
			}
		}
		return dminsq;
	}
	
}

void Bf_pair::quick_sort(int begin, int end, int isit)
{

	if (begin >= end - 1)return;
	int pos = partition(begin, end, isit);
	
	quick_sort(begin, pos, isit);
	quick_sort(pos + 1, end, isit);

}

int Bf_pair::partition(int begin, int end, int isit)
{
	int pos = begin;
	int last = end;
	Mypair tmp = pairs[pos];
	int pivot = pairs[pos].get(isit);
	while (pos < last) { 
		while (pos < last&&pairs[--last].get(isit) >= pivot);
		pairs[pos].copyfrom(pairs[last]);

		while (pos < last&&pairs[++pos].get(isit) <= pivot);
		pairs[last].copyfrom(pairs[pos]);

	}
	pairs[pos].swap(tmp);
	return pos;
}
