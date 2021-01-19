#include <stdio.h>
#define MAX 100005
#define NIL -1


/* 左子右兄弟表現(left-child, right-sibling representation) */
typedef struct
{
    /* 親のノード */
    int parent;
    /* 子のノード */
    int left_child;
    /* 左の兄弟ノード */
    int right_sibling;
} Node;

Node Tree[MAX];
int N, Depth[MAX];

/* 出力用関数 */
void print_node(int node_point)
{
    int i, child_node;
    printf("node %d: ", node_point);
    printf("parent = %d, ", Tree[node_point].parent);
    printf("depth = %d, ", Depth[node_point]);

    if (Tree[node_point].parent == NIL)
        printf("root, ");
    else if (Tree[node_point].left_child == NIL)
        printf("leaf, ");
    else
        printf("internal node, ");

    printf("[");

    for (i = 0, child_node = Tree[node_point].left_child; child_node != NIL; i++, child_node = Tree[child_node].right_sibling)
    {
        if (i)
        {
            printf(", ");
        }
        printf("%d", child_node);
    }
    printf("]\n");
}

/* 再帰的に深さを求める */
void recursive(int node_point, int depth)
{
    Depth[node_point] = depth;
    /* 右の兄弟に同じ深さを設定 */
    if (Tree[node_point].right_sibling != NIL)
        recursive(Tree[node_point].right_sibling, depth);
    /* 最も左の子に自分の深さ+1を設定 */
    if (Tree[node_point].left_child != NIL)
        recursive(Tree[node_point].left_child, depth + 1);
}

int main(void)
{
    int i, j, N_child, node_num, child_num, left_child, right_sibling,root;
    scanf("%d", &N);

    /* treeを初期化 */
    for (i = 0; i < N; i++)
    {
        Tree[i].parent = NIL;
        Tree[i].left_child = NIL;
        Tree[i].right_sibling = NIL;
    }

    /* 格納 */
    for (i = 0; i < N; i++)
    {
        /* ノード番号と持つ子の数 */
        scanf("%d %d", &node_num, &N_child);

        /* 子の関係を格納する */
        for (j = 0; j < N_child; j++)
        {
            scanf("%d", &child_num);

            /* 
            最初の子ノードはleft_childに格納
            次からは最初の子ノードの兄弟なので、right_siblingに入れる。
             */
            if (j == 0)
                Tree[node_num].left_child = child_num;
            else
                Tree[left_child].right_sibling = child_num;

            /* 親ノードの番号を入れる */
            left_child = child_num;
            Tree[child_num].parent = node_num;
        }
    }

    /* rootノードを見つける */
    for (i = 0; i < N; i++)
        if (Tree[i].parent == NIL)
            root = i;

    /* 深さD[]に格納する */
    recursive(root, 0);

    for (i = 0; i < N; i++)
        print_node(i);

    return 0;
}