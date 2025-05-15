# 🔍 Assignment 1 — Maximum Spacing Clustering (TBO)

This repository contains the implementation of **Assignment 1** for the course **Search and Sorting Techniques (TBO)**, part of the Computer Science program at the **Federal University of Espírito Santo (UFES)**.

## 📌 Objective

The goal of this project is to implement the **maximum spacing clustering** algorithm using a **Minimum Spanning Tree (MST)**. The approach groups points in a multidimensional space into clusters such that the **minimum distance between points in different clusters is maximized**.

## 🧠 Summary of the Method

1. **Input**: A set of points in ℝ<sup>m</sup> and an integer `k`, representing the number of desired clusters.
2. **Distance Matrix**: Compute the Euclidean distances between all pairs of points.
3. **Minimum Spanning Tree**: Construct a weighted, undirected, complete graph using these distances, and compute its MST using **Kruskal's algorithm**.
4. **Clustering**: Remove the `k − 1` most expensive edges from the MST. The resulting `k` connected components are the output clusters.

## 📂 Input and Output Format

- **Input file**: A plain text file where each line represents a point, formatted as: identifier,coord1,coord2,...,coordN

- **Output file**: Each line contains the identifiers of one cluster, sorted lexicographically. Clusters are also sorted by their first element.

## ⚙️ Implementation Notes

- Language: C
- MST Algorithm: Kruskal's algorithm with disjoint-set (union-find) data structure
- Distances sorted using `qsort`
- Strict memory management verified with `valgrind`
- Follows the execution standard: `./trab1 input.txt k output.txt`


## 📊 Report

The assignment includes a written report analyzing:

- Implementation methodology
- Algorithmic complexity of each stage
- Empirical runtime analysis on provided test cases
- Percentage of time spent on each step: reading data, computing distances, sorting, generating the MST, identifying clusters, writing output

## 👨‍💻 Author

- **Name**: Matheus de Oliveira Lima
- **Course**: Computer Science
- **Institution**: Federal University of Espírito Santo (UFES)
- **Semester**: 2nd semester, 2022

---

_Project submitted as part of the TBO course requirements. Based on specifications provided by the instructor._
