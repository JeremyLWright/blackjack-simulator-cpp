\page syllabus Syllabus

Instructor: [Jeremy Wright](mailto:jeremy.wright@asu.edu)

Lecture: Wednesday 6:00 - 6:50 in BYAC 260

------------------------------------------------------------------------------

Course Description
------------------
The C++ Programming Practicum is an opportunity for students to expand on their programming skills from CSE240, and CSE 220.  We will focus in using tools such as GDB, and Valgrind to improve the quality of our code.  A big emphasis will be placed on unit testing and Test-Driven Design.  

ASU has been generous enough to update all compilers and system tools on general.asu.edu. The full power of C++11, is now at our fingertips, and we’ll be leveraging much of the new standard to improve code quality, and performance especially for the programming projects of CSE310, and other upper-division projects. 

C++ is a vast and powerful language. Through various projects we will leverage specific features of the language. This class is an opportunity to learn the powerful features of C++, which has made it the industry leading language it is today. 

Evaluation Procedure
--------------------
| Metric | Weight |
| ------ | ------ |
| Programming Projects | 85% |
| In-class Quizzes	 | 15%	(3 quizzes of equal weight) |

Each project will be graded using automated unit-tests. Projects will be graded within 1 week of submission.
Quizzes will be submitted on blackboard and must be completed on-time to receive a grade. No late quizzes will be accepted. Quizzes are open-book, and open-internet. However, quizzes should be completed individually.

| Grade | Range |
|-------|-------|
|A	| (100% - 90%] |
|B	| (90% - 80%] |
|C	| (80% - 70%] |
|D	| (70% - 60%] |
|E	| < 60% |

Quizzes are intended to expose the student to student to topics and vernacular prevalent in industry.
End of Semester Survey is graded on participation only. Student names are separated from the data.
Grade disputes must be submitted in writing within 3 days of grade posting. Requesting a regrade will result in the entire item being regraded. The student has the potential to lose more points during this process.

Course Topics
-------------

| Date       | Lecture Topic                                         | Assignment Due  |
| ---------- | -----------------------------------------------       | --------------- |
| 8/28/2013  | Version Control with Mercurial                        |                 |
| 9/4/2013   | Unit Testing with GTest                               | [Project #1](@ref assign1)      |
| 9/11/2013  | Pointer Review                                        |                 |
| 9/18/2013  | Anatomy of the C++ Class                              | [Project #2](@ref assign2)      |
| 9/25/2013  | Polymorphism Part 1                                   |                 |
| 10/2/2013  | Polymorphism Part 2                                   | [Project #3](@ref assign3)      |
| 10/9/2013  | Introduction to Error Handling                        |                 |
| 10/23/2013 | Exceptions in C++                                     | [Project #4](@ref assign4)      |
| 10/30/2013 | Guest Lecture Comprehensive Error Handling            |                 |
| 11/6/2013  | Compile-Time Polymorphism                             | [Project #5](@ref assign5)      |
| 11/13/2013 | C++ Idioms (Design Patterns Part 1)                   |                 |
| 11/20/2013 | Anderson Smart Pointer Idiom (Design Patterns Part 2) | [Project #6](@ref assign6)      |
| 11/27/2013 | Smart Pointers                                        |                 |
| 12/4/2013  | const Correctness                                     | [Project #7](@ref assign7)      |

Through each section of the course we will apply the following principles to show how good design is independent of language features.  

-# Memory Management
-# Performance Tweaks (memory vs time tradeoff)
-# Const-Correctness
-# Object Oriented Design Principles
    -# Single responsibility
    -# Open-closed
    -# Liskov substitution
    -# Interface segregation
    -# Dependency inversion

Project Policy
--------------
This semester we will build a blackjack simulator. Each project will build some component of the system. At the end of the semester students will be left with a simple game to run blackjack simulations. It is left to the student to extend the project with a GUI, or a scripting interface. This project will provide us with a large enough canvas to explore many of the complex and powerful capabilities of C++.

Students will use the Mercurial Distributed Version Control System to manage their software projects. Students will turn in their project by submitting the url of a tag. Zip ﬁles of project source code will not be accepted.

ASU Code of Conduct and Academic Integrity Policy
-------------------------------------------------
Plagiarism or any form of cheating in assignments, projects, or exams is subject to serious academic penalty; this may range from a grade of zero for the work to failure of the course. To understand your responsibilities as a student read:
- [The ASU Student Code of Conduct](http://www.asu.edu/aad/manuals/usi/usi104-01.html)
- [The ASU Student Academic Integrity Policy](http://provost.asu.edu/academicintegrity/policy)

As a note, we are using a version control system to track software changed throughout the semester. My intent is to expose you to a very powerful tool which may be used the rest of your academic and professional career. However, version control systems make it easy for me to track the true origin of your submitted source code.

Cross Cutting Concerns
----------------------
From aspect-oriented-programming we learn there are a number of facets in a software system which every system must assess. These aspects are by their very nature global. Global has become something of a naughty word in object oriented programming, AOP acknowledges that some global entities are absolutely essential. System Logging is the canonical example. In this class are a number of cross-cutting concerns including but not limited to:
- Dynamic Memory
- RAII
- Object Life-Cycle Management
- Exceptions especially Exception Safety
- Lambda Expressions
- Iterators
- Design for Testability

Special Needs
-------------
Please schedule an appointment to see me during oﬃce hours if you have any questions, concerns, or if you have a disability that will require accommodations in this class.

Note: To qualify for disability accommodations here at ASU, students must register and qualify for services through the Disability Resource Center (DRC) located on the 1st Floor of the Matthews Center Building. (480) 965-1234 (V), (480) 965- 9000 (TTY)





