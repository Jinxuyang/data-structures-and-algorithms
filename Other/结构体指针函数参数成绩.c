#include <stdio.h>
struct {
	int gra = 0;
	char name[20];
} stu[1000];

struct {
	int fri = 0, sec = 0, thr = 0;
} inf;

void SortGra(int x) {
	if (x >= 80 && x <= 100)
		inf.fri++;
	else if (x >= 60 && x <= 79)
		inf.sec++;
	else inf.thr++;
}


void ReadStuInf(int n) {
	int i;
	for (i = 0; i < n; i++) {
		scanf("%s", stu[i].name);
		scanf("%d", &stu[i].gra);
		SortGra(stu[i].gra);
	}
}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	ReadStuInf(n);
	return 0;
}