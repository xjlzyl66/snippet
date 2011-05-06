//1.将类型大小转换为地址步进的大小.2.将判断不同类型是否相等的过程参数化（即引入函数指针）
//参数：1.任意类型的数组void * 2.任意类型的一个常量（类型与前面的数组相同）k 3.数组的大小n //4.sizeof(type) m   5.表达是否相等过程的函数指针

#include<stdio.h>



typedef struct { int x,y; } point;
point c[] = { {13,14},{42,434},{123,312},{12,26},{232,232},{156,43} };
point m = { 12, 26 };

int linear(void *a,int size,int stride ,void *k, int (*f)(void*x, void*y))
{
	int i;
	char *p,*p1;
	
	p = (char *)a;
	p1 = (char *)k;
	for(i=0;i<size;i++)
	{
		if(f((p+i*stride), p1))
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

int f_point(void *x,void*y) //struct可以整体赋值 不能用"=="判断相等
{
	//return(*(point *)x == *(point *)y) 这种点不然
	point * px = (point *)x;
	point * py = (point *)y;
	//x = (point *)x;            不得行。。。X.Y是传进来的参数。。
	//y = (point *)y;
	return((px->x == py->x) && (px->y == py->y));
	//return((x->x == y->x) && (x->y == y->y));//麻痹为啥子不是，不行。见上

}

//int find_first_point(point *x,int size,int stride,int (*f)(void*x,void*y))
//this function is a special case of int linear() search?

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	int k=10;
	double b[]={0.1,1.1,2.1,3.1,4.1,5.1,6.1,7.1,8.1,9.1,10.1,11.1,12.1,13.1,14.1,15.1};
	double l = 9.1;
	
	int s,d,p;
	s = linear(a,18,sizeof(int),&k,f_int);
	d = linear(b,15,sizeof(double),&l,f_double);
	p = linear(c,6,sizeof(point),&m,f_point);
	printf("Serial number  of int = %d\n",s);
	printf("Serial number of double =%d\n",d);
	printf("index of point =%d\n",p);

	return 0;
}


//typedef struct { int x,y; } point;
//point a[n] = { ... };
//point k = { 12, 26 };
