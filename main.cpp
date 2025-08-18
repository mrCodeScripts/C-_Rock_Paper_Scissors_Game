#include <iostream>
#include <algorithm>
#include <random>
#include <conio.h>
#include <cstdlib>

int pickRandomNumber(int min, int max)
{
    std::random_device random_device;
    std::mt19937 seedGenerator(random_device());
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(seedGenerator);
}

std::string getPlayerSelected(int &itemSelected)
{
    std::string selections[] = {"Exit", "Rock", "Paper", "Scissors"};
    if (itemSelected >= (sizeof(selections) / sizeof(selections[0])))
    {
        return "lmao";
    }
    return selections[itemSelected];
}

void sendRoundResponseResult(int &p1Score, int &p2Score, std::string &p1Selected, std::string &p2Selected, std::string humanName, int &maxScore)
{
    std::string player1WinsStatement = R"(
 ____  _                         _  __        ___           _ 
|  _ \| | __ _ _   _  ___ _ __  / | \ \      / (_)_ __  ___| |
| |_) | |/ _` | | | |/ _ \ '__| | |  \ \ /\ / /| | '_ \/ __| |
|  __/| | (_| | |_| |  __/ |    | |   \ V  V / | | | | \__ \_|
|_|   |_|\__,_|\__, |\___|_|    |_|    \_/\_/  |_|_| |_|___(_)
               |___/                                           
    )";

    std::string player2WinsStatement = R"(
 ____  _                         ____   __        ___           _ 
|  _ \| | __ _ _   _  ___ _ __  |___ \  \ \      / (_)_ __  ___| |
| |_) | |/ _` | | | |/ _ \ '__|   __) |  \ \ /\ / /| | '_ \/ __| |
|  __/| | (_| | |_| |  __/ |     / __/    \ V  V / | | | | \__ \_|
|_|   |_|\__,_|\__, |\___|_|    |_____|    \_/\_/  |_|_| |_|___(_)
               |___/                                              
    )";

    std::string playersDrawStatement = R"(
 ____                     _ 
|  _ \ _ __ __ ___      _| |
| | | | '__/ _` \ \ /\ / / |
| |_| | | | (_| |\ V  V /|_|
|____/|_|  \__,_| \_/\_/ (_) 
    )";

    std::string playerInvalidInput = R"(
 ___                 _ _     _   ___                   _   _ 
|_ _|_ ____   ____ _| (_) __| | |_ _|_ __  _ __  _   _| |_| |
 | || '_ \ \ / / _` | | |/ _` |  | || '_ \| '_ \| | | | __| |
 | || | | \ V / (_| | | | (_| |  | || | | | |_) | |_| | |_|_|
|___|_| |_|\_/ \__,_|_|_|\__,_| |___|_| |_| .__/ \__,_|\__(_)
                                          |_|                
    )";

    std::string playerWins = R"(
     ▄▄   ▄▄ ▄▄▄▄▄▄▄ ▄▄   ▄▄    ▄     ▄ ▄▄▄ ▄▄    ▄ ▄▄ 
█  █ █  █       █  █ █  █  █ █ ▄ █ █   █  █  █ █  █
█  █▄█  █   ▄   █  █ █  █  █ ██ ██ █   █   █▄█ █  █
█       █  █ █  █  █▄█  █  █       █   █       █  █
█▄     ▄█  █▄█  █       █  █       █   █  ▄    █▄▄█
  █   █ █       █       █  █   ▄   █   █ █ █   █▄▄ 
  █▄▄▄█ █▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█  █▄▄█ █▄▄█▄▄▄█▄█  █▄▄█▄▄█
)";
    std::string playerLose = R"(
    ▄▄   ▄▄ ▄▄▄▄▄▄▄ ▄▄   ▄▄    ▄▄▄     ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄ 
█  █ █  █       █  █ █  █  █   █   █       █       █       █       █  █
█  █▄█  █   ▄   █  █ █  █  █   █   █   ▄   █   ▄   █  ▄▄▄▄▄█    ▄▄▄█  █
█       █  █ █  █  █▄█  █  █   █   █  █ █  █  █ █  █ █▄▄▄▄▄█   █▄▄▄█  █
█▄     ▄█  █▄█  █       █  █   █▄▄▄█  █▄█  █  █▄█  █▄▄▄▄▄  █    ▄▄▄█▄▄█
  █   █ █       █       █  █       █       █       █▄▄▄▄▄█ █   █▄▄▄ ▄▄ 
  █▄▄▄█ █▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█  █▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄█ 
    )";

    if (p1Score >= maxScore) {
        std::cout << playerWins << std::endl;;
    }
    if (p2Score >= maxScore) {
        std::cout << playerLose << std::endl;;
    }

    if (p1Selected == p2Selected)
    {
        std::cout << playersDrawStatement << std::endl;
    }
    else if (p1Selected == "Rock")
    {
        if (p2Selected == "Scissors")
        {
            std::cout << " " << std::endl;
            std::cout << player1WinsStatement << std::endl;
            std::cout << "You picked: " + p1Selected << ", Bot Picked: " << p2Selected << std::endl;
        }
        else
        {
            std::cout << " " << std::endl;
            std::cout << player2WinsStatement << std::endl;
            std::cout << "You picked: " + p1Selected << ", Bot Picked: " << p2Selected << std::endl;
        }
    }
    else if (p1Selected == "Paper")
    {
        if (p2Selected == "Rock")
        {
            std::cout << " " << std::endl;
            std::cout << player1WinsStatement << std::endl;
            std::cout << "You picked: " + p1Selected << ", Bot Picked: " << p2Selected << std::endl;
        }
        else
        {
            std::cout << " " << std::endl;
            std::cout << player2WinsStatement << std::endl;
            std::cout << "You picked: " + p1Selected << ", Bot Picked: " << p2Selected << std::endl;
        }
    }
    else if (p1Selected == "Scissors")
    {
        if (p2Selected == "Paper")
        {
            std::cout << " " << std::endl;
            std::cout << player1WinsStatement << std::endl;
            std::cout << "You picked: " + p1Selected << ", Bot Picked: " << p2Selected << std::endl;
        }
        else
        {
            std::cout << " " << std::endl;
            std::cout << player2WinsStatement << std::endl;
            std::cout << "You picked: " + p1Selected << ", Bot Picked: " << p2Selected << std::endl;
        }
    }
    else
    {
        std::cout << playerInvalidInput << std::endl;
    }
}

int analyzeInput(std::string p1, std::string p2, int &p1Score, int &p2Score, bool &exit, int &maxScore)
{
    if (p1Score >= maxScore) {
        exit = true;
    }
    if (p2Score >= maxScore) {
        exit = true;
    }


    if (p1 == p2)
    {
        std::cout << "" << std::endl;
    }

    if (p1 == "Rock")
    {
        if (p2 == "Scissors")
        {
            p1Score++;
        }
        else
        {
            p2Score++;
        }
    }

    if (p1 == "Paper")
    {
        if (p2 == "Rock")
        {
            p1Score++;
        }
        else
        {
            p2Score++;
        }
    }

    if (p1 == "Scissors")
    {
        if (p2 == "Paper")
        {
            p2Score++;
        }
        else
        {
            p2Score++;
        }
    }

    if (p1 == "Exit")
    {
        exit = true;
    }
    return 0;
}

void play(int &player1Score, int &player2Score, std::string &player1Selected, std::string &player2Selected, std::string player1Name, bool &gameStarted, bool &exit)
{
    gameStarted = true;
    int player1IntSelection;

    std::cin >> player1IntSelection;

    int player2RandomPick = pickRandomNumber(1, 3);
    player2Selected = getPlayerSelected(player2RandomPick);
    player1Selected = getPlayerSelected(player1IntSelection);

    analyzeInput(player1Selected, player2Selected, player1Score, player2Score, exit);
}

int main()
{
    std::string name;
    bool exit = false;
    bool isAlreadyGreeted = false;
    int player1Score = 0;
    int player2Score = 0;
    int maxScore = 10;
    std::string player1Selected, player2Selected;
    bool gameStarted = false;

    while (true)
    {
        system("cls");
        if (name.empty())
        {
            std::cout << "Enter your name: ";
            std::getline(std::cin, name);
            std::cout << "Would you like to set Max Score (Default Max Score: 10)? Set Max Score: ";
            std::cin >> maxScore;
        }

        if (!isAlreadyGreeted)
        {
            std::cout << "" << std::endl;
            std::cout << "+==============================================================+" << std::endl;
            std::cout << "================================================================" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Hello, " << name << "! Welcome to the Rock-Paper-Scissors game!" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "================================================================" << std::endl;
            std::cout << "+==============================================================+" << std::endl;
            std::cout << "" << std::endl;
            isAlreadyGreeted = true;
        }

        if (exit)
        {

            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << R"(  ________________________
 (   "Well Played."      )
  ------------------------
              \
               \
                .-""""-.
               /  _  _  \
              /  (o)(o)  \
             |     ^      |
             |   \___/    |
             |  .-----.   |
          _.-|_/  ___  \__|-. _
       .-'    /  /   \  \     '-.
      /      /__/_____\__\       \
     /     _/  /_____\  \_        \
    /     /__.-'     '-.__\        \
    |      /   .-"""-.   \         |
    |     /   /  ___  \   \        |
    |     |  |  (___)  |  |        |
    |     |  |   ___   |  |        |
    |     |   \ (___) /   |        |
    |      \   '-----'   /         |
    \       '._       _.'         /
     \          '---'            /
      '._                    _.'
         '-.__          __.-'
               '--------'
)";
            break;
        }

        std::cout << "" << std::endl;
        std::cout << "+================================================================+" << std::endl;
        std::cout << "===                                                            ===" << std::endl;
        std::cout << "===   Pick: 1 -> Rock, 2 -> Paper, 3 -> Scissors, 0 -> Exit:   ===" << std::endl;
        std::cout << "===                                                            ===" << std::endl;
        std::cout << "+================================================================+" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;

        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << R"(
 ____                       ____                      _ 
/ ___|  ___ ___  _ __ ___  | __ )  ___   __ _ _ __ __| |
\___ \ / __/ _ \| '__/ _ \ |  _ \ / _ \ / _` | '__/ _` |
 ___) | (_| (_) | | |  __/ | |_) | (_) | (_| | | | (_| |
|____/ \___\___/|_|  \___| |____/ \___/ \__,_|_|  \__,_|
        )" << std::endl;
        std::cout << "=========================================================" << std::endl;
        std::cout << "Player 1: " << " " << name << " Score: " << std::to_string(player1Score) << std::endl;
        std::cout << "Player 2: " << " Bot" << " Score: " << std::to_string(player2Score) << std::endl;
        std::cout << "=========================================================" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;

        if (gameStarted)
        {
            sendRoundResponseResult(player1Score, player2Score, player1Selected, player2Selected, name, maxScore);
        }

        play(player1Score, player2Score, player1Selected, player2Selected, name, gameStarted, exit);
    }

    return 0;
}