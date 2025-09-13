#[Subordinates](https://cses.fi/problemset/task/1674)

```
Time limit: 1.00 s
Memory limit: 512 MB

Given the structure of a company, your task is to calculate for each employee the number of their subordinates.

Input
The first input line has an integer n: the number of employees. The employees are numbered 1,2,...,n, and employee 1 is the general director of the company.
After this, there are n-1 integers: for each employee 2,3,...,n their direct boss in the company.

Output
Print n integers: for each employee 1,2,...,n the number of their subordinates.

Constraints
1 <= n <= 2.10^5

Example
Input:
5
1 1 2 3

Output:
4 1 1 0 0

```

5 employees:

		(1)   	-> boss
	(2)		(3)	-> 1	1
	(4)		(5)	-> 2	3	-> 1 1 2 3

1 - Build the company hierarchy (adjacency list).

2 - Run a DFS (depth-first search) from the general director (employee 1).

3 - For each node, the total number of subordinates = sum of all subordinates of its children + number of direct children.
