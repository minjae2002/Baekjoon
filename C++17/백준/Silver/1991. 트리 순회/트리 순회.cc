#include <bits/stdc++.h>
using namespace std;

#define MAXN 26								// 알파벳 A부터 Z까지 총 26개 

struct stNode {								// 그래프 그리기 위한 노드 구조체를 정의 
    char left;								// 왼쪽 자식
    char right;								// 오른쪽 자식
};

stNode Data[MAXN+1];						// 트리의 모든 노드를 저장하는 배열 

// 전위 순회
// root - left - right
void preOrder(char node){
    if(node == '.') return;					// 자식이 없는 경우 
    
    printf("%c", node);
    preOrder(Data[node - 'A'].left);		// 알파벳을 숫자 index로 변환
    preOrder(Data[node - 'A'].right);		// 자식 노드로 이동하여 전위 순회(재귀) 
}

// 중위 순회
// left - root - right
void inOrder(char node){
    if(node == '.') return;
    
    inOrder(Data[node - 'A'].left);
    printf("%c", node);
    inOrder(Data[node - 'A'].right);
}

// 후위 순회
// left - right - root
void postOrder(char node){ 
    if(node == '.') return;
    
    postOrder(Data[node - 'A'].left);
    postOrder(Data[node - 'A'].right);
    printf("%c", node);
}

int main(){
    int n;
    scanf("%d", &n);
    
    char node, left, right;
    for(int i = 0; i < n; i++){
        scanf(" %c %c %c", &node, &left, &right);
        Data[node - 'A'].left = left;
        Data[node - 'A'].right = right;
    }

    preOrder('A');
    printf("\n");
    
    inOrder('A');
    printf("\n");
    
    postOrder('A');
    
    return 0;
}
