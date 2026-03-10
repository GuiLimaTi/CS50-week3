# CS50 – Week 3: Algorithms

This repository contains my work from *Week 3 of Harvard's CS50: Introduction to Computer Science*.

Week 3 focuses on *algorithms, particularly **sorting algorithms* and how to analyze their performance using time complexity and experimental testing.

## Topics Covered

- Algorithms
- Sorting algorithms
- Time complexity
- Performance analysis
- Empirical testing using the time command

## Problem: Sort

In this problem, three unknown sorting programs (sort1, sort2, and sort3) were tested using different datasets:

- Random numbers
- Already sorted numbers
- Reverse sorted numbers

By measuring the execution time of each program, it was possible to determine which algorithm each program uses.

## Results

| Program | Algorithm Identified |
|--------|---------------------|
| sort1 | Bubble Sort |
| sort2 | Merge Sort |
| sort3 | Selection Sort |

## Explanation

### sort1
sort1 runs much faster when the input is already sorted. This behavior is characteristic of *Bubble Sort*, which can terminate early when no swaps are needed.

### sort2
sort2 shows almost identical running times regardless of whether the input is random, sorted, or reversed. This is typical of *Merge Sort, which has a time complexity of **O(n log n)*.

### sort3
sort3 takes roughly the same amount of time for all input orders. This matches the behavior of *Selection Sort, which always performs the same number of comparisons (O(n²)*).

## Tools Used

- CS50 Codespaces
- C programming language
- Linux terminal
- Git & GitHub

## Course

Harvard University – *CS50: Introduction to Computer Science*

https://cs50.harvard.edu/x/
