# 8-Puzzle Problem – AI Search Algorithms

## 📌 Project Overview
This project focuses on solving the 8-Puzzle Problem, which is a classic problem in Artificial Intelligence.  
The goal is to reach a predefined target state from an initial state by moving tiles using valid operations.

The project demonstrates and compares three search algorithms:
- Depth First Search (DFS)
- Breadth First Search (BFS)
- A* Search Algorithm

---

## 👥 Team Members
- Youssef Mamdouh – Implemented the solution using DFS
- Ahmed Wael – Implemented the solution using BFS
- Abdullah Hany – Implemented the solution using A\*

---

## 🧩 Problem Description
The 8-Puzzle Problem consists of a 3×3 grid containing eight numbered tiles and one empty space (represented by 0).  
Tiles can be moved into the empty space to generate new states.

The objective is to transform the initial configuration into the goal configuration using the minimum number of moves.

---

## 🧠 Problem Representation
- The puzzle is represented as a one-dimensional vector of size 9.
- Each state represents a possible configuration of the puzzle.
- The empty tile (0) determines the possible next moves.

---

## ⚙️ Algorithms Used

### 1️⃣ Depth First Search (DFS)
DFS explores one path deeply before backtracking.

Advantages:
- Low memory usage
- Simple implementation

Disadvantages:
- Does not guarantee optimal solution
- May explore unnecessary deep paths

---

### 2️⃣ Breadth First Search (BFS)
BFS explores all states level by level.

Advantages:
- Guarantees the shortest solution
- Complete algorithm

Disadvantages:
- High memory consumption
- Slower for large state spaces

---

### 3️⃣ A* Search Algorithm
A* uses a heuristic function combined with path cost to guide the search efficiently.

Advantages:
- Optimal and complete
- Faster than DFS and BFS
- Reduces unnecessary state exploration

Disadvantages:
- Higher memory usage
- Depends on heuristic quality

---

## ⏱ Execution Time Results
The execution time of each algorithm was measured and compared.

- DFS: Fast in some cases but unreliable for optimal paths
- BFS: Consistent but slower due to large memory usage
- A\*: Best performance due to heuristic guidance

---

## 📊 Comparison Summary

| Algorithm | Optimal | Memory Usage | Execution Time |
|---------|--------|--------------|----------------|
| DFS     | No     | Low          | Medium         |
| BFS     | Yes    | High         | Slow           |
| A\*     | Yes    | Medium       | Fast           |

---

## ⭐ Why A* Is the Best
A* provides the most efficient solution for the 8-Puzzle Problem because it combines:
- Actual path cost
- Heuristic estimation

This allows it to reach the goal faster while maintaining optimality.

---

## 🙏 Acknowledgment
Thank you for reviewing this project.