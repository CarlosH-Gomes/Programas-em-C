#include<stdio.h>


// prot�tipo das fun��es
float soma(float n1, float n2);
float mult(float n1, float n2);
float div(float n1, float n2);
float sub(float n1, float n2);
int resto(float n1, float n2);
void menu(float n1,float n2);

int main()
{
	float n1,n2,r;
	
	printf("Digite dois numeros reais\n");
	scanf("%f%f",&n1,&n2);
	menu(n1,n2);
}

void menu(float n1, float n2)
{
	char op;
	float result;
	int mod;
	
	//do
	//{
		printf("Digite a opera��o desejada\n");
		printf("Digite + para adi��o\n");
		printf("Digite - para subtra��o\n");
		printf("Digite * para multiplicacao\n");
		printf("Digite / para divisao\n");
		printf("Digite %% para o resto da divis�o\n");
		fflush(stdin);
		scanf(" %c",&op);//op = getchar();
		switch(op)
		{
			case '+':
				result = soma(n1,n2);
				printf("%f\n",result);
				break;
			case '-':
				result = sub(n1,n2);
				printf("%f\n",result);
				break;
			case '*':
				result = mult(n1,n2);
				printf("%f\n",result);
				break;
			case '/':
				if(n2)
				{
				
					result = div(n1,n2);
					printf("%f\n",result);
				}
				else
					printf("n�o existe divis�o por zero\n");
				break;
			case '%':
				if(n2)
				{
				
					mod = resto(n1,n2);
					printf("%d\n",mod);
				}
				else
					printf("n�o existe divis�o por zero\n");
				break;
			default:
				printf("Operador inv�lido\n");
		}
	//}while((op!='+') && (op!= '-' ) && (op!= '*' )&& (op != '/') && (op!='%%'));
	
}
float soma(float n1, float n2)
{
	float r;
	
	r = n1+n2;
	return  r;
	
}

float mult(float n1, float n2)
{
	return (n1*n2);
}

float div(float n1, float n2)
{
	
	return n1/n2;
			
	
}
float sub(float n1, float n2)
{
	return n1-n2;
}

int resto (float n1,float n2)
{
	int a,b;
	a = (int)n1;
	b = (int)n2;
	printf("a=%d b=%d\n",a,b);
	return a%b;
}

