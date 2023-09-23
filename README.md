# Algorithms

|INDEX|
| -------- | 
|[1. Manacher's algorithm](https://github.com/d2ep4k/Algorithms/blob/main/README.md#1-manachers-algorithm)|
|[2. Mo's algorithm](https://github.com/d2ep4k/Algorithms/tree/main#2-mos-algorithm)|


## 1. Manacher's algorithm  
> Manacher’s algorithm is used to find the longest palindromic substring in a given string and was discovered by Glenn K. Manacher in 1975.

#### ALGORITHM :

- Preprocess the input text by adding special characters (such as "*") between each pair of characters in order to simplify the procedure. The above method allows us to deal with even and odd-length palindromes in the same way.

     *For example, string "abcba" becomes "\*a\*b\*c\*b\*a\*"*
  
- Create a list that has the same length as the modified string, with each entry representing the radius of the palindrome that has index i in the center. Additionally, in order to construct a bounding box or window for the longest local palindrome lately observed, we keep track of the bounding box with the use of two variables, 'mid' and 'right', which stand for the middle and rightmost boundary of the detected rightmost palindrome, respectively.

- Now loop over the altered string's position  by position. For each position, we determine the palindrome radius at that position using the following rules:
  1. We can use symmetry to compute  palindrome radius located within the bounding box. The radius at index  *(say 'i')* is equal to the radius at **((2*mid) - i)** if the mirrored point **((2*mid) - i)** is inside the known palindrome's perimeter. Otherwise, the rightmost border **(right - i)** restricts palindrome radius
  2. If i is outside the rightmost boundary 'right', we start a new palindrome centered at i and set palindrome radius at index i to 0.

*PALINDROMIC PROPERTY*
![Manacher0](https://github.com/d2ep4k/Algorithms/assets/143197927/a7d0455b-f9c3-405d-9c54-0608c29d5393)

- We maintain track of the rightmost palindrome boundary 'right' discovered thus far while updating the palindrome centers and radii. If a palindrome is found that goes beyond the existing 'right','mid' and 'right' are updated appropriately.

- To determine the largest palindrome radius, we visit the auxilary array. The characters centered at the place with the largest radius can be retrieved to yield the longest palindrome substring.

*PALINDROME MIRRORING*
  ![Manacher1](https://github.com/d2ep4k/Algorithms/assets/143197927/75d10e29-d62d-4728-b6e1-1a0070dd66fc)
  
[reference | cp-algorithms.com](https://cp-algorithms.com/string/manacher.html)
<br>
[cpp code](https://github.com/d2ep4k/Algorithms/blob/main/Manacher's%20Algorithm.cpp)
<BR>

---

## 2. Mo's algorithm
