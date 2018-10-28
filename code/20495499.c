#include <stdio.h>
int main() {
int t;
scanf("%d",&t);
while(t>0) {
    long a, b, nm, sc;
    scanf("%ld %ld %ld",&a, &b, &sc);
    nm=(a+b)/sc;
    //printf("nm=%ld\n",nm);
    if (nm%2==0)
        printf("CHEF\n");
    else
        printf("COOK\n");
    t--;
}
return 0;
}
//my solution to https://www.codechef.com/viewsolution/20495499
