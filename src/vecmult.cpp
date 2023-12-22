#include<iostream>
#include<immintrin.h>
#include<cstdio>
#include<time.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
//正常版（非疯癫版）
int main(){
	freopen("data/vecmult.in","r",stdin);
	int len,tlen;
	cin>>len;
	tlen = len/8;
	int *v1 = (int*)aligned_alloc(32,len*sizeof(int));
	int *v2 = (int*)aligned_alloc(32,len*sizeof(int));
	int *v3 = (int*)aligned_alloc(32,len*sizeof(int));
	for(int i=0;i<len;i++)scanf("%d",v1+i);
	for(int i=0;i<len;i++)scanf("%d",v2+i);
	__m256i *a,*b,*res;
	a = (__m256i*)v1;
	b = (__m256i*)v2;
	res = (__m256i*)v3;

	clock_t start,finish;
	start = clock();
	for (int i=0;i<tlen;i++){
		*res = _mm256_mullo_epi32(*a,*b);
		res++;
		a++;
		b++;
	}
	finish = clock();

	cout<<"读入完毕到准备输出的运行时间："<<fixed<<setprecision(8)<< double(finish-start)/CLOCKS_PER_SEC<<"S"<<endl;
	freopen("data/vecmult.out","w",stdout);
	for(int i=0;i<len;i++){
		printf("%d ",v3[i]);
	}
	cout<<endl;
	return 0;
}
