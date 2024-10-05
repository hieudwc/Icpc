#include<bits/stdc++.h>

using namespace std;

double calculate_minimum_cost(long long N, long long k, vector<long long>& D) {
    double P;
    
    double S = 0;
    if (k == 1) {
    	long long ans = INT_MAX;
    	for(int i = 0; i < N; i++){
    		long long sum = 0;
    		for(int j = 0; j < N; j++){
    			sum += abs(D[j] - D[i]);
    		}
    		ans = min(ans, sum);
    	}
    	S = ans;
    }
    else{
        P = 1.0 * accumulate(D.begin(), D.end(), 0.0) / N;
        for (int i = 0; i < N; ++i) {
            S += pow(D[i] - P, 2);
        }
    }

    return S;
}

int main() {
    long long N, k;
    cin >> N >> k;
    vector<long long> D(N);

    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    double result = calculate_minimum_cost(N, k, D);
    cout << fixed << setprecision(2) << result ;

    return 0;
}