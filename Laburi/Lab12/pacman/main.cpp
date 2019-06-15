#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>
#include <unordered_set>

#define pp pair<int, int>
#define mp make_pair<int, int>

using namespace std;


const int NMAX = 41 * 41;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int px,py;
int fx,fy;

int start;
int finish;

int n; int m;
int nodes;

char a[40][40];

vector<int> adj[NMAX];
uint32_t f[NMAX], g[NMAX];

int get_node(int x, int y) {return x * m + y + 1;}

vector<int> get_neigh(int x, int y) {

    vector<int> neigh;
    for (int k = 0 ; k < 4; ++k) {
        int posx = x + dx[k];
        int posy = y + dy[k];
        if (posx >= 0 && posy >= 0 && posx < n && posy < m && a[posx][posy] != '%') {
            neigh.push_back(get_node(posx, posy));

        }
    }
    return neigh;
}

pp get_pos(int node) {
    return {(node - 1) / m, (node - 1) % m};
}

void construct_graph() {
    nodes = n * m;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0; j < m; ++j)
            if (a[i][j] != '%')
                adj[get_node(i, j)] = get_neigh(i, j);
}


void print_graph() {

    for (int i = 1; i <= nodes; i++) {
        cout << i << ":  ";
        for(int v : adj[i])
            cout << v << ' ' ;
        cout << '\n';
    }
}

void print_path(int start, int finish, int* pi) {
    stack<int> ss;
    while(finish != 0){
        ss.push(finish);
        finish = pi[finish];
    }
    cout << ss.size() - 1 << '\n';;
    while(!ss.empty()){
        int w = ss.top();
        ss.pop();
        pp p = get_pos(w);
        cout << p.first << " "<< p.second << '\n';
    }
}

int h(int node1, int node2) {

    int node1x, node1y, node2x, node2y;
    pp p1 = get_pos(node1);
    pp p2 = get_pos(node2);
    node1x = p1.first; node1y = p1.second;
    node2x = p2.first; node2y = p2.second;

    //TODO impelment h
    return abs(node1x - node2x) + abs(node1y - node2y);
}


int astar_pacman(int start, int finish, int nodes) {
    //print_graph();
    //pi este vectorul de parinti
    int* pi = new int[nodes + 1]();

    auto cmp = [](int n1, int n2) {
        return f[n1] > f[n2];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    unordered_set<int> closed;

    int crtNode;
    pp crtPair;

    memset(f, 0xff, NMAX * sizeof(int));
    memset(g, 0xff, NMAX * sizeof(int));

    g[start] = 0;
    f[start] = h(start, finish);
    pq.push(start);
    pi[start] = 0;

    while (!pq.empty()) {
        crtNode = pq.top();

        if (crtNode == finish) {
            break;
        } else if (closed.find(crtNode) != closed.end()) {
            continue;
        }

        crtPair = get_pos(crtNode);
        pq.pop();
        closed.insert(crtNode);

        for (int nextNode : get_neigh(crtPair.first, crtPair.second)) {
            if (closed.find(nextNode) == closed.end() &&
                g[nextNode] > g[crtNode] + 1) {

                g[nextNode] = g[crtNode] + 1;
                pi[nextNode] = crtNode;
                f[nextNode] = g[nextNode] + h(nextNode, finish);
                pq.push(nextNode);
            }
        }
    }

    print_path(start, finish, pi);

    return 0;
}

int main(){
    cin >> px >> py;

    cin >> fx >> fy;
    cin >> n >> m;

    start = get_node(px, py);
    finish = get_node(fx, fy);

    string str;

    getchar();
    for(int i =0; i < n; i++){
        getline(cin,str);
        for(int j = 0; j < m && j < str.size(); j++){
            a[i][j] = str[j];
        }
    }
    construct_graph();
    astar_pacman(start, finish, nodes);

    return 0;
}