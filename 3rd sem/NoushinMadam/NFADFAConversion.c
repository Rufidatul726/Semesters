#include<stdio.h>
#include<string.h>

char generated_table[1000][1000];
int top=0;

struct node_matching{
    char node1[1000][1000];
    char node2[1000];
}tables;

int push_table_in_struct(char *node, int states){
    int i;
    char temp='A'+states+top;
    for( i=0;i < top;i++){
        if(strcmp(node, tables.node1[i])==0)return i;
    }
    strcpy(tables.node1[top],node);
    tables.node2[top]=temp;
    ++top;
    return top-1;
}
int main(){
    int i,j,k,m=0;
    int count;
    int alphabet=2, states=3;

    char alphabets[100]={"01"};
    char state[1000]={"ABC"};
    char composite_table[1000][1000];

    char table[alphabet+5][states+100][1000];

    printf("\n--------The Symbol '#' indicate dead state------\n");
    strcpy(table[0][0],"A");
    strcpy(table[0][1],"AB");
    strcpy(table[1][0],"C");
    strcpy(table[1][1],"BC");
    strcpy(table[2][0],"#");
    strcpy(table[2][1],"A");

    for(i=0;i<alphabet;i++){
        printf("\t%c\t",alphabets[i]);
    }

    for(i=0;i<states;i++){
        printf("\n%c ", state[i]);
        for(j=0;j<alphabet;j++){
            printf("\t%s\t", table[i][j]);
            if(strlen(table[i][j])>1){
                count = push_table_in_struct(table[i][j], states);
                composite_table[i][j]=tables.node2[count];
            }
            else if(strcmp(table[i][j],"#")!=0){
                composite_table[i][j]=table[i][j][0];
            }
        }
    }
    int flag;

    for(i=0;i<states+top;i++){
            flag=0;
        for(j=0;j<alphabet;j++){
            if(strcmp(table[i][j],"#")==0)flag=1;
        }
        if(flag==0){
            printf("\n%c ", state[i]);
            for(j=0;j<alphabet;j++){
                    printf("\t%c\t",composite_table[i][j]);
            }
        }
    }

}
