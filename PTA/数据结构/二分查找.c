#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

Position BinarySearch(List L, ElementType X) {
    int Lt = 1, Rt = L->Last, M = 0;
    while (X != L->Data[M]) {
        M = (Lt + Rt) / 2;
        if (X > L->Data[M]) Lt = M;
        else if (X < L->Data[M]) Rt = M;
        if (Rt - Lt == 1) {
            if (L->Data[Lt] == X) return Lt;
            else if (L->Data[Rt] == X) return Rt;
            else return NotFound;
        }
    }
    return M;
}