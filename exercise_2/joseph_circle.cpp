#include "joseph_circle.h"

int main() {
	int total, start, gap, survival;
	cout << "现有N个人围成一圈，从第S个人开始依次报数，报M的人出局，再由下一个人开始报数，如此循环，直至剩下K个人为止"<<endl;
	cout <<endl << "请输入生死游戏的总人数N：";
	cin >> total;
	cout << "请输入游戏开始的位置：";
	cin >> start;
	cout << "请输入死亡数字M：";
	cin >> gap;
	cout << "请输入剩余的生者人数K：";
	cin >> survival;
	
	CircularLinkList joseph_circle(total);
	joseph_circle.JosephStart(start, gap, survival);
	
	return 0;
}
