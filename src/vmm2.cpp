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
	int **m1 = new int*[len];//矩阵
	int **m2 = new int*[len];//输入的向量拓展的矩阵
	for(int i=0;i<len;i++){
		m1[i] = (int*)aligned_alloc(32,len*sizeof(int));
		m2[i] = (int*)aligned_alloc(32,8*sizeof(int));
	}
	int *x = (int*)aligned_alloc(32,len*sizeof(int));
	ll *ans = (ll*)aligned_alloc(64,len*sizeof(ll));
	int *t = (int*)aligned_alloc(32,8*sizeof(int));//临时空间，存储中间计算结果
	ll *t1 = (ll*)aligned_alloc(64,4*sizeof(ll));//把临时空间里的前4个数值转为4个64位存在该空间
	ll *t2 = (ll*)aligned_alloc(64,4*sizeof(ll));//临时空间后4个
	for(int j=0;j<len;j++)//转置
		for(int i=0;i<len;i++)
			scanf("%d",m1[i]+j);
	for(int i=0;i<len;i++){
		scanf("%d",x+i);
		ans[i]=0;
		for(int j=0;j<8;j++)
			m2[i][j]=x[i];
	}
	__m256i *a[len],*b[len],*c,*p,*tmp,*tmp1,*tmp2;
	//p是临时向量，每次循环开始指向c(输出的结果),b指向输入的向量拓展的向量
	tmp = (__m256i*)t;//tmp,tmp1,tmp2分别指向t,t1,t2
	tmp1 = (__m256i*)t1;
	tmp2 = (__m256i*)t2;
	for(int i=0;i<len;i++){
		a[i] = (__m256i*)m1[i];//a对应m1
		b[i] = (__m256i*)m2[i];
	}
	c = (__m256i*)ans;

	clock_t start,finish;
	start = clock();

	for (int j=0;j<len;j++){
		p = c;
		for (int i=0;i<tlen;i++){
			*tmp = _mm256_mullo_epi32(*a[j],*b[j]);
			for(int k=0;k<4;k++){//把t的8个int拆分到t1的4个ll和t2的4个ll里
				t1[k] = t[k];
				t2[k] = t[k+4];
			}
			*p = _mm256_add_epi64(*p,*tmp1);
			*(p+1) = _mm256_add_epi64(*(p+1),*tmp2);
			a[j]++;
			p+=2;
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
