#include "Mypair.h"
#include <math.h>
#include<algorithm>
#include<stdio.h>
Mypair::Mypair(int x,int y)
{
	this->x = x;
	this->y = y;
	count = 0;
}

int Mypair::get(int isit)
{
	if (isit == 1)return x;
	return y;
}

void Mypair::swap(Mypair & a)
{
	std::swap(x, a.x);
	std::swap(y, a.y);
	std::swap(count, a.count);
}

void Mypair::setx(int x)
{
	this->x = x;
}
void Mypair::sety(int y)
{
	this->y = y;
}

int Mypair::no_sqrt_distance(Mypair a)
{
	return (a.x - x)*(a.x - x) + (a.y - y)*(a.y - y);
}

void Mypair::set_count(int x)
{
	count = x;
}

int Mypair::get_count()
{
	return count;
}

void Mypair::print_pair()
{
	printf("(%d, %d)\n", x, y);

}

void Mypair::copyfrom(Mypair a)
{
	x = a.x;
	y = a.y;
	count = a.count;
}




