#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
vector<int> graph[N];
queue<int> q;
int visDFS[N];
int visBFS[N];

void DFS(int vertex)
{
    // Mark Node as visited
    visDFS[vertex] = 1;
    
    cout << vertex << " ";
    for (auto child : graph[vertex])
    {
        if (!visDFS[child])
        {
            DFS(child);
        }
    }
}

void BFS()
{
    if (q.empty())
    {
        return;
    }
    int x = q.front();
    visBFS[x] = 1;
    q.pop();
    cout << x << " ";
    for (auto child : graph[x])
    {
        if (!visBFS[child])
        {
            visBFS[child] = 1;
            q.push(child);
        }
    }
    BFS();
}


int main()
{
    int v, e;
    cout << "\nEnter the number of vertices and edges: ";
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter the start and end of edge: ";
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << "\nAdjacency list representation of graph:\n";
    for (int i = 0; i < v; i++)
    {
        cout << i << " : ";
        for (auto x : graph[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;

    int n;
    do
    {
        cout << "\n\tMENU" << endl;
        cout << "1. DFS" << endl;
        cout << "2. BFS" << endl;
        cout << "3. Search" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> n;
        switch (n)
        {
        case 0:
            cout << "\nProgram exited" << endl;
            break;
        case 1:
            int v1;
            cout << "\nEnter the starting vertex: ";
            cin >> v1;
            cout << "\nDFS of the graph: ";
            for (int i = 0; i < v; i++)
            {
                visDFS[i] = 0;
            }
            DFS(v1);
            cout << endl;
            break;
        case 2:
            int v2;
            cout << "\nEnter the starting vertex: ";
            cin >> v2;
            cout << "\nBFS of the graph: ";
            for (int i = 0; i < v; i++)
            {
                visBFS[i] = 0;
            }
            q.push(v2);
            BFS();
            cout << endl;
            break;
        case 3:
            int ver1;
            cout << "\nEnter the vertex for search: ";
            cin >> ver1;
            for (int i = 0; i < v; i++)
            {
                visDFS[i] = 0;
            }
            DFS(0);
            if (visDFS[ver1])
            {
                cout << "\n\nVertex is present in the graph" << endl;
            }
            else
            {
                cout << "\n\nVertex is not present in the graph" << endl;
            }
            break;
        default:
            cout << "\nPlease enter valid input!!!";
            break;
        }
    } while (n != 0);

    return 0;
}
