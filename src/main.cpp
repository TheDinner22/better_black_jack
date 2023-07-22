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
            default:
                throw 1;
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
                cards[index] = std::make_shared<Card>(j+1, (Suit)i);
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

    std::shared_ptr<Card> c0 = d.draw_card();
    std::cout << c0->as_string() << std::endl;
    std::shared_ptr<Card> c1 = d.draw_card();
    std::cout << c1->as_string() << std::endl;
    std::shared_ptr<Card> c2 = d.draw_card();
    std::cout << c2->as_string() << std::endl;
    std::shared_ptr<Card> c3 = d.draw_card();
    std::cout << c3->as_string() << std::endl;
    std::shared_ptr<Card> c4 = d.draw_card();
    std::cout << c4->as_string() << std::endl;
    std::shared_ptr<Card> c5 = d.draw_card();
    std::cout << c5->as_string() << std::endl;
    std::shared_ptr<Card> c6 = d.draw_card();
    std::cout << c6->as_string() << std::endl;
    std::shared_ptr<Card> c7 = d.draw_card();
    std::cout << c7->as_string() << std::endl;
    std::shared_ptr<Card> c8 = d.draw_card();
    std::cout << c8->as_string() << std::endl;
    std::shared_ptr<Card> c9 = d.draw_card();
    std::cout << c9->as_string() << std::endl;
    std::shared_ptr<Card> c10 = d.draw_card();
    std::cout << c10->as_string() << std::endl;
    std::shared_ptr<Card> c11 = d.draw_card();
    std::cout << c11->as_string() << std::endl;
    std::shared_ptr<Card> c12 = d.draw_card();
    std::cout << c12->as_string() << std::endl;
    std::shared_ptr<Card> c13 = d.draw_card();
    std::cout << c13->as_string() << std::endl;
    std::shared_ptr<Card> c14 = d.draw_card();
    std::cout << c14->as_string() << std::endl;
    std::shared_ptr<Card> c15 = d.draw_card();
    std::cout << c15->as_string() << std::endl;
    std::shared_ptr<Card> c16 = d.draw_card();
    std::cout << c16->as_string() << std::endl;
    std::shared_ptr<Card> c17 = d.draw_card();
    std::cout << c17->as_string() << std::endl;
    std::shared_ptr<Card> c18 = d.draw_card();
    std::cout << c18->as_string() << std::endl;
    std::shared_ptr<Card> c19 = d.draw_card();
    std::cout << c19->as_string() << std::endl;
    std::shared_ptr<Card> c20 = d.draw_card();
    std::cout << c20->as_string() << std::endl;
    std::shared_ptr<Card> c21 = d.draw_card();
    std::cout << c21->as_string() << std::endl;
    std::shared_ptr<Card> c22 = d.draw_card();
    std::cout << c22->as_string() << std::endl;
    std::shared_ptr<Card> c23 = d.draw_card();
    std::cout << c23->as_string() << std::endl;
    std::shared_ptr<Card> c24 = d.draw_card();
    std::cout << c24->as_string() << std::endl;
    std::shared_ptr<Card> c25 = d.draw_card();
    std::cout << c25->as_string() << std::endl;
    std::shared_ptr<Card> c26 = d.draw_card();
    std::cout << c26->as_string() << std::endl;
    std::shared_ptr<Card> c27 = d.draw_card();
    std::cout << c27->as_string() << std::endl;
    std::shared_ptr<Card> c28 = d.draw_card();
    std::cout << c28->as_string() << std::endl;
    std::shared_ptr<Card> c29 = d.draw_card();
    std::cout << c29->as_string() << std::endl;
    std::shared_ptr<Card> c30 = d.draw_card();
    std::cout << c30->as_string() << std::endl;
    std::shared_ptr<Card> c31 = d.draw_card();
    std::cout << c31->as_string() << std::endl;
    std::shared_ptr<Card> c32 = d.draw_card();
    std::cout << c32->as_string() << std::endl;
    std::shared_ptr<Card> c33 = d.draw_card();
    std::cout << c33->as_string() << std::endl;
    std::shared_ptr<Card> c34 = d.draw_card();
    std::cout << c34->as_string() << std::endl;
    std::shared_ptr<Card> c35 = d.draw_card();
    std::cout << c35->as_string() << std::endl;
    std::shared_ptr<Card> c36 = d.draw_card();
    std::cout << c36->as_string() << std::endl;
    std::shared_ptr<Card> c37 = d.draw_card();
    std::cout << c37->as_string() << std::endl;
    std::shared_ptr<Card> c38 = d.draw_card();
    std::cout << c38->as_string() << std::endl;
    std::shared_ptr<Card> c39 = d.draw_card();
    std::cout << c39->as_string() << std::endl;
    std::shared_ptr<Card> c40 = d.draw_card();
    std::cout << c40->as_string() << std::endl;
    std::shared_ptr<Card> c41 = d.draw_card();
    std::cout << c41->as_string() << std::endl;
    std::shared_ptr<Card> c42 = d.draw_card();
    std::cout << c42->as_string() << std::endl;
    std::shared_ptr<Card> c43 = d.draw_card();
    std::cout << c43->as_string() << std::endl;
    std::shared_ptr<Card> c44 = d.draw_card();
    std::cout << c44->as_string() << std::endl;
    std::shared_ptr<Card> c45 = d.draw_card();
    std::cout << c45->as_string() << std::endl;
    std::shared_ptr<Card> c46 = d.draw_card();
    std::cout << c46->as_string() << std::endl;
    std::shared_ptr<Card> c47 = d.draw_card();
    std::cout << c47->as_string() << std::endl;
    std::shared_ptr<Card> c48 = d.draw_card();
    std::cout << c48->as_string() << std::endl;
    std::shared_ptr<Card> c49 = d.draw_card();
    std::cout << c49->as_string() << std::endl;
    std::shared_ptr<Card> c50 = d.draw_card();
    std::cout << c50->as_string() << std::endl;
    std::shared_ptr<Card> c51 = d.draw_card();
    std::cout << c51->as_string() << std::endl;
    std::shared_ptr<Card> c52 = d.draw_card();
    std::cout << c52->as_string() << std::endl;
    std::shared_ptr<Card> c53 = d.draw_card();
    std::cout << c53->as_string() << std::endl;
    std::shared_ptr<Card> c54 = d.draw_card();
    std::cout << c54->as_string() << std::endl;
    std::shared_ptr<Card> c55 = d.draw_card();
    std::cout << c55->as_string() << std::endl;
    std::shared_ptr<Card> c56 = d.draw_card();
    std::cout << c56->as_string() << std::endl;
    std::shared_ptr<Card> c57 = d.draw_card();
    std::cout << c57->as_string() << std::endl;
    std::shared_ptr<Card> c58 = d.draw_card();
    std::cout << c58->as_string() << std::endl;
    std::shared_ptr<Card> c59 = d.draw_card();
    std::cout << c59->as_string() << std::endl;
    std::shared_ptr<Card> c60 = d.draw_card();
    std::cout << c60->as_string() << std::endl;
    std::shared_ptr<Card> c61 = d.draw_card();
    std::cout << c61->as_string() << std::endl;
    std::shared_ptr<Card> c62 = d.draw_card();
    std::cout << c62->as_string() << std::endl;
    std::shared_ptr<Card> c63 = d.draw_card();
    std::cout << c63->as_string() << std::endl;
    std::shared_ptr<Card> c64 = d.draw_card();
    std::cout << c64->as_string() << std::endl;
    std::shared_ptr<Card> c65 = d.draw_card();
    std::cout << c65->as_string() << std::endl;
    std::shared_ptr<Card> c66 = d.draw_card();
    std::cout << c66->as_string() << std::endl;
    std::shared_ptr<Card> c67 = d.draw_card();
    std::cout << c67->as_string() << std::endl;
    std::shared_ptr<Card> c68 = d.draw_card();
    std::cout << c68->as_string() << std::endl;
    std::shared_ptr<Card> c69 = d.draw_card();
    std::cout << c69->as_string() << std::endl;
    std::shared_ptr<Card> c70 = d.draw_card();
    std::cout << c70->as_string() << std::endl;
    std::shared_ptr<Card> c71 = d.draw_card();
    std::cout << c71->as_string() << std::endl;
    std::shared_ptr<Card> c72 = d.draw_card();
    std::cout << c72->as_string() << std::endl;
    std::shared_ptr<Card> c73 = d.draw_card();
    std::cout << c73->as_string() << std::endl;

    //Card c(1, DIAMONDS);
    //std::cout << c.as_string() << std::endl;
}
