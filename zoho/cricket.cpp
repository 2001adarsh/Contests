#include<bits/stdc++.h>
using namespace std;
#define int long long int


class Cricket
{
    vector<int> scores;
    vector<int> playedBalls;
    int striker = -1, non_striker = -1;
    int teamScore;
    int teamExtras;
    int numberOfBalls = 0;
    double run_rate = 0.0;
    int nextPlayer = 0;

public:
    int ballsLeft = 0;

    void scoresAtPoint() {
        cout << "Team Score: " << teamScore << " , Team Extras: " << teamExtras << ", Run-rate : " << run_rate << endl;
        for (int i = 0; i < scores.size(); i++) {
            cout << "Runs made by " << i << "th player: " << scores[i] << " Strike Rate :" << ( (double)scores[i] / (double) playedBalls[i]) * 100 << endl;
        }
        cout << endl << endl;
    }
    // 1lb, 2b, 3wd, w, n
    void eachBall(string ball) {
        string extras = "";
        int run = 0;
        for (int i = 0; i < ball.size(); i++) {
            if (ball[i] >= '0' and ball[i] <= '6')
                run = (run * 10) + (ball[i] - '0');
            else
                extras += ball[i];
        }

        teamScore += run;
        if (extras == "lb" or extras == "b" or extras == "wd")
            teamExtras += run;
        else
            scores[striker] += run;

        if (extras != "wd" and extras != "n")
            playedBalls[striker]++, numberOfBalls++, ballsLeft--;

        if (extras == "n")
            teamScore++, teamExtras++;

        if (extras == "w") { //got a wicket
            striker = nextPlayer;
            nextPlayer++;
        }

        cout << "After ball: " << numberOfBalls << " ";

        run_rate = ( (double) teamScore / (double) numberOfBalls) * 6;

        scoresAtPoint();
        if (extras == "wd" or extras == "n")
            run--;

        if (run % 2 == 1)
            swap(striker, non_striker);
        if (numberOfBalls % 6 == 0)
            swap(striker, non_striker);

    }

    Cricket() {
        striker = 0;
        non_striker = 1;
        scores.assign(4, 0);
        teamExtras = 0;
        teamScore = 0;
        playedBalls.assign(4, 0);
        run_rate = 0.0;
        nextPlayer = 2;
    }
};

int32_t main()
{

    Cricket cricket;

    int oversToPlay;
    cout << "Insert the number of overs in an inning: ";
    cin >> oversToPlay;
    cricket.ballsLeft = (6 * oversToPlay);

    cout << "Start entering balls to play: ";
    string input;
    cin >> input;
    do {
        if (input == "E" or cricket.ballsLeft == 0)
            break;

        cricket.eachBall(input);

        if (input == "E" or cricket.ballsLeft == 0)
            break;
        cin >> input;

    } while (input != "E" and cricket.ballsLeft != 0);

    return 0;
}