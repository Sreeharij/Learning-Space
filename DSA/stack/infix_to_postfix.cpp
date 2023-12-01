//INFIX TO POSTFIX ALSO HANDLING UNARY OPERATORS
//STRING FORMAT IS 
//1) SPACE BETWEEN EVERY OPERAND AND OPERATOR
//2) NO SPACE BETWEEN UNARY OPERATOR AND OPERAND
//3) MULTI DIGIT NUMBER DOES NOT CONTAIN SPACE

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int precendence(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    else if(x == '^'){
        return 3;
    }
    return 0; // return 0 when the given character is operand and not operator
}

void infix_to_postfix(char infix[],int size){
    char postfix[size];
    stack<char> stk;
    
    int k = 0;
    for(int i=0;i<size;i++){
        if(infix[i] ==' '){
            
        }
        else if(infix[i] == '('){
            stk.push('(');
        }
        else if(infix[i] == ')'){
            while(stk.top() != '('){
                postfix[k++] = ' ';
                postfix[k++] = stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else if(precendence(infix[i]) == 0){
            postfix[k++] = infix[i];
            
        }
        else{
            if(infix[i] == '-' && infix[i+1] != ' '){
                postfix[k++] = '-';
            }
            else{
                while(!stk.empty() && precendence(stk.top()) >= precendence(infix[i])){
                    if(infix[i] == '^'){
                        break;
                    }
                    postfix[k++] = ' ';
                    postfix[k++] = stk.top();
                    stk.pop();
                }
                stk.push(infix[i]);
                postfix[k++] = ' ';
            }
        }
    }
    while(!stk.empty()){
        postfix[k++] = ' ';
        postfix[k++] = stk.top();
        stk.pop();
    }
    postfix[k++] = '\0';
    printf("infix:   %s\n",infix);
    printf("postfix: ");
    for(int i=0;i<k;i++){
        printf("%c",postfix[i]);
    }printf("\n");

}

int main()
{
    char infix[] = "-35 + 20 * 30 + 38 ^ 2 ^ 3 / 3 + ( -7 + -50 ) * 10"; 
    int size = sizeof(infix)/sizeof(infix[0]);
    infix_to_postfix(infix,size);
    return 0;
}
