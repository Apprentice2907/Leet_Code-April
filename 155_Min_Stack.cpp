// #include <iostream>
// #include <stack>

#include <bits/stdc++.h> // all library at once but works in GCC only 
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> st;

    MinStack() {} // constructor - automatically do certain task when obj called 
    //Even if you remove this: C++ will automatically create a default constructor like this internally.

    void push(int val) {
        if (st.empty()) 
            st.push({val, val});
        else {
            int minv = min(val, st.top().second);
            st.push({val, minv});
        }
    }
    
    void pop() {
        if (!st.empty())
            st.pop();
        else
            cout << "Stack is empty!\n";
    }
    
    int top() {
        if (!st.empty())
            return st.top().first;
        cout << "Stack is empty!\n";
        return -1;
    }
    
    int getMin() {
        if (!st.empty())
            return st.top().second;
        cout << "Stack is empty!\n";
        return -1;
    }
};

int main() {
    MinStack obj; // constructor is called here

    obj.push(5);
    obj.push(3);
    obj.push(7);
    obj.push(2);

    cout << "Top: " << obj.top() << endl;       // Expected: 2
    cout << "Min: " << obj.getMin() << endl;    // Expected: 2

    obj.pop();
    cout << "After pop -> Top: " << obj.top() << endl;    // Expected: 7
    cout << "Min: " << obj.getMin() << endl;              // Expected: 3

    obj.pop();
    cout << "After pop -> Top: " << obj.top() << endl;    // Expected: 3
    cout << "Min: " << obj.getMin() << endl;              // Expected: 3

    return 0;
}










// Mathematical based approach 

class MinStack {
public:
    stack<long int> st;
    long int minv;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minv=val;
        }
        else{
            if(val<minv){
                st.push((long long)2*val-minv);
                minv=val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top()<minv){
            minv=2*minv-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<minv){
            return minv;
        }
        return st.top();
    }
    
    int getMin() {
        return minv;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */