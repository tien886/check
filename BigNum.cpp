#include <bits/stdc++.h>
using namespace std;
long long tong(int tmp[], int idx) {
    long long sum = 0;
    for (int i = 0; i < idx; i++) {
        sum += tmp[i];
    }
    return sum;
}
int modification(int tmp[], int idx) {
    long long ans = tong(tmp, idx); 
    int mod = ans % 3;              
    int largest_digit = tmp[0];    

    for (int i = 0; i < idx; i++) {
        int original = tmp[i]; 
        for (int digit = 9; digit >= 0; digit--) {
            if (digit == original) continue; 

            tmp[i] = digit;                 
            long long new_sum = tong(tmp, idx); 
            if (new_sum % 3 == 0 && digit > largest_digit) {
                largest_digit = digit;     
            }
        }
        tmp[i] = original; 
    }
    return largest_digit;
}

int main() {
    int tmp[101] = {0};  
    char numb[101];   
    cin.getline(numb, 101);

    int idx = 0;     
    for (int i = 0; numb[i] != '\0'; i++) {
        if (isdigit(numb[i])) {
            tmp[idx++] = numb[i] - '0'; 
        }
    }
    tmp[0] = modification(tmp, idx);
    for (int i = 0; i < idx; i++) {
        cout << tmp[i];
    }
    cout << endl;

    return 0;
}
