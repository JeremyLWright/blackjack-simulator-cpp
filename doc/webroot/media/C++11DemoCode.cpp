vector<Casino::Card*> cards;
auto rank_9 = new Card::ValueRank(9);
auto rank_2 = new Card::ValueRank(2);

cards.push_back(new Casino::Card(*rank_9, Casino::Card::Suite::CLUBS));
cards.push_back(new Casino::Card(*rank_2, Casino::Card::Suite::CLUBS));
cards.push_back(new Casino::AceCard(Casino::Card::Suite::CLUBS));

//This uses the sorting algorithm from the <algorithm> header in the STL.
//It performs very safe, very powerful sorting, but the caller has to
//provide a comparison function. Here we use a llambda function to tell
//std::sort how to compare 2 cards, a lhs -> left hand side. and a rhs ->
//right hand side 
//
//the begin and end are iterators to touch every element in the vector.
std::sort(std::begin(cards), std::end(cards), 
        [](Card* lhs, Card* rhs)
        { 
            return (lhs->HardValue() < rhs->HardValue()); 
        }
        );


//Lets take a step back from iterators and say lets iterate the C way
for(int i = 0; i < cards.size() - 1; ++i)
{
    cards[i] = .....
}

//If we increase our abstraction a bit we can use the member versions of
//begin to iterator over a list
for(vector<card*>::iterator i = cards.begin();
        i != cards.end();
        ++i)
{
    *i; //Remember to dereference i to get the actual card
}

// C++11 adds non-member version of begin and end which allow us to write code
// which is even more general.
for(vector<card*>::iterator i = begin(cards);
        i != end(cards);
        ++i)
{
    *i;
}

// C++11 allows even more generality by providing the auto type deduction
// keyword. Now we don't mention the type at all which makes this code very
// flexible.
for(auto i = begin(cards);
        i != end(card);
        ++i)
{
    *i;

}

// Now the C++11 allows llambda functions so we can use an STL function here.
// This is similar to how we sorted above. Notice that we cannot use auto
// here. the compiler is not smart enough to look ahead in the function to
// guess the llambda-method signature.
for_each(begin(cards), end(cards), [](Card* i){  i  });


//The range-based-for allows for absolute terseness, it also provides
//a dereference for us.
for(auto i : cards)
{
    i;
}

//Question: When would I need to dereference in a range-based-for???
vector<int*> numbers; //say we had a vector of pointers to integers remember int* is inbetween <>
int a = 0;
int b = 1;
numbers.push_back(&a); //Push on the address of a
numbers.push_back(&b); //Push on the address of b

for(auto i = begin(numbers);
        i != end(numbers);
        ++i)
{
    cout << *i; //Dereference once gets "the thing between <> e.g. int*. This prints the addresses
}

for(auto i = begin(numbers);
        i != end(numbers);
        ++i)
{
    cout << **i; //Derefernce twice gets the int. This prints 0 then 1
}

//Question: That seems really awkward, why is the syntax that way?
//The language designers wanted C++ iterators to behave like pointers so the
//syntax would be easy to understand for existing programmers. In C one could
//write a similar loop
for(int* i = &numbers;
        i != &numbers + sizeof(numbers);
        ++i)
{ 
    *i
}

//C++11 simply makes this easier with template type deducions and implicit
//iterators. 
for(auto i : numbers)
{
    cout << *i;
}

