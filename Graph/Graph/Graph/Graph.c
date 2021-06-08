#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50 
//MAX_VERTICES라는 50의 값을 갖는 상수를 선언합니다.

typedef struct GraphNode
//인접 리스트의 노드 구조를 구조체 형태의 자료형으로 선언합니다.
{
	int vertex;
	//정점을 나타내는 데이터 필드를 정수형으로 선언합니다.
	struct GraphNode* link;
	//다음 인접 정점을 연결하는 링크필드입니다.
}GraphNode;

typedef struct GraphType {
	int n;
	//그래프의 정점의 개수입니다.
	GraphNode* adj_list[MAX_VERTICES];
	//그래프 정점에 대한 헤드노드입니다.
}GraphType;


void init(GraphType* g) {
	//그래프를 초기화합니다.
	int v;
	g->n = 0;
	//그래프의 정점의 개수를 0으로 초기화합니다.
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
	//그래프 정점에 대한 헤드 노드의 배열을 NULL로 초기화합니다.
}

void insert_vertex(GraphType* g, int v)
//그래프 g에 정점 v를 삽입하는 연산입니다.
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
		//만약 그래프에 정점을 삽입했을때 최대 사이즈보다 크다면 오류 문구를 프린트합니다.
	}
	g->n++;
	//그렇지 않다면 그래프 정점이 하나 증가시킵니다.
}
void insert_edge(GraphType* g, int u, int v)
//그래프 g에 간선(u,v)를 삽입하는 연산입니다.
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
		//정점 u 또는 v의 번호가 그래프의 정점 개수보다 크다면 오류 문구를 프린트합니다.
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	//간선을 나타내는 노드를 생성합니다.
	node->vertex = v+100;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
	//정점 u의 인접리스트에 node를 삽입합니다.
	//위치는 상관이 없으므로 연결리스트의 맨 처음에 삽입합니다.
}


void print_adj_list(GraphType* g) {
	//그래프 g의 각 정점에 대한 인접리스트를 출력하는 연산입니다.
	for (int i = 0; i < g->n; i++) {
		//i가 0부터 정점의 개수만큼 까지 하나씩 증가하는 for문입니다.
		GraphNode* p = g->adj_list[i];
		//i를 그래프의 인접리스트 정점에 대입합니다.
		printf("정점 %d의 인접 리스트", i);
		//i에 대한 인접리스트를 출력합니다.
		while (p != NULL) {
			printf("-> %d", p->vertex);
			p = p->link;
			//정점을 출력합니다.
		}
		printf("\n");
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	//그래프를 동적할당 합니다.
	init(g);
	//그래프를 초기화합니다.
	for (int i = 0; i < 5; i++)
		insert_vertex(g, i);
	//삽입할 정점 g와 i를 대입합니다.
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 0, 4);

	print_adj_list(g);
	//그래프의 인접리스트를 출력합니다.
	free(g);
	//그래프를 free시킵니다.
	return 0;
}