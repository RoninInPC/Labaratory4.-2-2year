#include "function.h"
#include<stdio.h>
int main() {
	ListOfStudents* H = MakeListOfStudents(3);
	PrintList(H);
	printf("\n");
	WriteStudentInFile("Guy.txt", H);
	ListOfStudents* H1 = ReadInFile("Guy.txt");
	PrintList(H1);
	return 0;
}