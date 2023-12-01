//POSTFIX EVALUATION ALONG WHICH HANDLES UNARY - OPERATOR
//STRING FORMAT IS 
//1) SPACE BETWEEN EVERY OPERAND AND OPERATOR
//2) NO SPACE BETWEEN UNARY OPERATOR AND OPERAND
//3) MULTI DIGIT NUMBER DOES NOT CONTAIN SPACE

#include <bits/stdc++.h>
using namespace std;

int is_operator(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^'){
        return 1;
    }
    return 0;
}

int postfix_evaluation(char postfix[],int size){
    int answer = 0;
    bool negative_flag = false;
    stack<int> stk;
    int first,second;
    int number = 0;
    int digit = 0;
    for(int i = 0;i<size;i++){
        if(i!=(size-1) && postfix[i] == '-' && postfix[i+1]!=' '){
            negative_flag = true;
        }
        else if(postfix[i] == ' '){
            if(number != 0){
                if(negative_flag){
                    stk.push(-1*number);
                }
                else{
                    stk.push(number);
                }
            }
            negative_flag = false;
            number = 0;
        }
        else if(is_operator(postfix[i])){
            second = stk.top();
            stk.pop();
            first = stk.top();
            stk.pop();
            if(postfix[i] == '+'){
                stk.push(first + second);
            }
            else if(postfix[i] == '-'){
                stk.push(first - second);
            }
            else if(postfix[i] == '*'){
                stk.push(first * second);
            }
            else if(postfix[i] == '/'){
                stk.push(first / second);
            }
            else if(postfix[i] == '^'){
                stk.push(pow(first,second));
            }
        }
        else{
            digit = (int)(postfix[i] - '0');
            number = number*10 + digit;
        }
    }
    answer = stk.top();
    stk.pop();
    return answer;
}

int main()
{
    char postfix[] = "-35 20 30 * + 3 2 3 ^ ^ 3 / + -7 -50 + 10 * +";
    // char postfix[] = "1 2 3 * + 2 3 ^ +";
    int size = sizeof(postfix)/sizeof(postfix[0]);
    printf("postfix: %s\n",postfix);
    printf("answer = %d\n",postfix_evaluation(postfix,size));
    return 0;
}
