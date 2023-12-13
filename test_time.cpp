#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

int main(){
	// 方式一：CLOCK()精度ms,方式二time精度为s,选方法一
	int test;
	clock_t start,finish;//clock_t 时钟计时单位数
	start = clock();
	for(int i = 1;i <= 100000000;i++){
		test = i;
	}
	finish = clock();
	cout<<CLOCKS_PER_SEC<<endl;
	cout<<"运行时间："<<fixed<<setprecision(8)<< double(finish-start)/CLOCKS_PER_SEC<<"MS"<<endl;
	return 0;
}
