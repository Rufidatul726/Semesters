#include<stdio.h>
#include<string.h>

int operator_(char operator_);
int alphabet(char alphabet);
int bracket(char bracket);

char str(char *substring){
    if((substring[0]=='1' || substring[0]=='0' || substring[0]=='o') &&  (substring[1]=='*' || substring[2]=='+') && (substring[0]=='o' || substring[2]=='1' || substring[2]=='0')){
        return 'o';
    }
    else if((substring[0]=='(')  && (substring[1]=='o' || substring[1]=='1' || substring[1]=='0')   &&  (substring[2]==')')){
        return 'o';
    }
    else return substring[0];
}

int main(){
    int i,j,k=0;
    char temp[4];
    char stack[1000]={'\0'};
    char string[1000];
    int len=0;
    scanf("%s", string);

    for(i=0;i<strlen(string);i++){
        for(k=0;k<3;k++){
                for(j=0;j<3;j++){
                    temp[j]=string[i+j];
                }
                temp[3]='\0';
                stack[len]=str(temp);
                stack[len+1]='\0';
                len++;
                for(j=0;j<3;j++){
                    temp[j]=stack[len-3+j];
                }
                temp[3]='\0';
                if(str(temp)=='o'){
                    stack[len-3]=str(temp);
                    stack[len-2]='\0';
                    len=len-2;
                }
                //printf("%s\n", stack);
            break;

        }
    }

     if(strcmp(stack, "o")==0){
            printf("String accepted");
            return 0;
    }

    printf("String not accepted");
    return 0;
}
