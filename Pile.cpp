#include "Pile.h"



Pile::Pile()
{


}

//returns the top card in the pile
Card &Pile::topCard()
{
    if(pile.size() > 0)
        return pile.back();
    return empty;
}

//appends a card to the pile
void Pile::addToPile(Card c)
{

    pile.push_back(c);

}

//appends a vector of Cards to the top of the pile.
void Pile::addToPile(std::vector<Card> p)
{

    pile.insert(std::end(pile), std::begin(p), std::end(p));

}

//removes a set number, i, of cards from the top of the pile. Returns these cards as a seperate vector
std::vector<Card> Pile::removeFromPile(int i)
{
    std::vector<Card> temp;
    for(i; i > 0; i--)
        temp.insert(temp.begin(), pile.back()); 
        pile.pop_back();
    return temp;
}

//Returns the value of the bottom card that is facing up.
char Pile::bottomFaceUpCardVal()
{
    char val = 0;
    for(Card c : pile)
        if(c.isFaceUp())
            val = c.getValue();
    return val;
}

//Returns the bottom card that is facing up.
Card &Pile::bottomFaceUpCard()
{
    int index;
    for(int i = pile.size()-1; i >= 0; i--)
        if(pile[i].isFaceUp())
        {
            index = i;
        }
    return pile[index];
}

//returns the pile as a vector of cards
std::vector<Card> &Pile::getPile()
{

    return pile;

}

//returns the equivalence of two Piles. Compares all the values of all the cards.
bool Pile::equals(Pile p)
{
    if(p.size() == size())
        for(int i=0; i < p.size(); i++)
        {
            if(!p.getPile()[i].equals(pile[i]))
                return false;
        }   
    else
        return false;
    return true;
        

}

//returns the size of the pile
int Pile::size()
{

    return pile.size();

}

//prints the pile to the console. Primarily used for debugging
void Pile::print()
{

    for(Card c : pile)
        c.printCard();

}

//Takes one card from the bottom of the pile and puts it on the top
void Pile::draw()
{
    
    pile.insert(pile.begin(),pile.back());
    pile.pop_back();

}