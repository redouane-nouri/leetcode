#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

class TaskManager {
  struct Compare {
    bool operator()(const std::pair<int, int> &a,
                    const std::pair<int, int> &b) const {
      if (a.second == b.second)
        return a.first < b.first;

      return a.second < b.second;
    }
  };
  std::unordered_map<int, std::pair<int, int>> tasksInfo;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      Compare>
      orderedTasks;

public:
  TaskManager(std::vector<std::vector<int>> &tasks) {
    for (std::vector<int> &task : tasks) {
      tasksInfo[task[1]] = {task[0], task[2]};
      orderedTasks.push({task[1], task[2]});
    }
  }

  void add(int userId, int taskId, int priority) {
    tasksInfo[taskId] = {userId, priority};
    orderedTasks.push({taskId, priority});
  }

  void edit(int taskId, int newPriority) {
    int userId = tasksInfo[taskId].first;
    tasksInfo[taskId] = {userId, newPriority};
    orderedTasks.push({taskId, newPriority});
  }

  void rmv(int taskId) { tasksInfo.erase(taskId); }

  int execTop() {
    while (!orderedTasks.empty()) {
      const std::pair<int, int> &t = orderedTasks.top();
      std::unordered_map<int, std::pair<int, int>>::iterator it =
          tasksInfo.find(t.first);

      if (it != tasksInfo.end() && it->second.second == t.second) {
        int userId = it->second.first;
        tasksInfo.erase(it);
        orderedTasks.pop();
        return userId;
      }

      orderedTasks.pop();
    }
    return -1;
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
