class Solution
{
public:
    Node *createmapping(Node *root, map<Node *, Node *> &nodeToparent, int target)
    {
        queue<Node *> q;
        q.push(root);
        Node *hit = new Node(NULL);
        nodeToparent[root] = NULL;

        while (!q.empty())
        {

            Node *temp = q.front();
            q.pop();

            if (temp->data == target)
            {
                hit = temp;
            }

            if (temp->left)
            {
                nodeToparent[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                nodeToparent[temp->right] = temp;
                q.push(temp->right);
            }
        }

        return hit;
    }

    int burntree(Node *hit, map<Node *, Node *> nodeToparent)
    {

        map<Node *, bool> visited;
        queue<Node *> q;

        q.push(hit);
        visited[hit] = true;
        int ans = 0;
        while (!q.empty())
        {

            int size = q.size();
            bool flag = 0;
            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                q.pop();

                if (front->left && !visited[front->left])
                {

                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if (front->right && !visited[front->right])
                {

                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if (nodeToparent[front] && !visited[nodeToparent[front]])
                {
                    flag = 1;
                    q.push(nodeToparent[front]);
                    visited[nodeToparent[front]] = 1;
                }

            }
            if (flag == 1)
            {
                ans++;
            }
        }
        return ans;
    }
    int minTime(Node *root, int target)
    {
        // Your code goes here

        map<Node *, Node *> nodeToparent;
        Node *hit = createmapping(root, nodeToparent, target);
        int ans = burntree(hit, root, nodeToparent);
        return ans;
    }
};