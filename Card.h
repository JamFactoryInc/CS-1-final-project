#ifndef CardH
#define CardH

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>



//A basic class to contain the suits and values of all the cards. Also contains useful functions like flip, print, and set.
class Card
{
private:

    //The suit of the card. 
    //0 = hearts, 1 = clubs, 2 = diamonds, 3 = spades.
    char suit = 0;
    //A numerical representation of the value of the card (1-13)
    char intValue = 0;
    //A text representation of the value of a card. Ex. "A" "K" or "10".
    std::string value = "";

    bool faceUp = false;
    
public:
    //lookup table to translate a numerical suit into a character.
    // 0 = hearts, 1 = clubs, 2 = diamonds, 3 = spades.
    std::vector<char> suits = {'H', 'C', 'D', 'S'};


    //lookup table to deal with the different names of cards. Index 0 is NULL, as value 1 should be an Ace
    std::string values[14] = {"  ", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    static const char hearts = 0;
    static const char clubs = 1;
    static const char diamonds = 2;
    static const char spades = 3;

    Card();
    Card(char, char);
    void setSuit(char);
    void setValue(char);
    char getSuit();
    char getValue();
    void toString();
    void printCard();
    void printCardLayer(int);
    void flip();
    bool isFaceUp();
    bool color();
    void set(Card);
    bool equals(Card);
    void flipOver();

};
#endif