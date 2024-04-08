/*給予一個 structure
struct ListStruct ListArray[1000];
#define NULL 0xFFFF
unsigned int ListHead = 0;
其中有兩個條件
條件一  ListArray[Entry1].NextPtr = ListArray[Entry2]
條件二  (ListArray[Entry2].DataH << 16 + ListArray[Entry2].DataL) > (ListArray[Entry1].DataH << 16 + ListArray[Entry1].DataL)
==> 第一個 index 中的 NextPtr 會指到另一個 index 中的起始位址
    另一個 index 中的起始位址的資料內容大小一定大於原起始資料的大小
請寫一個function(unsigned int DATA_A, unsigned int DATA_B)，
能在ListArray中找到符合ListArray[Entry].DataH == Data_A 且 ListArray[Entry].DataL == Data_B
並印出其結果。如果沒有找到的話，印出”no found"  */


#include <stdio.h>
struct ListStruct{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};

struct ListStruct ListArray[1000];
#define NULL 0xFFFF
unsigned int ListHead = 0;

void Q3(unsigned int DATA_A, unsigned int DATA_B)
{

    auto found_entry = ListHead;
    int pre_entry = NULL;
    int next_entry = NULL;

    while (ListArray[found_entry].NextPtr != NULL) {
        if (ListArray[found_entry].DataH == DATA_A && ListArray[found_entry].DataL == DATA_B)
        {
            if (pre_entry == NULL)
                printf("pre_entry = NULL, found_entry = ListHead\n");
            else
                printf("pre_entry = %d, found_entry = %d", pre_entry, found_entry);
            printf("found it\n");

            // check condtion 2
            next_entry = ListArray[found_entry].NextPtr;
            if (ListArray[next_entry].DataH << 16 + ListArray[next_entry].DataL >
                DATA_A << 16 + DATA_B)
                break;
        }
        // update entry
        pre_entry = found_entry;
        found_entry = ListArray[found_entry].NextPtr;
    }
}

