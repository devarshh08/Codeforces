#include <bits/stdc++.h>
using namespace std;

struct Monster {
    long long power;
    int type;
};

bool can_defeat(const Monster& m1, const Monster& m2) {
    if (m1.power >= m2.power) return true;
    if (m1.type == m2.type && 2 * m1.power >= m2.power) return true;
    return false;
}

vector<vector<int>> build_graph(int N, const vector<Monster>& player_monsters, const vector<Monster>& enemy_monsters) {
    vector<vector<int>> graph(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (can_defeat(player_monsters[i], enemy_monsters[j])) {
                graph[i].push_back(j);
            }
        }
    }
    return graph;
}

bool bpm(const vector<vector<int>>& graph, int u, vector<bool>& seen, vector<int>& match) {
    for (int v : graph[u]) {
        if (seen[v]) continue;
        seen[v] = true;
        
        if (match[v] == -1 || bpm(graph, match[v], seen, match)) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

bool max_bipartite_matching(const vector<vector<int>>& graph, int N) {
    vector<int> match(N, -1);
    int result = 0;
    
    for (int u = 0; u < N; u++) {
        vector<bool> seen(N, false);
        if (bpm(graph, u, seen, match)) {
            result++;
        }
    }
    
    return result == N;
}

bool solve_testcase() {
    int N;
    cin >> N;

    vector<Monster> player_monsters(N);
    for (int i = 0; i < N; i++) {
        cin >> player_monsters[i].power >> player_monsters[i].type;
    }
    
    vector<Monster> enemy_monsters(N);
    for (int i = 0; i < N; i++) {
        cin >> enemy_monsters[i].power >> enemy_monsters[i].type;
    }
    
    vector<vector<int>> graph = build_graph(N, player_monsters, enemy_monsters);

    return max_bipartite_matching(graph, N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        bool result = solve_testcase();
        cout << (result ? "YES" : "NO") << '\n';
    }
    
    return 0;
}