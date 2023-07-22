#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

enum Suit {
    DIAMONDS, HEARTS, SPADES, CLUBS
};

const char* suit_as_str(const Suit& s) {
    switch (s) {
        case DIAMONDS:
            return "diamonds";
        case HEARTS:
            return "hearts";
        case SPADES:
            return "spades";
        case CLUBS:
            return "clubs";
        default:
            throw 1;
    }
}

class Card {
private:
    unsigned int value; // can be 1-13 inclusive
    Suit suit;

    const char* value_as_string() const {
        const char* name;
        switch (value) {
            case 1:
                name = "ace";
                break;
            case 2:
                name = "two";
                break;
            case 3:
                name = "three";
                break;
            case 4:
                name = "four";
                break;
            case 5:
                name = "five";
                break;
            case 6:
                name = "six";
                break;
            case 7:
                name = "seven";
                break;
            case 8:
                name = "eight";
                break;
            case 9:
                name = "nine";
                break;
            case 10:
                name = "ten";
                break;
            case 11:
                name = "Jack";
                break;
            case 12:
                name = "Queen";
                break;
            case 13:
                name = "King";
                break;
        }
        return name;
    }
public:
    // I do not check if the int is in bounds
    // fuck you!
    Card(unsigned int value, Suit s) : value(value), suit(s) {}

    // getters why not
    int get_value() const { return value; }
    Suit get_suit() const { return suit; }

    std::string as_string() const {
        std::string name = this->value_as_string();
        name += " of ";
        name += suit_as_str(suit);
        return name;
    }
};

class Deck {
private:
    std::shared_ptr<Card> cards[52];
public:
    Deck(){
        const int NUMBER_OF_SUITS = 4;
        const int NUMBER_OF_CARDS = 13;
        for (int i = 0; i < NUMBER_OF_SUITS; i++) {
            for (int j = 0; j < NUMBER_OF_CARDS; j++) {
                int index = j + (NUMBER_OF_CARDS*i); // 0, 1, 2, 3, ..., 51
                cards[index] = std::make_shared<Card>(j, (Suit)i);
            }
        }
    }

    // this will hang forever if all cards are "dealt"
    // that is if the their is more than one shared_ptr 
    // for every card
    std::shared_ptr<Card> draw_card() const {
        while(true){
            int card_index = rand() % 52;
            bool card_not_in_play = cards[card_index].unique();
            if (card_not_in_play) {
                return cards[card_index];
            }
        }
    }
};

class Player {};

int main(){
    srand((unsigned) time(NULL));

    Deck d;

    // card names are wrong and deck does not work as intended
    // (it should hang)
    std::cout << d.draw_card()->as_string() << std::endl;

    //Card c(1, DIAMONDS);
    //std::cout << c.as_string() << std::endl;
}
