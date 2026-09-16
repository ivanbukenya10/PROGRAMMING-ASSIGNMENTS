Exam Grading Program — Explained

This program grades multiple-choice exams for a class of students by comparing each student's answers against an answer key.

Overview

The program:
1. Stores each student's answers to 10 questions
2. Stores the correct answer key
3. Compares each student's answers to the key
4. Prints how many questions each student got right

Code Walkthrough
1. Setup

const int NUM_STUDENTS = 8;
const int NUM_QUESTIONS = 10;

Two constants define the size of the data: 8 students, 10 questions each. Using named constants (instead of writing '8' and '10' everywhere) makes the code easier to read and update — if you added a 9th student, you'd only change NUM_STUDENTS.

2. The answers array

char answers[NUM_STUDENTS][NUM_QUESTIONS] = { ... };

This is a 2D array — think of it as a grid with 8 rows (one per student) and 10 columns (one per question). Each cell holds a single character ('A' through 'E') representing that student's chosen answer.

answers[3][5] would give you Student 3's answer to Question 5.

3. The answer key

char key[NUM_QUESTIONS] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

This is a 1D array (a single row) of 10 correct answers — one per question, used as the standard every student is compared against.

4. Grading loop (the core logic)
- Outer loop('student'): walks through each of the 8 students, one at a time.
- Inner loop ('question'): for the current student, walks through all 10 questions.
- Comparison: for each question, it checks whether that student's answer ('answers[student][question]') matches the correct answer ('key[question]').
- Counting: 'correctCount' starts at 0 for each student and increases by 1 every time there's a match.
- Output: once the inner loop finishes checking all 10 questions, the student's total is printed, and the outer loop moves to the next student (resetting 'correctCount' to 0 again).

Why nested loops?
Because the data is two-dimensional (students × questions), you need one loop to move down through students and a second loop to move across each student's answers. This "loop inside a loop" pattern is one of the most common structures for processing grids/tables of data.

Key Concepts Used

- 2D arrays— storing tabular data (rows × columns)
- Constants— avoiding "magic numbers" and making code easier to maintain
- Nested for-loops— iterating over two dimensions of data
- Accumulator variable (correctCount) — a variable that builds up a running total inside a loop
