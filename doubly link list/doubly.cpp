#include <iostream>
#include <string>
using namespace std;
void insert_end(string nam, int id,int age);
void insert_first(string name, int id, int age);
void insert_givenPosition(string name, int id, int age);
void displaybackyard();
void deleteAtFront();
void deleteAtEnd();
struct student {
	string name;
	int id;
	int age;
	student *next;
	student *prev;
}*head=NULL;

void insert_end(string name, int id, int age) {
	student *newStudentInfo = new student;
	student *temp;
	newStudentInfo->id = id;
	newStudentInfo->name = name;
	newStudentInfo->age = age;
	newStudentInfo->next = NULL;
	newStudentInfo->prev = NULL;

	if (head == NULL) {
		head = newStudentInfo;
	}
	else {
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newStudentInfo;
		newStudentInfo->prev = temp;
	}

}
void insert_first(string nam, int id, int age) {
	student *newStudentInfo = new student;
//	student *temp;
	newStudentInfo->id = id;
	newStudentInfo->name = nam;
	newStudentInfo->age = age;
	newStudentInfo->next = NULL;
	newStudentInfo->prev = NULL;
	if (head == NULL) {
		head = newStudentInfo;
	}
	else {
		newStudentInfo->next = head;
		head->prev = newStudentInfo;
		newStudentInfo = head;
	}
}
void insert_givenPosition(string name, int id, int age) {
	student *newStudentInfo = new student;
	student *temp;
	newStudentInfo->id = id;
	newStudentInfo->name = name;
	newStudentInfo->age = age;
	newStudentInfo->next = NULL;
	newStudentInfo->prev = NULL;
	if (head == NULL) {
		head = newStudentInfo;
	}
	else {
		temp = head;
		cout << "Enter position" << endl;
		int pos;
		cin >> pos;
		for (int i = 0; i < pos; i++) {
			temp = temp -> next;
			newStudentInfo->next = temp->next;
			newStudentInfo->prev = temp;
			temp->next->prev = newStudentInfo;
			temp->next = newStudentInfo;
		}

	}
}
void displaybackyard() {
	student *newStudentInfo = new student;
	student *temp;
	student stud;
	newStudentInfo->id;//= id;
	newStudentInfo->name;// = name;
	newStudentInfo->age;// = age;
	newStudentInfo->next = NULL;
	newStudentInfo->prev = NULL;
	temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	while (temp->prev != NULL)
	{
		cout <<"Name "<<newStudentInfo->name<< " ID " << newStudentInfo->id << "Age " << newStudentInfo->age;
		temp = temp->prev;
	}

	
}
void deleteAtFront() {
	student *newStudentInfo = new student;
	student *temp;
	temp = head;
	head = head->next;
	delete temp;
}
void deleteAtEnd() {
	student *newStudentInfo = new student;
	student *temp;
	temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->prev->next = NULL;
	delete temp;

}int main() {
	int id;
	int age;
	string name;
	char ch;
	//char choice;
	do {
		cout << "Enter name ";
		cin >> name;
		cout << "Enter id ";
		cin >> id;
		cout << "Enter age ";
		cin >> age;
		insert_first(name, id, age);
		insert_end(name, id, age);
		displaybackyard();
		system("pause");

	} while (ch == 'Y' || ch == 'y');
}