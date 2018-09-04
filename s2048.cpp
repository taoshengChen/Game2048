#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include "s2048.h"

using std::endl;
using std::cout;

unsigned int matrix[M_SIZE*M_SIZE];//
static unsigned int score; 

//在空位上添加一个2 
bool addInEmpty(){
	unsigned int i, num = 0, t;
	for(i = 0; i < M_SIZE*M_SIZE;i++)
		if(matrix[i] == 0)
			num++;//0的数目 
	if(num == 0)
		return false;
	t = (unsigned int)rand()%num;//出现的位置 
	t++;
	for(i = 0; i < M_SIZE*M_SIZE;i++)
		if(matrix[i] == 0){
			t--;
			if(t == 0)
				matrix[i] = 2;
		}	
	return true;
}

bool haveEmpty(){
	unsigned i;
	for(i = 0; i < M_SIZE*M_SIZE;i++)
		if(matrix[i] == 0)
			return true;
	return false;
}

bool isGameOver(){
	unsigned int i, j;
	
	if(haveEmpty())
		return false;
	
	for(i = 0; i < M_SIZE;i++){
		for(j = 0; j < M_SIZE-1; j++){
			if(matrix[i*M_SIZE+j] == matrix[i*M_SIZE+j+1])
				return false;
		}
	}
	
	for(i = 0; i < M_SIZE-1;i++){
		for(j = 0; j < M_SIZE; j++){
			if(matrix[i*M_SIZE+j] == matrix[(i+1)*M_SIZE+j])
				return false;
		}
	}

	return true;
}

void initMatrix(){
	int i, j;
	score = 0;
	for(i = 0;i < M_SIZE;i++)
		for(j = 0;j < M_SIZE;j++) 
			matrix[i*M_SIZE+j] = 0;
	srand((unsigned int)time(NULL));
	addInEmpty(); 
}


//返回四个方向 
DIR getDir(){
	char c;
	DIR r;
	do{
		c = getch();
		switch(c){
		case 'w':
		case 'W': r = DIR_UP; break;
		case 'a':
		case 'A': r = DIR_LEFT; break;
		case 's':
		case 'S': r = DIR_DOWN; break;
		case 'd':
		case 'D': r = DIR_RIGHT; break;
		default : r = DIR_NONE; break;
		}
	}while(r == DIR_NONE);
	return r;
}

void outputMatrix(){
	int i, j;
	for(i = 0;i < M_SIZE;i++){
		for(j = 0;j < M_SIZE;j++)
			cout << '\t' << matrix[i*M_SIZE+j];
		cout << endl;
	}
	cout << endl;
	cout << "score: " << score << endl;
}

bool move(DIR dir){
	bool r = false;
	unsigned int i, ii, j, jj, k;
	//行位置初始值
	const unsigned int position[4] = {0, M_SIZE*(M_SIZE-1), 0, M_SIZE-1};
	//换行步进值
	const unsigned int iposition[4] = {+1, +1, +M_SIZE, +M_SIZE};//Up, Dwon, Left, Right
	//换列步进值
	const unsigned int jposition[4] = {+M_SIZE, -M_SIZE, +1, -1};
	
	for(i = position[dir], ii = 0; ii < M_SIZE; i += iposition[dir], ii++){
		k = i;
		for(j = i+jposition[dir], jj = 1;jj < M_SIZE; j += jposition[dir], jj++){
			if(matrix[j] != 0 && matrix[k] == 0){
				matrix[k] = matrix[j];
				matrix[j] = 0;
				r = true;
			}else if((matrix[j] == matrix[k]) && (matrix[k] != 0)){
				matrix[k] *= 2;//2 倍
				score += matrix[k];
				matrix[j] = 0;
				k += jposition[dir];
				r = true;
			}else if((matrix[j] != matrix[k]) && (matrix[j] != 0) && (matrix[k] != 0)){
				k += jposition[dir];
				if(k != j){
					matrix[k] = matrix[j];
					matrix[j] = 0;
					r = true;
				}
			}
		}
	}
	return r;
}


unsigned int getScorce(){
	return score;
}

 
