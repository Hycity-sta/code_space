顺序表是一种线性表，它的特点是元素在物理位置上连续存储，数据元素间的关系是一对一的关系。下面给出顺序表的ADT定义和基本操作：

ADT List {
    InitList(&L) // 初始化操作，建立一个空的线性表L
    DestroyList(&L) // 销毁操作，销毁线性表L
    ClearList(&L) // 清空操作，将线性表L清空为空表
    ListEmpty(L) // 判断线性表L是否为空表，若是返回true，否则返回false
    ListLength(L) // 求线性表L中的元素个数并返回
    GetElem(L, i, &e) // 取值操作，用e返回线性表L中第i个元素的值
    LocateElem(L, e) // 查找操作，查找线性表L中第1个与e相等的元素的位序
    PriorElem(L, cur_e, &pre_e) // 取前驱操作，若cur_e是线性表L中的元素且不是第1个，则用pre_e返回它的前驱
    NextElem(L, cur_e, &next_e) // 取后继操作，若cur_e是线性表L中的元素且不是最后一个，则用next_e返回它的后继
    ListInsert(&L, i, e) // 插入操作，在线性表L的第i个位置插入新元素e
    ListDelete(&L, i, &e) // 删除操作，删除线性表L的第i个元素，并用e返回其值
    ListTraverse(L, visit()) // 遍历操作，依次对L的每个元素调用visit()函数
}
