#include<iostream>
#include"my_list.h"
int main()
{
	my_List::List<size_t> a;
	my_List::List<size_t> b;
	for (size_t i = 0; i < 5; i++)
	{
		a.push_back(i);
	}
	a.print_list();
	a.reserve(1);
}