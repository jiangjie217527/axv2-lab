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
	for(int i=0;i<len;i++){
		m1[i] = (int*)aligned_alloc(32,len*sizeof(int));
	}
	int *x = (int*)aligned_alloc(32,len*sizeof(int));
	ll *ans = (ll*)aligned_alloc(64,len*sizeof(ll));
	int *t = (int*)aligned_alloc(32,8*sizeof(int));
	ll *t1 = (ll*)aligned_alloc(64,4*sizeof(ll));
	ll *t2 = (ll*)aligned_alloc(64,4*sizeof(ll));
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			scanf("%d",m1[i]+j);
	for(int i=0;i<len;i++){scanf("%d",x+i);ans[i]=0;}
	__m256i *a[len],*b,*c,*tmp,*tmp1,*tmp2,*p1,*p2;
	tmp = (__m256i*)t;
	tmp1 = (__m256i*)t1;
	tmp2 = (__m256i*)t2;
	for(int i=0;i<len;i++){
		a[i] = (__m256i*)m1[i];
	}
	b = (__m256i*)x;
	c = (__m256i*)ans;
	clock_t start,finish;
	start = clock();
	
	for (int j=0;j<len;j++){
		p1 = b;
		p2 = c;	
		for (int i=0;i<tlen;i++){
			*tmp = _mm256_mullo_epi32(*p1,*a[j]);
			for(int k=0;k<4;k++){
				t1[k] = t[k];
				t2[k] = t[k+4];
			}
			*p2 = _mm256_add_epi64(*p2,*tmp1);
			*(p2+1) = _mm256_add_epi64(*(p2+1),*tmp2);
			a[j]++;
			p2+=2;
			p1++;
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
