#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int digitSum(int number) {
    int sum = 0;
    
    while(number > 0) {
        sum += (number % 10);
        number /= 10;
    }
    
    return sum;
}

set<int> generateDivisorList(const int number) {
    set<int> divisorList;
    
    for(int i = 1; i <= ceil(sqrt(number)); i++) {
        if(number % i == 0) {
            divisorList.emplace(i);
            divisorList.emplace(number/i);
        }
    }
    
    return divisorList;
}

void bestDivisor(const int number) {
    set<int> divisorList = generateDivisorList(number);
    int divisorNumber = 0, divisorDigitSum = 0, tempDivisorDigitSum;
    
    for(int num : divisorList) {
        tempDivisorDigitSum = digitSum(num);
        
        if(tempDivisorDigitSum > divisorDigitSum) {
            divisorNumber = num;
            divisorDigitSum = tempDivisorDigitSum;
        }
    }
    
    cout << divisorNumber << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    
    bestDivisor(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

