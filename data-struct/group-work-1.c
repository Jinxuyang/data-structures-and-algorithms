#include <stdio.h>
#include <stdlib.h>

// 顾客
struct node {
	int id;
	int costTime;
	int waitTime;
	int windowsId;
};

typedef struct node Customer;

Customer c1[200],c2[200],c3[200];

// 初始化数组
void initArray(){
	c1[0].costTime = c2[0].costTime  = c3[0].costTime = 0;
	c1[0].waitTime = c2[0].waitTime = c3[0].waitTime = 0;
	c1[0].id = c2[0].id = c3[0].id = -1;

	c1[0].windowsId = 1;
	c2[0].windowsId = 2;
	c3[0].windowsId = 3;
}

// 获取等待时间最少的窗口，返回窗口号
int getMinWindow(Customer customer1,Customer customer2,Customer customer3){
	if (customer1.waitTime < customer2.waitTime){
		if (customer1.waitTime < customer3.waitTime) return customer1.windowsId;
		else return customer3.windowsId;	
	} else{
		if (customer2.waitTime < customer3.waitTime) return customer2.windowsId;
		else return customer3.windowsId;	
	}
}	
int main()
{
	// 初始化，将数组第一个元素作为窗口
	initArray();
	int k1 = 1, k2 = 1, k3 = 1;

	// 循环200 次模拟200个顾客
	for (int i = 1; i <= 200; i++)
	{
		// 初始化顾客
		Customer tempC;
		tempC.costTime = 1 + rand() % 10;
		tempC.id = i;

		// 选择等待时间最小的窗口
		switch (getMinWindow(c1[k1-1],c2[k2-1],c3[k3-1]))
		{
		case 1:
			tempC.windowsId = 1;
			tempC.waitTime = tempC.costTime + c1[k1-1].waitTime;
			c1[k1] = tempC;
			k1++;
			break;
		case 2:
			tempC.windowsId = 2;
			tempC.waitTime = tempC.costTime + c2[k2-1].waitTime;
			c2[k2] = tempC;
			k2++;
			break;
		case 3:
			tempC.windowsId = 3;
			tempC.waitTime = tempC.costTime + c3[k3-1].waitTime;
			c3[k3] = tempC;
			k3++;
			break;
		default:
			printf("error");
			break;
		}
	}
	
	printf("窗口1：\n");
	for (int i = 1; i < k1; i++)
		printf("第%d个顾客：花费时间：%d，预计等待时间：%d\n", c1[i].id,c1[i].costTime,c1[i].waitTime);

	printf("窗口2：\n");
	for (int i = 1; i < k2; i++)
		printf("第%d个顾客：花费时间：%d，预计等待时间：%d\n", c2[i].id,c2[i].costTime,c2[i].waitTime);
	
	printf("窗口3：\n");
	for (int i = 1; i < k3; i++)
		printf("第%d个顾客：花费时间：%d，预计等待时间：%d\n", c3[i].id,c3[i].costTime,c3[i].waitTime);
	return 0;
}