#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool myFunc(pair<int, int> a, pair<int, int> b) {
    return (a.second - a.first > b.second - b.first);
}

struct interval {
    int i, j;
} interval1;

struct node {
    interval interv;
    node *left, *right;
    int max;
} node1;

bool hasConflict(node *root, interval *interv) {
    if (root == NULL)
        return false;
    if(root->max < interv->i)
        return false;
    if (root->interv.i <= interv->j && interv->i <= root->interv.j)
        return true;
    if (root->left != NULL && root->max >= interv->i)
        return hasConflict(root->left, interv);
    else if (root->right != NULL)
        return hasConflict(root->right, interv);
    return false;
}

void insert(interval *interv, node **root) {
    if(*root == NULL) {
        node *tmp = new node;
        tmp->right = NULL;
        tmp->left = NULL;
        tmp->interv = *interv;
        *root = tmp;
        tmp->max = interv->j;
    }
    else if(interv->i <= (*root)->interv.i) {
        insert(interv, &(*root)->left);
    }
    else
        insert(interv, &(*root)->right);
    if((*root)->max < interv->j)
        (*root)->max = interv->j;
}

int main() {
    int ord, rep;
    while(scanf("%d%d", &ord, &rep) && (ord || rep)){
        int max = -1;
        int tmpInt;
        node *root = NULL;
        vector<pair<int, int>> tasks;
        for(int i = 0; i < ord; i++) {
            int tmp1, tmp2;
            scanf("%d%d", &tmp1, &tmp2);
            if(tmp2 > max)
                max = tmp2;
            tasks.push_back(make_pair(tmp1, tmp2));
        }
        sort(tasks.begin(), tasks.end(), &myFunc);
        bool conflict = false;
        for(int i = 0; i < ord; i++){
            interval interv = {tasks[i].first + 1, tasks[i].second - 1};
            if(hasConflict(root, &interv)) {
                conflict = true;
                break;
            }
            interv.i -= 1; interv.j += 1;
            insert(&interv, &root);
        }
        vector<pair<int, int>> repTs;
        if(conflict)
            for(int i = 0; i < rep; i++)
                scanf("%d%d%d", &tmpInt, &tmpInt, &tmpInt);
        else {
            int i, j, repTime;
            while(rep--) {
                scanf("%d%d%d", &i, &j, &repTime);
                while (i <= max) {
                    interval tmpInterval = {i + 1, j - 1};
                    if(hasConflict(root, &tmpInterval)) {
                        conflict = true;
                        break;
                    }
                    tmpInterval.i -= 1; tmpInterval.j += 1;
                    insert(&tmpInterval, &root);
                    i += repTime;
                    j += repTime;
                    if(j > 1000000)
                        j = 1000000;
                }
                repTs.push_back(make_pair(i, j));
                if(conflict) {
                    while(rep--)
                        scanf("%d%d%d", &i, &i, &i);
                    break;
                }
            }
        }
        if(conflict)
            printf("CONFLICT\n");
        else
            printf("NO CONFLICT\n");
    }
    return 0;
}