#include <iostream>
#include <fstream>
#include <vector>
#include "insert_sort.h"
#include "select_sort.h"
#include "bubble_sort.h"

using namespace std;

int main()
{
	vector<int> sort_arr;
	ifstream infile("/Users/weiter/data_structures/Sort/random_num.txt");
	ofstream outfile("/Users/weiter/data_structures/Sort/result_num.txt", ofstream::app);
	if (!infile)
	{
		cerr << "error: can't open the file!" << endl;
		return -1;
	}
	int num;
	while (infile >> num)
		sort_arr.push_back(num);
	//InsertSort<int>(sort_arr);
	//outfile << "The insert sort result is :" << endl;
	//SelectSort<int>(sort_arr);
	//outfile << "The select sort result is :" << endl;
	BubbleSort<int>(sort_arr);
	outfile << "The bubble sort result is :" << endl;
	vector<int>::iterator iter = sort_arr.begin();
	int count = 0;
	while (iter != sort_arr.end())
	{
		outfile << *iter++ << " " ;
		if ((count + 1) % 10 == 0)
			outfile << "\n" ;
		++count;
	}
	outfile << "\n";
	return 0;
}
