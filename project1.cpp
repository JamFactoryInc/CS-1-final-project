/*

Script by Kieran Smith April 2020

NOTES:

Hi! I'm a little tired of the tedious and basic things we've had to do this semester. 
I decided to have some fun with this and just make actual functional solitaire. SURPRISE! To be fair it doesn't work that well but also solitaire has a lot of rules

I also put in what you asked.


*/

#include "Deck.cpp"
#include "Card.cpp"
#include "Pile.cpp"
#include <iostream>

static const char ACE = 1;
static const char JACK = 11;
static const char QUEEN = 12;
static const char KING = 13;

//Lookup table of first however many prime numbers.
const std::vector<int> PRIMES 
    {2,      3,      5,      7,     11,     13,     17,     19,     23,     29, 
    31,     37,     41,     43,     47,     53,     59,     61,     67,     71, 
    73,     79,     83,     89,     97,    101,    103,    107,    109,    113, 
    127,    131,    137,    139,    149,    151,    157,    163,    167,    173, 
    179,    181,    191,    193,    197,    199,    211,    223,    227,    229, 
    233,    239,    241,    251,    257,    263,    269,    271,    277,    281, 
    283,    293,    307,    311,    313,    317,    331,    337,    347,    349, 
    353,    359,    367,    373,    379,    383,    389,    397,    401,    409, 
    419,    421,    431,    433,    439,    443,    449,    457,    461,    463, 
    467,    479,    487,    491,    499,    503,    509,    521,    523,    541, 
    547,    557,    563,    569,    571,    577,    587,    593,    599,    601, 
    607,    613,    617,    619,    631,    641,    643,    647,    653,    659, 
    661,    673,    677,    683,    691,    701,    709,    719,    727,    733};


//   ______      ______
//  |H    A|    |H____A|
//  |      |    |H____2|
//  |      |    |H    3|
//  |______|    |      |
//              |      |
//              |______|
//

void gameLoop();
int checkForAces(Deck &deck);
int checkForMoves(Deck &deck);
void checkMovesFrom(Deck &deck, int pileIndex);
void moveCard(Deck &deck, int pileIndexOrigin, int pileIndexLocation);
void moveCard(Deck &deck, Pile &pile, int pileIndexLocation);
void boringGameLoop();
void playSolitaire(Deck &deck);

int main ()
{
    char in = ' ';
    std::cout<< "Press 1 to play simple solitaire. Press 2 to view normal solitaire";
    std::cin >> in;
    if(in == '1')
        boringGameLoop();
    else
        gameLoop();
    
    //std::shuffle(cards.deck[0]);
}

//executes the boring version of solitaire.
void boringGameLoop()
{

    Deck deck;
    char in = '1';
    anjry:
    
    std::cout << "1) New Deck \n2) Display Deck \n3) Shuffle Deck \n4) Play Solitaire \n5) Exit";
    std::cin >> in;
    switch (in)
    {
    case '1':
        deck.newDeck();
    break;

    case '2':
    deck.display2();
    break;

    case '3':
    deck.shuffle();
    break;

    case '4':
    playSolitaire(deck);
    break;

    case '5':
    return;
    break;
    }
    goto anjry;

}


//returns a boolean of wether or not the inputted integer is prime.
bool isPrime(int sum)
{

    for(int i : PRIMES)
        if(i == sum)
        {
            return true;
        }
    return false;

}

//called from the game loop.
void playSolitaire(Deck &deck)
{
    int sum = 1;

    for(int i=0; i < 51; i++)
    {

        std::cout<< "Hand sum: " << sum;
        if(deck.getDeck()[i].getValue() > 10)
            sum+= 10;
        else
            sum += deck.getDeck()[i].getValue();
        
        std::cout<< "Adding: \n";
        deck.getDeck()[i].printCard();
        if(isPrime(sum))
        {
            sum = 1;
            std::cout<< "Sum is PRIME\n";
        } 
    }
    std::cout<< "Remaining sum: " << sum;
    std::cout << ".\nAdding \n";
    deck.getDeck()[51].printCard();
    std::cout << "\nto " << sum << " would make it ";
    if(isPrime(sum + deck.getDeck()[51].getValue()))
        std::cout << "PRIME. You lose.\n";
    else
    {
        std::cout << "NOT PRIME. You win.\n";
    }
    
        
        


}

//Checks the piles for aces
int checkForAces(Deck &deck)
{   
    int ret = 0;
    char val = 0;
    //std::cout << deck.getPiles()[0].size();
    for(Pile &p: deck.getPiles())
    {
        //p.print();
        val = p.topCard().getValue();
        //std::cout << val << " ";
        if(val == ACE)
        {
            //p.print();
            std::cout << std::endl;
            deck.getFoundations()[p.topCard().getSuit()].addToPile(p.removeFromPile(1));
            p.topCard().flip();
            //p.print();
            ret++;
        }
    }

    if(deck.getDrawPile().topCard().getValue()== ACE || (deck.getFoundations()[deck.getDrawPile().topCard().getSuit()].getPile().size() > 0 && deck.getDrawPile().topCard().getValue() - 1 == deck.getFoundations()[deck.getDrawPile().topCard().getSuit()].topCard().getValue()))
        deck.getFoundations()[deck.getDrawPile().topCard().getSuit()].addToPile(deck.getDrawPile().removeFromPile(1));

    return ret;

}


//checks the piles for available moves
int checkForMoves(Deck &deck)
{
    int numMoves = 0;
    std::vector<char> moves {' ',' ',' ',' ',' ',' ',' ',' '};
    for(Pile &foundation: deck.getFoundations())
        for(Pile &pOther: deck.getPiles())
            if(foundation.getPile().size() > 0 && pOther.topCard().getSuit() == foundation.topCard().getSuit() && pOther.topCard().getValue() - 1 == foundation.topCard().getValue())
            {
                foundation.addToPile(pOther.removeFromPile(1));
                pOther.topCard().flip();
            }
    int index = -1;            
    for(Pile &pThis: deck.getPiles())
    {
        index++;
        for(Pile &pOther: deck.getPiles())
        {
            if(!pThis.equals(pOther))
            {
                if(pThis.getPile().size() > 0 && pOther.getPile().size() > 0 && pThis.bottomFaceUpCard().color() != pOther.topCard().color() && (pThis.bottomFaceUpCard().getValue() + 1) == pOther.topCard().getValue())
                {
                    numMoves++;
                    moves[index] = '^';
                }
            }
        }
    }
    deck.setMoves(moves);
    return numMoves;
}


//checks a specific pile for moves. Used after selecting a card pile.
void checkMovesFrom(Deck &deck, int pileIndex)
{
    Pile pThis = deck.getPiles()[pileIndex];
    std::vector<char> moves {' ',' ',' ',' ',' ',' ',' ',' '};
    
    int index = -1;            
    

    for(Pile &pOther: deck.getPiles())
    {
        index++;
        if(!pThis.equals(pOther))
        {
            if(pThis.getPile().size() > 0 && pOther.getPile().size() > 0 && pThis.bottomFaceUpCard().color() != pOther.topCard().color() && (pThis.bottomFaceUpCard().getValue() + 1) == pOther.topCard().getValue())
            {
                moves[index] = '^';
            }
            else if (pThis.bottomFaceUpCard().getValue() == KING && pOther.getPile().size() == 0)
            {

                moves[index] = '^';

            }
        }
    }
    
    deck.setMoves(moves);

}


//Checks the Talon/Draw Pile for available moves.
int checkForMovesDrawPile(Deck &deck)
{
    

    
    std::vector<char> moves {' ',' ',' ',' ',' ',' ',' ',' '};
    
    int index = -1; 
    int numMoves = 0;     

    numMoves += checkForAces(deck);      
    
    std::cout << "run:" << deck.getDrawPile().topCard().values[deck.getDrawPile().topCard().getValue()];
    for(Pile &pOther: deck.getPiles())
    {
        
        index++;
        //std::cout << "run:" << ;
        if(deck.getDrawPile().getPile().size() > 0 && pOther.getPile().size() > 0 && deck.getDrawPile().topCard().color() != pOther.topCard().color() && (deck.getDrawPile().topCard().getValue() + 1) == pOther.topCard().getValue())
        {
            moves[index] = '^';
            numMoves ++;
        }
        else if (deck.getDrawPile().topCard().getValue() == KING && pOther.getPile().size() == 0)
        {

            moves[index] = '^';
            numMoves ++;

        }
        
    }
    
    deck.setMoves(moves);
    return numMoves;

}


//Appends pileIndexOrigin to PileIndexLocation and removes the former from its list
void moveCard(Deck &deck, int pileIndexOrigin, int pileIndexLocation)
{
    std::vector<char> moves {' ',' ',' ',' ',' ',' ',' '};
    deck.setMoves(moves);
    deck.getPiles()[pileIndexLocation].addToPile(deck.getPiles()[pileIndexOrigin].removeFromPile(1));
    for(Card c : deck.getPiles()[pileIndexOrigin].getPile())
        c.flipOver();
    deck.getPiles()[pileIndexOrigin].topCard().flip();

}

//Appends the top card of pile to PileIndexLocation and removes the former from its list
void moveCard(Deck &deck, Pile &pile, int pileIndexLocation)
{
    std::vector<char> moves {' ',' ',' ',' ',' ',' ',' '};
    deck.setMoves(moves);
    deck.getPiles()[pileIndexLocation].addToPile(pile.removeFromPile(1));
    for(Card c : pile.getPile())
        c.flipOver();
    pile.topCard().flip();

}

//game loop that does some logic and calls the functions.
void gameLoop()
{
    restart:
    int moveOrigin = 0;   
    int moveLocation = 0;  
    Deck deck;
    deck.newDeck();
    deck.shuffle();
    deck.populatePiles();
    char c = 'y';
    while(c=='y')
    {

        
        
        std::cout << std::endl;
        deck.display();
        checkForAces(deck);
        deck.display();
        if(checkForMoves(deck) > 0)
        {
            deck.display();
            std::cout << "Input your move (Number beside the caret).";
            
            std::cin >> moveOrigin;
            checkMovesFrom(deck, moveOrigin);
            deck.display();
            std::cout << "Input where you want to move the card (Number beside the caret).";
            std::cin >> moveLocation;
            moveCard(deck, moveOrigin, moveLocation);
            deck.display();
        }
        else if(checkForMovesDrawPile(deck) > 0)
        {
            
            
            deck.display();
            std::cout << "Input where you want to move the card from the Talon (Number beside the caret).";
            std::cin >> moveLocation;
            moveCard(deck, deck.getDrawPile(), moveLocation);
        

        }
        else
        {
            for(int i = 0; i< 104; i++)
            {
                
                deck.getDrawPile().draw();
                deck.display();
                if(checkForMovesDrawPile(deck) > 0)
                    i = 104;
                if(checkForMoves(deck) > 0)
                    i = 104;
            }
            if(checkForMovesDrawPile(deck) == 0)
            {
                std::cout<<"No moves available. Restart(n will exit the programm)? y/n";
                char response = 'y';
                std::cin >> response;
                if(response == 'y')
                    goto restart;
                else    
                    return;
            }
            deck.display();
        }
        

        std::cout<< "Continue? y/n";
        std::cin >> c;

    }

}


