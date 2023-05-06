#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"prototype.h"

void main()
{
	int op,n,exit = 1,plus = 0;
	printf("\n\n");
	printf("\t\t============================= Book Shop ===========================================");
	
 while(exit){

	
	
	printf("\n\n");
	printf("\n\t\t  1.Add Book ");
	printf("\n\t\t  2.See all books ");
	printf("\n\t\t  3.Search ");
	printf("\n\t\t  4.Top Three books ");
	printf("\n\t\t  5.Short ");
	printf("\n\t\t  6.Update ");
	printf("\n\t\t  7.Delete ");
	printf("\n\t\t  8.Exit ");
	

	
	printf("\n\n\t\t Please select your preferd operations.\t");
	scanf("%d",&op);
	
	
	
    
	switch(op){
		case 1:
		
			printf("\n\t\t Enter no of book that you want to add.\t");
            scanf("%d",&n);
            book* b;
			b = (book*)malloc(sizeof(book)*n);
		    add(b,n);
		     break;
		case 2:
		 display(b,n);
		 break;
		case 3:
		 search(b,n);
		 break;
		case 4:
		max(b,n);
		 break;
		case 5:
		shortt(b,n);
		 break;
		case 6:
	    update(b,n);
	    break;
		case 7:
		deletet(b,&n);
	    break;
		case 8:
			exit = 0;
			free(b);
			break;
	}
	
	printf("\n\n");
  } 
	
}
