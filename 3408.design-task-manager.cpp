#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
using std::string;
using std::unordered_map;
using std::set;
////////////////////////////////////////////////////////////////////////////////////////////////////

using user_id = int;
using task_id = int;
using priority = int;
unordered_map<task_id, user_id> belongs_to {};
unordered_map<task_id, priority> task_priority {};
auto comp = [](const task_id l, const task_id r)  {
    priority lp = task_priority.at(l), rp = task_priority.at(r);
    if (lp == rp) return l > r;
    return lp > rp;
};
class TaskManager {
public:
    set<task_id, decltype(comp)> user_tasks {};

    TaskManager(vector<vector<int>>& tasks) {
        for (auto&t:tasks) {
            user_id uid = t[0];
            task_id tid = t[1];
            priority prio = t[2];

            belongs_to[tid] = uid;
            task_priority[tid] = prio;
            user_tasks.insert(tid);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        belongs_to[taskId] = userId;
        task_priority[taskId] = priority;
        user_tasks.insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        user_tasks.erase(taskId);
        task_priority[taskId] = newPriority;
        user_tasks.insert(taskId);
    }
    
    void rmv(int taskId) {
        user_tasks.erase(taskId);
    }
    
    int execTop() {
        if (user_tasks.empty()) return -1;
        task_id tid = *user_tasks.begin();
        user_tasks.erase(tid);
        return belongs_to[tid];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */