#include<stdio.h>
#include <stdlib.h>
void Drawing();             // draw the game
void PlayerMove(char);     // record the move of the player
void EndGameCheck(char*); //check the status after the player move

	char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};	
	char GameCheck=1;   // 1 :game is not over   2:player one or two won  3:Draw
	char EmptySquare=9;
void main(void)  
{
	 char player=1;

		Drawing(); 
	do{
		PlayerMove(player);
		system("cls");
		Drawing();
		EndGameCheck(&player);

	}while(GameCheck==1);
	
	
	
}
void Drawing()
{
	for(char j=0;j<3;j++)
	{
		for(char i=0;i<3;i++)
		{
			printf("%c |",arr[j][i]);
		}
		printf("\n");
	}

}	
void PlayerMove(char player)
{
	char sign; // x or o
	char valid=1; // choice is valid ? 1:Yes 2:No 
	char choice; // which box ?
	printf("player %d enter a number ",player);	
	scanf("%s",&choice);
	do
	{
		if((choice<'1'||choice>'9')||((choice=='1')&&(arr[0][0]!='1'))||((choice=='2')&&(arr[0][1]!='2'))
			||((choice=='3')&&(arr[0][2]!='3'))||((choice=='4')&&(arr[1][0]!='4'))||((choice=='5')&&(arr[1][1]!='5'))
			||((choice=='6')&&(arr[1][2]!='6'))||((choice=='7')&&(arr[2][0]!='7'))||((choice=='8')&&(arr[2][1]!='8'))
			||((choice=='9')&&(arr[2][2]!='9')))
		{
			
		printf("please enter a valid number ");
		scanf("%s",&choice);
		}
		else
			valid=2;
	}while(valid==1);
	
	if(player==2)
	{
		sign='o';
	}
	else
		sign='x';
	switch(choice)
	{
		case '1':
		arr[0][0]=sign;
		break;
		case '2':
		arr[0][1]=sign;
		break;
		case '3':
		arr[0][2]=sign;
		break;
		case '4':
		arr[1][0]=sign;
		break;
		case '5':
		arr[1][1]=sign;
		break;
		case '6':
		arr[1][2]=sign;
		break;
		case '7':
		arr[2][0]=sign;
		break;
		case '8':
		arr[2][1]=sign;
		break;
		case '9':
		arr[2][2]=sign;
		break;
	}
			

}

	void EndGameCheck(char*PtrtoPlayer)
	{ 
				EmptySquare--;
		if((arr[0][0]==arr[0][1])&&(arr[0][0]==arr[0][2]))
			GameCheck=2;
		else if((arr[1][0]==arr[1][1])&&(arr[1][0]==arr[1][2]))
			GameCheck=2;
		else if((arr[2][0]==arr[2][1])&&(arr[2][0]==arr[2][2]))
			GameCheck=2;
		else if((arr[0][0]==arr[1][0])&&(arr[0][0]==arr[2][0]))
			GameCheck=2;
		else if((arr[0][1]==arr[1][1])&&(arr[0][1]==arr[2][1]))
			GameCheck=2;
		else if((arr[0][2]==arr[1][2])&&(arr[0][2]==arr[2][2]))
			GameCheck=2;
		else if((arr[0][0]==arr[1][1])&&(arr[0][0]==arr[2][2]))
			GameCheck=2;
		else if((arr[0][2]==arr[1][1])&&(arr[0][2]==arr[2][0]))
			GameCheck=2;
		else if(EmptySquare==0)
			GameCheck=3;
		
		if (GameCheck==2)
		{
		printf("player %d won  ",*PtrtoPlayer);	
		}
		else if(GameCheck==3)
		{
			printf("Draw");
		}
		if (*PtrtoPlayer==1)
		{
			*PtrtoPlayer=2;
		}
		else if(*PtrtoPlayer==2)
		{
			*PtrtoPlayer=1;
		}
	}
