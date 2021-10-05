    #include <iostream>
     
    using namespace std;
     
    int main()
    {
       int a, b, c; //1st we have to declare variables
       
       cout << "Enter two integers to add\n"; //we have to sk for input
       cin >> a >> b; ///take input for a and b
     
       c = a + b; //we can add value of a and b, assign it in c
       cout <<"Sum of the numbers: " << c << endl; //by this we can get the final value
       
       return 0;
    }