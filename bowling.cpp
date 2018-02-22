#include <iostream>

using namespace std;

const int tenthframe = 19;
int getInput(int ball, int balls[]); //gets input and checks if input is valid, loops until valid input
void printScores(int ball, int balls[]);
int getNextBalls(int i, int balls[]);//returns the value of the next 2 balls
void tenthFrame(int balls[]);

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
		score = getInput(ball, balls);
		balls[ball-1]=score;
		if(ball % 2 != 0 && score == 10)//is strike...
			++ball; //skip next ball
		++ball; //increment ball
		printScores(ball, balls);
	}
	
	tenthFrame(balls);
	
	return 0;
}

void printScores(int ball, int balls[])
{
	int total=0;
	
	//print ball scores
	for(int i=0; i<18; i=i+2)
		cout<<"|"<<balls[i]<<" "<<balls[i+1];
	cout<<"|"<<balls[18]<<" "<<balls[19]<<" "<<balls[20]<<"|"<<endl;
	
	//print frame totals
	for(int i=0; i<ball-1; i=i+2)
	{
		if(balls[i]!=10) //if not strike...
		{	//print normally
			total += balls[i]+balls[i+1];
			cout<<"| "<<balls[i]+balls[i+1]<<" ";
		}
		else //is strike...
		{	//print special
			if(i!=16)//not in 9th frame
			{
				total += balls[i]+balls[i+1]+getNextBalls(i+2, balls);
				cout<<"| "<<balls[i]+balls[i+1]+getNextBalls(i+2, balls)<<" ";
			}
			else//in 9th frame
			{
				total += balls[i]+balls[18]+balls[19];
				cout<<"| "<<balls[i]+balls[18]+balls[19]<<" ";
			}
		}
	}
	if(ball >= tenthframe)
	{
		total += balls[18]+balls[19]+balls[20];
		cout<<"| "<<balls[18]+balls[19]+balls[20]<<"   ";
	}
	cout<<"|\nGRAND TOTAL: "<<total<<endl;
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
	

int getInput(int ball, int balls[])
{
	int score = 0;
	bool valid = false;
	bool notInt = false;
	
	cout<<"Next Ball: ";
	cin>>score;
	
	if(cin.fail())//not an int type
	{
		notInt = true;
		cin.clear();
	}
		
	while(notInt)
	{
		cin.clear();
		cout<<"Invalid Input1. Try again:";
		cin.ignore();
		cin>>score;
		if(cin.good())
			notInt=false;
	}
	
	if(ball < tenthframe)//not tenth frame
	{
		while( !valid )
		{	
			if( score >= 0 && score <=10 )// score is in range
			{
				if(ball%2 == 0 && balls[ball-2]+score <= 10)//on 2nd ball and ball1 + input <= 10
					valid = true;
				else if(ball%2 != 0)
					valid = true;
			}
		
			if( !valid )//input not valid
			{
				cout<<"Invalid Input2. Try again:";
				cin>> score;
			}
		}
	}
	else //is tenth frame
	{
		while( !valid )
		{
			if( score >= 0 && score <= 10 )//score is in range
			{
				if( balls[18]+balls[19]+balls[20]+score <= 30)//10th frame total <= 30
					valid = true;
			}
			
			if( !valid )//invalid input
			{
				cout<<"Invalid Input3. Try again."<<endl;
				cin>>score;
			}
		}
	}
	return score;
}


void tenthFrame(int balls[])
{
	int roll1, roll2, roll3; //3 rolls of the 10th frame
	int total_score = 0; //total score for the 10th frame
	int tenthTotal = 0;
	
	//get roll1
	roll1 = getInput(tenthframe, balls);
	balls[18]=roll1;
	
	//print scores
	printScores(tenthframe, balls);
	
	//validate roll2
	roll2 = getInput(tenthframe, balls);
	balls[19]=roll2;
	
	//print scores
	printScores(tenthframe, balls);
	
	//begin roll 3 if stike or spare
	if(roll1+roll2 >= 10)
	{
		//get roll3
		roll3 = getInput(tenthframe, balls);
		balls[20]=roll3;
		
		//print scores
		printScores(tenthframe, balls);

	}
	//end of game...
}








