#pragma once
#include<vector>
#include"Source.h"
using namespace std;
class Mypair
{
private:
	int x;
	int y;
	int count;
public:
	
	Mypair(int x,int y);
	int get(int isit); //if input 1 return x  else return y
	void swap(Mypair &a);
	void setx(int x);
	void sety(int y);
	int no_sqrt_distance(Mypair a);
	void set_count(int x);
	int get_count();
	void print_pair();
	void copyfrom(Mypair a);
};

