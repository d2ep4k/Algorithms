# Algorithms

|INDEX|
| -------- | 
|[1. Manacher's algorithm](https://github.com/d2ep4k/Algorithms/blob/main/README.md#1-manachers-algorithm)|
|[2. Mo's algorithm](https://github.com/d2ep4k/Algorithms/tree/main#2-mos-algorithm)|
|[3. KMP algorithm](https://github.com/d2ep4k/Algorithms/tree/main#3-kmp-algorithm)|

## 1. Manacher's algorithm  
> **Manacher’s algorithm** is used to find the longest palindromic substring in a given string in linear time and was discovered by Glenn K. Manacher in 1975.

#### ALGORITHM :

- Preprocess the input text by adding special characters (such as "*") between each pair of characters in order to simplify the procedure. The above method allows us to deal with even and odd-length palindromes in the same way.

     *For example, string "abcba" becomes "\*a\*b\*c\*b\*a\*"*
  
- Create a list that has the same length as the modified string, with each entry representing the radius of the palindrome that has index i in the center. Additionally, in order to construct a bounding box or window for the longest local palindrome lately observed, we keep track of the bounding box with the use of two variables, 'mid' and 'right', which stand for the middle and rightmost boundary of the detected rightmost palindrome, respectively.

- Now loop over the altered string's position  by position. For each position, we determine the palindrome radius at that position using the following rules:
  1. We can use symmetry to compute  palindrome radius located within the bounding box. The radius at index  *(say 'i')* is equal to the radius at **((2*mid) - i)** if the mirrored point **((2*mid) - i)** is inside the known palindrome's perimeter. Otherwise, the rightmost border **(right - i)** restricts palindrome radius
  2. If i is outside the rightmost boundary 'right', we start a new palindrome centered at i and set palindrome radius at index i to 0.

*PALINDROMIC PROPERTY*
    ![Manacher0](./img/Manacher0.jpg)
    
- We maintain track of the rightmost palindrome boundary 'right' discovered thus far while updating the palindrome centers and radii. If a palindrome is found that goes beyond the existing 'right','mid' and 'right' are updated appropriately.

- To determine the largest palindrome radius, we visit the auxilary array. The characters centered at the place with the largest radius can be retrieved to yield the longest palindrome substring.

*PALINDROME MIRRORING*
    ![Manacher1](./img/Manacher1.jpg)
  
[reference | cp-algorithms.com](https://cp-algorithms.com/string/manacher.html)
<br>
[cpp code](https://github.com/d2ep4k/Algorithms/blob/main/Manacher's%20Algorithm.cpp)
<BR>

---

## 2. Mo's algorithm


---

## 3. KMP algorithm

> The **Knuth-Morris-Pratt algorithm**, also known as the KMP algorithm, is a string-searching algorithm that looks for instances of a "word" within a primary "text string" by making use of the observation that, in the event of a mismatch, the word itself contains enough information to determine where the next match could begin, avoiding the need to look again at previously matched characters, the time complexity of the overall algorithm is O(n + k), here n is length of "text string" and k is length of "word".

#### ALGORITHM :
The algorithm is similar to Automata theory, finite state automata pattern searching.

FSM pattern matching: 
![Patternmatching via FSM](./img/fsmPatternmatching.jpg)
> *DFA Graphical Representation*
> - *States are represented by the vertices*
> - *The transitions are displayed in the arcs with input alphabet labels*
> - *An empty single incoming arc indicates the beginning condition*
> - *Double circles denote the ultimate state*

The DFA mentioned above may be used to find the word "aab" in any text string comprised only of a's and b's. The idea is to move between different final and non-final states as the input is read character by character. Depending on the character encountered, different transitions are present, and the current state is stored in a variable. If we are able to get to the final stage, the text string is "accepted", meaning the word is present.

Componenets of KMP : 
1. Pre-computation(pi) :
    Pre-computation comprises LPS table construction, **LPS stands for the Longest proper prefix which is also a Suffix**. The construction of the LPS table is done in order to remove the partial matches from the table since if we continue to compute them, needless time and memory space will be consumed, slowing the process.

   LPS :
   LPS[i] stores the longest proper prefix, also a suffix for the substring ending at index i. A string's proper prefix is any other than the entire string itself.
   
   ![LPS](./img/LPS.jpeg)

When a match is made incorrectly, LPS evaluation enables us to move on to the following potential (partial) match because it stores the longest proper prefix, which is also the suffix ending at the current index 'i'. The repeated failure of prospective matching results in null LPS. 
   For example :
   seacrhing for "ababc" in "abababc"
   
 Precomputing "ababc" :

|  lps at\char        |a     |   b    |    a     |   b     |   c     |
|  ---------------    | ---  |   ---  |    ---   |   ---   |    ---  |
|    1                |$(0)  |        |          |         |         |
|    2                |      |$(0)    |          |         |         |         
|    3                |      |        |  a(1)    |         |         |        
|    4                |      |        |    a     |  b(2)   |         |            
|    5                |      |        |          |         |  $(0)   |         

LPS table :
|a     |   b    |    a     |   b     |   c     |
| ---  |   ---  |    ---   |   ---   |    ---  |
| 0    |    0   |     1    |    2    |    0    |
   
        
   
   
   
2. String matching :
     1.    (potential match at ind 0)
     
   |a  |  b  |  a  | b  |  a  |  b  |  c  |          
   | --- | ---  | ---  | ---  | --- | ---  | ---  |
   | = | =   | =   |  =  | != |     |     |
   | a |  b  |  a  |  b  | c  |     |     |
      
   3. a    b    a    b    a    b    c  
