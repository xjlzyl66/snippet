//1.将类型大小转换为地址步进的大小.2.将判断不同类型是否相等的过程参数化（即引入函数指针）
//参数：1.任意类型的数组void * 2.任意类型的一个常量（类型与前面的数组相同）k 3.数组的大小n //4.sizeof(type) m   5.表达是否相等过程的函数指针

#include<stdio.h>

int liner(void *a, void *k,int n,int m , int (*f)(void*x, void*y))
{
	int i;
	for(i=0;i<n;i++)
	{
		if(f((a+i*m), k))
        	   break;
	}
	return i;
}  	

int f_int(void *x,void *y)
{
	return(*(int *)x == *(int *)y);
}

int f_double(void *x,void *y)
{
	return(*(double *)x == *(double *)y);
}

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	int k=10;
	double b[]={0.1,1.1,2.1,3.1,4.1,5.1,6.1,7.1,8.1,9.1,10.1,11.1,12.1,13.1,14.1,15.1};
	double l = 9.1;
	
	int s,d;
	s = liner(a,&k,18,sizeof(int),f_int);
	d = liner(b,&l,15,sizeof(double),f_double);
	printf("Serial number  of int = %d\n",s);
	printf("Serial number of double =%d\n",d);
	getchar();
	return 0;
}


//typedef struct { int x,y; } point;
//point a[n] = { ... };
//point k = { 12, 26 };
