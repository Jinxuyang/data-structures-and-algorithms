#include <stdio.h>
#include<stdlib.h>
struct student
{
	char name[20];
	int gra;
	struct student *next;
};
typedef struct student *stu;

stu rear;

stu CreatNode() {
	stu N = (stu)malloc(sizeof(struct student));
	N->gra = 0;
	return N;
}

void ReadInf(stu N) {
	stu temp = N;
	N->next = CreatNode();
	printf("请输入学生姓名\n");
	scanf("%s", N->next->name);
	printf("请输入学生成绩\n");
	scanf("%d", &(N->next->gra));
	rear = N->next;
}

void PrintList(stu N) {
	while (N->next != NULL) {
		printf("姓名：%s   ", N->next->name);
		printf("成绩：%d\n", N->next->gra);
		N = N->next;
	}
}
int main(int argc, char const *argv[])
{
	int T;
	printf("请输入学生个数\n");
	scanf("%d", &T);
	stu N = CreatNode();
	rear = N;

	while (T--)
		ReadInf(rear);

	PrintList(N);
	return 0;
}
