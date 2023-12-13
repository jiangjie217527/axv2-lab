#include<immintrin.h>
#define ll long long
#include<iostream>
using namespace std;
#define ll long long
int main(){
	ll *a = (ll*)aligned_alloc(64,4*sizeof(ll));
	ll *b = (ll*)aligned_alloc(64,4*sizeof(ll));
	ll *c = (ll*)aligned_alloc(64,4*sizeof(ll));
	for(int i=0;i<4;i++)cin>>a[i];
	for(int i=0;i<4;i++)cin>>b[i];
	__m256i *x,*y,*z;
	x = (__m256i*)a;
	y = (__m256i*)b;
	z = (__m256i*)c;
	//*z = _mm256_mullo_epi64(*x,*y);
	for(int i=0;i<4;i++)cout<<c[i]<<" ";
	cout<<endl;
	return 0;
}
