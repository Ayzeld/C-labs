#define N 100
typedef struct {
    char name[64];
    int math;
    int physics;
    int informatics;
    int total;
} Student;
Student addStudent(const char *name, int math, int phy, int inf);
void printStudentInfo(Student s);
void insertionSort(Student arr[], int n);
int getMax(Student arr[], int n);
void countingSort(Student arr[], int n, int exp);
void radixSort(Student arr[], int n);