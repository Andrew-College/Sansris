#include "Pieces.h"
#include <string>
using namespace std;


piece::piece(){
	this -> m_name = "";
	this -> m_coords;
}
piece::piece(std::string t_name, int t_coords[4][2]){
	this -> m_name = t_name;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			this ->m_coords[i][j] = t_coords[i][j];
		}
	}
}