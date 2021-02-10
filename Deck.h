#ifndef TEST_H
#define TEST_H

#include "Card.h"
#include "Pile.h"

//Holds data for the standard 52-card deck.
class Deck {
    private:

    //stores the 4 foundational piles
    std::vector<Pile> foundations;

    //individially initialized Piles so I can keep their pointers.
    Pile foundation1;
    Pile foundation2;
    Pile foundation3;
    Pile foundation4;

    //same here but with the 7 piles.
    std::vector<Pile> piles;
    Pile pile1;
    Pile pile2;
    Pile pile3;
    Pile pile4;
    Pile pile5;
    Pile pile6;
    Pile pile7;

    //a character array to keep track of the available moves globally.
    std::vector<char> moves{' ',' ',' ',' ',' ',' ',' ',' '};

    //the Talon/ Draw pile.
    Pile pickUp;
    

    public:
        
        void setMoves(std::vector<char>);
        std::vector<Card> deck;
        Deck();
        void shuffle();
        void newDeck();
        void printCards();
        void populatePiles();
        
        void display();
        void display2();
        
        std::vector<Pile> &getPiles();
        std::vector<Pile> &getFoundations();
        Pile &getDrawPile();
        std::vector<Card> &getDeck();

        
};
#endif
