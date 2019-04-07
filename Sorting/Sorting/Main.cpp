#include "LinkedList.h"

void main() {

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