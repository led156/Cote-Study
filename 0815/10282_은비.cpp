#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_n 10001
#define INF 987654321

int T, n, d, c, a, b, s, ans_node, ans_time;
vector<pair<int, int>> edges[MAX_n];
int dist[MAX_n];

void init_() {
    fill(&dist[0], &dist[MAX_n], INF);
    for (int i = 0; i < MAX_n; ++i) {
        edges[i].clear();
    }
    ans_node = 0;
    ans_time = 0;
}

void dijk() {
    priority_queue<pair<int, int>> que;
    que.push({0, c});
    dist[c] = 0;

    pair<int, int> cur;
    int cur_node, cur_cost, nxt_node, nxt_cost;
    while (!que.empty()) {
        cur = que.top();
        cur_node = cur.second;
        cur_cost = -cur.first;
        que.pop();

        if (dist[cur_node] < cur_cost) continue;

        for (pair<int, int> nxt : edges[cur_node]) {
            nxt_node = nxt.first;
            nxt_cost = nxt.second;
            if (dist[nxt_node] > nxt_cost + cur_cost) {
                dist[nxt_node] = nxt_cost + cur_cost;
                que.push({-dist[nxt_node], nxt_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> d >> c;
        init_();
        for (int i = 0; i < d; ++i) {
            cin >> a >> b >> s;
            edges[b].push_back({a, s});
        }

        dijk();

        for (int i = 1; i <= n; ++i) {
            if (dist[i] < INF) {
                ++ans_node;
                ans_time = max(ans_time, dist[i]);
            }
        }

        cout << ans_node << " " << ans_time << '\n';
    } 

    return 0;
}
