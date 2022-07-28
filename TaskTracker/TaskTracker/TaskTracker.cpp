// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW, // новая
    IN_PROGRESS, // в разработке
    TESTING, // на тестировании
    DONE // завершена
};

TaskStatus Next(TaskStatus CurrentTaskStatus) {
    return static_cast<TaskStatus>(static_cast<int>(CurrentTaskStatus) + 1);
}
// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return PersonTaskList.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        ++PersonTaskList[person][TaskStatus::NEW];
    }

    // Функция для удаления нулей из словаря
    void RemoveZeros(TasksInfo& tasks_info) {
        // Соберём те статусы, которые нужно убрать из словаря
        vector<TaskStatus> statuses_to_remove;
        for (const auto& task_item : tasks_info) {
            if (task_item.second == 0) {
                statuses_to_remove.push_back(task_item.first);
            }
        }
        for (const TaskStatus status : statuses_to_remove) {
            tasks_info.erase(status);
        }
    }
    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count) {
        TasksInfo& PersonTasks = PersonTaskList[person];
        TasksInfo UpdatedPersontasks, UntouchedPersonTasks;

        for (TaskStatus status = TaskStatus::NEW;
            status != TaskStatus::DONE; status = Next(status)) {

            UntouchedPersonTasks[status] = PersonTasks[status];

            //can be used two cycle for - first for updated, second for untouched
            while (UntouchedPersonTasks[status] > 0 && task_count > 0) {
                ++UpdatedPersontasks[Next(status)];
                --UntouchedPersonTasks[status];
                --task_count;
            }
            PersonTasks[status] = UntouchedPersonTasks[status] + UpdatedPersontasks[status];
        }
        RemoveZeros(UpdatedPersontasks);
        RemoveZeros(UntouchedPersonTasks);

        return { UpdatedPersontasks, UntouchedPersonTasks };
    }
private: 
    map<string, TasksInfo> PersonTaskList;
};
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main()
{
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}
