# Bonnie-and-clyde

Bonnie and Clyde have decided to meet at a restaurant to have Sushi. The city is given in the form of an undirected graph with nodes (numbered from ) and edges (without any parallel edges or self loops). Bonnie's house is located at node and Clyde's house is located at node . The famous restaurant Sushi Grand is located at node

.

Your task is to find out if Bonnie and Clyde can meet at Sushi Grand such that their path has no common node other than the destination

.

For example,
In the graph shown below, Bonnie's path goes from
and Clyde's path goes from

.

image

You have to answer
queries. In each query you will be given , and

. Find out if Bonnie and Clyde can meet at the Sushi Grand restaurant. If yes, print YES otherwise print NO.

Input Format

The first line contains three space separated integers
, and .
The next lines contain two space separated integers denoting that there exist an undirected edge in the graph between vertex and vertex .
The next lines describe the queries. Each line contains three space-separated integers , and

.

Constraints

Output Format

For each query, if there exists a pair of paths such that Bonnie and Clyde can meet at Sushi grand, then print YES otherwise, print NO.

Sample Input 0

4 4 3  
1 2  
2 3  
2 4  
3 1  
2 4 1
1 4 3
1 4 2  

Sample Output 0

NO
YES
YES

Explanation 0

The graph is shown in the image below.

image

    For the first query, 

, available paths for Clyde are and . Since both of them pass through node
where Bonnie is, We print NO.
For the second query,
, Of all the available paths, Clyde will follow path and Bonnie will follow path
. This is the only combination possible such that their paths do not have any node in common and hence we print YES.
For the third query,
, Clyde will follow path and Bonnie will follow path , as both of their paths don't share a common node, we print YES. 
