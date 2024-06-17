#include <stdio.h>
#include <stdlib.h>
#define size 100


int main(void){
	system("chcp 1253>nul");
	
	int p[size];
	
	int k=0;
	
	int x,i,j,flag,start,finish,middle,pos,min,temp;
	

	
	//Åéóáãùãç óôïé÷åßùí áðï ÷ñçóôç
	puts("Äþóôå ôá óôïé÷åßá ôïõ ðßíáêá, üôáí ôåëåéþóåôå ðáôÞóôå =");
	
	while(1){
		printf("Äþóå ôï %d-o óôïé÷åßï: ",k+1);
		
		scanf("%d",&p[k]);
		
		char c=getchar(); 
		
		if(c=='='){
			
			puts("ÏëïêëÞñùóç åéóáãùãÞò óôïé÷åßùí.");
			break;
			
		}
		
		if(k==100){
			puts("ÖôÜóáôå ôï ìÝãéóôï (100 óôïé÷åßá). ÏëïêëÞñùóç åéóáãùãÞò óôïé÷åßùí.");
			break;
		
		}
		
		
		
		++k;
			
		
	}
	
	
	
	
	
	
	
	
	//Áñéèìüò ðïõ èá áíáæçôÞóïõìå
	printf("Áñéèìüò ðñïò áíáæÞôçóç: ");
	scanf("%d",&x); 
	
	
	//--------Ôáîéíüìçóç Ðßíáêá ìå selection sort classic------------------------------------/
	
	//Ôõðþíïõìå ïôé ìáò Ýäùóå ãéá Ýëåã÷ï ìåôÜ ìðïñïýìå íá ôï êÜíïõìå ó÷üëéï íá ôï êñýøïõìå
	
	puts("\nÏ ðßíáêáò ìå ôïõò áñéèìïýò ðïõ Ýäùóåò:");
	
	puts("--------------------------------------");
	for(i=0;i<k;++i){
		
		printf("[%d]  ",p[i]);
	}
	
	
	//SELECTION SORT CLASSIC
	
	for (i=0;i<k-1;++i){
		min=p[i];
		pos=i;
		for(j=i+1;j<k;++j){
			if (p[j]<min){
				min=p[j];
				pos=j;		
			}				
		}
		//SWAP
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;		
	}
	
	
	//Ôõðþíïõìå ïôé ìáò Ýäùóå ôáîéíïìçìÝíï ìåôÜ ìðïñïýìå íá ôï êÜíïõìå ó÷üëéï íá ôï êñýøïõìå
	
	puts("\n\nÏ ðßíáêáò óïõ ÔÁÎÉÍÏÌÇÌÅÍÏÓ: ");
	
	puts("--------------------------------------");
	for(i=0;i<k;++i){
		
		printf("[%d]  ",p[i]);
	}
	
	puts("\n\n");
	
	//----------------------------------------------------------------
	
	
	
	
	
	//BINARY SEARCH
	start=0;
	finish=k-1;
	flag=0;
	while(flag==0 && start<=finish){
		
		middle=(start+finish)/2;
		if (x==p[middle]){
			
			printf("Ôï óôïé÷åßï %d âñÝèçêå:\n  óôç èÝóç %d [Áñßèìçóç áðü 1]\nÞ óôç èÝóç %d [Áñßèìçóç ÐéíÜêùí áðü 0]",
			x,middle+1,middle);
			
			flag=1;
		}else if(x>p[middle]){
			start=middle+1;
		}else{
			
			finish=middle-1;
		}		
		
	}
	if (flag==0){
		printf("Äåí âñÝèçêå ï áñéèìüò %d.",x);
	}
	
	
	
	
	
	
}
