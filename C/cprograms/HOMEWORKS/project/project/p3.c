/* Author: Bhishan Poudel
  Question:project 3 
  Simulate a Books database
  Typical fields of Books are: Title: Author: Year: Edition: Publisher: ISBN:
  Program should access books information from a file
  User should be able to search book by title or ISBN, if found display all fields of the
  book. If not found, display so!
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//defining structure before the int main
struct books_database { 
	char title[20];
	char author[20];
	int  year;
	char edition[20];
	char publisher[20];
	long int isbn;
};
typedef struct books_database NAME;
NAME books[10], temp[10];	//we have 10 books each having titles etc.

//function prototypes
void display_input(int n);
void sort_title(int n);
void sort_isbn(int n);


 
//main function
int main() {

	FILE *fp;
	fp = fopen("books.txt", "r");
	
	int code;	// to sort by title or isbn
	int n=0;
	int temp1; // for year strcpy
	long int temp2;	// for isbn strcpy
	
	if (fp == NULL) {
        	fprintf(stderr, "Could not open file\n");
        	exit(-1);
        }
	
	//storing input from file into  the structure
	while(!feof(fp)){
		fscanf(fp, "%s[^\n]", books[n].title);
		fscanf(fp, "%s[^\n]",books[n].author );
		fscanf(fp, "%d", &books[n].year);
		fscanf(fp, "%s[^\n]",books[n].edition );
		fscanf(fp, "%s[^\n]",books[n].publisher );
		fscanf(fp, "%ld", &books[n].isbn);
		
		n=n+1;
	}
	fclose(fp);
	n=n-1;
	
	//choosing sort by title or isbn
	display_input(n);
	
	// storing the code to search or sort or abort
	printf("MENU:\n");
	printf("1 : sort by title \n");
	printf("2 : sort by isbn)\n");
	printf("3 : exit\n");
	printf("Enter the code => ");
	scanf("%d", &code);
	
	switch(code)
	{
    
    		case 1:	sort_title(n);		// calling the function
        	break;

   		case 2: sort_isbn(n);
        	break;
    
    		case 3: printf("Thank You for using the program!\n");
    		default:
        		printf("Sorry! you have entered the wrong code\n");
	}
	
 printf("**************************************************************************************************\n");	
return 0;
}  
//function display_input
void display_input(int n) {
	int k=0;

	printf("\n*************************************Books Database***************************************\n\n");
        printf("Title\t       Author \t\t   Year\t    Edition\t  Publisher\t  ISBN\n\n");
        
        for(k=0; k<n; k=k+1){
        printf("%-12s  %-20s %-7d %-14s %-14s %-14ld\n",books[k].title,books[k].author,books[k].year,books[k].edition,books[k].publisher,books[k].isbn);
        }
         printf("**************************************************************************************************\n");
} 
//function sort_title
 void sort_title(int n)
 {
        NAME	temp;
        int 	i,j,k;
        
         printf("\n*************************************Sorted by Title***************************************\n\n");
        printf("Title\t       Author \t\t   Year\t    Edition\t  Publisher\t  ISBN\n\n");
        
        for(i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){			
            if (strcmp(books[i].title,books[j].title)>0){ 	// title is stirng so we use string compare	
                temp 	= books[i];
                books[i]=books[j];
                books[j]=temp;
            }
        }
	}
	//displaying sorted list
        for(k=0; k<n; k=k+1){
        printf("%-12s  %-20s %-7d %-14s %-14s %-14ld\n",books[k].title,books[k].author,books[k].year,books[k].edition,books[k].publisher,books[k].isbn);
        }
}
//function sort_isbn
void sort_isbn(int n)
{
        NAME	temp;
        int 	i,j,k;
        
         printf("\n*************************************Sorted by ISBN***************************************\n\n");
        printf("Title\t       Author \t\t   Year\t    Edition\t  Publisher\t  ISBN\n\n");
        
        for(i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){			
            if (books[i].isbn > books[j].isbn){		// isbn is long integer we directly compare
                temp 	= books[i];
                books[i]=books[j];
                books[j]=temp;
            }
        }
	}


	//displaying sorted list
        for(k=0; k<n; k=k+1){
        printf("%-12s  %-20s %-7d %-14s %-14s %-14ld\n",books[k].title,books[k].author,books[k].year,books[k].edition,books[k].publisher,books[k].isbn);
        }
       


}
//function sort_isbn

