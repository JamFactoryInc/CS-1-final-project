#include "Deck.h"

Deck::Deck()
{

    

}


//inits the deck/ fills it with values.
void Deck::newDeck()
{

    for(char suitIterator = 0; suitIterator < 4; suitIterator++)
        for(char valueIterator = 1; valueIterator < 14; valueIterator++) 
        {
            std::cout << int(suitIterator) << " | " << int(valueIterator) << "   ";
            Card temp(valueIterator,suitIterator);
            deck.push_back(temp);
        }
    
    piles.push_back(pile1);
    piles.push_back(pile2);
    piles.push_back(pile3);
    piles.push_back(pile4);
    piles.push_back(pile5);
    piles.push_back(pile6);
    piles.push_back(pile7);



    foundations.push_back(foundation1);
    foundations.push_back(foundation2);
    foundations.push_back(foundation3);
    foundations.push_back(foundation4);

}

//shuffles the created deck.
void Deck::shuffle()
{
    srand(time(NULL));
    int size = deck.size();
    for (int i = 0; i < size - 1; i++) 
    {
        int j = i + rand() % (size - i);
        
        Card temp(0,0);
        temp.setValue(deck[i].getValue()); temp.setSuit(deck[i].getSuit());
        deck[i].setValue(deck[j].getValue()); deck[i].setSuit(deck[j].getSuit());
        deck[j].setValue(temp.getValue()); deck[j].setSuit(temp.getSuit());

   }

}


//prints all the cards in the deck. This is primarily used for debugging.
void Deck::printCards()
{

    for(Card card: deck)
        card.printCard();

}

//Adds cards to the appropriate piles based on the traditional rules of solitaire.
void Deck::populatePiles()
{

    for(int i = 0; i < 7; i++)
        piles[0].addToPile(deck[i]);
    piles[0].topCard().flip();
    for(int i = 7; i < 13; i++)
        piles[1].addToPile(deck[i]);
    piles[1].topCard().flip();
    for(int i = 13; i < 18; i++)
        piles[2].addToPile(deck[i]);
    piles[2].topCard().flip();
    for(int i = 18; i < 22; i++)
        piles[3].addToPile(deck[i]);
    piles[3].topCard().flip();
    for(int i = 22; i < 25; i++)
        piles[4].addToPile(deck[i]);
    piles[4].topCard().flip();
    for(int i = 25; i < 27; i++)
        piles[5].addToPile(deck[i]);
    piles[5].topCard().flip();
    piles[6].addToPile(deck[28]);
    piles[6].topCard().flip();

    for(int i = 29; i < 52; i++)
        pickUp.getPile().push_back(deck[i]);
    pickUp.topCard().flip();

    for (Card c : pickUp.getPile())
        c.flip();




}

//Displays the current state of the game.
void Deck::display()
{

    std::cout << std::endl;
    for(int i = 1; i < 6; i++)
    {
        foundations[0].topCard().printCardLayer(i);
        foundations[1].topCard().printCardLayer(i);
        foundations[2].topCard().printCardLayer(i);
        foundations[3].topCard().printCardLayer(i);
        std::cout<<"        ";
        pickUp.topCard().printCardLayer(i);

        std::cout << std::endl;
    }
    std::cout<<"                                                   ";
    if(moves[7] == '^')
        std::cout << moves[7] << 7;
    //std::cout << std::endl;
    //piles[0].print();
    //std::cout << std::endl;
    //piles[1].print();
    //std::cout << std::endl;
    //piles[2].print();
    std::cout << std::endl;
    for(int layer = 1; layer < 7; layer++)
    {
        for(int pileIndex = 0; pileIndex < 7; pileIndex++)
        {
            if(layer == 1 && piles[pileIndex].getPile().size() > 0 && !piles[pileIndex].topCard().equals(piles[pileIndex].bottomFaceUpCard()))
            {
                piles[pileIndex].bottomFaceUpCard().printCardLayer(1);
                //std::cout << layer << " " << pileIndex;
            }
            else if(layer == 2 && piles[pileIndex].getPile().size() > 0 && !piles[pileIndex].topCard().equals(piles[pileIndex].bottomFaceUpCard()))
            {
                piles[pileIndex].bottomFaceUpCard().printCardLayer(7);
                //std::cout << layer << " " << pileIndex;
            }
            else if(!piles[pileIndex].topCard().equals(piles[pileIndex].bottomFaceUpCard()))
            {
                piles[pileIndex].topCard().printCardLayer(layer-1);
                //std::cout << layer << " " << pileIndex;
            }
            else if( layer == 1)
            {
                piles[pileIndex].topCard().printCardLayer(1);
                //std::cout << layer << " " << pileIndex;
            }
            else    
            {
                piles[pileIndex].topCard().printCardLayer(layer);
                //std::cout << layer << " " << pileIndex;
            }
        }
        std::cout << std::endl;
            
    }
    for(int i = 0; i < 7; i++)
        if (moves[i] == '^')
            std:: cout << "   " << moves[i] << i << "   ";
        else
            std:: cout << "        ";
    std::cout<< std::endl;

}


//displays the deck as a 4x13 rectangle.
void Deck::display2()
{
    //std::cout << std::endl;
    //piles[0].print();
    //std::cout << std::endl;
    //piles[1].print();
    //std::cout << std::endl;
    //piles[2].print();
    std::cout << std::endl;
    for(int layer = 1; layer < 7; layer++)
    {
        for(int deckIndex = 0; deckIndex < 13; deckIndex++)
        {

            deck[deckIndex].printCardLayer(layer);
            
        }
        std::cout << std::endl;
            
    }
    std::cout << std::endl;
    for(int layer = 1; layer < 7; layer++)
    {
        for(int deckIndex = 13; deckIndex < 26; deckIndex++)
        {

            deck[deckIndex].printCardLayer(layer);
            
        }
        std::cout << std::endl;
            
    }
    for(int layer = 1; layer < 7; layer++)
    {
        for(int deckIndex = 26; deckIndex < 39; deckIndex++)
        {

            deck[deckIndex].printCardLayer(layer);
            
        }
        std::cout << std::endl;
            
    }
    for(int layer = 1; layer < 7; layer++)
    {
        for(int deckIndex = 39; deckIndex < 52; deckIndex++)
        {

            deck[deckIndex].printCardLayer(layer);
            
        }
        std::cout << std::endl;
            
    }

}

//returns the piles of a deck
std::vector<Pile> &Deck::getPiles()
{
    return  piles;
}

//returns the foundations of the deck
std::vector<Pile> &Deck::getFoundations()
{
    return foundations;
}

//changes the global available moveset
void Deck::setMoves(std::vector<char> m)
{

    moves = m;

}

//returns the draw pile of the deck
Pile &Deck::getDrawPile()
{

    return pickUp;

}

//returns the deck as a vector of cards
std::vector<Card> &Deck::getDeck()
{

    return deck;

}


