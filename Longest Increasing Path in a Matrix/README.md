# [329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/) 

Given an ```m x n``` integers ```matrix```, return *the length of the longest increasing path in* ```matrix```.
From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** (i.e., wrap-around is not allowed).

## Example 1: 

<table>
  <tr>
    <td>9</td>
    <td>9</td>
    <td>4</td>
  </tr>
  <tr>
    <td>6</td>
    <td>6</td>
    <td>8</td>
  </tr>
  <tr>
    <td>2</td>
    <td>1</td>
    <td>1</td>
  </tr>
</table>

**Input:** row = matrix = [[9,9,4],[6,6,8],[2,1,1]]</br>
**Output:** 4</br>
**Explanation:** The longest increasing path is ```[1, 2, 6, 9]```.

## Example 2:

<table>
  <tr>
    <td>3</td>
    <td>4</td>
    <td>5</td>
  </tr>
  <tr>
    <td>3</td>
    <td>2</td>
    <td>6</td>
  </tr>
  <tr>
    <td>2</td>
    <td>2</td>
    <td>1</td>
  </tr>
</table>

**Input:** row = matrix = [[3,4,5],[3,2,6],[2,2,1]]</br>
**Output:** 4</br>
**Explanation:** The longest increasing path is ```[3, 4, 5, 6]```. Moving diagonally is not allowed.

## Example 3:

**Input:** matrix = [[1]]
**Output:** 1

## Constraints

- ```m == matrix.length```
- ```n == matrix[i].length```
- ```1 <= m, n <= 200```
- ```0 <= matrix[i][j] <= 231 - 1```

