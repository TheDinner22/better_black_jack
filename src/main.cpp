#include <iostream>
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

class Deck {};
class Player {};

int main(){
    Card c(1, DIAMONDS);

    std::cout << c.as_string() << std::endl;
}
