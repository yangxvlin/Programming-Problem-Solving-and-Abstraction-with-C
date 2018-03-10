#include <stdio.h>
#define MAXSTACK 20   /* 栈的最大深度 */
int c = 1; /* 一个全局变量，表示目前移动的步数 */

struct hanoi { /* 存储汉诺塔的结构，包括盘的数目和三个盘的名称 */
	int n;
	char x, y, z;
};

void move(char x, int n, char y) /* 移动函数，表示把某个盘从某根针移动到另一根针 */
{
	printf("%d. Move disk %d from %c to %c\n", c++, n, x, y);
}

void push(struct hanoi *p, int top, char x, char y, char z, int n)
{
	p[top+1].n = n - 1; 
	p[top+1].x = x; 
	p[top+1].y = y; 
	p[top+1].z = z; 
}

void unreverse_hanoi(struct hanoi *p) /* 汉诺塔的非递归算法 */
{
	int top = 0;
	while (top >= 0) {
		while (p[top].n > 1) { /* 向左走到尽头 */
		   push(p, top, p[top].x, p[top].z, p[top].y, p[top].n);
		   top++;
		}
		
		if (p[top].n == 1) { /* 叶子结点 */
		   move(p[top].x, 1, p[top].z);
		   top--;
		}
		
		if (top >= 0) { /* 向右走一步 */
		   move(p[top].x, p[top].n, p[top].z);
		   top--;
		   push(p, top, p[top+1].y, p[top+1].x, p[top+1].z, p[top+1].n);
		   top++;
		}
		//printf("%d\n", top);
	}
}

int main(void)
{
int i;

printf("unreverse program:\n");
struct hanoi p[MAXSTACK];
c = 1;
p[0].n = 3;
p[0].x = 'A', p[0].y = 'B', p[0].z = 'C';
unreverse_hanoi(p);
return 0;
}