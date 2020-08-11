#include<stdio.h>
#include<string.h>

void criptografa(char *msg,int t);

int main()
{
	char m[81];
	int tam,i;
	
	gets(m);
	tam = strlen(m);
	criptografa(m,tam);
	
		
}

void criptografa(char *msg, int t)
{
	char cripto[81];
	int i;
	
	
	for(i=0;i<t;i++)
	{
		if(msg[i]=='z')
			cripto[i] = 'a';
		else
		{
		
			if(msg[i]=='Z')
				cripto[i]='A';
			else
			{
				if(msg[i]==32)
					cripto[i]=32;
				else
					cripto[i]=msg[i]+1;
			}	
			
		}
	}
	printf("%s\n",msg);
	printf("%s\n",cripto);
	return;
	
}
