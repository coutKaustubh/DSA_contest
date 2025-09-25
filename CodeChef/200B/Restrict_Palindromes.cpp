#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
    int n;
    scanf("%d", &n);

    char pattern[] = "abc";
    char result[n + 1]; 

    for (int i = 0; i < n; i++) {
        result[i] = pattern[i % 3];  
    }
    result[n] = '\0';

    printf("%s\n", result);
}
return 0;
}