#include <iostream>
#include <math.h>
#include <time.h>
#include <random>
#include <chrono>

using namespace std;

class cricket
{
private:
    int startgame;

public:
    cricket(int start);
    int random_selector(int lower, int upper, int count);
    void cricketGame();
    int playerBat(int done, int computerRun);
    int playerBall(int done, int playerRun);
};

cricket::cricket(int start)
{
    cricket::startgame = start;
}

int cricket::random_selector(int lower, int upper, int count)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib(1, 6);
    return distrib(rng);
}

int cricket::playerBat(int done, int computerRun)
{
    int playerHit, ComputerBall, playerRun = 0, computerHit, playerBall;
    if (done == 0)
    {
        while (1)
        {
            cout << ("You should play between 1 to 6 or else you will be out\n:");
            cin.sync();
            cin >> playerHit;
            ComputerBall = random_selector(1, 6, 1);
            cout << "COMPUTER GAVE : " << ComputerBall << endl;
            cout << ("\n");
            if (playerHit != ComputerBall)
            {
                playerRun += playerHit;
            }
            if (playerHit == ComputerBall)
            {
                cout << ("YOU ARE OUT\n");
                break;
            }
            if (playerHit > 6 || playerHit < 1)
            {
                cout << ("YOU LOSE!\n");
                return -1;
                break;
            }
        }
    }
    if (done == 1)
    {
        while (1)
        {
            cout << ("You should play between 1 to 6 or else you will be out\n:");
            cin.sync();
            cin >> playerHit;
            ComputerBall = random_selector(1, 6, 1);
            cout << "COMPUTER GAVE : " << ComputerBall << endl;
            cout << ("\n");
            if (playerHit != ComputerBall)
            {
                playerRun += playerHit;
            }
            if (playerHit == ComputerBall && playerRun <= computerRun || playerHit < 1 || playerHit > 6)
            {
                cout << ("YOU LOSE!!\n");
                break;
            }
            if (playerRun > computerRun)
            {
                cout << ("CONGRATULATIONS! YOU WON THE MATCH\n");
                break;
            }
        }
    }
    return playerRun;
}

int cricket::playerBall(int done, int playerRun)
{
    int computerHit, computerRun = 0, playerBall;
    if (done == 1)
    {
        while (1)
        {
            computerHit = random_selector(1, 6, 1);
            cout << ("You are balling. Selecet between 1 to 6 or else computer will own\n:");
            cin.sync();
            cin >> playerBall;
            cout << "COMPUTER GAVE : " << computerHit << endl;

            if (computerHit != playerBall)
            {
                computerRun += computerHit;
            }
            if (computerHit == playerBall && computerRun <= playerRun)
            {
                cout << ("CONGRATULATIONS! YOU WON THE MATCH\n");
                break;
            }
            if (computerRun > playerRun || playerBall > 6 || playerBall < 1)
            {
                cout << ("YOU LOSE\n");
                break;
            }
            cout << "COMPUTER TOTAL RUN : " << computerRun << endl;
        }
    }
    if (done == 0)
    {
        while (1)
        {
            computerHit = random_selector(1, 6, 1);
            cout << ("You are balling. Selecet between 1 to 6 or else computer will own\n:");
            cin.sync();
            cin >> playerBall;
            cout << "COMPUTER GAVE : " << computerHit << endl;

            if (computerHit != playerBall)
            {
                computerRun += computerHit;
            }
            if (computerHit == playerBall)
            {
                cout << ("COMPUTER IS OUT\n");
                break;
            }
            if (playerBall > 6 || playerBall < 1)
            {
                cout << ("YOU LOSE\n");
                return -1;
                break;
            }
            cout << "COMPUTER TOTAL RUN : " << computerRun << endl;
        }
    }
    return computerRun;
}

void cricket::cricketGame()
{
    if (cricket::startgame)
    {
        int toss, playerChoice, decision, playerRun = 0, playerHit, ComputerRun = 0, ComputerHit, ComputerBall;

        cout << ("WELCOME TO CRICKET GROUNDS\n\nChose Head(1) or Tail(0)\n");
        cin.sync();
        cin >> playerChoice;

        // toss evaluation
        srand(time(0));
        if (random_selector(1, 100, 1) % 2 == 0)
        {
            toss = 0;
        }
        else
        {
            toss = 1;
        }

        if (playerChoice == toss)
        {
            cout << ("CONGRATULATIONS! YOU WON THE TOSS\nPress 1 for Bat and 0 for Ball: ");
            cin.sync();
            cin >> decision;

            // if player chose to bat
            if (decision == 1)
            {
                playerRun = playerBat(0, 0);
                cout << "\nYOUR TOTAL RUN : " << playerRun << endl;
                ComputerRun = playerBall(1, playerRun);
            }

            // if player chose to ball
            if (decision == 0)
            {
                ComputerRun = playerBall(0, playerRun);
                playerRun = playerBat(1, ComputerRun);
            }
        }
        else
        {
            decision = random_selector(1, 100, 1);
            if (decision % 2 == 0)
            {
                cout << ("COMPUTER CHOSE TO BAT\n");
                ComputerRun = playerBall(0, playerRun);
                playerRun = playerBat(1, ComputerRun);
            }
            else
            {
                cout << ("COMPUTER CHOSE TO BALL\n");
                playerRun = playerBat(0, 0);
                cout << "\nYOUR TOTAL RUN : " << playerRun << endl;
                ComputerRun = playerBall(1, playerRun);
            }
        }
    }
    else
    {
        cout << "No Problem\n";
    }
    getchar();
}