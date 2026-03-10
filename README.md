# CS50 Week 3 — Algorithms

This repository contains my solutions for *Problem Set 3* from Harvard's *CS50: Introduction to Computer Science*.

Week 3 focuses on understanding *algorithms*, especially sorting and election systems, while practicing problem solving using the C programming language.

Course: https://cs50.harvard.edu/x/psets/3/

---

## Exercises

### Sort
The objective of this exercise is to analyze the behavior of three unknown sorting programs (sort1, sort2, and sort3). By running each program with different datasets (random, sorted, and reversed numbers), we compare their execution times and determine which algorithm each program implements.

After testing and analyzing performance:

- *sort1 → Bubble Sort*
- *sort2 → Merge Sort*
- *sort3 → Selection Sort*

This exercise focuses on understanding how algorithm performance changes depending on input conditions and computational complexity.

Concepts practiced:
- Algorithm analysis
- Time complexity
- Experimental testing using execution time
- Understanding differences between O(n²) and O(n log n)

---

### Plurality
This program implements a *plurality voting system*, where each voter selects a single candidate. The candidate with the highest number of votes wins the election. If there is a tie, all candidates with the highest vote count are printed.

The program:
- Accepts candidate names through command-line arguments
- Records votes from voters
- Validates each vote
- Counts votes and determines the winner

Concepts practiced:
- Structures (struct)
- Arrays
- String comparison using strcmp
- Command-line arguments
- Loops and conditionals

Example execution:

./plurality Alice Bob Charlie
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice

Output:

Alice 
---

### Runoff
This program simulates an *instant-runoff election* (ranked-choice voting). Instead of selecting only one candidate, voters rank candidates by preference.

The algorithm works as follows:

1. Voters rank candidates in order of preference.
2. If a candidate receives more than *50% of the first-choice votes*, they win.
3. If no candidate reaches a majority, the candidate with the *fewest votes is eliminated*.
4. Votes are redistributed according to the next preference.
5. The process repeats until a winner is determined or a tie occurs.

Concepts practiced:
- Multi-dimensional arrays
- Election algorithms
- Candidate elimination logic
- Iterative vote redistribution

---

## Technologies Used

- C Programming Language
- CS50 Library
- GCC Compiler
- Linux / GitHub Codespaces
- Git & GitHub

---

## How to Compile and Run

Example for compiling and running a program:

make plurality
./plurality Alice Bob Charlie

---

## Key Learning Outcomes

This problem set helped reinforce fundamental computer science concepts such as:

- Algorithm efficiency
- Sorting algorithms
- Voting systems and decision algorithms
- Data structures in C
- Structured problem solving

---

## Course

Harvard University  
*CS50: Introduction to Computer Science*

https://cs50.harvard.edu/x/
