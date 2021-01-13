#include <stdio.h>
#include <stdlib.h>
typedef struct gfun{
	int (*pfun)(int);	
}gfun;

int myfun(int data)
{
	printf("get data:%d\n",data);
	return (data*2);
}

int print()
{
	printf("this is print function\n");
	return 0;
}

int fun(int data)
{
	printf("get data:%d\n",data);
	return (data*10);
}

//带参数的回调函数必须而是通过另外增加一个参数来保存回调函数的参数值，直接放在函数括号里会显示未定义
	//int rt_data(int (*tr_fun)( int data))  //回调函数,带参数
	//{
	//	return ((*tr_fun)(data));    //这里是错误的带参数的回调函数示范
	//}  

int rt_data(int date,int x,int (*tr_fun)())  //回调函数,带参数
{
	return ((*tr_fun)());    //即使向这里写三个参数，但是默认传递第一个
}

int rt_data2(int tr_fun())  //回调函数，不带参数，写成正常函数形式
{	
	tr_fun();
	printf("this rt_data2\n");
	return 0;
}  

int main(int argc,char *argv[])
{
	int ret;
	int get;
	gfun gf;
	gfun f;
	gf.pfun = myfun;
	//f.pfun=fun;
	//ret = rt_data(100,gf.pfun);//**一样
	ret = rt_data(100,200,myfun);//**

	//get = (*myfun)(100);//*一样
	//get=myfun(100);//*

	rt_data2(&print);//不带参数的回调函数   
	rt_data2(print);// 函数名加与不加取地址符号结果是一样的，都可以通过编译
	
	printf("return data:%d\n",ret);
	//printf("return data:%d\n",get);
	return 0;
}
