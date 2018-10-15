#include <bits/stdc++.h> 
using namespace std; 
 
void permute(string str) 
{
    sort(str.begin(), str.end()); 
    do { 
       cout << str << endl; 
    } while (next_permutation(str.begin(), str.end())); 
} 

int main() 
{ 
    string str = "CBA"; 
    permute(str); 
    return 0; 
}