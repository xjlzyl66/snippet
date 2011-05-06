//1.�����ʹ�Сת��Ϊ��ַ�����Ĵ�С.2.���жϲ�ͬ�����Ƿ���ȵĹ��̲������������뺯��ָ�룩
//������1.�������͵�����void * 2.�������͵�һ��������������ǰ���������ͬ��k 3.����Ĵ�Сn //4.sizeof(type) m   5.����Ƿ���ȹ��̵ĺ���ָ��

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

int f_point(void *x,void*y) //struct�������帳ֵ ������"=="�ж����
{
	//return(*(point *)x == *(point *)y) ���ֵ㲻Ȼ
	point * px = (point *)x;
	point * py = (point *)y;
	//x = (point *)x;            �����С�����X.Y�Ǵ������Ĳ�������
	//y = (point *)y;
	return((px->x == py->x) && (px->y == py->y));
	//return((x->x == y->x) && (x->y == y->y));//���Ϊɶ�Ӳ��ǣ����С�����

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
