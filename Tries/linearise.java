import java.util.*;
Node *linearizeAndReturnTail(Node *node)
{
    if (node->childs.size() == 0)
        return node;
    int n = node->childs.size();
    Node *oTail = linearizeAndReturnTail(node->childs[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        Node *tail = linearizeAndReturnTail(node->childs[i]);
        tail->childs.push_back(node->childs[i + 1]);
        node->childs.pop_back();
    }

    return oTail;
}