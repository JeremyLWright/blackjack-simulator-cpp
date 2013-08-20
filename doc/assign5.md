

  \page assign5 Assignment 5 :: Deck Factory
 In this project you will use the Card classes you built in project 4 to build a deck for dealing. The deck requires a specific and detailed construction. The Factory Pattern fits this need to construct complex objects.

The Shoe object is used to deal a deck of cards. It manages shuffling, and tells the dealer which to reshuffle. The stop is a card counting counter measure, since it add entropy to decks.

Objectives
----------
- Complete 2 class: Casino::DeckFactory, and Casino::Shoe
- Create 1 unit test of your own
- Push to bitbucket.
- Turn in the tag URL on Blackboard 

Tests
-----
-# Pass DeckFactoryTest.Simple
-# Pass ShoeTest.Simple
-# Design a test for Casino::Shoe::Draw()
    -# Design your own test that create a new shoe, and draws all the cards from the shoe. Verify that the final card (the “53rd” card) is a nullptr

Instructions
------------
-# Pass all 2 given Unit Tests.
-# Write your own test to verify the Shoe::Draw method.
-# Commit, and Tag this as: Assignment5_vXX
-# Turn in your Project URL and Tag on Blackboard 
 
