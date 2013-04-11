#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include <vector>
#include <string>


class piece{
private:
	
	std::string m_name;
	int m_coords[4][2];

	
public:
	piece::piece();
	piece::piece(std::string t_name, int t_coords[4][2]);
};
#endif;