#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        stack<int> stack1;
        queue<int> queue1;
        priority_queue<int> priority_queue1;
        bool isStack = true, isQueue = true, isPrioQ = true;
        for (int i = 0; i < n; i++) {
            int task, num;
            scanf("%d%d", &task, &num);
            if (task == 1) {
                if (isStack)
                    stack1.push(num);
                if (isPrioQ)
                    priority_queue1.push(num);
                if (isQueue)
                    queue1.push(num);
            }
            else {
                if (isStack) {
                    if (!stack1.empty() && num == stack1.top())
                        stack1.pop();
                    else
                        isStack = false;
                }
                if (isPrioQ) {
                    if (!priority_queue1.empty() && num == priority_queue1.top())
                        priority_queue1.pop();
                    else
                        isPrioQ = false;
                }
                if (isQueue) {
                    if (!queue1.empty() && num == queue1.front())
                        queue1.pop();
                    else
                        isQueue = false;
                }
            }
            if (!(isPrioQ || isQueue || isStack)) {
                for (int j = i + 1; j < n; j++)
                    scanf("%d%d", &num, &num);
                break;
            }
        }
        if (!(isPrioQ || isQueue || isStack))
            printf("impossible\n");
        else if ((isPrioQ && isQueue) || (isPrioQ && isStack) || (isQueue && isStack))
            printf("not sure\n");
        else if (isPrioQ)
            printf("priority queue\n");
        else if (isQueue)
            printf("queue\n");
        else
            printf("stack\n");

    }


    return 0;
}