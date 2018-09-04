
#ifndef M_SIZE 
#define M_SIZE 4//matrix size. default 4.the minimun is 3
#endif
extern unsigned int matrix[M_SIZE*M_SIZE];

enum DIR{
	DIR_NONE  = -1,
	DIR_UP    = 0,
	DIR_DOWN  = 1,
	DIR_LEFT  = 2,
	DIR_RIGHT = 3
};

void initMatrix();
void outputMatrix();
DIR getDir();
bool move(DIR r);
bool addInEmpty();
bool haveEmpty();
bool isGameOver();
unsigned int getScorce();
