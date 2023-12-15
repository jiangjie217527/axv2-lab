#include<iostream>
#include<immintrin.h>
#include<cstdio>
#include<time.h>
#include<iomanip>
using namespace std;
#define ll long long

int main(){
	freopen("data/vmm.in","r",stdin);
	int len,tlen;
	cin>>len;
	tlen = len/4;
	ll **m1 = new ll*[len];
	for(int i=0;i<len;i++)
		m1[i] = (ll*)aligned_alloc(64,len*sizeof(ll));
	ll *x = (ll*)aligned_alloc(64,len*sizeof(ll));
	ll *t = (ll*)aligned_alloc(64,4*sizeof(ll));
	ll *ans = (ll*)aligned_alloc(64,len*sizeof(ll));
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			scanf("%lld",m1[i]+j);
	for(int i=0;i<len;i++)scanf("%lld",x+i);
	__m256i *a[len],*b,*p,*tmp;//p每次循环开始指向输入的向量,tmp是累加每行的结果
	for(int i=0;i<len;i++)
		a[i] = (__m256i*)m1[i];
	b = (__m256i*)x;
	tmp = (__m256i*)t;
	clock_t start,finish;
	start = clock();
	
	for (int j=0;j<len;j++){
		p=b;
		for (int i=0;i<4;i++) t[i] = 0;	
		for (int i=0;i<tlen;i++){
			*tmp = _mm256_add_epi64(*tmp,_mm256_mullo_epi32(*a[j],*p));
			a[j]++;
			p++;
		}
		for (int i=0;i<4;i++){
			ans[j] += t[i];//累加结果，所需时间可以忽略
		}
	}

	finish = clock();
	cout<<"读入完毕到准备输出的运行时间："<<fixed<<setprecision(8)<< double(finish-start)/CLOCKS_PER_SEC<<"S"<<endl;
	freopen("data/vmm.out","w",stdout);
	for(int i=0;i<len;i++){
		printf("%lld ",ans[i]);
	}
	cout<<endl;
	return 0;
}
