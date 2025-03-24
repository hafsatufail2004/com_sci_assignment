#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Score
{
private:
    int score;
public:
    Score(int inintialScore) : score(inintialScore){}

    Score & operator++(){
        ++score;
        return *this;
    }

    Score & operator--(){
        --score;
        return *this;
    }  

    Score operator--(int){
    Score temp = *this;
    score--;
    return temp;
    }

    int getScore() const{
        return score;
    }  
};

class GuessingGame
{
private:
    int targetNumber;
    Score playerScore;
public:
    GuessingGame() : playerScore(5){
        srand(time(0));
        targetNumber = rand() % 10 +1;
    }

    void play(){
        cout << "Virtual Guessing Game Start!\n";
        cout << "The virtual game player will guess a number between 1 to 10.\n";
        cout << "Score will decrease for incorrect guesses and increase for correct guesses.\n";

        int attempt = 0;
        while(playerScore.getScore() > 0 ){
          attempt++;
          int guess = rand()  % 10 +1;
          cout << "Attempt" << attempt << "player guess:" << guess << ".";

          if(guess > targetNumber){
            cout << "Too low";
            --playerScore;
          }else if(guess < targetNumber){
            cout << " Too high";
            playerScore--;
          }else{
            cout << "Correct";
            ++playerScore;
            return;
          }

          cout << "Total score" << playerScore.getScore() << endl;
        }

        cout << "\n Game Over! The Virtual Player Run Out Of Score.\n";
        cout << "The Correct Number Was:" << targetNumber << endl;

    }
    };

int main(){
    GuessingGame game;
    game.play();
    return 0;
}    