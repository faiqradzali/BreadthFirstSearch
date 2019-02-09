#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
void areAdjacent(vector< vector<int> > adjMatrix, int node1, int node2)
    {

        bool areAdjacent = false;
        if (adjMatrix [node1-1][node2-1] == 1)
        {
            areAdjacent = true;
            cout << node1 << " and " << node2 << " are adjacent." << endl;
    }
        else{cout << "Not adjacent." << endl;}
    }

void addEdge(vector< vector<int> > adjMatrix, int node1, int node2, int totalNode)
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
    }



int main(){



    ifstream file("1.txt");
    int totalNode;
    file >> totalNode;
    int val = 0;
    vector< vector<int> > adjMatrix(totalNode, vector<int> (totalNode, val));

    int i, j;
    while (file >> i >> j)
    {
        adjMatrix [i-1][j-1] = 1;
        adjMatrix [j-1][i-1] = 1;
    }


        for(int i = 0;i < totalNode; i++)
        {
            for(int j = 0; j < totalNode; j++)
            cout << adjMatrix[i][j] << "  ";
            cout << endl;
        }
    int start;
    cout << endl << "Enter starting point: ";
    cin >> start;
    bool visited[adjMatrix.size()] = {false};
    queue<int> bfs;
    start = start - 1;
    visited[start] = true;
    bfs.push(start);

    while(bfs.empty() == false)
    {
        int currentVertex = bfs.front();
        bfs.pop();
        //cout << "def";
        cout << currentVertex+1 << " ";

        for (int i = 0; i < adjMatrix[currentVertex].size(); i++)
        {
            //cout << "abc";
            int neighbor = i;
            int currentEdge = adjMatrix[currentVertex][i];

            if (currentEdge == 0){
                    //cout << "lkj";
                    continue;}

            if (visited[neighbor] == false)
            {
                //cout << "ghi";
                bfs.push(neighbor);
                visited[neighbor] = true;
            }
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
        areAdjacent(adjMatrix, node1, node2);
    }

    if (process == 2)
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
    }




    return 0;

}
