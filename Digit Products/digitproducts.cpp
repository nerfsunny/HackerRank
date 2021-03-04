#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long int;

vector<string> split_string(string);

ull digitProduct(long num) {
    ull total = 1;
    
    while(num > 0) {
        total *= (num % 10);
        num /= 10;
    }
    
    return total;
}

// Complete the solve function below.
int solve(string a, string b, long k) {
    int lowerBound = stoi(a), upperBound = stoi(b), count = 0;
    
    for(int num = lowerBound; num <= upperBound; num++) {
        if(digitProduct(num) == k)
            count++;
    }

    return count % 1000000007;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string abk_temp;
        getline(cin, abk_temp);

        vector<string> abk = split_string(abk_temp);

        string a = abk[0];

        string b = abk[1];

        long k = stol(abk[2]);

        int result = solve(a, b, k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
