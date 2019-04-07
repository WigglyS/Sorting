
#include "LinkedList.h"

void main() {
	//vector<int> testarry = { 100,0,8,4,5,2,5,3,45,2,1,7,3,4,0,7,1,12,3,67 ,45,23,82,69,26,37,176,73,65,3,29,30, 100,0,8,4,5,2,5,3,45,2,1,7,3,4,0,7,1,12,3,67 ,45,23,82,69,26,37,176,73,65,3,29,30 };
	//
	//cout << "Unsorted Array : "<< endl;
	//for (int i = 0; i < testarry.size(); i++)
	//{
	//	cout << testarry[i] << " ";
	//}

	//cout << endl << endl << "insertion sort took : " << InsertionSort(testarry) << " seconds"<< endl << endl;
	//InsertionSort("numToSort.txt", testarry);


	//cout << "Sorted Array : " << endl;
	//for (int i = 0; i < testarry.size(); i++)
	//{
	//	cout << testarry[i] << " ";
	//}
	//system("pause");


	LinkedList<int> linkedList;


	int Quit = 0;

	do {

		int input;
		linkedList.Display();
		cout << "Size : " << linkedList.Size() << endl;
		cout << "Press (1) to Add Number to List" << endl;
		cout << "Press (2) to Remove A Number From the list" << endl;
		cout << "Press (3) to Clear the List" << endl;
		cout << "Press (4) to Run Insertion Sort" << endl;
		cout << "Press (5) to Run Shell Sort" << endl;
		cout << "Press (6) to Add From a File (Will clear the current List)" << endl;
		cout << "Press (0) to Quit" << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			int AddNum;
			cout << "Enter a Number to Add: ";
			cin >> AddNum;
			linkedList.Insert(AddNum);
			system("CLS");
			break;
		case 2:
			int RemoveNum;
			cout << "Enter a Number to Remove: ";
			cin >> RemoveNum;
			linkedList.Delete(RemoveNum);
			system("CLS");
			break;
		case 3:
			system("CLS");
			linkedList.Clear();
			break;
		case 4:
			system("CLS");
			cout << "InsertionSort took " << linkedList.InsertionSort() << " seconds to complete"<< endl;
			break;
		case 5:
			system("CLS");
			cout <<"ShellSort took "<< linkedList.ShellSort() << " seconds to complete"<< endl;
			break;
		case 6: {
			system("CLS");
			string file;
			//my file holding numbers rn is :  numToSort.txt
			cout << "Enter a File to Read From: ";
			cin >> file;
			linkedList.InsertFromFile(file);
			break;
		}
			
		case 0:
			Quit = 1;
			break;
		}

	} while (Quit == 0);


}