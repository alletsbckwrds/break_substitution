#include <iostream>
using namespace std;

void analyze(string &input, int len, int lettere[26][3])
{
	for(int i=0; i<len; i++)
	{
		switch(input[i]) //non è il metodo più elegante, ma non avevo voglia di
		{				 //chiedere al computer se quel char era una lettera e poi di aumentare gli indici in base
						 //ad un offset* della tabella ascii		(*0 partirebbe da 'a')
			case 'a':
				lettere[0][1]++;
				break;
			case 'b':
				lettere[1][1]++;
				break;
			case 'c':
				lettere[2][1]++;
				break;
			case 'd':
				lettere[3][1]++;
				break;
			case 'e':
				lettere[4][1]++;
				break;
			case 'f':
				lettere[5][1]++;
				break;
			case 'g':
				lettere[6][1]++;
				break;
			case 'h':
				lettere[7][1]++;
				break;
			case 'i':
				lettere[8][1]++;
				break;
			case 'j':
				lettere[9][1]++;
				break;
			case 'k':
				lettere[10][1]++;
				break;
			case 'l':
				lettere[11][1]++;
				break;
			case 'm':
				lettere[12][1]++;
				break;
			case 'n':
				lettere[13][1]++;
				break;
			case 'o':
				lettere[14][1]++;
				break;
			case 'p':
				lettere[15][1]++;
				break;
			case 'q':
				lettere[16][1]++;
				break;
			case 'r':
				lettere[17][1]++;
				break;
			case 's':
				lettere[18][1]++;
				break;
			case 't':
				lettere[19][1]++;
				break;
			case 'u':
				lettere[20][1]++;
				break;
			case 'v':
				lettere[21][1]++;
				break;
			case 'w':
				lettere[22][1]++;
				break;
			case 'x':
				lettere[23][1]++;
				break;
			case 'y':
				lettere[24][1]++;
				break;
			case 'z':
				lettere[25][1]++;
				break;
		}
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
				input[i]=(lettere[j][2]+97);
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
				lettere[i+1][0]=temp;			//(non ho guardato molto questa parte, se non va, forse qui qualquadra non cosa.
												//ignorare il commento in caso funzioni(dubito))
			}
		}
 }
 
 void sminuscola(string &input, int len)
 {
 	for (int i=0; i<len; i++)
 	{
 		switch(input[i])
 		{
 			case 'A':
 				input[i]=input[i]+32; //aggiungendo 32, si trasforma un carattere maiuscolo in uno minuscolo
 				break;
 			case 'B':
 				input[i]=input[i]+32;
 				break;
 			case 'C':
 				input[i]=input[i]+32;
 				break;
 			case 'D':
 				input[i]=input[i]+32;
 				break;
 			case 'E':
 				input[i]=input[i]+32;
 				break;
 			case 'F':
 				input[i]=input[i]+32;
 				break;
 			case 'G':
 				input[i]=input[i]+32;
 				break;
 			case 'H':
 				input[i]=input[i]+32;
 				break;
 			case 'I':
 				input[i]=input[i]+32;
 				break;
 			case 'J':
 				input[i]=input[i]+32;
 				break;
 			case 'K':
 				input[i]=input[i]+32;
 				break;
 			case 'L':
 				input[i]=input[i]+32;
 				break;
 			case 'M':
 				input[i]=input[i]+32;
 				break;
 			case 'N':
 				input[i]=input[i]+32;
 				break;
 			case 'O':
 				input[i]=input[i]+32;
 				break;
 			case 'P':
 				input[i]=input[i]+32;
 				break;
 			case 'Q':
 				input[i]=input[i]+32;
 				break;
 			case 'R':
 				input[i]=input[i]+32;
 				break;
 			case 'S':
 				input[i]=input[i]+32;
 				break;
 			case 'T':
 				input[i]=input[i]+32;
 				break;
 			case 'U':
 				input[i]=input[i]+32;
 				break;
 			case 'V':
 				input[i]=input[i]+32;
 				break;
 			case 'W':
 				input[i]=input[i]+32;
 				break;
 			case 'X':
 				input[i]=input[i]+32;
 				break;
 			case 'Y':
 				input[i]=input[i]+32;
 				break;
 			case 'Z':
 				input[i]=input[i]+32;
 				break;
		}
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
	sminuscola(input,lunghezza); //LO SO CHE C'è "TOLOWER()" MA FACENDO COSì HO MENO PROBABILITà DI SBAGLIARE!
	
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
	letteresort(lettere); //è bubblesort ma a questo punto, per un quicksort, non avevo abbastanza neuroni
	//quindi adesso la matrice lettere è stata riordinata secondo la frequenza(spostando anche le corrispettive lettere)
	
	//[i][2] è 4... (le lettere più frequenti in inglese, indicate con numeri ordinali da 0 a 26, secondo l'alfabeto)
	/*lettere[0][2]=4;
	lettere[1][2]=0;
	lettere[2][2]=17;
	lettere[3][2]=8;
	lettere[4][2]=14;
	lettere[5][2]=19;
	lettere[6][2]=13;
	lettere[7][2]=18;
	lettere[8][2]=11;
	lettere[9][2]=2;
	lettere[10][2]=20;
	lettere[11][2]=3;
	lettere[12][2]=15;
	lettere[13][2]=12;
	lettere[14][2]=7;
	lettere[15][2]=6;
	lettere[16][2]=1;
	lettere[17][2]=5;
	lettere[18][2]=24;
	lettere[19][2]=22;
	lettere[20][2]=10;
	lettere[21][2]=21;
	lettere[22][2]=23;
	lettere[23][2]=25;
	lettere[24][2]=9;
	lettere[25][2]=16;*/
	//quelle non funziano bene.
	lettere[0][2]=4;
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
	lettere[14][2]=22; //avrei potuto farlo un po' più elegantemente, ma il concetto è quello;
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
	lettere[25][2]=25;
	
	sostituisci(input,lunghezza,lettere); //sostituisce le lettere
	
	
	cout<<"\n\noutput: "<<input<<"\n"; //output stringa modificata
	
	system("pause");
	return 0;
}
