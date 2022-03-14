# vg101: Introduction to Computer Programming 

## RC 1

*CHEN Xiwen*

*2019/5/20*

### Outline

* Lectures
  * Computer basics
  * Program design
  * Learning a programming language
    * Data
    * Operations (indexing, calculations, etc.)
      * Visualization
    * I/O
  * MATLAB
* Practice

### Lectures

#### Computer Basics

1. Number system.

   | Number System |            Description             |
   | :-----------: | :--------------------------------: |
   |    Binary     |     base 2, digits used: 0, 1      |
   |     Octal     |     base 8, digits used: 0 ~ 7     |
   |  Hexadecimal  | base 16, digits used: 0 ~ 9, A ~ F |

2. Base conversion.

   - Convert base  $m$ to base  $n$:

   $$
   N = m_1\times m^{l_m-1} + m_2\times m^{l_m-2} + \cdots + m_{l_m} \\
   l_n = \lceil \log_n(N + 1)\rceil \\
   n_k = \left\lfloor\frac{N}{n^{l_n - k}}\right\rfloor\mod n, \qquad \mathrm{for}\ k = 1, \ldots, l_n
   $$

   - Examples:

     - Convert $(100011)_2$ from binary to hexadecimal.
       $$
       N = 1\times 2^5 + 0\times 2^4 + 0\times 2^3 + 0\times 2^2 + 1\times 2^1 + 1 = 35 \\
       l_n = \lceil \log_{16}(36)\rceil = 2 \\
       n_1 = \left\lfloor \frac{35}{16}\right\rfloor \mod 16 = 2, \qquad n_2 = 35\mod 16 = 3\\
       $$
       Therefore, $(100011)_2 = (23)_{16}$.

     - Convert $5F3EC6$ from hexadecimal to binary.
       $$
       (5F3EC6)_{16} = (0101\ 1111\ 0011\ 1110\ 1100\ 0110)_2
       $$
3. Algorithm.

   ```
   IN: input of the algorithm
   OUT: output of the algorithm
   RECIPE: what the algorithm computes to obtain the output
   COMPLEXITY: in terms of space/time consumption
   ```

#### Program Design

> 1. Clearly state or translate the problem.
> 2. Define what is know as the *input*.
> 3. Define what is know as the *output*.
> 4. Develop an *algorithm*, i.e., a systematic way to solve the problem.
> 5. Verify the solution on simple input.
> 6. Implementing the algorithm.

#### Learning a Programming Language

***READ-THE-DOC!***

* What can we learn from a documentation?
  1. Data type (integers, double, arrays, chars, etc.) and operations.
  2. Functional APIs (input, output, options) and descriptions.

* API (application programming interface)

  ```
  output = funcName(arg1, arg2, ..., options)
  	arg1: description of arg1
  	arg2: description of arg2
  	...
  	options: available options for the function
  ```

#### MATLAB Inerface

* Modes:

  * Desktop: graphical interface

    1. Current folder: *default file I/O path, available functions*.
    2. Workspace: *current variables and their values*.
    3. Command window: *View immediate results*.
    4. Editor: *edit scripts*.

  * Terminal

    1. Start MATLAB from terminal:  `$./matlab -nodesktop -nosplash`

       ![](.\images\1.png)

       Other options:

       ```bash
   matlab [-h|-help] | [-n | -e]
              [-arch | v=variant | v=arch/variant]
          [-c licensefile] [-display Xdisplay | -nodisplay]
              [-nosplash] [-mwvisual visualid] 
              [-debug] [-softwareopengl]
              [-desktop | -nodesktop | -nojvm]
              [-r MATLAB_command] [-logfile log]
              [-Ddebugger [options]]
       ```
    
       
    
    2. Exit MATLAB from terminal: `>> exit`
    
    3. Run MATLAB scripts in terminal mode: `run('path-to-script/file.m')`, or with error handling: `try, run('path-to-script/file.m'), catch e, fprintf('%s\n', e.message), end`
    
    4. To use a MATLAB function that we write: 
    
       1. Add path: `addpath(path-to-function)`
       2. Use function as in command window in desktop mode: `function(args)`
    
    5. View the current folder: `pwd`
    
    6. Change current folder: `cd path-to-folder` 
    
    7. View all files with `.m` extension: `dir path-to-folder`
    
    8. **NOTE: be cautious with your naming of the file.**
  
* Command window:

  - Clear command history: `clc`
  - View command history: $\uparrow$
  - Clear a certain variable in workspace: `clear varName`
  - Clear all variables in workspace: `clearvars`
  - Query the existence of a variable or a file: `exist varName/fileName`

* Workspace:

  - Access current variable value from command window: `varName` 
  - Current variables are not cleared when starting running a script: **avoid variable conflicts by clearing the workspace in the first line of the script**
  - Save variables in current workspace to `fileName.mat` or load variables from `fileName.mat` to workspace: `save fileName` and `load fileName`

* Editor:

  - Place to define your functions and write your scripts.
  - If the `.m` file is a function definition, the name should be consistent with the function name (e.g., `function myFunc(n)` is defined in `myFunc.m`), one main function definition per file, but  a file can contain sub-functions that are only accessible inside the file.
  - Function vs. script: 
    - Function: with API (inputs, outputs), can be called within another script or function.
    - Script: a series of tasks, with possible function calls.

  * Printed results from running the script will be shown in the command window: variable assignment that ends with `;` will not print the value in the command window. **(Please end with a `;` for every unnecessary output.)**

* Help and documentation:
  * Directly search using keywords.
  * In the command window: `help funcName` or `doc keyWord`

* Debugging: *add breakpoints (basics)* or `disp`
  1. Add a breakpoint by clicking the dash beside a line number.
  2. Run the script.
  3. The process will stop at the breakpoint, you can view the intermediate values for variables in the workspace.
  4. Continue running the script.

#### Scripting in MATLAB

* Coding style

  * Use `Tab` or `Space` to improve readability.

  * End with `;` to suppress unnecessary outputs and begin the following lines with a new line.

  * Space after operators, e.g., `a = 2;`  instead of `a=2`.

  * Space after a `,` or `;`, e.g., `A = [1, 2; 3, 4]` instead of `A = [1,2;3,4]`.

  * Use `...` for continuation in the next line, e.g., 

    ```matlab
    if ((a == 2 && b < 3) || (a == 3 && b > 5) ...
    			|| a == 4)
    ```

  * You might want to **properly** align for variable assignments, e.g.,

    ```matlab
    myArray = [1, 2, 3];
    myInt   = 7;
    ```

  * Use `%` for comment.

  * Variable/function names: *begin with a character, case sensitive*.

    1. Use meaningful names: `publicKey` or `public_key`, `getVerifyData()` or `get_verify_data()` for functions.
    2. Avoid built-in names (variables that already have meanings, e.g., `ans`) in some situations.

* Variable types

  1. Numeric types: `double`(default), `single`, `uint8`, `uint16`, `uint32`, `uint64`, `int8`, `int16`, `int32`, `int64`

  2. Characters: `char`(use ASCII code: `char(65) = 'A'`, `char('A' + 1) = 'B')`, 

     ![](.\images\2.png)

  3. Strings: `string` `<demoStr.m>`

     1. `strcmp(s1, s2)`: compare `s1` and `s2`
     2. `strrep(str, old, new)`: replace `old` substring with `new`
     3. `strfind(str, subStr)`: return the index of the `subStr` in `str`
     4. `strcat(s1, ..., sN)`: concatenate strings

  4. Logical: **in case of integers, only `0` evaluates to `False`, e.g.**

     ```matlab
     % a = 4;
     if -2
     	a = 4;
     else
     	a = 3;
     end
     ```

     ```matlab
     % a = 3;
     if 0
     	a = 4;
     else
     	a = 3;
     end
     ```

  5. Arrays & matrices

     - Initialization:
       1. `A = [1, 2, 3; 4, 5, 6; 7, 8, 9];`
       2. `A = [1:4];`, with default step 1, same as `A = [1, 2, 3, 4];`
       3. `A = [1:3:7];`, with step 3, same as `A  = [1, 4, 7];`
       4. `A = linspace(start, end, num);`
       5. `A = zeros(col, row);`
       6. `A = ones(col, row);`
       7. `A = magic(n);`: $n\times n$ magic matrix

     * Indexing:

       1. `A(k)`, `A(r, c)`, **starting from 1** 

          (**Q**: what does `A(n + 3)` return when `A` is an $n\times n$ matrix?)

       2. `A(r, :)`, access a row; `A(:, c)`, access a column.

       3. `A(r1:r2, :)`, access `r1` to `r2` inclusive; `A(:, c1:c2)`, access `c1` to `c2` inclusive.

          (**Q**: How about `A(r1:r2, c1:c2)`?)

       4. Block assignment: 

          ```matlab
          A = magic(4);
          B = magic(2);
          A(2:3, 2:3) = B;
          ```

       5. Exchange rows/columns: `A([r1, r2], :) = A([r2, r1], :)`/`A(:, [c1, c2]) = A(:, [c2, c1])`

       6. `A(:)`, access all elements in matrix `A` as an array (column-first).

     * Operations:

        1. Element-wise addition: `A + B` (`A` and `B` should have a consistent dimension.)

        2. Element-wise multiplication: `A .* B`

        3. Matrix multiplication: `A * B`

        4. Element-wise division: `A ./ B`(`A` and `B` should have a consistent dimension)

        5. Concatenation: `[A, B]`(`A` and `B` should have a consistent row dimension), `[A; B]`(`A` and `B` should have a consistent column dimension.)

           (**Q**: What does `A = [1:4]; A = [0, A];` do?)

        6. Reshape:

           ```matlab
           A = [1:30];
           A = reshape(A, 5, 6);
           ```

        7. Transpose, inverse, eigenvalues, determinant: `A'`, `inv(A)`, `eig(A)`, `det(A)`

        8. Flip up and down, left and right: `flipud(A)`, `fliplr(A)`

        9. Number of array elements: `numel(A)`

        10. Sum and mean:

             	1. `sum(A, 1)`/`mean(A, 1)`: sum up/average all rows of the columns
             	2. `sum(A, 2)`/`mean(A, 2)`: sum up/average all columns of the rows
             	3. `sum(A(:))`/`mean(A(:))`: sum up/average all elements in `A`

  6. Type conversion: `newVar = type(var)`, e.g., 

     ```matlab
     a = 1.2; % double, 1.2000;
     a = int8(a); % a = 1, unsigned integer;
     ```

* Control flow

  1. `if-else`

     ```matlab
     if expression1
     	statements1
     elseif expression2
     	statements2
     else
     	statements3
     end
     ```

  2. `switch-case`

     ```matlab
     switch variable
     	case value1
     		statements1
     	case value2
     		statements2
     	otherwise
     		statements3
     end
     ```

  3. `while`

     ```matlab
     while expression
     	statements
     end
     ```

  4. `for`

     ```matlab
     for i = start:increment:end
     	statements
     end
     ```

  5. `break` and `continue` 

     `break`: jump out of the current loop

     `continue`: jump to the next iteration in the current loop

     **Q**: What is the value of `A` in the following two cases? `<demoBreak.m, demoCont.m>`

     ```matlab
     A = zeros(10);
     for i = 1:10
     	for j = 1:10
     		if i == 2 && j == 4
     			break;
     		end
     		A(i, j) = 1;
     	end
     end
     ```

     ```matlab
     A = zeros(10);
     for i = 1:10
     	for j = 1:10
     		if i == 3 && j == 4
     			continue;
     		end
     		A(i, j) = 1;
     	end
     end
     ```

* Logical mask: accessing elements using logical array.

  e.g., define step functions: `<demoLogicalMask.m>`
  
  ```matlab
  f = @(x) (x < 0) .* x + (x >= 0) .* (x.^2);
  a = linspace(-1, 1, 50);
  plot(a, f(a));
  ```
  
  e.g., homework 1 ex7.1 (not optimal)
  
* Function definitions: *inputs, outputs, operations*

  ```matlab
  % myFunc.m file;
  function [out1, out2, '...'] = myFunc(in1, in2, '...')
  
  	% operations defined here;
  	% ...
  	out1 = subFunc(in1); % all the output values should be defined;
  	% ...
  	out2 = subFunc(in2); % all the output values should be defined;
  	% ...
  
  function out = subFunc(in)
  	out = %...;
  ```

* Function handles:

  1. Usage: `<demoFuncHandle.m, myLess.m, mySort.m, mainFuncTools>`

     > 1. pass a function to another function.
     > 2. specify call back functions.
     > 3. construct handles to functions defined inline instead of stored in a program file.
     > 4. call local functions from outside the main function.

  2. Defining a function handle:

     1. `f = @(x) x.^2 + 1;`

     2. Via an existing function: `f = @computeSquare`, where

        ```matlab
        function y = computeSquare(x)
        	y = x.^2;
        ```
     
  3. Call function: `f(args)`

### General Coding Suggestions

1. Write more functions to avoid copying code.
2. Think more before you start.
3. Never be lazy with looking back to requirements.
4. Improve algorithms.

**Q: Implement the modified Newton's method in MATLAB based on the following algorithm, and use the algorithm to find a root of the following function with accuracy 0.000001.**
$$
f(x) = x^5 - 11x^4 + 46x^3 - 90x^2 + 81x - 27.
$$

```
Input: a function f, accuracy e
Output: a root x such that f(x) = 0
------------------------------------------------------------------
calculate the derivative of f as df;
choose an initial value x0;
while |f(x)| > e do
	update x as x(k + 1) = x(k) - f(x(k)) / df(x(k));
end
return last updated x;
```

Things to consider when implementing the algorithm: `<demoNewton.m, newtonsMethod.m>`

* How to find the derivative of $f$ in MATLAB?
* How to pass function $f$ as an argument?
* How to choose the initial value?
* What might go wrong with division? How to handle this error in MATLAB? (Note that Newton's method does not guarantee a solution if the initial value is not chosen properly.)
* How to update $x$? Store all intermediate $x$, or just successive two of them?

### Practices

***1. Where is Waldorf?***

Write a function that reads from a file `input.txt`. The first line of the file indicates the number of rows $r$ and columns $c$ in the following matrix of letters, separated by a space. The following $r$ lines of the file content is a $r\times c$ matrix of letters. Then the next line includes the number of words $w$ in the rest of the file, followed by $w$ words that need to be found. For instance, a sample input file might look like the following:

> `input.txt`
>
> ```
> 8 11
> a b c D E F G h i g g
> h E b k W a l D o r f
> F t y A w a l d O R k
> F t s i m r L q s r c
> b y o A r B e D e y v
> K l c b q w i k o m k
> s t r E B G a d h r b
> y U i q l x c n B j f
> 4
> Waldorf
> Bambi
> Betty
> Dagbert
> ```

Then the function finds the position of the first letter of a word in the form of `(r, c)` that is found in the matrix. The word can be in horizontal, vertical and diagonal in both directions (left and right), case insensitive. Output the results in the file `output.txt` in the format of `[word] is located at (r, c) in the [direction] direction ` (direction: `right/left/up/down/up right/up left/down right/down left`), line separated. For instance, the output of the input file above should be the following:

> `output.txt`
>
> ```
> Waldorf is located at (2, 5) in the right direction
> Bambi is located at (2, 3) in the down right direction
> Betty is located at (1, 2) in the down direction
> Dagbert is located at (7, 8) in the left direction
> ```

For simplicity, the word in the input file is guaranteed to appear at least once in the matrix, and you only need to find one of the locations if multiple solutions possible.

***2. Minesweeper.***

Write a function `myMinesweeper(r, c)` which takes the number of rows $r > 3$ and columns $c > 3$ as inputs, and randomly generate a $r\times c$ truth board, with $0$ indicating safe position, and $1$ indicating a mine in that position, with a total of $n$ mines. To decide whether a position has a mine, generate a random number from standard normal distribution and set a mine if the number is greater than $0$. Start from an empty board containing only $0$s. Then until the user wins (with all mines identified without touching them) or loses (touched a mine), the user is prompted to input two numbers `[r, c]` indicating a guess (comma separated, bracket enclosed). The the number in the position is updated with the number of mines within a $3\times 3$ grid centered at the guessed location. If the game ends, the user should be prompted with either `Congratulations, you win!`, or `Sorry, you lose!`. For each intermediate round, the updated board should be printed in the command window.

### JOJ

#### Submission Guidelines

Refer to Announcements on Canvas.

#### Common Errors

1. File naming.

   > Compile Error
   >
   > cp: cannot stat '/in/ex2.m': No such file or directory

2. No error reporting when the `.tar` file contains unnecessary files. But it is not allowed in homework submissions.

3. The answer is not correct. 

   > Wrong Answer
   * Check your output, especially the format (`\n`, `space`, etc.) or unnecessary outputs.
   * If you use a wrong command, or a command that will lead to MATLAB error message, the error message will also be printed to `std`, which is considered as an output in JOJ. (e.g., initializing with `A = zeros(100000000)​`.)

4. The script might contain infinite loop.

   > Time Exceeded