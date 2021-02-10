#ifndef PileH
#define PileH

#include "Card.h"

//a collection of cards smaller than a deck. Contains methods such as TopCard, Equals, set, and BottomFaceUpCard
class Pile 
{
    private:
    Card empty = Card(0,0);
    std::vector<Card> pile;
    public:
        
        Pile();
        Card &topCard();
        std::vector<Card> &getPile();
        char bottomFaceUpCardVal();
        void addToPile(Card c);
        void addToPile(std::vector<Card> p);

        //Removes (int) from the top of the pile. 
        std::vector<Card> removeFromPile(int);
        Card &bottomFaceUpCard();
        bool equals(Pile);
        int size();
        void print();
        void draw();

        
};
#endif