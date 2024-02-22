#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
#define endl "\n"

class Node
{
public:
    char character;
    int value;
    Node *left;
    Node *right;

    Node(char x, int y)
    {
        this->character = x;
        this->value = y;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        if (a->value > b->value)
        {
            return true;
        }
        return false;
    }
};

void dfs(Node *top, string answer)
{
    if (!top->left && !top->right)
    {
        cout << top->character << "-->" << answer << endl;
    }

    if (top->left)
        dfs(top->left, answer + "0");
    if (top->right)
        dfs(top->right, answer + "1");
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);

    map<char, int> alphabet;
    alphabet['a'] = 5;
    alphabet['b'] = 9;
    alphabet['c'] = 12;
    alphabet['d'] = 13;
    alphabet['e'] = 16;
    alphabet['f'] = 45;
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto x : alphabet)
    {
        Node *node = new Node(x.first, x.second);
        pq.push(node);
    }

    while (pq.size() > 1)
    {
        Node *n1 = pq.top();
        pq.pop();
        // cout << n1->character << ' ' << n1->value << endl;

        Node *n2 = pq.top();
        pq.pop();
        // cout << n2->character << ' ' << n2->value << endl;

        Node *n3 = new Node('Z', n1->value + n2->value);
        n3->left = n1;
        n3->right = n2;
        pq.push(n3);
    }

    dfs(pq.top(), "");
}