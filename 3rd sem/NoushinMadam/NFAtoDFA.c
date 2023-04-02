#include<stdio.h>
#include<string.h>

int find_state(char *state, char character);

void generate_state(int state_, int alphabet, int m, char *tran_states, char *table[], char *c_table){
    int i,j,k=0;
    char temp[1000][1000][1000];

    for(i=0;i<m;i++){
        for(j=0;j<state_;j++){
            if(c_table[i]==tran_states[j]){
                printf("\n%s ", c_table[i]);
                for(k=0;k<alphabet;k++){
                    strcpy(temp[i][k], table[j][k]);
                    printf("%s ", temp[i][k]);
                }
                break;
            }
        }
    }

}
void main(void){
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
        printf("\n%c ", state[i]);
        for(j=0;j<alphabet;j++)
        {
            if(strcmp(table[i][j],"#")==0)break;
            else{
                    if(strlen(table[i][j])>1){
                        //generating DfA Table
                        state[states+m]='A'+state+m;
                        strcpy(composite_table[m],table[i][j]);
                        for(k=0;k<strlen(table[i][j]);k++){
                            count= find_state(state, table[i][j][k]);
                            for(int alc=0;alc<alphabet;alc++){
                                strcat(table[states+m][alc], table[count][alphabet]);
                            }
                        }
                        generate_state(states, alphabet, m, state ,table, composite_table[m]);
                        m++;
                    }

                printf("%s ", table[i][j]);
            }
        }
    }


}

int find_state(char *state, char character){
    for(int i=0;i<strlen(state);i++){
        if(character== state[i])return i;
    }
}
