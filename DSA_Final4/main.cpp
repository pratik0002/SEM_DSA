#include<algorithm>
#include <iostream>
#include<string>
using namespace std;
const int maxn = 100007;
int removing_array[maxn][2], upper[maxn], n;
struct guard_node {
    int l, r;
    bool operator < (const guard_node& tmp) const {
        return l == tmp.l ? r < tmp.r : l < tmp.l;
    }
} node[maxn];
int calc(int cur, int pre) {
    return std::max(node[cur].r - node[pre].r, 0) - std::max(node[cur].l - node[pre].r, 0);
}
int main() {
    for (int i = 1; i <= 10; i++) {
        string file_name = std::to_string(i) + ".in";
        freopen(file_name.c_str(), "r", stdin);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d%d", &node[i].l, &node[i].r);
        std::sort(node + 1, node + 1 + n);
        for (int i = 1; i <= n; i++) {
            if (i < n) {
                removing_array[i][0] = removing_array[i - 1][0] + calc(i, upper[i - 1]);
                upper[i] = node[upper[i - 1]].r > node[i].r ? upper[i - 1] : i;
            }
            if (i > 1) removing_array[i][1] = std::max(removing_array[i - 1][1] + calc(i, upper[i - 1]), removing_array[i - 2][0] + calc(i, upper[i - 2]));
        }
        freopen("Output.out", "a", stdout);
        printf("%d\n", std::max(removing_array[n - 1][0], removing_array[n][1]));

    }
    return 0;
}
