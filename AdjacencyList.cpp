#include <iostream>
#include <fstream> //open text file
#include <vector> //best way to handle array in c++
#include <queue> //bfs queue
#include <algorithm> //sort & delete duplicate edges
#include <cstring> //change string to char
//#include <chrono> //measure time taken

using namespace std;
void bfs(vector<int> adjList[], int st, int totalNode)
{
    //auto start = std::chrono::high_resolution_clock::now();
    int n = totalNode;
    bool visited[n] = {false}; //create array visited of type bool to record visited nodes
    int val = 0;
    vector< vector<int> > bfsMatrix(totalNode, vector<int> (totalNode, val));
    queue<int> bfs; //initialize bfs queue
    st = st - 1;
    visited[st] = true;
    bfs.push(st); //add visited nodes to end of queue

    while(bfs.empty() == false)
    {
        int currentVertex = bfs.front(); //set currentVertex to first node in queue
        bfs.pop(); //dequeue currentVertex from bfs queue

        int x = 0; //to loop index of list one by one
        for (vector<int>::iterator it = adjList[currentVertex].begin(); it != adjList[currentVertex].end(); ++it) //iterate list owned by currentVertex
        {

            int neighbor = adjList[currentVertex].at(x); //set nodes at location x of list currentVertex as neighbor
            neighbor = neighbor-1;


            if (visited[neighbor] == false) //visit neighbor if it has not been visited
            {

                bfs.push(neighbor);
                bfsMatrix[currentVertex][neighbor] = 1;
                visited[neighbor] = true;

            }
            x++;
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
    //cout << endl << "Elapsed time: " << elapsed.count() << " s\n";

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
    vector<int> adjList[totalNode]; //create array adjList of type vector integer (list)

    int i, j;
    while (file >> i >> j) //add connection between node with edges, push node to end of list
    {
        adjList[i-1].push_back(j);
        adjList[j-1].push_back(i);
    }

    for (int i = 0; i < totalNode; i++) //sort content of adjList, then delete duplicate edges (this is caused by our graph dataset)
    {
        sort(adjList[i].begin(), adjList[i].end());
        adjList[i].erase(unique(adjList[i].begin(), adjList[i].end()), adjList[i].end());
    }
    int disp;
    cout << "Display adjacency list? (1 for yes, 0 for no): ";
    cin >> disp;
    if (disp == 1)
    {
    for (int i = 0; i < totalNode; i++){
        cout << i+1;
        vector <int>::iterator iter = adjList[i].begin();
        while (iter != adjList[i].end())
        {
            cout << " -> " << *iter;
            iter++;
        }
        cout << endl;
    }
    }
    cout << endl << endl << "Breadth-First Search" << endl;
    int st;
    cout << "Enter starting point: ";
    cin >> st;
    bfs (adjList, st, totalNode);
    cout << endl << endl;
}

