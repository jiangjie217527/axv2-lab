#include<iostream>
#include<cstdio>
#include<time.h>
#include<iomanip>
using namespace std;
//正常版（非疯癫版）
int main(){
	freopen("data/vecmult.in","r",stdin);
	int len;
	cin>>len;
	int *v1 = new int[len];
	int *v2 = new int[len];
	int *v3 = new int[len];
	for(int i=0,x;i<len;i++){
		scanf("%d",v1+i);
	}
	for(int i=0,x;i<len;i++){
		scanf("%d",v2+i);
	}
	int *p1 = v1,*p2 = v2,*p3 = v3;//这里为了和vecmult.cpp一致所以多定义了3个指针，其实不需要，但是不重要。
	clock_t start,finish;
	start = clock();
	for(int i = 0;i<len;i++){
		*p3 = *p1 * *p2;
		p1++;
		p2++;
		p3++;
	}
	finish = clock();
	cout<<"读入完毕到准备输出的运行时间："<<fixed<<setprecision(8)<< double(finish-start)/CLOCKS_PER_SEC<<"S"<<endl;
	freopen("data/vecmult.out","w",stdout);
	for(int i = 0;i<len;i++){
		printf("%d ",v3[i]);
	}
	return 0;
}
