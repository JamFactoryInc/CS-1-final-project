#include "Card.h"

Card::Card()
{

    suit = 0;
    intValue = 0;
    value = values[0];

}
Card::Card(char myVal, char mySuit)
{

    suit = mySuit;
    intValue = myVal;
    value = values[intValue];

}

//A layer-by-layer approach to rendering cards. prints a layer 1-6 of the card so that I may print cards next to each other.
void Card::printCardLayer(int l)
{

    switch (l)
    {
        case 1: 
        if(intValue != 0)
            std::cout <<" ______ ";
        else
            std::cout <<"|      |";
        break;
        case 2: 
        if(intValue != 0)
        {
            if(intValue == 10)
                std::cout << "|" << suits[suit] << " " << ((color()) ? "##" : "  ") << value << "|";
            else
                std::cout << "|" << suits[suit] << " " << ((color()) ? "## " : "   ") << value << "|";
        }
        else
        {
            std::cout <<"        ";
        }
        
        break;
        case 3: 
        std::cout <<"|      |";
        break;
        case 4: 
        if(intValue != 0)
            std::cout <<"|      |";
        else
        std::cout << "        ";
                
        break;
        case 5: 
        if(intValue != 0)
            std::cout <<"|______|";
        else
            std::cout <<"|      |";
        
        break; 
        default: 
            std::cout << "        ";
        break;
        case 7: 
            if(intValue != 0)
        {
            if(intValue == 10)
                std::cout << "|" << suits[suit] << "_" << ((color()) ? "##" : "__") << value << "|";
            else
                std::cout << "|" << suits[suit] << "_" << ((color()) ? "##_" : "___") << value << "|";
        }
        break;


    }

    
    
    

}
//Primarily for debugging. Prints a card to the console.
void Card::printCard()
{

    for(int i = 1; i < 7; i++)
    {
        printCardLayer(i);
        std::cout << "\n";
    }

}

//sets the suit of the card
void Card::setSuit(char s)
{
    suit = s;
}

//sets the value of the card
void Card::setValue(char v)
{
    intValue = v;
    value = values[intValue];
}

//returns the suit of the card
char Card::getSuit()
{
    return suit;
}

//returns the numerical value of the card
char Card::getValue()
{
    return intValue;
}

//sets the card to be facing up
void Card::flip()
{
    faceUp = true;
}

//sets the card to be facing down
void Card::flipOver()
{

    faceUp = false;

}

//returns if the card is facing up or not
bool Card::isFaceUp()
{
    return faceUp;

}

//returns the suit color of the card
bool Card::color()
{

    return (suit == 0 || suit == 2);

}

//sets a card equal to the values of another card
void Card::set(Card c)
{
    suit = c.getSuit();
    intValue = c.getValue();
    value = values[intValue];
 

}

//returns the equivalency of this card and another
bool Card::equals(Card c)
{

    return (c.getSuit() == suit && c.getValue() == intValue);

}