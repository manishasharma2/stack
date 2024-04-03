#include<iostream>
#include<stack>
using namespace std;

// #define n 100

// class stack{
//     int* arr;
//     int top;

//     public:
//     stack(){
//         arr = new int[n];
//         top  = -1;
//     }
//     void push(int val){
//         if(top == n-1){
//             cout<<"Stack Overflow"<<endl;
//             return;
//         }
//         top++;
//         arr[top] = val;
//     }
//     void pop(){
//         if(top == -1){
//             cout<<"Stack Underflow"<<endl;
//             return;
//         }
//         int temp = arr[top];
//         top--;
//         cout<<temp<<endl;
//     }
//     int peek(){
//         if(top == -1){
//             cout<<"Stack Underflow"<<endl;
//             return -1;
//         }
//         return arr[top];
//     }
//     int empty(){
//         return top == -1;
//     }
//     void display(){
//          if(top == -1){
//             cout<<"Stack Underflow"<<endl;
//             return;
//         }
//         for(int i=0;i<top;i++){
//             cout<<arr[i]<<" "<<endl;
//         }
//     }
// };

Program to reverse a string
void reverse(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word ="";
        while(s[i]!=' ' && i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
//Program to insert element at the bottom of the stack
void insertAtBottom(stack<int>&st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}
//Program to reverser the stack
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,ele);
}

int main(){

    stack<int> st;
    st.push(22);
    st.push(90);
    st.push(3);
   
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}