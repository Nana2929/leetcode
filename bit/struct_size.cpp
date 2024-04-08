
/*what is size of StructA and StructB
https://www.twblogs.net/a/5b8cad052b71771883347a35

如何計算結構體的大小？
(1) 整體空間是佔用空間最大的成員（的類型）所佔字節數的整數倍。
(2) 數據對齊原則---內存按結構體成員的先後順序排列，當排到該成員時，其前面已擺放的空間大小必須是該成員類型大小的整數倍，如果不夠則補齊，依次向後類推。
*/
#include <iostream>
using namespace std;

struct A
{
    int a; // 4 bytes ｜｜｜｜
    short b; // 2 bytes, ｜｜｜｜｜｜
    int c; // 4 bytes, 發現前面只有擺放6 bytes，因此先補齊2 bytes後才存放c
    // ｜｜｜｜｜｜xx｜｜｜｜
    char d; // 1 byte, ｜｜｜｜｜｜xx｜｜｜｜｜
    // 總共是 13 bytes，但基於整體空間原則，整體 struct 大小應該是最大成員（int）的整數倍，因此補齊到 16 bytes, ｜｜｜｜｜｜xx ｜｜｜｜｜xxx

};
struct B
{
    int a; // 4 bytes
    short b; // 2 bytes
    char c; // 1 byte
    int d; // 4 bytes，前面擺放了7 bytes，因此補齊 1 byte 後才存放d
    // 總共 12 bytes，恰好符合整體空間原則，因此不用補齊
};

// what is size of StructA and StructB
int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    return 0;
}


