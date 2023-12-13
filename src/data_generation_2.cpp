#include<stdio.h>
#include<random>
using namespace std;

int main(){
    freopen("data/vmm.in", "w", stdout);
    int len = 4096*4;
    printf("%d\n", len);

    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 32767);
	for(int j = 0; j < len; j++){
    	for(int i = 0; i < len; i ++){
        	printf("%d ", u(e));
    	}
		printf("\n");
	}
    printf("\n");

    for(int i = 0; i < len; i ++){
        printf("%d ", u(e));
    }
    printf("\n");
    
    return 0;
}
