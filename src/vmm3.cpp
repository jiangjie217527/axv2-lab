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
	int **m1 = new int*[len];// m1为输入的方针
	for(int i=0;i<len;i++){
		m1[i] = (int*)aligned_alloc(32,len*sizeof(int));
	}
	int *x = (int*)aligned_alloc(32,len*sizeof(int));//x是输入的向量
	int *t = (int*)aligned_alloc(32,8*sizeof(int));//t暂存每次计算得到的一组数据，接下来对得到的这组数据进行累加
	ll *ans = (ll*)aligned_alloc(64,len*sizeof(ll));
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			scanf("%d",m1[i]+j);
	for(int i=0;i<len;i++)scanf("%d",x+i);
	__m256i *a[len],*b,*tmp,*p;//a,b对应输入，tmp对应临时t空间，p是临时指针，每次循环开始指向b(输入的向量)
	for(int i=0;i<len;i++){
		a[i] = (__m256i*)m1[i];
	}
	b = (__m256i*)x;
	tmp = (__m256i*)t;
	clock_t start,finish;
	start = clock();
	
	for (int j=0;j<len;j++){
		p=b;	
		for (int i=0;i<tlen;i++){
			*tmp = _mm256_mullo_epi32(*a[j],*p);
			for(int k=0;k<8;k++){
				ans[j] += t[k];
			}
			a[j]++;
			p++;
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
