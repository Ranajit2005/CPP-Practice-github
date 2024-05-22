#include <iostream>
using namespace std;

template <class t = int>
class vector
{
    t *a;
    int capacity;
    int index;

public:
    vector(int n = 0)
    {
        a = (t *)malloc(sizeof(t) * (n + 1));
        capacity = n;
        index = 0;
    }

    int size()
    {
        return capacity;
    }

    void push_back(t value)
    {
        capacity++;
        if (index + 1 == capacity)
        {
            a = (t *)realloc(a, sizeof(t) * (capacity + 1));
        }
        a[index++] = value;
    }
    t &operator[](int it)
    {
        if (it < 0 || it > capacity - 1)
            exit(0);
        return a[it];
    }
};

// template <class t = int>
class PriorityQueue // min-heap
{
    pair<int, int> *arr;
    int idx, capacity;

public:
    PriorityQueue(int n)
    {
        arr = new pair<int, int>[n];
        idx = -1;
        capacity = n;
    }
    void push(pair<int, int> value)
    {
        if (idx == capacity - 1)
            return;
        arr[++idx] = value;
        int i = idx;
        while (i > 0)
        {
            int parent = i / 2;
            if (arr[i].first < arr[parent].first)
            {
                swap(arr[i], arr[parent]);
            }
            else
                break;
            i = parent;
        }
    }
    void pop()
    {
        if (empty())
            return;
        arr[0] = arr[idx];
        idx--;
        int i = 0;
        while (i < idx)
        {
            int left = i * 2;
            int right = i * 2 + 1;

            int smallest = i;
            if (left <= idx && arr[left].first < arr[smallest].first)
                smallest = left;
            if (right <= idx && arr[right].first < arr[smallest].first)
                smallest = right;
            if (smallest == i)
                break;
            arr[i] = arr[smallest];
            i = smallest;
        }
    }
    int empty()
    {
        return idx == -1;
    }
    pair<int, int> top()
    {
        if (empty())
            exit(0);
        return arr[0];
    }
};

void dijkstra(vector<pair<int, int>> adj[], int V, int src)
{
    vector<int> dist(V), parent(V);
    for (int i = 0; i < dist.size(); i++)
    {
        dist[i] = 1e8;
        parent[i] = i;
    }
    dist[src] = 0;
    PriorityQueue pq(V);
    pq.push({0, src});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[node].size(); i++)
        {
            int next = adj[node][i].first;
            int weight = adj[node][i].second;

            if (dis + weight < dist[next])
            {
                dist[next] = (dis + weight);
                parent[next] = node;
                pq.push({dist[next], next});
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        cout << "Node : " << i << " ";
        if (dist[i] == 1e8)
        {
            dist[i] = -1;
        }
        cout << "Distance : " << dist[i] << " parent : " << parent[i] <<endl;
    }
}

int main(){

    return 0;
}