//广义表表示法进行序列化
/* 空树：（）
单一节点：A or A（）
表示父子关系：A（B，） or A（B) ->根节点是A，仅有一个左子树B
父节点（左子树节点，右子树节点）
A（B，C）  -> A的左子树是B右子树是C */

//问题1：二叉树->广义表
//问题2：广义表->二叉树
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define KEY(n) (n?n->data:-1)

//二叉树转广义表的过程
typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
}node;

node* get_new_node(int data){
    node* p = (node*)malloc(sizeof(node));
    p->data = data;
    p->lchild = nullptr;
    p->rchild = nullptr;
    return p;
}

//将某个节点随机插入二叉树中的某个位置
node* insert(node* root,int data){
    if(root == nullptr) return get_new_node(data);
    if(rand()%2){
        root->lchild = insert(root->lchild,data);
    }else{
        root->rchild = insert(root->rchild,data);
    }
    return root;
}

//随机生成一个拥有n个节点的二叉树
node* get_random_binary_tree(int n){
    node* root = nullptr;
    for(int i =0;i<n;i++){
        root = insert(root,rand()%100);
    }
    return root;
}

void clear(node* root){
    if(root == nullptr) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
char buff[10000];
int len = 0;

void __serialize(node* root){
    //类似于前序遍历
    if(root == nullptr) return;
    //先输出根节点的信息
    len += sprintf(buff + len,"%d", root->data);
    if(root->lchild == nullptr and root->rchild == nullptr) return;
    len += sprintf(buff + len,"(");

    __serialize(root->lchild);
    if(root->rchild) len+=sprintf(buff+len,",");
    __serialize(root->rchild);
    len += sprintf(buff+len,")");
    return;
}

void serialize(node* root){
    memset(buff,0,sizeof(buff));
    len = 0;
    __serialize(root);
    return;
}

void print(node* root){
    printf("%d(%d,%d)\n",KEY(root),KEY(root->lchild),KEY(root->rchild));
    return;
}

void output(node* root ){
    if(root == nullptr) return;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return;
}


void test01(){
    node* root = get_random_binary_tree(10);
    output(root);//输出树的相关信息
    serialize(root);
    printf("%s\n",buff);

}
int main(void){
    srand(time(0));
    test01();
    system("pause");
    return 0;
}
