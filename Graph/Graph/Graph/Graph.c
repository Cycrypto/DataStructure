#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50 
//MAX_VERTICES��� 50�� ���� ���� ����� �����մϴ�.

typedef struct GraphNode
//���� ����Ʈ�� ��� ������ ����ü ������ �ڷ������� �����մϴ�.
{
	int vertex;
	//������ ��Ÿ���� ������ �ʵ带 ���������� �����մϴ�.
	struct GraphNode* link;
	//���� ���� ������ �����ϴ� ��ũ�ʵ��Դϴ�.
}GraphNode;

typedef struct GraphType {
	int n;
	//�׷����� ������ �����Դϴ�.
	GraphNode* adj_list[MAX_VERTICES];
	//�׷��� ������ ���� ������Դϴ�.
}GraphType;


void init(GraphType* g) {
	//�׷����� �ʱ�ȭ�մϴ�.
	int v;
	g->n = 0;
	//�׷����� ������ ������ 0���� �ʱ�ȭ�մϴ�.
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
	//�׷��� ������ ���� ��� ����� �迭�� NULL�� �ʱ�ȭ�մϴ�.
}

void insert_vertex(GraphType* g, int v)
//�׷��� g�� ���� v�� �����ϴ� �����Դϴ�.
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
		//���� �׷����� ������ ���������� �ִ� ������� ũ�ٸ� ���� ������ ����Ʈ�մϴ�.
	}
	g->n++;
	//�׷��� �ʴٸ� �׷��� ������ �ϳ� ������ŵ�ϴ�.
}
void insert_edge(GraphType* g, int u, int v)
//�׷��� g�� ����(u,v)�� �����ϴ� �����Դϴ�.
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
		//���� u �Ǵ� v�� ��ȣ�� �׷����� ���� �������� ũ�ٸ� ���� ������ ����Ʈ�մϴ�.
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	//������ ��Ÿ���� ��带 �����մϴ�.
	node->vertex = v+100;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
	//���� u�� ��������Ʈ�� node�� �����մϴ�.
	//��ġ�� ����� �����Ƿ� ���Ḯ��Ʈ�� �� ó���� �����մϴ�.
}


void print_adj_list(GraphType* g) {
	//�׷��� g�� �� ������ ���� ��������Ʈ�� ����ϴ� �����Դϴ�.
	for (int i = 0; i < g->n; i++) {
		//i�� 0���� ������ ������ŭ ���� �ϳ��� �����ϴ� for���Դϴ�.
		GraphNode* p = g->adj_list[i];
		//i�� �׷����� ��������Ʈ ������ �����մϴ�.
		printf("���� %d�� ���� ����Ʈ", i);
		//i�� ���� ��������Ʈ�� ����մϴ�.
		while (p != NULL) {
			printf("-> %d", p->vertex);
			p = p->link;
			//������ ����մϴ�.
		}
		printf("\n");
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	//�׷����� �����Ҵ� �մϴ�.
	init(g);
	//�׷����� �ʱ�ȭ�մϴ�.
	for (int i = 0; i < 5; i++)
		insert_vertex(g, i);
	//������ ���� g�� i�� �����մϴ�.
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 0, 4);

	print_adj_list(g);
	//�׷����� ��������Ʈ�� ����մϴ�.
	free(g);
	//�׷����� free��ŵ�ϴ�.
	return 0;
}