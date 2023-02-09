Word Search Puzzle Solver
A program that solves word search puzzles by reading an nxn grid of letters from a file and a list of words from a dictionary file. The program outputs all the candidate words that can be found in the dictionary and located in the grid.

Input
An nxn grid of letters from a file.
A list of k words from a dictionary file.

Output
All candidate words that can be found in the dictionary and located in the grid.

Algorithm
The program employs an algorithm that efficiently searches for candidate words in the grid by exploring all possible combinations of letters starting from any letter, and reading in all eight possible directions (left, right, up, down, and along any of the four diagonals). The algorithm takes into account the edge case of wrapping around the edges of the grid. Words that are at least 5 characters long are considered candidate words.

Goal
The goal of the program is to find an algorithm that runs as quickly as possible for large n and k values. The program includes several sample word search puzzles for testing purposes.
