#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void areAdjacent(vector<int> adjList[], int node1, int node2)
    {
        int i = 0;
        bool areAdjacent = false;
        for (vector<int>::iterator it = adjList[node1-1].begin(); it != adjList[node1-1].end(); ++it)
        {

            if (adjList[node1-1].at(i) == node2)
            {

                areAdjacent = true;
                break;
            }
            i++;
        }

        if (areAdjacent == true)
        {
            cout << node1 << " and " << node2 << " are adjacent." << endl;
        }
        else
        {
            cout << "Not adjacent." << endl;
        }
    }

/*void addEdge(vector< vector<int> > adjMatrix, int node1, int node2, int totalNode)
    {
        if (adjMatrix[node1-1][node2-1] == 0)
        {
            adjMatrix [node1-1][node2-1] = 1;
            adjMatrix [node2-1][node1-1] = 1;
            cout << "New edge between" << node1 << " and " << node2 << " added." << endl << endl;
            for(int i = 0;i < totalNode; i++)
            {
                for(int j = 0; j < totalNode; j++)
                cout << adjMatrix[i][j] << "  ";
                cout << endl;
            }
        }
        else
        {
            cout << "Edge already available. " << endl << endl;
        }
    }

void removeEdge (vector< vector<int> > adjMatrix, int node1, int node2, int totalNode)
    {
    if (adjMatrix[node1-1][node2-1] == 1)
        {
            adjMatrix [node1-1][node2-1] = 0;
            adjMatrix [node2-1][node1-1] = 0;
            cout << "Edge between" << node1 << " and " << node2 << " removed." << endl << endl;
            for(int i = 0;i < totalNode; i++)
            {
                for(int j = 0; j < totalNode; j++)
                cout << adjMatrix[i][j] << "  ";
                cout << endl;
            }
        }
        else
        {
            cout << "No edge here. " << endl << endl;
        }
    }*/


int main(){

    ifstream file("1.txt");
    int totalNode;
    file >> totalNode;
    int val = 0;
    vector<int> adjList[totalNode];

    int i, j;
    while (file >> i >> j)
    {
        adjList[i-1].push_back(j);
        adjList[j-1].push_back(i);
    }




    for (int i = 0; i < totalNode; i++){
        sort(adjList[i].begin(), adjList[i].end());
        cout << i+1;
        vector <int>::iterator iter = adjList[i].begin();
        while (iter != adjList[i].end())
        {
            cout << " -> " << *iter;
            iter++;
        }
        cout << endl;
    }

    int start;
    cout << "Enter starting point: ";
    cin >> start;
    int n = totalNode;
    bool visited[n] = {false};
    queue<int> bfs;
    start = start - 1;
    visited[start] = true;
    bfs.push(start);

    while(bfs.empty() == false)
    {
        int currentVertex = bfs.front();
        bfs.pop();

        cout << currentVertex+1 << " ";
        int x = 0;
        for (vector<int>::iterator it = adjList[currentVertex].begin(); it != adjList[currentVertex].end(); ++it)
        {

            int neighbor = adjList[currentVertex].at(x);
            neighbor = neighbor-1;


            if (visited[neighbor] == false)
            {

                bfs.push(neighbor);
                visited[neighbor] = true;
            }
            x++;
        }
    }

    cout << endl << endl;
    int process;
    cout << "Other process: " << endl << "1. areAdjacent" << endl << "2. addEdge" << endl
    << "3. removeEdge" << endl;
    cout << "Enter process no.: ";
    cin >> process;
    if (process == 1)
    {
        int node1, node2;
        cout << "Check if 2 nodes are adjacent, enter node1 and node2: ";
        cin >> node1 >> node2;
        areAdjacent(adjList, node1, node2);
    }

  /*  if (process == 2)
    {
        int node1, node2;
        cout << "Add new edge between 2 nodes, enter node1 and node2: ";
        cin >> node1 >> node2;
        addEdge (adjMatrix, node1, node2, totalNode);
    }

    if (process == 3)
    {
        int node1, node2;
        cout << "Remove new edge between 2 nodes, enter node1 and node2: ";
        cin >> node1 >> node2;
        removeEdge (adjMatrix, node1, node2, totalNode);
    }*/
}


