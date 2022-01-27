#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

int main(int argc, char* argv[]){
	ifstream MusicFile("lista de canciones.txt");
	string ytlink;
	string command="youtube-dl -f m4a ";
	string str;
	int e;
	while(getline (MusicFile,ytlink)){
		str = command+ytlink;
		e=str.length();
		char arr[e];
		for(int i=0; i<e;i++){
			arr[i] = str[i];
		}
		cout<<str<<endl;
		system(arr);
	}
	MusicFile.close();
				
	ofstream M("lista de canciones.txt", ofstream::trunc);
	M.close();
	return 1;
}
