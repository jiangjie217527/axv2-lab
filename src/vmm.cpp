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
	tlen = len/8;
	int **m1 = new int*[len];
	int **m2 = new int*[len];
	for(int i=0;i<len;i++){
		m1[i] = (int*)aligned_alloc(32,len*sizeof(int));
		m2[i] = (int*)aligned_alloc(32,len*sizeof(int));
	}
	int *x = (int*)aligned_alloc(32,len*sizeof(int));
	ll *ans = new ll[len]();
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			scanf("%d",m1[i]+j);
	for(int i=0;i<len;i++)scanf("%d",x+i);
	__m256i *a[len],*b,*res[len];
	for(int i=0;i<len;i++){
		a[i] = (__m256i*)m1[i];
		res[i] = (__m256i*)m2[i];
	}
	b = (__m256i*)x;
	clock_t start,finish;
	start = clock();
	
	for (int j=0;j<len;j++){
		__m256i *p=b;	
		for (int i=0;i<tlen;i++){
			*res[j] = _mm256_mullo_epi32(*a[j],*p);
			res[j]++;
			a[j]++;
			p++;
		}
	}
	for (int j=0;j<len;j++)
		for (int i=0;i<len;i++)
			ans[j] += (ll) m2[j][i];

	finish = clock();
	cout<<"读入完毕到准备输出的运行时间："<<fixed<<setprecision(8)<< double(finish-start)/CLOCKS_PER_SEC<<"S"<<endl;
	freopen("data/vmm.out","w",stdout);
	for(int i=0;i<len;i++){
		printf("%lld ",ans[i]);
	}
	cout<<endl;
	return 0;
}
