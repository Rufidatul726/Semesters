#include<stdio.h>

int main(void){
    int i,count=0;
    char x[10000];

    //String taking:
    printf("Enter String:\t");
    scanf("%s",x);

    //String length = count
    for(i=0;x[i]!='\0';i++){
        count++;
    }


    //state initializing
    int state[10000]={0};


    //state generating
    for(i=0;i<count;i++){
        if(x[i]=='0' && state[i] ==0){
            state[i+1]=0;
        }
        if(x[i]=='1' && state[i] ==0){
            state[i+1]=1;
        }
         if(x[i]=='0' && state[i] ==1){
            state[i+1]=0;
        }
         if(x[i]=='1' && state[i] ==1){
            state[i+1]=2;
        }
        if(x[i]=='0' && state[i] ==2){
            state[i+1]=0;
        }
         if(x[i]=='1' && state[i] ==2){
            state[i+1]=2;
        }
    }

    //tuple printing
    printf("Alphabet, %c= {0, 1}\nQ= {q0, q1, q2}\n" ,228);
    printf("Start State: q0\n");
    printf("F={q2}\n");
    printf("Transition Table:\n%c\t\t0\t1\n->q0\t\tq0\tq1\n q1\t\tq0\tq2\n*q2\t\tq0\tq2\n\n", 235);
    printf("start-> q0");

    //transition printing
    for(i=0;i<count;i++){
        printf(" -> q%d", state[i+1]);
    }

    //accepting state printing
     if(state[count]!=2){
        printf("\n\nNot accepted the string at the string.");
    }
    else printf("\n\nAccepted the string at the condition.");

}
 