  \page assign2 Assignment 2 :: Card Classes

This project will you will begin hacking the Blackjack program. The base framework and initial tests are provided in a mercurial bundle file. You will merge in this bundle to your own repository. Next, you will model the 3 card types in Blackjack. Unit Tests will be a valuable part of this project since the rest of your projects will uses these card classes extensively. Some base unit tests are provided. Your grade is based on these base tests. However the test coverage of the base project is poor, and I encourage you to write your own tests.

This base framework uses inheritance, and composition where appropriate for the design. Study when inheritance vs composition. One is not necessarily better than the other. Once we complete the base implementation, we’ll be able to script player behavior to evaluate betting strategies, using the Lua scripting language.

Objectives
----------
- Merge in the base project bundle.
- Complete three classes: Casino::Card, Casino::FaceCard, and Casino::AceCard
- Create unit tests for methods. 100% coverage is not required, but these are core classes. The more robust they are, the easier the rest of the project will be.
- Push to bitbucket.
- Turn in the tag URL on Blackboard 

| Card | Hard Value | Soft Value | Rank |
|------|------------|------------|------|
| Ace | 11 | 1 | 11 |
|Queen| 10 |10 |10|
|King | 10 |10 |10|
|Jack | 10 |10 |10|
|10   | 10 |10 |10|
| 9 | 9 | 9 | 9|
| 8 | 8 | 8 | 8|
| 7 | 7 | 7 | 7|
| 6 | 6 | 6 | 6|
| 5 | 5 | 5 | 5|
| 4 | 4 | 4 | 4|
| 3 | 3 | 3 | 3|
| 2 | 2 | 2 | 2| 

Instructions
------------
-# Merge in the project2.bundle (See below)
-# Implement your 3 classes.
-# All Cards tests must pass to get full credit.
-# Commit, and Tag this as: Assignment2_XX (where XX is a counter starting at 00)

Merging in Mercurial
--------------------
Merging is a very common task in programming as part of a team. This project is to demonstrate how easily one can share code with another person using Mercurial. I completed the base framework of the application and created a “bundle”. A bundle is easy to make: simply type hg bundle before you type hg push and a zip archive will be created with the outgoing changes. This file is then easy to email to someone. In this scenario, I created the bundle, and I want you to merge in my changes to your own repository.
- Copy the bundle file to general.asu.edu
- On general.asu.edu, navigate to your working copy. Assure there are not any outstanding change by typing hg status.
    - hg status should return with no changes.
- Merge in the project2 base project by "pulling" changes from my zip bundle
    - hg pull ../project2.bundle
    - hg merge
- Now commit to save the merge result.
    - hg commit
- Now use cmake like you normally do.
    - mkdir build #You probably already have this….
    - cd build
    - cmake ..
    - make
- Run the unit tests
    - ./unit-test

You should have a pile of failing unit tests now. Each project will be to fix a small number of them. In this project you only need to make the Card tests pass. Note this means that when you complete Project 1 some tests will still be failing; this is okay. 

