#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge( List L1, List L2 ) {
    List L, temp;
    temp = (List)malloc(sizeof(struct Node));
    L = temp;
    temp -> Next = NULL;
    List temp1, temp2;
    temp1 = L1->Next;
    temp2 = L2->Next;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 -> Data <= temp2 -> Data) {
            temp->Next = temp1;
            temp1 = temp1->Next;
        }
        else {
            temp->Next = temp2;
            temp2 = temp2-> Next;
        }
        temp = temp->Next;
    }
    temp->Next = NULL;
    if (temp1 == NULL) temp->Next = temp2;
    if (temp2 == NULL) temp->Next = temp1;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}

void Print( List L )
{
    if (L->Next == NULL) {
        printf("NULL\n");
        return;
    }
    L = L->Next;
    while (L != NULL) {
        printf("%d ", L->Data);
        L = L->Next;
    }
    putchar('\n');
}
List Read()
{
    int len = 0;
    int num = 0;
    PtrToNode h = NULL;
    PtrToNode last = NULL;

    scanf( "%d", &len );
    if (  len == 0  )
        return NULL;

    h = ( PtrToNode )malloc( sizeof( struct Node ) );//建立头结点
    h->Next = NULL;
    last = h;
    while (  len ) {
        scanf( "%d", &num );
        PtrToNode node = ( PtrToNode )malloc( sizeof( struct Node ) );
        node->Data = num;
        node->Next = NULL;
        last->Next = node;
        last = node;
        len--;
    }
    return h;
}
