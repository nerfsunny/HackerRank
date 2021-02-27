#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
using ull = unsigned long long int;

void generatePrimeFactorList(list<ull>& primeFactors, ull number) {
    while(number % 2 == 0) {
        primeFactors.push_back(2);
        number /= 2;
    }
    
    for(int i = 3; i <= (int) sqrt(number); i+=2) {
        while(number % i == 0) {
            primeFactors.push_back(i);
            number /= i;
        }
    }
    
    if(number > 2)
        primeFactors.push_back(number);
}

int main() {
    ull numberOfInputs, number, counter = 0;
    list<ull> primeFactors;
    
    cin >> numberOfInputs >> number;
    
    for(ull i = 0; i < numberOfInputs; i++) {
        for(ull j = 4; j <= number; j++) 
            generatePrimeFactorList(primeFactors, number);
        
        if(primeFactors.size() == 2)
            counter++;
            
        primeFactors.clear();
    }
    
    cout << counter << endl;
    
    return 0;
}
