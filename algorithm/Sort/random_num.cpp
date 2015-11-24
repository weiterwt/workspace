#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	string file("/Users/weiter/data_structures/Sort/random_num.txt");
	ofstream out_file(file.c_str());
	if (!out_file)
	{
		cerr << "error: unable to open the file : " << file << endl;
		return -1;
	}
	for (int i = 0; i < 100; ++i)
	{
		int num = rand() % 100;
		out_file << num << " " ;
		if ((i + 1) % 10 == 0)
			out_file << "\n";
	}
	out_file.close();
	return 0;
}
