#include <bits/stdc++.h>

using namespace std;

bool is_sorted(const vector<int>& P) {
    for (size_t i = 0; i < P.size() - 1; ++i) {
        if (P[i] > P[i + 1]) {
            return false;
        }
    }
    return true;
}

vector<int> swap_type1(const vector<int>& P, int N) {
    vector<int> new_P = P;
    for (int i = 0; i < 2 * N; i += 2) {
        swap(new_P[i], new_P[i + 1]);
    }
    return new_P;
}

vector<int> swap_type2(const vector<int>& P, int N) {
    vector<int> new_P = P;
    for (int i = 0; i < N; ++i) {
        swap(new_P[i], new_P[N + i]);
    }
    return new_P;
}

int min_operations_to_sort(int N, vector<int>& P) {
    queue<pair<vector<int>, int>> q;
    set<vector<int>> visited;

    q.push({P, 0});
    visited.insert(P);

    while (!q.empty()) {
        auto [current_P, depth] = q.front();
        q.pop();

        if (is_sorted(current_P)) {
            return depth;
        }

        vector<int> next_P1 = swap_type1(current_P, N);
        if (visited.find(next_P1) == visited.end()) {
            visited.insert(next_P1);
            q.push({next_P1, depth + 1});
        }

        vector<int> next_P2 = swap_type2(current_P, N);
        if (visited.find(next_P2) == visited.end()) {
            visited.insert(next_P2);
            q.push({next_P2, depth + 1});
        }
    }

    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> P[i];
    }

    int result = min_operations_to_sort(N, P);
    cout << result << endl;

    return 0;
}
