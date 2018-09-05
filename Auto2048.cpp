#include "StdAfx.h"
#include "Auto2048.h"


Auto2048::Auto2048(void){
}


Auto2048::~Auto2048(void){
}

int Auto2048::negaMaxSearch(const s2048 *m, const int depth){	// ����С�����㷨
	unsigned int i, j;
	int best, value;
	s2048 m1(0);
	
	if(depth == 0)
		return m->score;
	
	best = -1;
	for(i = 0; i < 4; i++){
		m1 = *m;//���������'='

		if(!m1.move((DIR)i))//��֦%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				continue;

		for(j = 0; j < M_SIZE*M_SIZE; j++){
			if(m1.matrix[j] == 0){
				m1.matrix[j] = 2;//2�����
				value = negaMaxSearch(&m1, depth-1);
				if(value > best){
					best = value;
					if(depth == MAXDEPTH)//��һ���¼���ŷ���
						bestDir = (DIR)i;
				}

				//m1.matrix[k] = 4;//4�����*******************************************************************
				//value = negaMaxSearch(&m1, depth-1);
				//if(value > best){
				//	best = value;
				//	if(depth == MAXDEPTH)//��һ���¼���ŷ���
				//		bestDir = (DIR)i;
				//}
				m1.matrix[j] = 0;//undo
			}
		}
	}
	if(best == -1)
		return m1.score >> 1;//****************************
	return best;
}
