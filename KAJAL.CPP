#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
class EXPR
{
		char INFIX[50],POSTFIX[50];
	public:
		EXPR();
		void READ_INFIX();
		void INFIX_POSTFIX();
		void SHOW_INFIX();
		void SHOW_POSTFIX();
		int IS_OPR(char);
		int PRIORITY(char);
		void EVALUATION();
		int OPR(char, int,int);
};
EXPR::EXPR()
{
	  strcpy(INFIX,"a+b*(c-d)/e");
}
int EXPR::PRIORITY(char c)
{
	if(c=='+' || c=='-')
		return 1; // true
	else
		if(c=='*' ||c=='/')
			return 2; // true
		else
			return 0; // false
}
int EXPR::IS_OPR(char c)
{
	if(c=='+' || c=='-'|| c=='*' ||c=='/')
		return 1; // true
	else
		return 0; // false
}
void EXPR::READ_INFIX()
{
	cout<<endl<<"Enter an Infix Expression : ";
	cin>>INFIX;
}
void EXPR::INFIX_POSTFIX()
{
	char STK[50];
	int top=0;
	// step 1
	strcat(INFIX,")");
	// step 2
	top=top+1;
	STK[top]='(';
	// step 3
	int i=0,j=-1;
	while(INFIX[i] != '\0')
	{
		if(isalpha(INFIX[i])) // case 1
		{
			j=j+1;
			POSTFIX[j]=INFIX[i];
		}
		else
		{
			if( INFIX[i] == '(' ) // case 2
			{
				top=top+1;
				STK[top]=INFIX[i];
			}
			else
			{
				// if( INFIX[i] =='+' || INFIX[i] =='-'||INFIX[i] =='*'||INFIX[i] =='/') // case 3
				if( IS_OPR(INFIX[i]) ) // case 3
				{
					//     oprator on stack and having higher or equal priority
					while(IS_OPR(STK[top])  && PRIORITY(STK[top]) >= PRIORITY(INFIX[i]) )
					{
							j=j+1;
							POSTFIX[j]=STK[top];
							top=top-1;
					}
					top=top+1;
					STK[top]=INFIX[i];
				}
				else
				{
					if( INFIX[i] == ')' ) // case 4
					{
						while(STK[top] !='(')
						{
							j=j+1;
							POSTFIX[j]=STK[top];
							top=top-1;
						}
						top=top-1; //remove '(' from stk
					}
				}
			}

		}
		i=i+1;
	}
	j=j+1;
	POSTFIX[j]='\0';

}
void EXPR::SHOW_INFIX()
{
}
void EXPR::SHOW_POSTFIX()
{
	cout<<POSTFIX;
}
void EXPR::EVALUATION()
{
	int i=0,temp,STK[50],top=0;
	int result, left, right;
	while(POSTFIX[i] != '\0')
	{
		if(isalpha(POSTFIX[i]))
		{
			cout<<endl<<"Enter value of "<<POSTFIX[i]<<" : ";
			cin>>temp;
			STK[++top]=temp;
		}
		else
		{
			right=STK[top--];
			left=STK[top--];
			result=OPR(POSTFIX[i],left,right);
			STK[++top]=result;
		}
		//cout<<" " <<POSTFIX[i];
		i=i+1;
	}
	cout<<endl<<" Value of expression = "<<STK[top];
}
int EXPR::OPR(char opr, int left, int  right)
{
	if(opr=='+')
		return (left+right);
	else
		if(opr=='-')
			return (left-right);
		else
			if(opr=='*')
				return (left*right);
			else
				return(left/right);
}
void main()
{
	clrscr();
	EXPR obj;
	//obj.READ_INFIX();
	obj.INFIX_POSTFIX();
	//obj.SHOW_INFIX();
	obj.SHOW_POSTFIX();
	obj.EVALUATION();
	getch();
}
