class Solution 
{
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) 
    {
        // Step 1: Store nums in an unordered_set for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());

        // Step 2: Create a dummy node pointing to head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 3: Use a pointer 'curr' to traverse the list
        ListNode* curr = dummy;

        // Step 4: Traverse and remove nodes whose values exist in numSet
        while (curr->next) 
        {
            if (numSet.count(curr->next->val)) 
            {
                // Delete node by skipping it
                curr->next = curr->next->next;
            } 
            else 
            {
                // Move to next node
                curr = curr->next;
            }
        }

        // Step 5: Return modified list (skipping dummy node)
        return dummy->next;
    }
};
