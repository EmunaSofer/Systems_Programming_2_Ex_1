# Graph and Algorithms Project

## Overview
This project implements an undirected graph data structure and performs several basic algorithms on it, including searches (BFS, DFS), shortest path calculations (Dijkstra), and minimum spanning tree calculations (Prim, Kruskal). These algorithms are implemented on a disconnected graph without the use of pre-existing data structures (such as queues, stacks, or vectors from the STL).

The graph is represented by the `Graph` class, and the algorithms are implemented in the `Algorithms` class. Each function is accompanied by unit tests to ensure they work as expected.

## Requirements
Before running the project, ensure that your system has the following tools:
- C++11 or later
- g++ (C++ compiler)

## File Structure
The project is divided into several files:
1. **Graph.cpp** - Implementation of the `Graph` class representing the graph and performing operations on it.
2. **Algorithms.cpp** - Implementation of the `Algorithms` class that performs various algorithms on the graph.
3. **Point.cpp** - Implementation of the `Point` class (if needed).
4. **Queue.cpp** - Basic implementation of a queue (if needed).
5. **QueueNode.cpp** - Implementation of the `QueueNode` class (if needed).
6. **test_algorithms.cpp** - The test file that runs unit tests using the `doctest` library.
7. **main.cpp** - The main demonstration file showcasing how to use the classes and algorithms.
8. **Makefile** - The file used to build and run the project with different commands (build, test, valgrind).

## Running the Project
After downloading all the files, run the following commands in your terminal:

1. **Build the main executable**:
   make main

2. **Run unit tests:**
  make test

3. **Check for memory leaks with Valgrind:**
  make valgrind

4. **Clean up unnecessary files:**
  make clean


Explanation of Functions
Graph Class
The Graph class represents an undirected graph. It contains the following functions:

**addEdge(int src, int dest, int weight=1):**
Adds an edge between the vertices src and dest with an optional weight (default is 1).

**removeEdge(int src, int dest):**
Removes an edge between the vertices src and dest. If the edge does not exist, an exception is thrown.

**print_graph():**
Prints the graph in a user-defined format (output depends on the implementation).

Algorithms Class
The Algorithms class contains the following functions:

**bfs(Graph& graph, int start):**
Performs a BFS traversal on the graph and returns a rooted tree (a new graph representing the tree).

**dfs(Graph& graph, int start):**
Performs a DFS traversal on the graph and returns a tree or forest (depending on the graph structure).

**dijkstra(Graph& graph, int start):**
Computes the shortest paths using Dijkstra’s algorithm and returns a tree of paths.

**prim(Graph& graph):**
Computes the minimum spanning tree using Prim's algorithm and returns the graph representing the tree.

**kruskal(Graph& graph):**
Computes the minimum spanning tree using Kruskal's algorithm and returns the graph representing the tree.

Unit Tests
Unit tests are written using the doctest library to validate the functions in the project. Each function is tested with various inputs to ensure the correct output is generated.

Example Test
The unit tests generate a sample graph and produce the following output:
Vertex 0: 0 -> 1 -> 4 -> NULL
Vertex 1: 1 -> 0 -> 2 -> 3 -> NULL
Vertex 2: 2 -> 1 -> NULL
Vertex 3: 3 -> 1 -> NULL
Vertex 4: 4 -> 0 -> NULL
