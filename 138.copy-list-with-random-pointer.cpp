/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, int> node_map;
        vector<Node *> node_vec;
        Node *ptr = head;
        int i = 0;
        while (ptr != nullptr)
        {
            //            node_map[ptr] = i;
            node_map.insert(pair<Node *, int>(ptr, i));
            node_vec.push_back(new Node(ptr->val, nullptr, nullptr));
            ++i;
            ptr = ptr->next;
        }
        //to avoid doing other operation to the next of the last node
        node_vec.push_back(nullptr);

        ptr = head;
        i = 0;
        while (ptr != nullptr)
        {
            node_vec[i]->next = node_vec[i + 1];
            if (ptr->random != nullptr)
            {
                int temp = node_map[ptr->random];
                node_vec[i]->random = node_vec[temp];
            }
            ptr = ptr->next;
            ++i;
        }
        return node_vec[0];
    }
};
