#include <iostream>
#include "myvector.h"
#include "MyList.h"
#include "BinarySearchTree.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	/*cout << "Test of MyVector:" << endl;
	MyVector<int> my_vec;
	int numbers;
	cout << "enter some numbers(the -1 to end):";
	while (cin >> numbers && numbers != -1)
		my_vec.push_back(numbers);
	MyVector<int> my_vec_copy(my_vec);
	cin >> numbers;
	my_vec_copy.push_back(numbers);
	MyVector<int>::iterator ite = my_vec_copy.begin();
	cout << "elements of my_vec_copy : " << endl;
	while (ite != my_vec_copy.end())
		cout << *ite++ << " ";
	cout << endl;
	my_vec.reserve(50);
	my_vec.pop_back();
	cout << "elements of my_vec : " << endl;
	for (int i = 0 ; i < my_vec.size(); ++i)
		cout << my_vec[i] << " ";
	cout << endl;
	if (my_vec.empty())
		cout << "this is empty" << endl;
	else
		cout << "this is not empty" << endl;
	cout << "the length of my_vec is : " << my_vec.size() << " and the capacity is : " << my_vec.capacity() << endl;
	cout << "the length of my_vec_copy is : " << my_vec_copy.size() << " and the capacity is : " << my_vec_copy.capacity() << endl;
	cout << "the end element of my_vec_copy is : " << my_vec_copy.back() << endl;
	cout << "\nend of the program" << endl;

	cout << "Test of MyList:" << endl;
	MyList<int> my_lst;
	cout << "input some numbers: " ;
	int numbers;
	while (cin >> numbers)
		my_lst.push_back(numbers);
	cout << "elements of my_lst is: ";
	MyList<int>::const_iterator itr = my_lst.begin();
	while (itr != my_lst.end())
		cout << *itr++ << " ";
	if (my_lst.size() == 0)
		cout << "the size is 0 " << endl;
	if (my_lst.empty())
		cout << "my_lst is empty." << endl;
*/
	cout << "Test of BinarySearchTree:" << endl;
	BinarySearchTree<int> my_bst;
	cout << "\nInput some numbers: ";
	int num_tree;
	while (cin >> num_tree)
		my_bst.insert(num_tree);
	if (my_bst.empty())
		cout << "This tree is empty!" << endl;
	cout << "The max number is: " << my_bst.FindMax() << endl;
	cout << "The min number is: " << my_bst.FindMin() << endl;
	cout << endl;
	return 0;
}
