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
void SORT(student* arr, int n) {	//n�� �迭�� ũ�� / ���� �ȹް� MAX�� �ص� ��
	if (n == 1)	return;	//���� ����� �������� �˰�����.
	for (int i = 0; i < n; i++) {	//sort�� ������ sort2�� �й�����
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
	student *s = malloc (sizeof(struct student) * MAX);	//����ü �����͸� �����迭 �Ҵ��Ͽ� �����.
	int i = 0; //�ݺ�������
	int num = 0;
	char str[40];

	//stduent information field
	for (i = 0; i < MAX; i++)
	{
		printf("Student Information (�й�, �̸�, ����) : ");
		scanf("%d", &s[i].student_no);
		scanf("%s", str);
		strcpy(s[i].name, str);
		scanf("%d", &s[i].score);
	}

	printf("���� �� �л� ���\n");
	SORT(s, MAX); //��Ʈ(�л� �迭,0,num-1)
	for (i = 0; i < MAX; i++)
		printf("%d\t%s\t%d\n", s[i].student_no, s[i].name, s[i].score);
	printf("\n\n");

	printf("�й� �� �л� ���\n");
	SORT2(s, MAX); //��Ʈ(�л� �迭,0,num-1)
	for (i = 0; i < MAX; i++)
		printf("%d\t%s\t%d\n", s[i].student_no, s[i].name, s[i].score);
	printf("\n");

	free(s);	//����ü �����Ϳ� ����ϴ� �޸𸮸� ������
	return 0;
}