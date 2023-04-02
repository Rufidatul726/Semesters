#include<stdio.h>
#include<string.h>

struct node_matching{
    char node1[1000][1000];
    char node2[1000];
}tableNode;



int main(void){
    int i,j,k,m=0;
    int count;
    int alphabet, states;

    char alphabets[100];
    char state[1000];
    char composite_table[1000][1000];

    printf("Enter number of Alphabets of string:\n");
    scanf("%d", &alphabet);
    printf("Enter the Alphabets of string:\n");
    scanf("%s", alphabets);

    printf("Enter how many States to make transition table:\n");
    scanf("%d", &states);

    char table[alphabet+5][states+100][1000];

    printf("THE STATES ARE :\n");
    for(i=0;i<states;i++){
        state[i]='A'+i;
        printf("%c ", state[i]);
    }

    printf("\n--------The Symbol '#' indicate dead state------\n");

    printf("\nMAKING THE TRANSITION TABLE\n   ");
    for(i=0;i<alphabet;i++){
        printf("%c  ",alphabets[i]);
    }

    for(i=0;i<states;i++){
        printf("\n%c ", state[i]);
        for(j=0;j<alphabet;j++){
            scanf("%s", table[i][j]);
        }
    }

    printf("\nGENERATING THE TRANSITION TABLE\n   ");
    for(i=0;i<alphabet;i++){
        printf("%c  ",alphabets[i]);
    }

    for(i=0;i<states;i++){
        for(j=0;j<alphabet;j++){
            if(strcmp(table[i][j],"#")==0){
                strcpy(table[i][j],"");
            }
        }
    }
}