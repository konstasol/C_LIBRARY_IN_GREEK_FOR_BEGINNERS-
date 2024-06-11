#include <stdio.h>
#define N 8


int main(void){
	system("chcp 1253>nul");
	int i;
	int p[N];
	printf("Äþóå ôï 1-ï óôïé÷åßï:");
	scanf("%d",&p[0]);
	for (i=1;i<N;++i){
		do{
			printf("Äþóå ôï %d-ï óôïé÷åßï:",i+1);
			scanf("%d",&p[i]);
			if(p[i]<p[i-1]) puts("Εισάγετε αριθμό μεγαλύτερο από τον προηγούμενο");
		}while(p[i]<p[i-1]);
	}
	puts("Πίνακας: ");
	for(i=0;i<N;++i){
		printf("[%d] ",p[i]);
	}
	int x;
	
	printf("\nΔώστε αριθμό για αναζήτηση: ");
	scanf("%d",&x);
	//binary
	int start=0;
	int finish=N-1;
	int found=0;
	int  middle;
	int count=1;
	while(start<=finish){
		middle=(start+finish)/2;
		printf("\nΕπανάληψη: %d\n",count++);
		for(i=start;i<=finish;++i) printf("[%d]",p[i]);
		printf("  -middle=%d\n",middle);
		if (x==p[middle]) {
			found=1;		
			
			break;
		}else if (x>p[middle]) start=middle+1;
		else finish=middle-1;
		
	}
	printf("\nΕπανάληψη: %d\n",count++);
	for(i=start;i<=finish;++i) printf("[%d]",p[i]);
	printf("  -middle=%d\n",middle);
	found==1? puts("Βρέθηκε!") : puts("Δεν βρέθηκεå!");
	
	return 0;
	
}




