// https://leetcode.com/problems/add-two-numbers/description/

// Hidden code
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// My code
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *current1 = l1;
        ListNode *current2 = l2;

        ListNode *resultHead = new ListNode();

        ListNode *currentResult = resultHead;
        int newVal = 0;
        int carry = 0;
        bool first = true;
        while (current1 || current2)
        {
            if (current1 != nullptr)
            {
                newVal += current1->val;
                current1 = current1->next;
            }
            if (current2 != nullptr)
            {
                newVal += current2->val;
                current2 = current2->next;
            }
            if (carry > 0)
            {
                newVal += carry;
                carry = 0;
            }
            if (newVal > 9)
            {
                carry = newVal / 10;
                newVal = newVal % 10;
            }
            if (first)
            {
                currentResult->val = newVal;
                first = false;
            }
            else
            {
                ListNode *newNode = new ListNode(newVal);
                currentResult->next = newNode;
                currentResult = newNode;
            }
            newVal = 0;
        }
        if (carry > 0)
        {
            ListNode *newNode = new ListNode(carry);
            currentResult->next = newNode;
        }
        return resultHead;
    }
};