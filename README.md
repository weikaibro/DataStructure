# NCKU_DataStructure_HW
A series of data structure assignments in College.

## hw1 _ Array and Insertion Sort

There are a total of n students in the class. Students in the same row belong to the same group. A drawing is held to determine which activity (a, b, c, d, or e) each group will participate in. The teacher wants to know how many students in each group are participating in activity c.

(1) Create a 2D array of size n x n (10 x 10 for example) based on the input number n (range is 10 to 20).

(2) In the 2D array, randomly generate one of the English letters a, b, c, d, or e in each position (i,j).

(3) Count how many c's there are in each column (row) and print out the number of c's in each column.

(4) Based on the number of c's, print out the index value of the Row from largest to smallest. If there are two or more index values with the same number of c's, print out the smaller index value first.

## hw2 _ Circular Linked list

At the beginning, a group of students (n, where n is a value between 4 and 10, for example 8) enter a game called "Blow Up the Miserable Ghost." The students, labeled A to H, form a circle as shown in the picture. The rules of the game are as follows:

(1) The first round starts with student A passing the bomb.

(2) In each round, the bomb is passed down to 0 to 3 students.

(3) After each round, there is a 0.4 probability that the bomb will explode, eliminating the student who received the bomb. If the bomb does not explode, the next round starts with the student who received the bomb.

(4) The game continues until there is only one student left, the winner.

## hw3 _ Binary Search Tree

HC Pizza is a chain of pizza restaurants located throughout Taiwan. The chairman, Mr. Wang, wants to know the profit status of 5 branches in each of the North, Central, and South regions for the current quarter. The accounting manager has been tasked with finding and reporting back the branch with the highest profit within two weeks. However, the accounting manager is very busy and has asked for help from the junior accountants. The task has the following requirements:

(1) The manager will provide a text file (profit.txt) that records the expenses and revenues of each branch. Using this data, calculate the profit for each branch.

(2) Use the profit values (profit = revenue - expenses, each node should record the branch name, revenue, and expenses) to create a Binary Search Tree (larger or equal profits should be placed on the right side). The inorder sorting result of this tree should be from small to large, and for profits with the same value there is no restriction on the order.

## hw4 _ Dijkstra’s Shortest Paths Algorithm

HC Pizza is a chain of pizza restaurants located throughout Taiwan. As Christmas approaches, HC Pizza has launched a promotion where customers will receive a toy with their pizza purchase. However, there is a limited number of toys available. The chairman, Mr. Wang, wants the store staff to recommend customers visit other branches once the toys run out. Therefore, the secretary has been asked to find the shortest path between branches.

![image](https://user-images.githubusercontent.com/75520777/211195206-7ffdb931-0a5f-4cf1-a764-b614afca462f.png)
