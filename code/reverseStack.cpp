#include<iostream>
#include<stack>

void reverseStackUtil(std::stack<int> &s, int num) {
    if(s.empty()) {
        s.push(num);
        return;
    }
    else {
        int temp = s.top();
        s.pop();
        reverseStackUtil(s, num);
        s.push(temp);
    }
}

void reverseStack(std::stack<int> &s) {
    if(s.empty()) {
        return;
    }
    else {
        int temp = s.top();
        s.pop();
        reverseStack(s);
        reverseStackUtil(s, temp);
    }
}

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    std::stack<int> temps;
    temps = s;
    while(!temps.empty()) {
        std::cout << temps.top() << " ";
        temps.pop();
    }
    std::cout << std::endl;
    reverseStack(s);
    temps = s;
    while(!temps.empty()) {
        std::cout << temps.top() << " ";
        temps.pop();
    }
    std::cout << std::endl;
    return 0;
}