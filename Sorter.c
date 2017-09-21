#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//#include "Sorter.h"
#include <string.h>


// ./sort -c movie_title

int main(int argc, char *argv[])
 {
   //check flags
   int options;
   int cFlag =0;
   char * headerTitle = "deault_header";
   while( (options = getopt(argc, argv,"c:")) != -1 )
     {
       switch (options)
	 {
	 case 'c':
	   {
	     headerTitle = optarg;
	     cFlag = 1;
	     break;
	   }
	 }
     }
 
     if ( cFlag == 0 )
     {
       printf("No -c option: Please try again with a header selected to sort by\n");
       return -1;
     }


     
   char * inputStr = (char*) malloc(10000 * sizeof(char));
   char ** headers = NULL;
   char * secondRead = (char*) malloc(1000* sizeof(char));
   int numHeaders = 1;

   scanf( "%s", inputStr);
   memcpy( secondRead, inputStr, strlen(inputStr)+1);
   printf("%s \n",inputStr);

   char * test;
   test = strtok(inputStr,",");
   while (test != NULL)
     {
       printf("input:%s\n %d\n",test,numHeaders);
       test = strtok(NULL,",");
       ++numHeaders;
     }
   printf("inputFile After initial read %s\n",inputStr);
   printf("inputFile After initial read %s\n",secondRead);
   headers = (char**)malloc(numHeaders *  sizeof(char*));
   int headerIndex = 0;
   for ( headerIndex; headerIndex < numHeaders-1; ++headerIndex)
     {
       printf("headerIndex: %d\n",headerIndex);
       headers[headerIndex] = (char*)malloc(100 * sizeof(char));

       if ( headerIndex == 0 )
	 headers[headerIndex * 100] = strtok(secondRead,",");
       else
	 headers[headerIndex * 100] = strtok(NULL,",");
	        
     }
   printf("secondread After initial read %s\n",secondRead);
   int i = 0;
   for( i; i < numHeaders-1; ++i)
     {
       printf( "%d : %s\n",i,headers[i*(100)]);
     }

   return 0;
 }
