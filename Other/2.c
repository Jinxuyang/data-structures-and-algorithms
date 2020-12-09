#include <stdio.h>
#include<stdlib.h>
//定义student这个结构，此结构包含学生姓名和成绩
struct student
{
	char name[20];
	int gra;
	struct student *next;
};
typedef struct student *stu;
//声明一个stu用来保存链表的尾部
stu rear;
//创建结点
stu CreatNode() {
	stu N = (stu)malloc(sizeof(struct student));
	N->gra = 0;
	return N;
}
//读入学生信息
void ReadInf(stu N) {
	stu temp = N;
	N->next = CreatNode();
	printf("请输入学生姓名\n");
	scanf("%s", N->next->name);
	printf("请输入学生成绩\n");
	scanf("%d", &(N->next->gra));
	rear = N->next;
}
//输出学生信息
void PrintList(stu N) {
	while (N->next != NULL) {
		printf("姓名：%s   ", N->next->name);
		printf("成绩：%d\n", N->next->gra);
		N = N->next;
	}
}

int main()
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