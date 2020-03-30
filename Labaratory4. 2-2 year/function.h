#ifndef H_FUNCTION
#define H_FUNCTION
struct student {
	char* Name;
	char* Family;
	int Age;
	char* PhoneNumber;
	char* Groop;
	int SizeArrOfMark;
	int* ArrOfMark;
};
typedef struct student Student;
struct List{
	Student Human;
	struct List* NextPointer;
	struct List* BeforePointer;
};
typedef struct List ListOfStudents;
Student MakeRandomStudent(int i);
void PrintStudent(Student* Human);
void PrintCleverStudent(ListOfStudents* List);
void PrintStudentInGroop(ListOfStudents* List, char* Groop);
void PrintStudentOnIv(ListOfStudents* List);
void PushInList(ListOfStudents* List, Student Human);
ListOfStudents* MakeListOfStudents(int Size);
void PrintList(ListOfStudents* List);
void DeleteStudentForFamily(ListOfStudents* List, char* Family);
void DeleteNotCleverStudent(ListOfStudents* List);
void DeleteInListOfOrdinal(ListOfStudents* List, int OrdinalNumber);
void WriteStudentInFile(char* FileName, ListOfStudents* Humans);
#endif