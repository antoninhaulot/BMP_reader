#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace std;

int main(){
	cout << "Hello" << endl;

	unsigned int size;
	unsigned int offset;
	unsigned short bitperpixel;

	FILE * fichier;

	fichier = fopen("logo.bmp","r");

	fseek(fichier,2,SEEK_SET);
	fread(&size,1,4,fichier);

	fseek(fichier,10,SEEK_SET);
	fread(&offset,1,4,fichier);

	fseek(fichier,28,SEEK_SET);
	fread(&bitperpixel,1,2,fichier);

	cout << "taille du fichier : " << size << endl;
	cout << "offset des pixels : " << offset << endl;

	cout << "bit par pixel : " << bitperpixel << endl;

	fseek(fichier,offset,SEEK_SET);


	unsigned char color[3];
	fread(&color,sizeof(char),3,fichier);

	//printf("%x %x %x \t",color[0],color[1],color[2]);
	//cout << (int)color[2] << endl;

	cout << (124& 1) << endl;

	cout << (char)(1+2) << endl;
	printf("%x\n",(char)(1+2));


	int compteur = 0;
	unsigned char octet_input;
	unsigned int octet_output = 0;

	fseek(fichier,offset,SEEK_SET);

	FILE * fichier_output;
	fichier_output = fopen("image.png","w");

	for(unsigned int i = offset; i < size; i++){
		//cout << "octet n°" << i << endl;
		
		fread(&octet_input,1,1,fichier);
		//cout <<"compteur : " << compteur << " " << (int)octet_input << " " << (int)((octet_input & 1)) << " " << pow(2,compteur) <<  endl;
		octet_output += (int)((octet_input & 1) * pow(2,compteur));

		if(compteur == 7){
			compteur = 0;
			cout << "concatenation octet " << (int)octet_output << endl;


			//fwrite(octet_output);

			octet_output = false;

			fprintf(fichier_output, "%c",(char)octet_output);

		}
		else{
			compteur++;
		}
	}
	fclose(fichier_output);
	//cout << std::hex << (int)temp[0] << (int)temp[1] << (int)temp[2] << (int)temp[3] << endl;
	/*ifstream fichier("logo.bmp", ios::in | ios::binary);


	
	string ligne;
	if(fichier){
		int n;

		std::vector<char> pixel_color;
		char var[4];
		
		//while(!fichier.eof()){
		fichier.seekg(10, ios_base::beg);
		fichier.read(var,4);
		//cout << var[0] << var[1] << var[2] << var [3] << "\t";
		
		printf("%x",var[0]);
		//std::cout << std::hex << (int)var[0] << (int)var[1] <<(int)var[2] <<(int)var[3] <<endl;//}
		//std::cout <<  (int)var[0] << (int)var[1] <<(int)var[2] <<(int)var[3] <<endl;//}
		fichier.close();
	}*/
	fclose(fichier);
	return 0;
}
