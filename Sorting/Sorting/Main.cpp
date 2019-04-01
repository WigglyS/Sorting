#include"SortingFunctions.h"

void main() {
	vector<int> testarry = { 100,0,8,4,5,2,5,3,45,2,1,7,3,4,0,7,1,12,3,67 ,45,23,82,69,26,37,176,73,65,3,29,30, 100,0,8,4,5,2,5,3,45,2,1,7,3,4,0,7,1,12,3,67 ,45,23,82,69,26,37,176,73,65,3,29,30 };
	
	cout << "Unsorted Array : "<< endl;
	for (int i = 0; i < testarry.size(); i++)
	{
		cout << testarry[i] << " ";
	}

	cout << endl << endl << "insertion sort took : " << InsertionSort(testarry) << " seconds"<< endl << endl;
	InsertionSort("numToSort.txt", testarry);


	cout << "Sorted Array : " << endl;
	for (int i = 0; i < testarry.size(); i++)
	{
		cout << testarry[i] << " ";
	}
	system("pause");

}