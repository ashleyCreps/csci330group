#include <iostream>

using namespace std;

const int tenthframe = 19;
int checkInput(int ball, int score, int balls[]); //NEEDS WORK. gets input and checks if input is valid, loops until valid input
void printScores(int b, int balls[]);
int getNextBalls(int i, int balls[]);//returns the value of the next 2 balls
int roll1, roll2, roll3; //3 rolls of the 10th frame
int total_score = 0;    //total score for the 10th frame

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
	if( ball >= tenthframe && ball <= tenthframe+2)
	{
	    	cout<<"Enter roll1";
		cin >> roll1;
		if(roll1 == 10){
		   
		        cout<< "Strike";
		        total_score = total_score+10;
		        cout << total_score;
	       }
	   
	   	else if(roll1<=10){    //If roll1 is less than or = 10, enter roll2
	       		cout<< "roll2";
			cin >> roll2;
	       		if(roll1+roll2 ==10){
		           cout <<"Spare";
		           total_score = total_score+roll1+roll2;
		           cout<<total_score;
		        }
	       
	       		else if(roll1+roll2>10){  //if roll1+roll2 is greater than 10, get the last roll of the entire game
		           cout<<"Enter Roll3";
		           cin >> roll3;
		           total_score = total_score + roll3;
		           cout << total_score;
	           
		        }
	    	}
	}
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
	
	if( i >= 19 & i <=21)
	{
	    	cout<<"Enter roll1";
		cin >> roll1;
		if(roll1 == 10){
		        cout<< "Strike";
		        total_score = total_score+10;
		        cout << total_score;
		   }
	   
		   else if(roll1<=10){    //If roll1 is less than or = 10, enter roll2
		       cout<< "roll2";
		       cin >> roll2;
		       if(roll1+roll2 ==10){
		           cout <<"Spare";
		           total_score = total_score+roll1+roll2;
		           cout<<total_score;
		       }
	       
		       else if(roll1+roll2>10){  //if roll1+roll2 is greater than 10, get the last roll of the entire game
		           cout<<"Enter Roll3";
		           cin >> roll3;
		           total_score = total_score + roll3;
		           cout << total_score;
	           
		       }
		   }
		    
	}
	
	return total_score;
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
