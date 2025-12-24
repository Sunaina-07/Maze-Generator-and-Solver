# Maze Generator and Solver in C

This is a C program that generates a random maze and solves it automatically. I created this for my first-semester Computer Science Engineering project.

## How it Works
1.  Generation: uses the Binary Tree Algorithm. It goes through the grid and randomly knocks down walls to ensure a path exists.
2.  Solving: uses Recursive Backtracking. It searches for a path from 'S' (Start) to 'E' (End). If it hits a dead end, it backtracks and tries a new direction.

## Features
*   Randomized Layout: The maze is different every time you run the program (seeded by time).
*   Key Characters:
    *   `#` = Wall
    *   `S` = Start Point
    *   `E` = End Point
    *   `.` = Solution Path
