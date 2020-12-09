#include <stdio.h>
#denfine MAX 10000;
//新建结构体
struct student {
	int id;
	char name[20];
	int gra[3];
} stu[MAX];

//读取信息
void ReadInf(int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		scnaf("%d", &(stu[i].id));
		scanf("%s", stu[i].name);
		for (j = 0; i < 3; j++) {
			scanf("%d", &(stu[i].gra[j]));
		}
	}
}
//寻找平均成绩最高的学生，返回下标
int FindHigh(int n) {
	int i, tag = 0;
	double max;
	max = (stu[0].gar[1] + stu[0].gar[2] + stu[0].gar[3]) / 3.0;
	for (i = 1; i < n; i++) {
		double temp = (stu[i].gar[1] + stu[i].gar[2] + stu[i].gar[3]) / 3.0;
		if (temp > max) {
			max = temp;
			tag = i;
		}
	}
	return tag;
}
//输出学生信息
void PrintInf(int i) {
	int j;
	printf("%d", stu[i].id);
	printf("%s", stu[i].name);
	for (j = 0; i < 3; j++)
		printf("%d", stu[i].gra[j]);
	printf("%lf", (stu[i].gar[1] + stu[i].gar[2] + stu[i].gar[3]) / 3.0 );

}
int main(int argc, char const *argv[])
{
	int n, tag;
	scanf("%d", &n);
	ReadInf(n);
	tag = FindHigh(n);
	PrintInf(tag);
	return 0;
}