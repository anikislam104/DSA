//
// Created by aniki on 12/28/2022.
//
#include "iostream"
#include "stack"
#include "string"
using namespace std;

char* postfix_converter(const string& s)
{
    stack<char> st;
    char postfix[s.length()];
    cout<<s.length()<<endl;
    int index_count=0;
    char operators_with_higher_precedence[] = {'^','*','/','+','-'};
    for(char i : s)
    {
        if(i == ' '){
//            postfix[i] = ' ';
            continue;
        }
        else if(i > 47 && i < 58){
            postfix[index_count] = i;
            index_count++;
        }

        else if(i > 64 && i <91) {
//            postfix += i;
            postfix[index_count] = i;
            index_count++;
        }

        else if(i >96 && i <123) {
            postfix[index_count] = i;
            index_count++;
        }

        else if(i == ')'){
            st.push(i);
        }

        else if(i == '('){
            while(st.top() != ')'){
                postfix[index_count++] = st.top();
                st.pop();
            }
            st.pop();
        }

        else if(i == '^'){
            st.push(i);
        }

            else if(i == '*' || i == '/'){
                while(st.top() == '^'){
                    postfix[index_count++] = st.top();
                    st.pop();
                }
                st.push(i);
            }

            else if(i == '+' || i == '-'){
                while(st.top() == '^' || st.top() == '*' || st.top() == '/'){
                    postfix[index_count++] = st.top();
                    st.pop();
                }
                st.push(i);
            }
    }
    return postfix;
}

int main(){
    string s="a+b*(c^d-e)^(f+g*h)-i";
    char* postfix = postfix_converter(s);
    for(int i=0;i<s.length();i++){
        cout<<postfix[i];
    }
}