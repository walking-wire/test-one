struct ListNode* reverseList(struct ListNode* head)
{
    if(!head)
    {
        return head;
    }
    struct ListNode * pre = NULL;
    struct ListNode * later = head->next;
    while(later)
    {
        head->next = pre;
        pre = head;
        head = later;
        later = later->next;
    }
    head->next = pre;
    return head;
}
