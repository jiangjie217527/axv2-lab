#include<iostream>
#include<immintrin.h>
#include<cstdio>
#include<time.h>
#include<iomanip>
using namespace std;
#define ll long long

int main(){
	freopen("data/vmm.in","r",stdin);
	int len,tlen,plen;
	cin>>len;
	tlen = len/8;
	plen = len/4;
	int **m1 = new int*[len];
	for(int i=0;i<len;i++){
		m1[i] = (int*)aligned_alloc(32,len*sizeof(int));
	}
	int *x = (int*)aligned_alloc(32,len*sizeof(int));
	ll *ans = (ll*)aligned_alloc(64,len*sizeof(ll));
	int *t = (int*)aligned_alloc(32,8*sizeof(int));
	ll *t1 = (ll*)aligned_alloc(64,4*sizeof(ll));
	ll *t2 = (ll*)aligned_alloc(64,4*sizeof(ll));
	/*
	int **t1 = new int*[4];
	for(int i=0;i<4;i++)t1[i] =  (int*)aligned_alloc(32,8*sizeof(int));
	ll **t2 = new ll*[8];
	for(int i=0;i<8;i++)t2[i] = (ll*)aligned_alloc(64,4*sizeof(ll));
	__m256i *tmp1[4],*tmp2[8];
	for(int i=0;i<4;i++){
		tmp1[i] = (__m256i*)t1[i];
	}
	for(int i=0;i<8;i++){
		tmp2[i] = (__m256i*)t2[i];
	}
	*/
	for(int j=0;j<len;j++)//转置
		for(int i=0;i<len;i++)
			scanf("%d",m1[i]+j);
	for(int i=0;i<len;i++){scanf("%d",x+i);ans[i]=0;}
	__m256i *a[len],*b,*c,*p,*tmp,*tmp1,*tmp2;
	tmp = (__m256i*)t;
	tmp1 = (__m256i*)t1;
	tmp2 = (__m256i*)t2;
	for(int i=0;i<len;i++){
		a[i] = (__m256i*)m1[i];
	}
	b = (__m256i*)x;
	c = (__m256i*)ans;

	int **m2 = new int*[len];
	for(int i=0;i<len;i++){
		m2[i] = (int*)aligned_alloc(32,8*sizeof(int));
	}
	for(int i=0;i<len;i++){
		for(int j=0;j<8;j++){
			m2[i][j]=x[i];
		}
	}
	__m256i *d[len];
	for(int i=0;i<len;i++){
		d[i] = (__m256i*)m2[i];
	}
	clock_t start,finish;
	start = clock();

	for (int j=0;j<len;j++){
		p = c;
		for (int i=0;i<tlen;i++){
			*tmp = _mm256_mullo_epi32(*a[j],*d[j]);
			for(int k=0;k<4;k++){
				t1[k] = t[k];
				t2[k] = t[k+4];
			}
			*p = _mm256_add_epi64(*p,*tmp1);
			*(p+1) = _mm256_add_epi64(*(p+1),*tmp2);
			a[j]++;
			p+=2;
		}
	}
/*	
	for (int j=0;j<tlen;j++){//每8列处理一次
		p = c;	
		for (int i=0,w=0;i<plen;i++){//每4行处理
			for(int k=0;k<4;k++){
				*tmp1[k] = _mm256_mullo_epi32(*a[w],*b);
				a[w]++;
				w++;
			}
			for(int k=0;k<4;k++){
				for(int l=0;l<8;l++){
					t2[l][k]=(ll)t1[k][l];
				}
			}
			for(int k=0;k<8;k++){
				*p = _mm256_add_epi64(*p,*tmp2[k]);
			}
			p++;
		}
		b++;
	}
*/
	finish = clock();
	cout<<"读入完毕到准备输出的运行时间："<<fixed<<setprecision(8)<< double(finish-start)/CLOCKS_PER_SEC<<"S"<<endl;
	freopen("data/vmm.out","w",stdout);
	for(int i=0;i<len;i++){
		printf("%lld ",ans[i]);
	}
	cout<<endl;
	return 0;
}
