#include <iostream>

using namespace std;

const int tenthframe = 19;
int checkInput(int ball, int score, int balls[]); //NEEDS WORK. gets input and checks if input is valid, loops until valid input
void printScores(int b, int balls[]);
int getNextBalls(int i, int balls[]);//returns the value of the next 2 balls

int main()
{
	int balls[21];
	//generate new score card
	//set everything to NULL
	for(int i=0; i<21; ++i)
		balls[i]=0;
	
	int score=0;//input variable
	int ball=1;//current ball
	//run game through 9th frame
	while(ball < tenthframe)
	{
		score = 0;
		cout<<"Next Ball: ";
		cin>>score;
		score = checkInput(ball, score, balls);//needs work
		balls[ball-1]=score;
		if(ball % 2 != 0 && score == 10)//is strike...
			++ball; //skip next ball
		++ball; //increment ball
		printScores(ball, balls);
	}
	
	score = 0;
	//begin special case for frame 10
	
	return 0;
}

void printScores(int b, int balls[])
{
	int total=0;
	for(int i=0; i<19; i=i+2)
	{
		if(balls[i]!=10) //if not strike...
		{	//print normally
			total += balls[i]+balls[i+1];
			cout<<balls[i]<<" "<<balls[i+1]<<" Frame Total: "<<balls[i]+balls[i+1]<<endl;
		}
		else //is strike...
		{	//print special
			total += balls[i]+balls[i+1]+getNextBalls(i+2, balls);
			cout<<balls[i]<<" "<<balls[i+1]<<" Frame Total: "<<(balls[i]+balls[i+1]+getNextBalls(i+2, balls))<<endl;
		}
	}
	cout<<"GRAND TOTAL: "<<total<<endl;
}

//returns value of next 2 balls
int getNextBalls(int i, int balls[])
{
	if(i<19)//not 10th frame
	{
		if(balls[i]!=10) //next ball not strike
			return balls[i]+balls[i+1];
		else //next ball is strike
			return balls[i]+balls[i+2];
	}
	else //handles in 10th frame UNTESTED maybe broken
		return balls[i]+balls[i+1];
}
	

int checkInput(int ball, int score, int balls[])
{
	while((score < 0 || score > 10) || (ball%2 == 0 && (balls[ball-1] + score > 10)))
	{
		cout<<"Invalid Input. Try again."<<endl;
		cin>> score;
	}
	return score;
}











