#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <chrono>
#include <iomanip>

using namespace std;

int steps = 0;

int heuristic(const vector<int>& s) {
    int h = 0;
    for (int i = 0; i < 9; i++) {
        if (s[i] != 0) {
            int x = i / 3, y = i % 3;
            int gx = (s[i] - 1) / 3, gy = (s[i] - 1) % 3;
            h += abs(x - gx) + abs(y - gy);
        }
    }
    return h;
}

void print(const vector<int>& s) {
    for (int i = 0; i < 9; i++) {
        cout << s[i] << " ";
        if (i % 3 == 2) cout << "\n";
    }
    steps++;
    cout << "------\n";
}

vector<vector<int>> nextMoves(const vector<int>& s) {
    vector<vector<int>> v;
    int z;

    for (int i = 0; i < 9; i++)
        if (s[i] == 0) z = i;

    int r = z / 3;
    int c = z % 3;

    if (r > 0) {
        vector<int> t = s;
        swap(t[z], t[z - 3]);
        v.push_back(t);
    }
    if (r < 2) {
        vector<int> t = s;
        swap(t[z], t[z + 3]);
        v.push_back(t);
    }
    if (c > 0) {
        vector<int> t = s;
        swap(t[z], t[z - 1]);
        v.push_back(t);
    }
    if (c < 2) {
        vector<int> t = s;
        swap(t[z], t[z + 1]);
        v.push_back(t);
    }

    return v;
}

struct Node {
    vector<int> state;
    int g, f;
};

struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.f > b.f;
    }
};

int main() {
    auto start = chrono::high_resolution_clock::now();

    vector<int> startState = {
        1, 2, 3,
        0, 4, 6,
        7, 5, 8
    };

    vector<int> goalState = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 0
    };

    priority_queue<Node, vector<Node>, Compare> pq;
    set<vector<int>> visited;

    pq.push({startState, 0, heuristic(startState)});
    visited.insert(startState);

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        print(cur.state);

        if (cur.state == goalState) {
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> time = end - start;

            cout << "Goal Reached\n";
            cout << "Steps: " << steps << "\n";
            cout << "Time: " << fixed << setprecision(2) << time.count() << " ms\n";
            return 0;
        }

        for (auto n : nextMoves(cur.state)) {
            if (visited.find(n) == visited.end()) {
                int g = cur.g + 1;
                int f = g + heuristic(n);
                visited.insert(n);
                pq.push({n, g, f});
            }
        }
    }

    cout << "No Solution\n";
    return 0;
}