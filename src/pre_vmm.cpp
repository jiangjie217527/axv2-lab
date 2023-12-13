#include<iostream>
#include<immintrin.h>
#include<cstdio>
#include<time.h>
#include<iomanip>
using namespace std;
#define ll long long

int main(){
	freopen("data/vmm.in","r",stdin);
	int len;
	cin>>len;
	int **m1 = new int*[len];
	int **m2 = new int*[len];
	for(int i=0;i<len;i++){
		m1[i] = new int[len];
		m2[i] = new int[len];
	}
	int *x = new int[len];
	ll *ans = new ll[len]();
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			scanf("%d",m1[i]+j);
	for(int i=0;i<len;i++)scanf("%d",x+i);
	clock_t start,finish;
	start = clock();

	for (int j=0;j<len;j++)
		for (int i=0;i<len;i++)
			ans[j] +=  m1[j][i] * x[i];

	finish = clock();
	cout<<"读入完毕到准备输出的运行时间："<<fixed<<setprecision(8)<< double(finish-start)/CLOCKS_PER_SEC<<"S"<<endl;
	freopen("data/vmm.out","w",stdout);
	for(int i=0;i<len;i++){
		printf("%lld ",ans[i]);
	}
	cout<<endl;
	return 0;
}
