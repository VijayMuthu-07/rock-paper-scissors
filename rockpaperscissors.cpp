#include <iostream>
#include <ctime>

char userchoice() {
    char player;

    do {
        std::cout << "***************************\n";
        std::cout << "Choose one of the foolowing\n";
        std::cout << "***************************\n";
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for scissors\n";

        std::cin >> player;
    }while(player != 'r' && player != 'p' && player != 's');

    return player;
}
char computerchoice() {
    char computer;
    int num;

    srand(time(0));

    num = rand() % 3 + 1;

    switch(num) {
        case 1:
            computer = 'r';
            break;
        case 2:
            computer = 'p';
            break;
        case 3:
            computer = 's';
            break;
    }

    return computer;
}
void showchoice(char choice) {
    switch(choice) {
        case 'r': 
            std::cout << "rock\n";
            break;
        case 'p': 
            std::cout << "paper\n";
            break;
        case 's': 
            std::cout << "scissor\n";
            break;
    }
}
char choosewinner(char pl, char comp) {
    switch(pl) {
        case 'r': 
            if(comp == 'r') {
                return 'd';
            }
            else if(comp == 'p') {
                return 'l';
            }
            else {
                return 'w';
            }
            break;
        case 'p': 
            if(comp == 'r') {
                return 'w';
            }
            else if(comp == 'p') {
                return 'd';
            }
            else {
                return 'l';
            }
            break;
        case 's': 
            if(comp == 'r') {
                return 'l';
            }
            else if(comp == 'p') {
                return 'w';
            }
            else {
                return 'd';
            }
            break;
    }
    return 'd';
}

int main() {
    char player;
    char computer;
    bool is_running = true;
    char ch;
    int cs = 0;
    int ps = 0;

    std::cout << "WELCOME TO ROCK-PAPER-SCISSOR GAME\n";

    do{
        player = userchoice();
        std::cout << "Your choice is: ";
        showchoice(player);

        computer = computerchoice();
        std::cout << "Computer choice is: ";
        showchoice(computer);

        switch (choosewinner(player, computer)) {
            case 'w':
                std::cout << "YOU WON!\n";
                ps++;
                std::cout << "*********\n";
                std::cout << "SCORECARD\n";
                std::cout << "*********\n";
                std::cout << "player score: " << ps << '\n';
                std::cout << "computer score: " << cs << '\n';
                break;
            case 'd':
                std::cout << "It's a TIE\n";
                std::cout << "*********\n";
                std::cout << "SCORECARD\n";
                std::cout << "*********\n";
                std::cout << "player score: " << ps << '\n';
                std::cout << "computer score: " << cs << '\n';
                break;
            case 'l':
                std::cout << "YOU LOST\n";
                cs++;
                std::cout << "*********\n";
                std::cout << "SCORECARD\n";
                std::cout << "*********\n";
                std::cout << "player score: " << ps << '\n';
                std::cout << "computer score: " << cs << '\n';
                break;
        }

        std::cout << "Do you want to play again(y/n): ";
        std::cin >> ch;
        if(ch == 'n' || ch == 'N') {
            is_running = false;
        }
    }while(is_running);

    return 0;
}