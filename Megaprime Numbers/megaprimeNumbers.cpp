#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool isPrime(const long num) {
    if(num % 2 == 0 || num == 1)
        return false;
        
    for(long i = 3; i <= (int) sqrt(num); i+=2)
        if(num % i == 0)
            return false;
            
    return true;
}

int findMegaprimes(const long lowerBound, const long upperBound) {
    int count = 0, digit;
    
    for(int num = lowerBound; num <= upperBound; num++) {
        if(isPrime(num)) {
            do {
                digit = num % 10;
                num /= 10;
            }while(num > 0 && isPrime(digit));
            
            if(num == 0)
                count++;
        }
    }
    
    return count;
}

int main()
{
    string firstLast_temp;
    getline(cin, firstLast_temp);

    vector<string> firstLast = split_string(firstLast_temp);

    long first = stol(firstLast[0]);

    long last = stol(firstLast[1]);

    cout << findMegaprimes(first, last) << endl;

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
