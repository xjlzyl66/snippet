//1.�����ʹ�Сת��Ϊ��ַ�����Ĵ�С.2.���жϲ�ͬ�����Ƿ���ȵĹ��̲������������뺯��ָ�룩
//������1.�������͵�����void * 2.�������͵�һ��������������ǰ���������ͬ��k 3.����Ĵ�Сn //4.sizeof(type) m   5.����Ƿ���ȹ��̵ĺ���ָ��

#include<stdio.h>

int liner(void *a,int size,int stride ,void *k, int (*f)(void*x, void*y))
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

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	int k=10;
	double b[]={0.1,1.1,2.1,3.1,4.1,5.1,6.1,7.1,8.1,9.1,10.1,11.1,12.1,13.1,14.1,15.1};
	double l = 9.1;
	
	int s,d;
	s = liner(a,18,sizeof(int),&k,f_int);
	d = liner(b,15,sizeof(double),&l,f_double);
	printf("Serial number  of int = %d\n",s);
	printf("Serial number of double =%d\n",d);

	return 0;
}


//typedef struct { int x,y; } point;
//point a[n] = { ... };
//point k = { 12, 26 };
