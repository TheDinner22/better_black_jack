#include <iostream>
#include <memory>
#include <string>
#include <vector>

std::string input(const char* prompt){
    std::cout << prompt << std::endl;

    std::string buffer;
    std::getline(std::cin, buffer); //WARN idk this function
    
    return buffer;
}

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
    // copy breaks the deck i think
    Deck(const Deck& other) = delete;
    Deck& operator=(const Deck& other) = delete;

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
    // TODO should this not be const?
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

class Player {
private:
    std::string name;
    std::vector<std::shared_ptr<Card>> cards;
public:
    int money;

    // copy breaks the Player i think
    Player(const Player& other) = delete;
    Player& operator=(const Player& other) = delete;

    Player(std::string name) : money(100), name(name) {}

    const std::string& get_name () const {return name;}

    void print_hand() const {
        if (cards.empty()) {
            std::cout << get_name() << " has no cards!" << std::endl;
            return;
        }

        std::cout << get_name() << " has:" << std::endl;
        for (int i=0; i < cards.size(); i++) {
            std::shared_ptr<Card> card = cards[i];
            std::cout << card->as_string() << std::endl;
        }
        std::cout << std::endl << "which totals " << total_points() << " points." << std::endl;
    }

    int total_points() const {
        int total = 0;

        for (int i=0; i < cards.size(); i++) {
            std::shared_ptr<Card> card = cards[i];
            total += std::min(card->get_value(),10);
        }

        return total;
    }

    bool is_bust() const {
        if (total_points() > 21) {
            return true;
        }
        else {
            return false;
        }
    }

    void clear_hand() {
        cards.clear();
    }

    void draw_card(const Deck& d, bool verbose=false) {
        std::shared_ptr<Card> card = d.draw_card();

        if (verbose){
            std::cout << name << " drew a " << card->as_string() << "!" << std::endl;
        }

        cards.push_back(card);
    }
};

void create_players(std::vector<std::unique_ptr<Player>>& players) {
    while (true){
        if (players.size() > 6) {
            std::cout << "max player count reached!\nStarting Game!" << std::endl;
            break;
        }

        std::cout << "enter a players name to add them to the game!" << std::endl;
        std::string username = input("or enter 's' to start the game" );

        if (username.empty()) {
            std::cout << "you gotta actually enter a name bruh" << std::endl;
            continue;
        }
        else if (username == "s") {
            if(players.size() == 0) {
                std::cout << "cannot start game with 0 players!" << std::endl;
                continue;
            }

            std::cout << "starting the game!" << std::endl;
            break;
        }

        // add player | haha implicit conversion
        players.push_back( std::make_unique<Player>(username) );
    }
}

int main(){
    // seed rng
    srand((unsigned) time(NULL));

    // init stuff for game
    Deck d;
    // https://www.reddit.com/r/cpp_questions/comments/swb3et/cant_create_a_vector_of_semaphores_emplacing_back/
    // and
    // https://stackoverflow.com/questions/27470827/why-does-stdvectorreserve-call-the-copy-constructor
    // is why this is unique ptr
    // player needs to exist on heap and not move or be copied
    // it cannot be emplaced in the vector or pushed to the back
    std::vector<std::unique_ptr<Player>> players;
    Player dealer("dealer");

    // this fills the players vec with players
    create_players(players);

    while(true) {
        std::cout << "------------" << std::endl;
        std::cout << "start new game" << std::endl;
        std::cout << "------------" << std::endl << std::endl;

        // draw dealer 2 cards and announce one of them
        dealer.draw_card(d, true);
        dealer.draw_card(d);

        // draw players cards
        for (int i = 0; i < players.size(); i++) {
            players[i]->draw_card(d);
            players[i]->draw_card(d);
        }

        // player turns
        for (int i = 0; i < players.size(); i++) {
            players[i]->print_hand();

            while(true) {
                if(players[i]->is_bust()) {
                    std::cout << "you are bust!" << std::endl;
                    break;
                }

                std::string choice = input("hit or stand (h/s)?");

                if(choice == "s") {break;}
                else if (choice == "h") {
                    // draw card
                    players[i]->draw_card(d, true);
                    std::cout << players[i]->get_name() << " now has " << players[i]->total_points() << " total points!" << std::endl;
                    std::cout << "--------------" << std::endl;
                }
            }
        }

        // dealers turn (dealer hits on 16 or lower)
        while (true) {
            dealer.print_hand();

            if (dealer.total_points() > 16) {
                std::cout << "end dealers turn" << std::endl;
                break;
            }

            dealer.draw_card(d, true);
        }

        std::cout << "dealer ended their turn with " << dealer.total_points() << " points" << std::endl;

        // handle winning and losing
        // players that win get +1 point
        // while losers get -1 point
        for (int i = 0; i < players.size(); i++) {
            if(players[i]->is_bust()) {
                players[i]->money -= 1;
            }
            else if(dealer.is_bust()) {
                players[i]->money += 1;
            }
            else if (players[i]->total_points() > dealer.total_points()) {
                players[i]->money += 1;
            }
            else {
                players[i]->money -= 1;
            }
        }
        
        // post game
        dealer.clear_hand();
        for (int i = 0; i < players.size(); i++) {
            players[i]->clear_hand();
        }
    }
}
