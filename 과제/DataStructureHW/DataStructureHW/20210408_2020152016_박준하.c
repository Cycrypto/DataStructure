#define _CRT_SECURE_NO_WARNINGS
#define MAX 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{
	int student_no;
	char name[40];
	int score;
}student;

void SWAP(student* arr, int a, int b) {
	student temp;
	temp = *(arr + a);
	*(arr + a) = *(arr + b);
	*(arr + b) = temp;
}
void SORT(student* arr, int n) {	//n은 배열의 크기 / 따로 안받고 MAX로 해도 됨
	if (n == 1)	return;	//정렬 방식은 선택정렬 알고리즘임.
	for (int i = 0; i < n; i++) {	//sort는 성적순 sort2는 학번순임
		if ((arr + i)->score < (arr + i + 1)->score)
			SWAP(arr, i, i+1);
	}
	SORT(arr, n - 1);
}
void SORT2(student* arr, int n) {	
	if (n == 1)	return;
	for (int i = 0; i < n; i++) {
		if ((arr + i)->student_no < (arr + i + 1)->student_no)
			SWAP(arr, i, i + 1);
	}
	SORT2(arr, n - 1);
}

int main(void) {
	student *s = malloc (sizeof(struct student) * MAX);	//구조체 포인터를 동적배열 할당하여 사용함.
	int i = 0; //반복문변수
	int num = 0;
	char str[40];

	//stduent information field
	for (i = 0; i < MAX; i++)
	{
		printf("Student Information (학번, 이름, 성적) : ");
		scanf("%d", &s[i].student_no);
		scanf("%s", str);
		strcpy(s[i].name, str);
		scanf("%d", &s[i].score);
	}

	printf("성적 순 학생 출력\n");
	SORT(s, MAX); //소트(학생 배열,0,num-1)
	for (i = 0; i < MAX; i++)
		printf("%d\t%s\t%d\n", s[i].student_no, s[i].name, s[i].score);
	printf("\n\n");

	printf("학번 순 학생 출력\n");
	SORT2(s, MAX); //소트(학생 배열,0,num-1)
	for (i = 0; i < MAX; i++)
		printf("%d\t%s\t%d\n", s[i].student_no, s[i].name, s[i].score);
	printf("\n");

	free(s);	//구조체 포인터에 사용하던 메모리를 해제함
	return 0;
}