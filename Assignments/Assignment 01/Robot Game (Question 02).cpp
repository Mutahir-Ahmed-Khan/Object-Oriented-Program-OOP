#include <iostream>
using namespace std;

class Robot;
class Ball;
class Goal;

class Robot {
private:
    string robotName;
    int hitCount;

public:
    Robot() {}

    Robot(string name) {
        robotName = name;
    }

    void hitBall(int &ballPosX, int &ballPosY, const string &moveDirection) {
        if (moveDirection == "up") {
            ballPosY++;
        } else if (moveDirection == "down") {
            ballPosY--;
        } else if (moveDirection == "right") {
            ballPosX++;
        } else if (moveDirection == "left") {
            ballPosX--;
        } else {
            cout << "Invalid Direction!" << endl;
        }
        hitCount++;
    }

    int getHitCount() {
        return hitCount;
    }
};

class Ball {
private:
    int posX;
    int posY;

public:
    Ball(int x, int y) {
        posX = x;
        posY = y;
    }

    Ball() {}

    int getPosX() {
        return posX;
    }

    int getPosY() {
        return posY;
    }

    void move(int newX, int newY) {
        posX = newX;
        posY = newY;
    }

    int* getPosition() {
        static int position[2];
        position[0] = posX;
        position[1] = posY;
        return position;
    }
};

class Goal {
private:
    int goalPosX;
    int goalPosY;

public:
    Goal() {
        goalPosX = 3;
        goalPosY = 3;
    }

    int isGoalReached(int ballPosX, int ballPosY) {
        return (ballPosX == goalPosX && ballPosY == goalPosY);
    }
};

class Team {
public:
    string teamName;
    Robot *teamPlayer;

    Team(string name, Robot *player) {
        teamName = name;
        teamPlayer = player;
    }
    
    Team() {}
};

class Game {
    Team teamA;
    Team teamB;
    Ball gameBall;
    Goal gameGoal;

    int ballX;
    int ballY;

public:
    string moveDirection;

    Game(Team t1, Team t2, Ball ball, Goal goal) {
        teamA = t1;
        teamB = t2;
        gameBall = ball;
        gameGoal = goal;
        ballX = 0;
        ballY = 0;
    }

    void play(Team *currentTeam) {
        currentTeam->teamPlayer->hitBall(ballX, ballY, moveDirection);
        gameBall.move(ballX, ballY);
    }

    void startGame() {
        ballX = gameBall.getPosX();
        ballY = gameBall.getPosY();

        while (!gameGoal.isGoalReached(ballX, ballY)) {
            cout << "Team A, your turn: Enter direction: ";
            cin >> moveDirection;
            play(&teamB);
        }

        ballX = 0;
        ballY = 0;

        while (!gameGoal.isGoalReached(ballX, ballY)) {
            cout << "Team B, your turn: Enter direction: ";
            cin >> moveDirection;
            play(&teamA);
        }
    }

    void declareWinner() {
        int hitsTeamA = teamA.teamPlayer->getHitCount();
        int hitsTeamB = teamB.teamPlayer->getHitCount();

        if (hitsTeamA < hitsTeamB) {
            cout << teamA.teamName << " Wins!!" << endl;
        } else {
            cout << teamB.teamName << " Wins!!" << endl;
        }
    }
};

int main() {
    string robotName1 = "RobotOne";
    string robotName2 = "RobotTwo";
    Robot robot1(robotName1), robot2(robotName2);
    Team team1("Team A", &robot1);
    Team team2("Team B", &robot2);
    Ball ball(0, 0);
    Goal goal;

    Game game(team1, team2, ball, goal);
    game.startGame();

    if (team1.teamPlayer->getHitCount() < team2.teamPlayer->getHitCount()) {
        cout << "Team A";
    } else {
        cout << "Team B";
    }

    return 0;
}
