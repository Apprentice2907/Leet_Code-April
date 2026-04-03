#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens){
            if(s=="+" || s=="*" || s=="-" || s=="/"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if(s == "+") st.push(a + b);
                else if(s == "-") st.push(a - b);
                else if(s == "*") st.push(a * b);
                else if(s == "/") st.push(a / b);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};

int main(){
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << sol.evalRPN(tokens) << endl; 
}








// Crazy approach but not optimal 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string,function<int(int,int)>>mp = {
            {"+",[](int a,int b){return a+b;}},
            {"-",[](int a,int b){return a-b;}},
            {"/",[](int a,int b){return a/b;}},
            {"*",[](int a,int b){return a*b;}},
        };
        for(string s:tokens){
            if(s=="+" || s=="*" || s=="-" || s=="/"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                int ans=mp[s](a,b);
                st.push(ans);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};