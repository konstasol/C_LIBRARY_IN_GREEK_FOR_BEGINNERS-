#include <stdio.h>
#define N 15


int main(void){
	system("chcp 1253>nul");
	int i;
	int p[N];
	printf("Δώσε το 1-ο στοιχείο: ");
	scanf("%d",&p[0]);
	for (i=1;i<N;++i){
		do{
			printf("Δώσε το %d-ο στοιχείο: ",i+1);
			scanf("%d",&p[i]);
			if(p[i]<p[i-1]) puts("Εισάγετε μεγαλύτερο από το προηγούμενο!");
		}while(p[i]<p[i-1]);
	}
	puts("Αρχικός Πίνακας: ");
	for(i=0;i<N;++i){
		printf("[%d] ",p[i]);
	}
	int x;
	
	printf("\nΑριθμός προς αναζήτηση: ");
	scanf("%d",&x);
	//binary
	int start=0;
	int finish=N-1;
	int found=0;
	int  middle;
	int count=1;
	
	printf("\nΕπανλάληψη: %d\n",count++);
	for(i=start;i<=finish;++i) printf("[%d]",p[i]);
	
	
	while(start<=finish){
		middle=(start+finish)/2;
		printf("  -->middle= p[%d] = %d\n",middle,p[middle]);
		if (x==p[middle]) {
			found=1;		
			
			break;
		}else if (x>p[middle]) start=middle+1;
		else finish=middle-1;
		printf("\nΕπανάληψη: %d\n",count++);
		for(i=start;i<=finish;++i) printf("[%d]",p[i]);
		
		
	}
	
	found==1? puts("Βρέθηκε!") : puts("Δεν βρέθηκε!");
	
	return 0;
	
}







