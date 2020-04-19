#include <iostream>
using namespace std;

struct Vertex {
    int edge_count = 0;
    int edges[1000];
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int vertex_count, edge_count;
    cin >> vertex_count >> edge_count;

    Vertex vertices[1000];

    while (edge_count-- > 0) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        vertices[a].edges[vertices[a].edge_count++] = b;
        vertices[b].edges[vertices[b].edge_count++] = a;
    }

    bool visited[1000] = { false, };
    int to_visit[1000];
    int visit_top = 0;

    int component_count = 0;

    for (int i = 0; i < vertex_count; ++i) {
        if (!visited[i]) {
            component_count += 1;
            to_visit[0] = i;
            visit_top = 1;
            visited[i] = true;
            while (visit_top > 0) {
                auto current = to_visit[--visit_top];
                for (int j = 0; j < vertices[current].edge_count; ++j) {
                    auto connected = vertices[current].edges[j];
                    if (!visited[connected]) {
                        to_visit[visit_top++] = connected;
                        visited[connected] = true;
                    }
                }
            }
        }
    }
    cout << component_count;
}