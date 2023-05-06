#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"prototype.h"
void max(book* b,int n)
{
	book temp;
	int i,j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<n-1; j++)
		{
			if(b[j].price<b[j+1].price)
			{
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
		}
	}
   display(b,3);
	
}

void shortt(book* b, int n)
{
	book temp;
	int choice,i,j;
	float price;
	printf("\n\t------------------short-----------------------------------------------------------");
	printf("\n\t1.price");
	printf("\n\t2.book name ");
    scanf("%d",&choice);
    
    switch(choice)
    {
    	case 1:
    		
    		for(i=0; i<n; i++)
    		{
    			for(j=0; j<n-1; j++)
    			{
    				if(b[j].price>b[j+1].price)
    				{
    					temp = b[j];
    					b[j] = b[j+1];
    					b[j+1] = temp;
					}
				}
			}
		  display(b,n);	
		  break;
		  	
	    case 2:
         for(i=0; i<n; i++)
           {    // ascii value
   	            for(j=0; j<n; j++)
   	             {
   	                  if(b[j].book_name[0]>b[i].book_name[0])
			           {
			                temp = b[j];
				             b[j]= b[i];
				           b[i] = temp;	
			    }	   }
	       }
	     display(b,n);   
	    break;
    }
	
}

void update(book* b, int n)
{
	printf("\n\t----------------------- update --------------------------------------------------");
	int choice ,id,found = 1,i;
	char key[20];
	printf("\n\t1.Update Price using id ");
	printf("\n\t2.Update Whole data of book using book name ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("\n\tEnter Id : ");
			scanf("%d",&id);
			
			for(i=0; i<n; i++)
			{
				if(id==b[i].book_id)
				{
					printf("\n\tEnter New price ");
					scanf("%d",&b[i].price);
					printf("\tUpdated successful ");
					found = 0;
					break;
				}
			}
			break;
		case 2:
		   printf("\n\tEnter book name ");
		   scanf("%s",&key);
		   
		   for(i=0; i<n; i++)
		   {
		   	    if(strcmp(key,b[i].book_name)==0)
		   	    {
		   	    	printf("\tEnter New data ");
		   	    	printf("\n\t\t   Enter Book id     : ");
		            scanf("%d",&b[i].book_id);
		            printf("\t\t   Enter book name   : ");
		            scanf("%s",&b[i].book_name);
		            printf("\t\t   Enter author name : ");
		            scanf("%s",&b[i].author_name);
		            printf("\t\t   Enter price       : ");
		            scanf("%d",&b[i].price);
		            found = 0;
		            printf("\tUpdated successful ");
		            break;
			    }
		   	
		  }	
		  
		  break;
	}	
}
void deletet(book* b, int* p)
{
	book temp;
	int n,choice, id,i , found = 1,j;
	char name[20];
	n = *p;
	printf("\n\t------------------------------ delete----------------------------------------------");
	printf("\n\t1.Using Id ");
	printf("\n\t2.Using book name ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
		   printf("\n\t\t enter id : ");
	       scanf("%d",&id);
	      for(i =0; i<n; i++)
	        {
		       if(b[i].book_id==id)
		         {	
		         	
		         	found = 0;
		         	break;
	             }
	        }
	        
	          for(j = i; j<n-1; j++)
             	{
	            	temp = b[j];
	            	b[j] = b[j+1];
	            	b[j+1] = temp;
              	}
                printf("\n");
                *p = n-1;
                
                
              if(found){
              	printf("\n\tInvalid id ");
			  }
              else {
               printf("\n\t\t sucessfully deleted !");
              }
              break;
              
              
		case 2:
			
			printf("\n\tEnter Name of book ");
			scanf("%s",&name);
			
			for(i =0; i<n; i++)
	        {
		       if(strcmp(b[i].book_name,name)==0)
		         {	
		        
		         	found = 0;
		         	break;
	             }
	        }
	        
	          for(j = i; j<n-1; j++)
             	{
	            	temp = b[j];
	            	b[j] = b[j+1];
	            	b[j+1] = temp;
              	}
                printf("\n");
                *p = n-1;
              if(found){
              	printf("\n\tInvalid Book name ");
			  }
              else {
               printf("\n\t\t sucessfully deleted !");
              }
              break;
			
	}
}
void add(book *b, int n)
{
	int i , count;
	for(i=0; i<n; i++)
	{
	    printf("\n\t\t   Enter Book id     : ");
		scanf("%d",&b[i].book_id);
		printf("\t\t   Enter book name   : ");
		scanf("%s",&b[i].book_name);
		printf("\t\t   Enter author name : ");
		scanf("%s",&b[i].author_name);
		printf("\t\t   Enter price       : ");
		scanf("%d",&b[i].price);
	
	}
}


void display(book *b, int n)
{
	int i;
	printf("\n\n");
	    printf("\n\t\t------------------ Book detalis are Given Below --------------------\n");
	for(i=0; i<n; i++)
	{
		printf("\n\t\t--------------------------------------------------------------------\n");
		printf("\t\tbook Number    : %d \n",i+1);
		printf("\t\t----------------------------------------------------------------------\n");
		printf("\n");
		printf("\t\tbook id is     : %d         ",b[i].book_id);
		printf("\t\tbook name is   : %s  \n",b[i].book_name);
		printf("\t\tAuthor name is : %s       ",b[i].author_name);
		printf("\t\tbook price is  :  %d   ",b[i].price);
		printf("\n\t\t----------------------------------------------------------------------\n");
		printf("\n\n");
	}
}

void search(book* b, int n)
{
	int choice,id,i,found = 1;
	char key[20];
	printf("\n\tSearch book by :: ");
	printf("\n\t1.Using book ID ");
	printf("\n\t2.Using book name ");
	printf("\n\t3.Using book author name ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
		printf("\n\tEnter ID ");
		scanf("%d",&id);
		
		for(i=0; i<n; i++)
		{
			 if(id==b[i].book_id)
			 {
			 	printf("\n\n");
			 	printf("\n\t\t--------------------------------------------------------------------\n");
		        printf("\t\tbook Number    : %d \n",i+1);
		        printf("\t\t----------------------------------------------------------------------\n");
		        printf("\n");
		        printf("\t\tbook id is     : %d         ",b[i].book_id);
		        printf("\t\tbook name is   : %s  \n",b[i].book_name);
		        printf("\t\tAuthor name is : %s       ",b[i].author_name);
		        printf("\t\tbook price is  :  %d   ",b[i].price);
		        printf("\n\t\t----------------------------------------------------------------------\n");
		        printf("\n\n");
		        found = 0;
		        break;
			 }
		}
		if(found)
		{
			printf("\t\t Book not Found ");
		}
		break;
		
		
	  case 2:
	  	
	    printf("\n\t\tEnter Book name : ");
	    scanf("%s",&key);
	    
	    for(i=0; i<n; i++)
	    {
	    	if(strcmp(b[i].book_name,key)==0)
	    	{
	    		printf("\n\n");
			 	printf("\n\t\t--------------------------------------------------------------------\n");
		        printf("\t\tbook Number    : %d \n",i+1);
		        printf("\t\t----------------------------------------------------------------------\n");
		        printf("\n");
		        printf("\t\tbook id is     : %d         ",b[i].book_id);
		        printf("\t\tbook name is   : %s  \n",b[i].book_name);
		        printf("\t\tAuthor name is : %s       ",b[i].author_name);
		        printf("\t\tbook price is  :  %d   ",b[i].price);
		        printf("\n\t\t----------------------------------------------------------------------\n");
		        printf("\n\n");
		        found = 0;
		        break;
			}
			
		}
		if(found)
		{
			printf("\t\t Book not Found ");
		}
	   break;
	  case 3:
	  	
	  	printf("\n\t\tEnter Book Author name : ");
	    scanf("%s",&key);
	    
	    for(i=0; i<n; i++)
	    {
	    	if(strcmp(b[i].author_name,key)==0)
	    	{
	    		printf("\n\n");
			 	printf("\n\t\t--------------------------------------------------------------------\n");
		        printf("\t\tbook Number    : %d \n",i+1);
		        printf("\t\t----------------------------------------------------------------------\n");
		        printf("\n");
		        printf("\t\tbook id is     : %d         ",b[i].book_id);
		        printf("\t\tbook name is   : %s  \n",b[i].book_name);
		        printf("\t\tAuthor name is : %s       ",b[i].author_name);
		        printf("\t\tbook price is  :  %d   ",b[i].price);
		        printf("\n\t\t----------------------------------------------------------------------\n");
		        printf("\n\n");
		        found = 0;
		        break;
			}
			
		}
		if(found)
		{
			printf("\t\t Book not Found ");
		}
	  	
	  break; 		
   }
   
}

