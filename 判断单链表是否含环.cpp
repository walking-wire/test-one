bool hasCycle(struct ListNode *head)
{
    struct ListNode * fast = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        head = head->next;
        if(fast == head)
        {
            return true;
        }
    }
    return false;
}
