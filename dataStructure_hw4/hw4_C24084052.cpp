#include <iostream>
#include <climits>
#include <fstream>
using namespace std;

int vertexNum = 8;

int miniDist(int distance[], bool Tset[]) {
  int minimum = INT_MAX;
  int U = 0;

  for (int k = 0; k < vertexNum; k++) {
    if (Tset[k] == false && distance[k] <= minimum) {
      minimum = distance[k];
      U = k;
    }
  }

  return U;
}

void printPath(int parent[], int j) {
  if (parent[j] == -1) return;   // case: if "j" is source

  printPath(parent, parent[j]);
  cout << " -> Shop" << j + 1;
}

void DijkstraAlgo(int graph[8][8], int start, int end) {
  int distance[8];  // array to calculate the minimum distance for each node
  bool Tset[8];   // boolean array to mark visited and unvisited for each node
  int parent[8];   // store the nodes which form a shortest path

  for (int k = 0; k < vertexNum; k++) {
    distance[k] = INT_MAX;
    Tset[k] = false;
    parent[start-1] = -1;  // source
  }

  distance[start-1] = 0;   // Source vertex distance is set 0

  for (int i = 0; i < vertexNum; i++) {
    int m = miniDist(distance, Tset);   // looking for the minimal distance and unvisited shop

    Tset[m] = true;
    for (int k = 0; k < vertexNum; k++) {
      int temporaryDist;
      temporaryDist = distance[m] + graph[m][k];

      // updating the distance of neighbor vertex
      if (!Tset[k] && graph[m][k] && distance[m] != INT_MAX && temporaryDist < distance[k]) {
        parent[k] = m;
        distance[k] = temporaryDist;
      }
    }
  }


  for (int i = 0; i < 8; i++) {
    if (end == i+1) {
      cout << "\n---------------------";
      cout << "\n\nShortest path to other shops recommended for you...";
      cout << "\n\nPath: Shop" << start;
      printPath(parent, i);
      cout << "\n\nBegin: Shop" << start;
      cout << "\n\nTarget: Shop" << end;
      cout << "\n\nDistance: " << distance[i] << endl;
    }
  }

}

int main() {
  ifstream in, inFile;
  ofstream out, outFile;
  int adjacencyMatrix[8][8], distanceMatrix[8][8];

  // adjacency_matrix.txt
  in.open("adjacency_matrix.txt");
  while(!in.eof()) {                                
    for(int i = 1; i <= 8; i++) {
      for(int j = 1; j <= 8; j++) {
        in >> adjacencyMatrix[i][j];
      }
    }
  }
  out.close();
  cout << "Adjacency matrix: ";
  for(int i = 1; i <= 8; i++) {
    cout << "\n";        
    for(int j = 1; j <= 8; j++) {
      cout << adjacencyMatrix[i][j] << " ";
    }
  }
  cout << "\n\nAdjacency list:";
  for (int i = 1; i <= 8; i++) {
    cout << "\n" << i;
    for(int j = 1; j <= 8; j++) {
      if (adjacencyMatrix[i][j] == 1) {
        cout << " -> " << j;
      }
    }
  }

  // distance_matrix.txt
  inFile.open("distance_matrix.txt");
  cout << "\n\n";
  while(!inFile.eof()) {
    for(int i = 1; i <= 8; i++) {
      for(int j = 1; j <= 8; j++) {
        inFile >> distanceMatrix[i][j];
      }
    }
  }
  cout << "Distance matrix: ";
  for(int i = 1; i <= 8; i++) {
    cout << "\n";
    for(int j = 1; j <= 8; j++) {
      cout << distanceMatrix[i][j] << " ";
    }
  }


  int startShop, endShop; 
  cout << "\n\nPlease input the start shop: ";
  cin >> startShop;
  cout << "\nPlease input the destinate shop: ";
  cin >> endShop;

  int graph[8][8] = {
    {0, 8, 0, 0, 3, 0, 0, 0},
    {0, 0, 0, 7, 0, 4, 0, 0},
    {5, 6, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 6, 0},
    {0, 0, 0, 0, 0, 0, 7, 8},
    {0, 0, 0, 0, 2, 0, 0, 7},
    {0, 6, 0, 0, 0, 0, 0, 9},
    {0, 0, 2, 3, 0, 0, 0, 0}
  };
  DijkstraAlgo(graph, startShop, endShop); 

  return 0;

}