#pragma once
#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include<fstream>


using namespace std;
//returns the time it took to sort
float ShellSort(int arrayToSort[]) {
	return 0;
}

float ShellSort(string fileTosortFrom) {
	return 0;
}


float InsertionSort(vector<int> &arrayToSort) {
	clock_t t;
	t = clock();
	//dostuff;
	int placeHolder = 0;
	while (placeHolder < arrayToSort.size()) {
		int iterator = placeHolder - 1;
		while (iterator >= 0) {
			if (arrayToSort[placeHolder] < arrayToSort[iterator]) {

				iterator--;
			}
			else {
				//put the thingy here
				int transferNUmber = arrayToSort[placeHolder];
				arrayToSort.erase(arrayToSort.begin() + placeHolder);
				arrayToSort.insert(arrayToSort.begin() + iterator + 1, transferNUmber);
				break;
			}

			if (iterator == -1) {
				int transferNUmber = arrayToSort[placeHolder];
				arrayToSort.erase(arrayToSort.begin() + placeHolder);
				arrayToSort.insert(arrayToSort.begin(), transferNUmber);
				
			}
		}

		placeHolder++;
	}

	//t is number of ticks and clocks_per_sec is number of ticks per second
	t = clock() - t;
	return ((float)t/CLOCKS_PER_SEC);
}

float InsertionSort(string fileTosortFrom, vector<int> &arrayToAddInto) {
	ifstream myFile;
	myFile.open(fileTosortFrom);
	if (myFile.is_open()) {

		string fileLine;
		while (getline(myFile, fileLine))
		{
			arrayToAddInto.push_back(stoi(fileLine));
		}
		myFile.close();
	}
	else {
		cout << "Cannot open File" << endl;
		return 0;
	}
	
	return InsertionSort(arrayToAddInto);
}
