#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int n=0;
    int line=0;
    int count=0;
    int point=0;
    char input[100][10000];
    int toint[100][10000];
    int intpoint=0;
    int sortpoint=0;
    int tmp=0;
    for(line=0;line<100;line++)
        for(n=0;n<10000;n++){
  	    input[line][n]='\0';
	    toint[line][n]=0;
    }

    printf("enter what you want to sort or type exit for stop\n");
    for(line=0;input[line-1][0]!='e' && line<100;line++){ //input data
        fgets(input[line], sizeof(input), stdin);
    }

    for(n=0;n<line-1;n++){                  //change char to int
	for(point=0;point<10000;point++){
	    if((input[n][point]==' ' && input[n][point-1]!=' ') || input[n][point]=='\n'){
		if(input[n][point-1]=='S')
		    toint[n][intpoint]+=4;
		else if(input[n][point-1]=='H')
		    toint[n][intpoint]+=3;
		else if(input[n][point-1]=='D')
		    toint[n][intpoint]+=2;
		else
		    toint[n][intpoint]+=1;
		
 	        if(input[n][point-2]=='A')
		    toint[n][intpoint]+=1*10;
	        else if(input[n][point-2]=='J')
	   	    toint[n][intpoint]+=11*10;
	        else if(input[n][point-2]=='Q')
		    toint[n][intpoint]+=12*10;
	        else if(input[n][point-2]=='K')
		    toint[n][intpoint]+=13*10;
		else if(input[n][point-2]=='0')
		    toint[n][intpoint]+=((int)input[n][point-3]-48)*100;
	        else
		    toint[n][intpoint]+=((int)input[n][point-2]-48)*10;
	    intpoint++;
	    }
	}
    intpoint=0;
    }

    for(n=0;n<line-1;n++)   //sorting
	for(count=0;toint[n][count+1];count++){
	    for(sortpoint=0;toint[n][sortpoint+1+count]!=0;sortpoint++){
	        if(toint[n][sortpoint]>toint[n][sortpoint+1]){
		    tmp=toint[n][sortpoint];
		    toint[n][sortpoint]=toint[n][sortpoint+1];
		    toint[n][sortpoint+1]=tmp;
		}
	    }
	}

    for(n=0;n<line-1;n++){   //output data for char
        for(count=0;toint[n][count]!=0;count++){
	    if(toint[n][count]/10==13)
		printf("K");
            else if(toint[n][count]/10==12)
                printf("Q");
            else if(toint[n][count]/10==11)
                printf("J");
            else
                printf("%d",toint[n][count]/10);

	    if(toint[n][count]%10==1)
		printf("C ");
            else if(toint[n][count]%10==2)
                printf("D ");
            else if(toint[n][count]%10==3)
                printf("H ");
            else 
                printf("S ");
	}
    printf("\n");
    }    
}
