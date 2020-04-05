#include"function.h"
#include"strfunction.h"
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
const char** Family[20] = { "Sidorov","Guyev","Irodov","Vasiliev","Ivanov","Cumonov","Ivranov","Ivin", "Dobchinskii","Bobchinsckii","Adams","Palmer","Lenin","Ganeiev","Grechnev","Slavov","Slivov","Andreev","Ivranov","Georgiev" };
const char** Name[20] = { "Ivan","Ilya","Andrey","Georgii","Vladimir","Akakii","German","Daniil","Maxim","Alex","Danny","Van","Alexander","Billy","Darii","Nicolai","Vasilii","Petr","Alexey","Gennadii" };
const char** Groop[20] = { "MK-101","MP-101","MN-101", "MR-101","MK-201","MP-201","MN-201", "MR-201","MK-301","MP-301","MN-301", "MR-301","MK-401","MP-401","MN-401", "MR-401","MK-501","MP-501","MN-501", "MR-501" };
float Average(int* Arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += Arr[i];
	}
	return sum / size;
}
Student MakeRandomStudent(int i) {
	srand((i+1) * time(NULL));
	Student Ans;
	Ans.Age = rand() % 8 + 18;
	Ans.SizeArrOfMark = rand() % 5 + 10;
	int* ArrOfMark = (int*)malloc(Ans.SizeArrOfMark * sizeof(int));
	for (int j = 0; j < Ans.SizeArrOfMark; j++) {
		ArrOfMark[j] = rand() % 4 + 2;
	}
	Ans.ArrOfMark = ArrOfMark;
	Ans.Family = Family[rand() % 20];
	Ans.Name = Name[rand() % 20];
	int sizeStr = 11;
	char* PhoneNumber = (char*)malloc((sizeStr + 1) * sizeof(char));
	for (int j = 0; j < sizeStr; j++) {
		PhoneNumber[j] = rand() % 10 + 48;
	}
	PhoneNumber[sizeStr] = '\0';
	Ans.PhoneNumber = PhoneNumber;
	sizeStr = 7;
	Ans.Groop = Groop[rand() % 20];
	return Ans;
}
void PushInList(ListOfStudents* List, Student Human) {
	ListOfStudents* Next = (ListOfStudents*)malloc(sizeof(ListOfStudents));
	Next->Human = Human;
	Next->NextPointer = NULL;
	ListOfStudents* P = List;
	while (P->NextPointer != NULL) {
		P = P->NextPointer;
	}
	Next->BeforePointer = P;
	P->NextPointer = Next;
	List = P;
}
ListOfStudents* MakeListOfStudents(int Size) {
	ListOfStudents* Ans = (ListOfStudents*)malloc(sizeof(ListOfStudents));
	Ans->BeforePointer = NULL;
	Ans->Human = MakeRandomStudent(0);
	Ans->NextPointer = NULL;
	for(int i = 1; i < Size; i++){
		PushInList(Ans, MakeRandomStudent(i));
	}
	return Ans;
}
void PrintStudent(Student* Human) {
	printf("Name:%s Family:%s Age:%d PhoneNumber:%s Groop:%s", Human->Name, Human->Family, Human->Age, Human->PhoneNumber, Human->Groop);
	printf(" Marks:");
	for (int i = 0; i < Human->SizeArrOfMark; i++) {
		printf(" %d", Human->ArrOfMark[i]);
	}
	printf("\n");
}
void PrintList(ListOfStudents* List) {
	while(1)  {
		PrintStudent(&List->Human);
		if (List->NextPointer == NULL) break;
		List = List->NextPointer;
	} 
}
void PrintStudentOnIv(ListOfStudents* List) {
	while (1) {
		if (List->Human.Family[0] == 'I' && List->Human.Family[1] == 'v') {
			PrintStudent(&List->Human);
		}
		if (List->NextPointer == NULL) break;
		List = List->NextPointer;
	}
}
void PrintStudentInGroop(ListOfStudents* List, char* Groop) {
	while (1) {
		if (List->Human.Groop == Groop) {
			PrintStudent(&List->Human);
		}
		if (List->NextPointer == NULL) break;
		List = List->NextPointer;
	}
}
void PrintCleverStudent(ListOfStudents* List) {
	while (1) {
		if (Average(List->Human.ArrOfMark, List->Human.SizeArrOfMark) >= 4) {
			PrintStudent(&List->Human);
		}
		if (List->NextPointer == NULL) break;
		List = List->NextPointer;
	}
}
void PrintNeededStudent(ListOfStudents* List,char* SmallStr,char* PartStudent, int FindNumber) {
	while (1) {
		if (FindStrInPartOfStudent(SmallStr, List->Human, PartStudent, FindNumber) == 1) {
			PrintStudent(&List->Human);
		}
		if (List->NextPointer == NULL) break;
		List = List->NextPointer;
	}
}
void DeleteStudentForFamily(ListOfStudents* List, char* Family) {
	while (List != NULL) {
		if (List->Human.Family == Family) {
			ListOfStudents* Next = List->NextPointer;
			ListOfStudents* Before = List->BeforePointer;
			ListOfStudents* tmp = List;
			free(tmp);
			if (Before != NULL) {
				List = Before;
			}
			
			if (List != NULL) {
				List->NextPointer = Next;
				List = List->NextPointer;
				List->BeforePointer = Before;
			}
		}
		List = List->NextPointer;
	}
}
void DeleteNotCleverStudent(ListOfStudents* List) {
	while (List != NULL) {
		if (Average(List->Human.ArrOfMark, List->Human.SizeArrOfMark) < 4) {
			ListOfStudents* Next = List->NextPointer;
			ListOfStudents* Before = List->BeforePointer;
			ListOfStudents* tmp = List;
			free(tmp);
			if (Before != NULL) {
				List = Before;
			}
			if (List != NULL) {
				List->NextPointer = Next;
				List = List->NextPointer;
				List->BeforePointer = Before;
			}
		}
		List = List->NextPointer;
	}
}
void DeleteInListOfOrdinal(ListOfStudents* List, int OrdinalNumber) {
	int k = 0;
	while (List != NULL) {
		if (k == OrdinalNumber) {
			ListOfStudents* Next = List->NextPointer;
			ListOfStudents* Before = List->BeforePointer;
			ListOfStudents* tmp = List;
			free(tmp);
			if (Before != NULL) {
				List = Before;
			}
			if (List != NULL) {
				List->NextPointer = Next;
				List = List->NextPointer;
				List->BeforePointer = Before;
			}
			break;
		}
		k++;
		List = List->NextPointer;
	}
}
void WriteStudentInFile(char* FileName,ListOfStudents* Humans){
	FILE* f;
	fopen_s(&f, FileName, "wb");
	if (FileName[strlen(FileName)-3]=='d' && FileName[strlen(FileName) - 2] == 'a' && FileName[strlen(FileName) - 1] == 't') {
		while (Humans != NULL) {
			fwrite(&Humans->Human.Name, sizeof(Humans->Human.Name), 1, f);
			char Pust = ' ';
			fwrite(&Pust, sizeof(Pust), 1, f);
			fwrite(&Humans->Human.Family, sizeof(Humans->Human.Family), 1, f);
			fwrite(&Pust, sizeof(Pust), 1, f);
			fwrite(&Humans->Human.Age, sizeof(Humans->Human.Age), 1, f);
			fwrite(&Pust, sizeof(Pust), 1, f);
			fwrite(&Humans->Human.PhoneNumber, sizeof(Humans->Human.PhoneNumber), 1, f);
			fwrite(&Pust, sizeof(Pust), 1, f);
			fwrite(&Humans->Human.Groop, sizeof(Humans->Human.Groop), 1, f);
			fwrite(&Pust, sizeof(Pust), 1, f);
			fwrite(&Humans->Human.SizeArrOfMark, sizeof(Humans->Human.SizeArrOfMark), 1, f);
			fwrite(&Pust, sizeof(Pust), 1, f);
			for (int i = 0; i < Humans->Human.SizeArrOfMark; i++) {
				fwrite(&Humans->Human.ArrOfMark[i], sizeof(Humans->Human.ArrOfMark[i]), 1, f);
				fwrite(&Pust, sizeof(Pust), 1, f);
			}
			Humans = Humans->NextPointer;
		}
	}
	else
	{
		while (Humans != NULL) {
			for (int i = 0; i < strlen(Humans->Human.Name); i++) {
				fprintf(f, "%c", Humans->Human.Name[i]);
			}
			fprintf(f, "%c", ' ');
			for (int i = 0; i < strlen(Humans->Human.Family); i++) {
				fprintf(f, "%c", Humans->Human.Family[i]);
			}
			fprintf(f, "%c", ' ');
			fprintf(f, "%d", Humans->Human.Age);
			fprintf(f, "%c", ' ');
			for (int i = 0; i < strlen(Humans->Human.PhoneNumber); i++) {
				fprintf(f, "%c", Humans->Human.PhoneNumber[i]);
			}
			fprintf(f, "%c", ' ');
			for (int i = 0; i < strlen(Humans->Human.Groop); i++) {
				fprintf(f, "%c", Humans->Human.Groop[i]);
			}
			fprintf(f, "%c", ' ');
			fprintf(f, "%d", Humans->Human.SizeArrOfMark);
			fprintf(f, "%c", ' ');
			for (int i = 0; i < Humans->Human.SizeArrOfMark; i++) {
				fprintf(f, "%d ", Humans->Human.ArrOfMark[i]);
			}
			fprintf(f, "%c", '\n');
			Humans = Humans->NextPointer;
		}
	}
	fclose(f);
}
ListOfStudents* ReadInFile(char* FileName) {
	FILE* f;
	char c;
	char* Str = (char*)malloc(0 * sizeof(char));
	int k = 0;
	int q = 0;
	ListOfStudents* Humans = (ListOfStudents*)malloc(sizeof(ListOfStudents));
	Humans->BeforePointer = NULL;
	Humans->NextPointer = NULL;
	if (FileName[strlen(FileName) - 3] == 'd' && FileName[strlen(FileName) - 2] == 'a' && FileName[strlen(FileName) - 1] == 't') {
		fopen_s(&f, FileName, "rb");
		while (1) {
			fread(&c, sizeof(c), 1, f);
			if (c == '\n' || c == EOF) {
				Str[k] = '\0';
				Student Human = StrToStudent(Str);
				q++;
				if (q == 1) {
					Humans->Human = Human;
				}
				else {
					if (feof(f) != 0) break;
					PushInList(Humans, Human);
				}
				k = 0;
			}
			else
			{
				k++;
				Str = (char*)realloc(Str, k * sizeof(char));
				Str[k - 1] = c;
			}
			if (feof(f) != 0) break;
		}
	}
	else
	{
		fopen_s(&f, FileName, "r");
		while (1) {
			fscanf_s(f, "%c", &c);
			if (c == '\n') {
				Str[k] = '\0';
				Student Human = StrToStudent(Str);
				
				q++;
				if (q == 1) {
					Humans->Human = Human;
				}
				else {
					if (feof(f) != 0) break;
					PushInList(Humans, Human);
				}
				k = 0;
			}
			else
			{
				k++;
				Str = (char*)realloc(Str, k * sizeof(char));
				Str[k - 1] = c;
			}
			if (feof(f) != 0) break;
		}
	}
	fclose(f);
	return Humans;
}