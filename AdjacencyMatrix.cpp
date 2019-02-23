#include <iostream>
#include <fstream> //open text file
#include <vector> //best way to handle array in c++
#include <queue> //bfs queue
#include <cstring> //change string to char
//#include <chrono> //measure time taken

using namespace std;
void bfs(vector< vector<int> > adjMatrix, int st, int totalNode)
{
    //auto start = std::chrono::high_resolution_clock::now();
    bool visited[adjMatrix.size()] = {false}; //create array visited to mark visited nodes
    int val = 0;
    vector< vector<int> > bfsMatrix(totalNode, vector<int> (totalNode, val));
    queue<int> bfs;
    st = st - 1;
    visited[st] = true;
    bfs.push(st); //add visited nodes to end of queue

    while(bfs.empty() == false)
    {
        int currentVertex = bfs.front(); //set currentVertex to first node in queue
        bfs.pop(); //dequeue currentVertex from bfs queue

        for (int i = 0; i < adjMatrix[currentVertex].size(); i++)
        {
            int neighbor = i;
            int currentEdge = adjMatrix[currentVertex][i]; //see if there is edge between currentVertex and its neighbor

            if (currentEdge == 0){ //if no edge then do nothing
                    continue;}

            if (visited[neighbor] == false) //if `has edge and the node has not been visited, add the node to bfs queue
            {
                bfs.push(neighbor);
                bfsMatrix[currentVertex][i] = 1;
                visited[neighbor] = true;
            }
        }
    }
    //auto finish = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> elapsed = finish - start;

    int disp;
    cout << "Display BFS matrix? (1 for yes, 0 for no): ";
    cin >> disp;
    if (disp == 1)
    {
    cout << "   ";
    for (int i = 0; i < totalNode; i++)
    {
        cout << i+1 << "  ";
    }
    cout << endl;
    {
        for(int i = 0;i < totalNode; i++)
        {
            cout << i+1 << + "| ";
            for(int j = 0; j < totalNode; j++)
            cout << bfsMatrix[i][j] << "  ";
            cout << endl;
        }
    }
    }

    //cout << endl << "Time taken: " << elapsed.count() << " s\n";

}


int main(){

    string fileName, fileExt, sourceFile;
    cout << "Enter source file: ";
    cin >> fileName;
    fileExt = ".txt";
    sourceFile = fileName + fileExt;
    char source[sourceFile.size() +1];
    strcpy(source, sourceFile.c_str());
    ifstream file(source);
    int totalNode;
    file >> totalNode;
    int val = 0;
    vector< vector<int> > adjMatrix(totalNode, vector<int> (totalNode, val)); //initialize 2d array adjMatrix and set all value to 0

    int i, j;
    while (file >> i >> j) //change value of edge to 1
    {
        adjMatrix [i-1][j-1] = 1;
        adjMatrix [j-1][i-1] = 1;
    }
    int disp;
    cout << "Display adjacency matrix? (1 for yes, 0 for no): ";
    cin >> disp;
    if (disp == 1)
    {
        cout << "   ";
    for (int i = 0; i < totalNode; i++)
    {
        cout << i+1 << "  ";
    }
    cout << endl;
        for(int i = 0;i < totalNode; i++)
        {cout << i+1 << + "| ";
            for(int j = 0; j < totalNode; j++)
            cout << adjMatrix[i][j] << "  ";
            cout << endl;
        }
    }

    cout << endl << endl << "Breadth-First Search" << endl;
    int st;
    cout << "Enter starting point: ";
    cin >> st;
    bfs (adjMatrix, st, totalNode);
    cout << endl << endl;

    return 0;

}


