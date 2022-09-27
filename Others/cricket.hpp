#include <iostream>
#include <math.h>
#include <time.h>

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
    int num;
    for (int i = 0; i < count; i++)
    {
        num = (rand() % (upper - lower + 1)) + lower;
    }
    return num;
}

int cricket::playerBat(int done, int computerRun)
{
    int playerHit, ComputerBall, playerRun = 0, computerHit, playerBall;
    if (done == 0)
    {
        while (1)
        {
            printf("You should play between 1 to 6 or else you will be out\n:");
            cin.sync();
            cin >> playerHit;
            ComputerBall = random_selector(1, 6, 1);
            printf("COMPUTER GAVE : %d", ComputerBall);
            printf("\n");
            if (playerHit != ComputerBall)
            {
                playerRun += playerHit;
            }
            if (playerHit == ComputerBall)
            {
                printf("YOU ARE OUT\n");
                break;
            }
            if (playerHit > 6 || playerHit < 1)
            {
                printf("YOU LOSE!\n");
                return -1;
                break;
            }
        }
    }
    if (done == 1)
    {
        while (1)
        {
            printf("You should play between 1 to 6 or else you will be out\n:");
            cin.sync();
            cin >> playerHit;
            ComputerBall = random_selector(1, 6, 1);
            printf("COMPUTER GAVE : %d", ComputerBall);
            printf("\n");
            if (playerHit != ComputerBall)
            {
                playerRun += playerHit;
            }
            if (playerHit == ComputerBall && playerRun <= computerRun || playerHit < 1 || playerHit > 6)
            {
                printf("YOU LOSE!!\n");
                break;
            }
            if (playerRun > computerRun)
            {
                printf("CONGRATULATIONS! YOU WON THE MATCH\n");
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
            printf("You are balling. Selecet between 1 to 6 or else computer will own\n:");
            cin.sync();
            cin >> playerBall;
            printf("COMPUTER GAVE : %d\n", computerHit);

            if (computerHit != playerBall)
            {
                computerRun += computerHit;
            }
            if (computerHit == playerBall && computerRun <= playerRun)
            {
                printf("CONGRATULATIONS! YOU WON THE MATCH\n");
                break;
            }
            if (computerRun > playerRun || playerBall > 6 || playerBall < 1)
            {
                printf("YOU LOSE\n");
                break;
            }
            printf("COMPUTER TOTAL RUN : %d\n", computerRun);
        }
    }
    if (done == 0)
    {
        while (1)
        {
            computerHit = random_selector(1, 6, 1);
            printf("You are balling. Selecet between 1 to 6 or else computer will own\n:");
            cin.sync();
            cin >> playerBall;
            printf("COMPUTER GAVE : %d\n", computerHit);

            if (computerHit != playerBall)
            {
                computerRun += computerHit;
            }
            if (computerHit == playerBall)
            {
                printf("COMPUTER IS OUT\n");
                break;
            }
            if (playerBall > 6 || playerBall < 1)
            {
                printf("YOU LOSE\n");
                return -1;
                break;
            }
            printf("COMPUTER TOTAL RUN : %d\n", computerRun);
        }
    }
    return computerRun;
}

void cricket::cricketGame()
{
    if (cricket::startgame)
    {
        int toss, playerChoice, decision, playerRun = 0, playerHit, ComputerRun = 0, ComputerHit, ComputerBall;

        printf("WELCOME TO CRICKET GROUNDS\n\nChose Head(1) or Tail(0)\n");
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
            printf("CONGRATULATIONS! YOU WON THE TOSS\nPress 1 for Bat and 0 for Ball: ");
            cin.sync();
            cin >> decision;

            // if player chose to bat
            if (decision == 1)
            {
                playerRun = playerBat(0, 0);
                printf("\nYOUR TOTAL RUN : %d\n", playerRun);
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
                printf("COMPUTER CHOSE TO BAT\n");
                ComputerRun = playerBall(0, playerRun);
                playerRun = playerBat(1, ComputerRun);
            }
            else
            {
                printf("COMPUTER CHOSE TO BALL\n");
                playerRun = playerBat(0, 0);
                printf("\nYOUR TOTAL RUN : %d\n", playerRun);
                ComputerRun = playerBall(1, playerRun);
            }
        }
    }
    else
    {
        cout << "No Problem\n";
    }
}