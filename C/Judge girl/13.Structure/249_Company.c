#include <stdio.h>
#include <string.h>
struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
};
typedef struct employee Employee;

int getid(Employee arr[], int size, char first_name[32], char last_name[32]) {
    int i;
    for (i = 0; i < size; ++i) {
        if (!(strncmp(first_name, arr[i].first_name, 32)))
            if (!(strncmp(last_name, arr[i].last_name, 32)))
                return arr[i].id;
    }
    return 0;
}

int get_bossid(Employee arr[], int size, int id) {
    int i;
    for (i = 0; i < size; ++i)
        if (arr[i].id == id)
            return arr[i].boss_id;
} //prime will return his own id

void getlist(int list[], int i, int id, Employee arr[], int size) {
    int boss = get_bossid(arr, size, id);
    if (boss == id) {
        list[i] = -1;
        return;
    }
    list[i] = boss;
    getlist(list, i+1, boss, arr, size);


}
int main() {
    int n, i, j, conflict, num;
    Employee arr[32];
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i].id);
        scanf("%s", &arr[i].first_name);
        scanf("%s", &arr[i].last_name);
        scanf("%d", &arr[i].boss_id);
    }
    char af[32], al[32], bf[32], bl[32];
    int bosslist_a[32], bosslist_b[32], a_id, b_id;
    scanf("%d", &num);
    for (num; num > 0; --num){
        conflict = 0;
    scanf("%s%s", &af, &al);
    scanf("%s%s", &bf, &bl);
    a_id = getid(arr, n, af, al);
    b_id = getid(arr, n, bf, bl);
    getlist(bosslist_a, 0, a_id, arr, n);
    getlist(bosslist_b, 0, b_id, arr, n);
    for (i = 0; i < n; ++i) {
        if (bosslist_a[i] == -1)
            break;
        if (bosslist_a[i] == b_id){
            printf("subordinate\n");
            conflict = 1;
            break;
        }
    }
    if (!conflict){
    for (i = 0; i < n; ++i) {
        if (bosslist_b[i] == -1)
            break;
        if (bosslist_b[i] == a_id){
            printf("supervisor\n");
            conflict = 1;
            break;
        }
    }
    }
    if (!conflict){
    for (i = 0; i < n; ++i) {
        if (bosslist_a[i] == -1)
            break;
        for (j = 0; j < n; ++j) {
            if (bosslist_b[j] == -1)
                break;
            if (bosslist_a[i] == bosslist_b[j]){
                printf("colleague\n");
                conflict = 1;
                break;
            }
        }
        if (conflict)
            break;
    }
    }
    if (!conflict)
        printf("unrelated\n");  
    }
    return 0;
}
