/*************************************************
 * C program to count no of lines, words and 	 *
 * characters in a file.			 *
 *************************************************/

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/stat.h>

int main()
{
 FILE *fp;
 char filename[256];
 char ch;
 int linecount, wordcount, charcount;
 struct timeval star, end;
 double totaltime;

 // Initialize counter variables
 linecount = 0;
 wordcount = 0;
 charcount = 0;

 // Prompt user to enter filename
  printf("Enter a filename :");
  gets(filename);
    
    // Open file in read-only mode
   fp = fopen(filename,"r");
  gettimeofday(&start,NULL);
   // If file opened successfully, then write the string to file
   if ( fp )
   {
	//Repeat until End Of File character is reached.	
	   while ((ch=getc(fp)) != EOF) {
	   	  // Increment character count if NOT new line or space
		    if (ch != ' ' && ch != '\n') { ++charcount; }
		  
		  // Increment word count if new line or space character
		   if (ch == ' ' || ch == '\n') { ++wordcount; }
		   
		  // Increment line count if new line character
		   if (ch == '\n') { ++linecount; }
		   


	   }

	   if (charcount > 0) {
		++linecount;
		++wordcount;
	   }
    }
   else
      {
         printf("Failed to open the file\n");
        }
  gettimeofday(&end, NULL);
    printf("Lines : %d \n", linecount);
    printf("Words : %d \n", wordcount);
    printf("Characters : %d \n", charcount);
    totaltime = (((end.tv_usec - start.tv_usec) / 1.0e6 + end.tv_sec - start.tv_sec) * 1000) / 1000;
    printf("total time : %f sec\n",totaltime);

getchar();
return(0);
}
