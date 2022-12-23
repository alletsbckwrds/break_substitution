#include <iostream>
using namespace std;

void analyze(string &input, int len, int lettere[26][3])
{
	for(int i=0; i<len; i++)
	{
		if(input[i]>=97 && input[i]<=122) //if char is between 97(a) and 122(z)
			lettere[input[i]-97][1]++;
	}
}

void sostituisci(string &input, int len, int lettere[26][3])
{
	int cc=0;
	bool cerca=1;
	for (int i=0; i<len; i++)
	{
		for (int j=0; j<26; j++) //cerca con difficoltà Nx26(nel senso, 26 possibilità per ogni elemento) la
		{						 //lettera in [i][0] (dove ci sono le lettere dell'input ordinate)
			if (input[i]==(lettere[j][0]+97))
			{
				input[i]=(lettere[j][2]+97); //0+97=A e 25+97=Z
				break;
			}
		}
	}
}

 void letteresort(int lettere[26][3])
 {
 	int temp=0;
 	for(int j=0;j<(26-1);j++)
		for(int i=0;i<(26-1);i++)
		{
			if(lettere[i][1]<lettere[i+1][1])
			{
				temp=lettere[i][1];				//
				lettere[i][1]=lettere[i+1][1];	//swap dei valori di frequenza per le lettere
				lettere[i+1][1]=temp;			//
				
				temp=lettere[i][0];				//
				lettere[i][0]=lettere[i+1][0];	//swap delle lettere per i valori di frequenza
				lettere[i+1][0]=temp;			//(non ho guardato molto questa parte, se non va, forse l'errore è qui.
												//ignorare il commento in caso funzioni)
			}
		}
 }
 
 void sminuscola(string &input, int len) //to lower case
 {
 	for (int i=0; i<len; i++)
 	{
 		if(input[i]>=65 && input[i]<=90) //se carattere maiuscolo (65(A)-90(Z))
 			input[i] += 32; //lo trasforma in minuscolo
	}
 }

int main()
{
	string input;
	
	cout<<"inserisci stringa cifrata: ";
	//input stringa c++
	getline (cin, input);
	
	int lunghezza=input.length();//possiamo usare come lunghezza i byte della stringa, dato che 1 carattere ascii corrisponde ad un byte
	
	//to lower case
	sminuscola(input,lunghezza); //LO SO CHE C'è "TOLOWER()" MA NON MI FIDO.
	
	int lettere[26][3] = {0}; //l'indice 0 corrisponde alla "a"...e il 25 alla "z" (il coso a destra è come una flag da settare,
						      //se è settata su 0 si ha la posizione della lettera nell'alfabeto, e se è settata su 1,
							  //si ha la frequenza di quella lettera. e se si mette su 2, si hanno le posizioni (nell'alfabeto) delle lettere eari...)
	
	
	//quindi [i][0] è 0 1 2 3 4 5 6 7 8 9...
	for (int i=0; i<26; i++)
	{
		lettere[i][0]=i;
	}
	
	
	
	analyze(input,lunghezza,lettere); //rileva la frequenza delle lettere, e la mette in lettere[i][1]
	
	
	//sort in base a lettere[][1]
	letteresort(lettere); //è bubblesort dentro
	//quindi adesso la matrice lettere è stata riordinata secondo la frequenza(spostando anche le corrispettive lettere)
	
	//[i][2] è 4... (le lettere più frequenti in inglese, indicate con numeri ordinali da 0 a 26, secondo l'alfabeto)

	lettere[0][2]=4; //'e'
	lettere[1][2]=19;
	lettere[2][2]=0;
	lettere[3][2]=14;
	lettere[4][2]=8;
	lettere[5][2]=13;
	lettere[6][2]=18;
	lettere[7][2]=7;
	lettere[8][2]=17;
	lettere[9][2]=3;
	lettere[10][2]=11;
	lettere[11][2]=2;
	lettere[12][2]=20;
	lettere[13][2]=12;
	lettere[14][2]=22; //avrei potuto farlo un po' più elegantemente, ma il concetto è lettere in ordine di uso
	lettere[15][2]=5;
	lettere[16][2]=6;
	lettere[17][2]=24;
	lettere[18][2]=15;
	lettere[19][2]=1;
	lettere[20][2]=21;
	lettere[21][2]=10;
	lettere[22][2]=9;
	lettere[23][2]=23;
	lettere[24][2]=16;
	lettere[25][2]=25; //'z'
	
	sostituisci(input,lunghezza,lettere); //sostituisce le lettere
	
	
	cout<<"\n\noutput: "<<input<<"\n"; //output
	
	system("pause");
	return 0;
}

/*
	|0a	|ft	|rl	|
	-------------
	|1b	|ft	|rl	|
	-------------
	|2c	|ft	|rl	|
	-------------
	|3d	|ft	|rl	|
	-------------
	...

	ft: frequency in input text (int counter)
	rl: real letter. what the program thinks it should actually be (added later after sorting the lines of the matrix)
*/
