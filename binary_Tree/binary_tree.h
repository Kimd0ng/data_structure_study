#define	boolean	unsigned char
#define	true	1
#define	false	0

typedef int Element;

// Binary tree node
typedef struct tree_node* tree_pointer;
typedef struct tree_node {
	Element 		data;
	tree_pointer 	left;
	tree_pointer 	right;
} tree_node;

// ������ ���� Ʈ���� �����ϰ� root �����͸� ��ȯ
//
//                   a
// 
//           b               c
// 
//        d     e         f     g
//
tree_pointer build_simple_tree();

// Ʈ���� ������ ���
int bt_count(tree_pointer ptr);
// Ʈ���� ������ ���� ���
int bt_sum(tree_pointer ptr);
// Ʈ���� ���̸� ���
int bt_height(tree_pointer ptr);
// Ʈ���� ������ preorder�� ��� 
void bt_show_preorder(tree_pointer ptr);
// Ʈ���� ��� ��带 �ý��ۿ� ��ȯ(free)
void free_bt(tree_pointer ptr);

int MAX(int i, int j);
