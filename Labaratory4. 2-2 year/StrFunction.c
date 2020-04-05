#include"function.h"
#include<string.h>
int StrToInt(char* String) {
	int Ans = 0;
	for (int i = 0; i < strlen(String); i++) {
		Ans = Ans * 10 + String[i] - 48;
	}
	return Ans;
}
Student StrToStudent(char* String) {
	Student Ans;
	int k = 0;
	char* Name = (char*)malloc(k * sizeof(char));
	int n = 0;
	while (1) {
		if (String[n] == ' ') {
			Name[k] = '\0';
			break;
		}
		k++;
		Name = (char*)realloc(Name, k * sizeof(char));
		Name[k - 1] = String[n];
		n++;
	}
	n++;
	k = 0;
	char* Family = (char*)malloc(k * sizeof(char));
	while (1) {
		if (String[n] == ' ') {
			Family[k] = '\0';
			break;
		}
		k++;
		Family = (char*)realloc(Family, k * sizeof(char));
		Family[k - 1] = String[n];
		n++;
	}
	n++;
	k = 0;
	char* Age = (char*)malloc(k * sizeof(char));
	while (1) {
		if (String[n] == ' ') {
			Age[k] = '\0';
			break;
		}
		k++;
		Age = (char*)realloc(Age, k * sizeof(char));
		Age[k - 1] = String[n];
		n++;
	}
	n++;
	k = 0;
	char* PhoneNumber = (char*)malloc(k * sizeof(char));
	while (1) {
		if (String[n] == ' ') {
			PhoneNumber[k] = '\0';
			break;
		}
		k++;
		PhoneNumber = (char*)realloc(PhoneNumber, k * sizeof(char));
		PhoneNumber[k - 1] = String[n];
		n++;
	}
	n++;
	k = 0;
	char* Groop = (char*)malloc(k * sizeof(char));
	while (1) {
		if (String[n] == ' ') {
			Groop[k] = '\0';
			break;
		}
		k++;
		Groop = (char*)realloc(Groop, k * sizeof(char));
		Groop[k - 1] = String[n];
		n++;
	}
	n++;
	k = 0;
	char* SizeOfMark = (char*)malloc(k * sizeof(char));
	while (1) {
		if (String[n] == ' ') {
			SizeOfMark[k] = '\0';
			break;
		}
		k++;
		SizeOfMark = (char*)realloc(SizeOfMark, k * sizeof(char));
		SizeOfMark[k - 1] = String[n];
		n++;
	}
	n++;
	Ans.Name = Name;
	Ans.Family = Family;
	Ans.PhoneNumber = PhoneNumber;
	Ans.Groop = Groop;
	Ans.Age = StrToInt(Age);
	Ans.SizeArrOfMark = StrToInt(SizeOfMark);
	int* Arr = (int*)malloc(Ans.SizeArrOfMark * sizeof(int));
	for (int i = 0; i < Ans.SizeArrOfMark; i++) {
		k = 0;
		char* Mark = (char*)malloc(k * sizeof(char));
		while (1) {
			if (String[n] == ' ' || String[n]=='\0') {
				Mark[k] = '\0';
				break;
			}
			k++;
			Mark = (char*)realloc(Mark, k * sizeof(char));
			Mark[k - 1] = String[n];
			n++;
		}
		n++;
		Arr[i] = StrToInt(Mark);
	}
	Ans.ArrOfMark = Arr;
	return Ans;
}
int FindSmallStrInBigStr(char* SmallStr, char* BigStr, int FindNumber) {
	//FindNumber = 0 => beginning of line
	//FindNumber = 1 => middle in line
	//FindNumber = 2 => end of line
	if (FindNumber == 0) {
		for (int i = 0; i < strlen(SmallStr); i++) {
			if (SmallStr[i] != BigStr[i]) {
				return 1;
			}
		}
		return 0;
	}
	if (FindNumber == 2) {
		for (int i = strlen(BigStr) - strlen(SmallStr); i < strlen(BigStr); i++) {
			if (BigStr[i] != SmallStr[i - strlen(BigStr) + strlen(SmallStr)]) {
				return 1;
			}
		}
		return 0;
	}
	if (FindNumber == 1) {
		for (int i = strlen(SmallStr); i < strlen(BigStr) - strlen(SmallStr); i++) {
			int k = 0;
			for (int j = i; j < i + strlen(SmallStr); j++) {
				if (BigStr[j] != SmallStr[k]) {
					return 1;
				}
				k++;
			}
		}
		return 0;
	}
	return 0;
}
int FindStrInPartOfStudent(char* SmallStr, Student Human, char* PartStudent, int FindNumber) {
	//PartStudent = Name or Family or PhoneNumber or Groop
	if (PartStudent == "Name") {
		return FindSmallStrInBigStr(SmallStr, Human.Name, FindNumber);
	}
	if (PartStudent == "Family") {
		return FindSmallStrInBigStr(SmallStr, Human.Family, FindNumber);
	}
	if (PartStudent == "PhoneNumber") {
		return FindSmallStrInBigStr(SmallStr, Human.PhoneNumber, FindNumber);
	}
	if (PartStudent == "Groop") {
		return FindSmallStrInBigStr(SmallStr, Human.Groop, FindNumber);
	}
	return 0;
}