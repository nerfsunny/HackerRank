#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long int;

ull sequenceValue(ull num) {
    //return pow(num, 2) - pow(num - 1, 2);
    return 2*num -1;
}

/*
 * Complete the summingSeries function below.
 */
int summingSeries(long n) {
    ull sum = 0;
    
    for(ull i = 1; i <= n; i++)
        sum += sequenceValue(i);
        
    return sum % 1000000007;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = summingSeries(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}