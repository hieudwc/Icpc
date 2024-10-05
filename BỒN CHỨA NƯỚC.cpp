#include <bits/stdc++.h>
using namespace std;

int calculateWater(vector<int>& H) {
    int N = H.size();
    vector<int> left_max(N), right_max(N);

    left_max[0] = H[0];
    for (int i = 1; i < N; ++i) {
        left_max[i] = max(left_max[i - 1], H[i]);
    }

    right_max[N - 1] = H[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        right_max[i] = max(right_max[i + 1], H[i]);
    }

    int water = 0;
    for (int i = 0; i < N; ++i) {
        water += max(0, min(left_max[i], right_max[i]) - H[i]);
    }

    return water;
}

int maximizeWater(vector<int>& H, int K, int idx) {
    if (K == 0 || idx == H.size()) {
        return calculateWater(H);
    }

    int max_water = calculateWater(H);
    for (int i = idx; i < H.size(); ++i) {
        H[i]++;
        max_water = max(max_water, maximizeWater(H, K - 1, i));
        H[i]--;  
    }

    return max_water;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int result = maximizeWater(H, K, 0);
    cout << result << endl;

    return 0;
}
