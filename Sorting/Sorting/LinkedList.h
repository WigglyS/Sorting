#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<fstream>

using namespace std;

///  The Node class is to store data of a generic type and acess to the next and previous in the list// nested so you have to go through the list to create nodes
template<typename T>
class Node
{
public:
	Node* GetPrevious() { return Previous; }
	void SetPrevious(Node* prev) { Previous = prev; }
	Node* GetNext() { return Next; }
	void SetNext(Node* next) { Next = next; }

	T Getdata() { return data; };
	void SetData(T d) { data = d; };
private:
	Node* Previous = nullptr;
	Node* Next = nullptr;
	T data;
};

//The list class is for holding acess to the head and tail as well as the funtions for adding deleting etc for the list
template<typename T>
class LinkedList
{
private:
	Node<T>* Head = nullptr;
	Node<T>* Tail = nullptr;
	int size;
public:
	int Size() { return size; }
	/// This function inserts the data you pass it to the end of the list
	void Insert(T data)
	{
		//this condition is for the first node created, the nodes pointers are set to null and the head and tail are set to it since its the only node
		if (Head == nullptr && Tail == nullptr)
		{
			Node<T>* newNode = new Node<T>;
			newNode->SetData(data);
			newNode->SetPrevious(NULL);
			newNode->SetNext(NULL);
			Head = newNode;
			Tail = newNode;

			//all the other nodes are handled by this one, adds a new node rearanges the pointers of the previous node and the new one and moves the tail to the new node
		}
		else
		{
			Node<T>* newNode = new Node<T>;
			newNode->SetData(data);
			newNode->SetPrevious(Tail);
			Tail->SetNext(newNode);
			newNode->SetNext(NULL);
			Tail = newNode;
		}

		size++;
	}

	//only works on Int right now
	bool InsertFromFile(string fileName) {
		Clear();
		ifstream myFile;
		myFile.open(fileName);
		if (myFile.is_open()) {

			string fileLine;
			while (getline(myFile, fileLine))
			{
				Insert(stoi(fileLine));
			}
			myFile.close();
			return true;
		}
		else {
			cout << "Cannot open File" << endl;
			return false;
		}
	}

	///Deletes the node of which you give the pointer to
	void Delete(Node<T>* N)
	{
		//this first one is the general case, moves the pointers on both sides of the node to be deleted
		if (Tail != N && Head != N) {
			N->GetPrevious()->SetNext(N->GetNext());
			N->GetNext()->SetPrevious(N->GetPrevious());
		}
		//these next 2 handle it if it  either the head or tail or both, it moves the head to the next/null if thereisnt one and sets the its previous to null then 
		// the same with the tail using previous instead of next
		if (Head == N)
		{
			Head = N->GetNext();
			if (N->GetNext() != NULL) {
				N->GetNext()->SetPrevious(NULL);
			}
		}
		if (Tail == N)
		{
			Tail = N->GetPrevious();
			if (N->GetPrevious() != NULL) {
				N->GetPrevious()->SetNext(NULL);
			}

		}
		//in any case we made the node to be deleted pointers = to null then finaly delete it
		N->SetNext(NULL);
		N->SetPrevious(NULL);
		delete N;

		size--;
	}

	///this delete funcion takes data instead of a pointer,  still  deletes the node which contains the data
	void Delete(T data) {
		// uses the find function below to get a pointer then just uses the destroy function above
		Node<T>* FoundData = Find(data);
		if (FoundData != NULL) {
			Delete(FoundData);
		}
		else {
			cout << "That data is not in the List" << endl;
		}
	}

	///loops through all the nodes and if it finds a  match to the data then it returns a pointer to it, if it doesnt find it it returns null
	Node<T>* Find(T data)
	{
		Node<T>* temp = Head;
		while (temp != NULL)
		{
			if (temp->Getdata() == data)
			{
				return temp;
			}
			else
			{
				temp = temp->GetNext();
			}
		}
		return NULL;
	}

	//loops through all the nodes and displays their data
	void Display() {
		if (size > 100) {
			cout << "Size : " << size << " is too big to Display" << endl;
			return;
		}
		Node<T>* temp = Head;
		//if the whole list is emply dont print anyhting otherwise  print the list and an endl;
		if (temp != NULL) {
			cout << "The list contains: " << endl;
			while (temp != NULL)
			{
				cout << temp->Getdata() << " ";
				temp = temp->GetNext();
			}
			cout << endl;
		}
	}

	void Clear() {
		while (Tail != NULL)
		{
			Delete(Tail);
		}
		size = 0;
	}

	float InsertionSort() {
		clock_t t;
		t = clock();

		Node<T>* placeHolder = Head;
		while (placeHolder != NULL) {
			Node<T>* iterator = placeHolder->GetPrevious();
			while (iterator != NULL) {
				if (placeHolder->Getdata() < iterator->Getdata()) {
					iterator = iterator->GetPrevious();
				}
				else {
					//take the place holder out of the list 
					if (placeHolder->GetNext() != NULL)
						placeHolder->GetNext()->SetPrevious(placeHolder->GetPrevious());
					if (placeHolder->GetPrevious() != NULL)
						placeHolder->GetPrevious()->SetNext(placeHolder->GetNext());

					//inset him in the correct spot ebhind the Iterator
					if (iterator->GetNext() != NULL) {
						iterator->GetNext()->SetPrevious(placeHolder);
						placeHolder->SetNext(iterator->GetNext());
					}
					iterator->SetNext(placeHolder);
					placeHolder->SetPrevious(iterator);
						
					break;
				}

				//if it makes it all the way to the front then the iterator will be null
				if (iterator == NULL) {
					//take the place holder out of the list 
					if (placeHolder->GetNext() != NULL) {
						placeHolder->GetNext()->SetPrevious(placeHolder->GetPrevious());
					}
					if (placeHolder->GetPrevious() != NULL)
						placeHolder->GetPrevious()->SetNext(placeHolder->GetNext());

					placeHolder->SetNext(Head);
					Head->SetPrevious(placeHolder);
					placeHolder->SetPrevious(NULL);
					Head = placeHolder;

				}
			}

			placeHolder = placeHolder->GetNext();
		}

		//t is number of ticks and clocks_per_sec is number of ticks per second
		t = clock() - t;
		return ((float)t / CLOCKS_PER_SEC);
	}

	//float QuickSort() {
	//	clock_t t;
	//	t = clock();
	//	if(Head != NULL)
	//		RecursiveQuickSort(Head)




	//	//t is number of ticks and clocks_per_sec is number of ticks per second
	//	t = clock() - t;
	//	return ((float)t / CLOCKS_PER_SEC);
	//}

	//Node<T>* RecursiveQuickSort(Node<T>* StartingPoint) {
	//	Node<T>* partition = StartingPoint;
	//	Node<T>* iterator = partition->GetNext();
	//	while (iterator != NULL)
	//	{
	//		if (iterator->Getdata() > partition->Getdata()) {

	//		}
	//		else {
	//			//swap the value next to the partition
	//			T temp = iterator->Getdata();
	//			iterator->SetData(partition->GetNext()->Getdata());
	//			partition->GetNext()->Setdata(temp);

	//			//then swap the partitionand it so it goes on the left of the partition
	//			T temp = partition->Getdata();
	//			partition->SetData(partition->GetNext()->Getdata());
	//			partition->GetNext()->Setdata(temp);

	//		}
	//		iterator = iterator->GetNext();
	//	}
	//	if(iterator ->GetNext() != NULL)
	//		RecursiveQuickSort(iterator->GetNext())
	//	
	//	if (iterator->GetPrevious() != NULL)
	//		RecursiveQuickSort(iterator->GetPrevious())

	//}

	float ShellSort(){
		clock_t t;
		t = clock();
		
		int Gap = floor( size / 2);

		Node<T>* iterator = Head;
		Node<T>* comparer;
	

		while (Gap > 1)
		{
			iterator = Head;
			comparer = iterator;
			while (comparer != NULL) {
				int count = 0;
				comparer = iterator;
				while (count < Gap) {
					if (comparer != NULL) {
						comparer = comparer->GetNext();
						count++;
					}
					else {
						break;
					}
				}
				if (comparer != NULL) {
					if (iterator->Getdata() > comparer->Getdata()) {
						T temp = iterator->Getdata();
						iterator->SetData(comparer->Getdata());
						comparer->SetData(temp);
					}
				}
				iterator = iterator->GetNext();
			}
			Gap = floor(Gap / 2.2);
		}

		InsertionSort();

		//t is number of ticks and clocks_per_sec is number of ticks per second
		t = clock() - t;
		return ((float)t / CLOCKS_PER_SEC);
	}
};