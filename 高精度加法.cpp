#include<stdio.h>
#include<string.h>
#define N 1000000
//只能在dev中运行
int main() {
	void hi_ac(char array1[], char array2[]);//声明hi_ac函数 

	char a[100] = {};
	char b[100] = {};
	printf("请输入a\n");
	gets(a);
	printf("请输入b\n");
	gets(b);
	printf("a+b=");
	hi_ac(a, b);
	return 0;
}

void hi_ac(char a[], char b[]) {
	int c[100] = {};					//存放a+b 
	void arraychange(char a[], char b[]);//声明数组交换函数 
	arraychange(a, b);
	int n = strlen(a);
	int m = strlen(b);
	char temp;
	int next = 0;
	for (int i = 0; i < n / 2; i++) {			//转置a 
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
	for (int i = 0; i < m / 2; i++) {			//转置b
		temp = b[i];
		b[i] = b[m - 1 - i];
		b[m - 1 - i] = temp;
	}
	for (int i = 0; i < n; i++) {				//计算c[]=a[]+b[] 
		if (i < m) {
			c[i] = a[i] + b[i] - 2 * '0' + next;
			if (c[i] >= 10)
			{
				c[i] = c[i] - 10;
			}
			next = (a[i] + b[i] + next - 2 * '0') / 10;
		}
		else {
			c[i] = a[i] + next - '0';
			if (c[i] >= 10)
			{
				c[i] = c[i] - 10;
			}
			next = (a[i] + next - '0') / 10;
		}

	}if (next == 1) {
		for (int i = n; i >= 0; i--)
			printf("%d", c[i]);
	}
	else	for (int i = n - 1; i >= 0; i--)
		printf("%d", c[i]);
}

void arraychange(char a[], char b[]) {
	int n = strlen(a);
	int m = strlen(b);
	char c[100];
	if (n < m) {
		strcpy(c, a);
		strcpy(a, b);
		strcpy(b, c);
	}
}