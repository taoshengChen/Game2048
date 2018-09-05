#include "StdAfx.h"
#include "Auto2048.h"


Auto2048::Auto2048(void){
}


Auto2048::~Auto2048(void){
}

int Auto2048::negaMaxSearch(const s2048 *m, const int depth){	// 极大极小搜索算法
	unsigned int i, j;
	int best, value;
	s2048 m1(0);
	
	if(depth == 0)
		return m->score;
	
	best = -1;
	for(i = 0; i < 4; i++){
		m1 = *m;//重载运算符'='

		if(!m1.move((DIR)i))//剪枝%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				continue;

		for(j = 0; j < M_SIZE*M_SIZE; j++){
			if(m1.matrix[j] == 0){
				m1.matrix[j] = 2;//2的情况
				value = negaMaxSearch(&m1, depth-1);
				if(value > best){
					best = value;
					if(depth == MAXDEPTH)//第一层记录最优方向
						bestDir = (DIR)i;
				}

				//m1.matrix[k] = 4;//4的情况*******************************************************************
				//value = negaMaxSearch(&m1, depth-1);
				//if(value > best){
				//	best = value;
				//	if(depth == MAXDEPTH)//第一层记录最优方向
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
