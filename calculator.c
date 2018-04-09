#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
extern unsigned _add(int a, int b);
extern unsigned _multi(int a, int b);
extern unsigned _sub(int a, int b);
extern unsigned _div(int a, int b);
#define SIZE 1024

typedef struct bigNum
{
	long number_digits;
	int sign ;
	char * byte;
} bigNum;


void resize(char * src,char ch)
{
	int length  = strlen(src);
	src = (char*) realloc(src,(length*2+1)*sizeof(char));
	src[length] = ch;
	src[length+1] = '\0'; 
}

void inital_bigNum(bigNum* newNum ,char ch){
	newNum->number_digits = 1;
	newNum->sign=1;
	newNum->byte = (char*) malloc(sizeof(char));
	resize(newNum->byte,ch);
}
bigNum* s[1024] ;
bigNum **top = &(s[0]);
int flag=0;
int flag_minus=0;
bigNum* pop(){
    return((*top)--);
}

void push(int elem)
{
    if(flag==1){
        bigNum* num;
       // inital_bigNum(num,'');
        num = pop();
        long dig = num->number_digits;
        num->number_digits =dig+1;
        resize(num->byte,elem);
        (++*top);
        top = num;
    }
    else if(flag==0){
    	bigNum* newBigNum = (bigNum*) malloc (sizeof(bigNum));
    	inital_bigNum(newBigNum,elem);
        ++top;
        top = newBigNum;
        flag=1;
    }
}

int isEmpty()
{
    return top == &s[0] ;
}

int main()
{
    FILE * fp = stdin;
    char ch;
    bigNum* op1;
    bigNum* op2;
    fprintf(stdout, "Enter the Postfix Expression:");
    s[0] =  (bigNum*) malloc (sizeof(bigNum));
    inital_bigNum(s[0], '1');
    
    flag=1;
    push('2');
    printf("%d\n",(s[0]->number_digits));
  printf("%d\n",s[0]->sign);
    printf("%s\n",s[0]->byte);
    free(s[0]);
 /*   while((ch=fgetc(fp)) != 'q')
    {
        if(isdigit(ch)){
            push(ch-'0');
        }
        else if(ch < 33){
            flag = 0;
            if(flag_minus ==1){
            	bigNum* b = pop();
                b->sign = -1;
                flag_minus=0;
                push(b);
                flag = 0 ;
            }
        }
        else if(ch =='p'){
           // fprintf(stdout, "Result: %d\n",s[top]);
        }
        else if(ch =='c'){
            while(!isEmpty()){
                free(pop());
            }

        }
        else if(ch =='_'){
            flag_minus = 1;
        }
        else
        {
            if(flag_minus ==1){
            	bigNum* b = pop();
                b->sign = -1;
                flag_minus=0;
                push(b);
                flag = 0 ;
            }
            flag=0;
           // op2=pop();
            //op1=pop();
            switch(ch)
            {
            //    case '+':push(_add(op1, op2));
             //       break;
             //   case '-':push(_sub(op1,op2));
             //       break;
              //  case '*':push(_multi(op1, op2));
             //       break;
             //   case '/':push(_div(op1,op2));

              //      break;
                default:
                    return 0;
            }
        }
    }
    free(op1);
    //free(op2);
    */
    fclose(fp);
    return 0 ;
}


