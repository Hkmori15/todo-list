#include <cstddef>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Task {
  std::string description;
  bool completed{false};
};

class TodoList {
private:
  std::vector<Task> tasks;
  const std::string filename{"tasks.txt"};

  void saveToFile() {
    std::ofstream file(filename);

    for (const auto &task : tasks) {
      file << task.completed << ";" << task.description << "\n";
    }
  }

  void loadFromFile() {
    std::ifstream file(filename);

    if (!file)
      return;

    std::string line;

    while (std::getline(file, line)) {
      Task task;
      task.completed = line[0] == '1';
      task.description = line.substr(2);
      tasks.push_back(task);
    }
  }

public:
  TodoList() { loadFromFile(); }

  void addTask(const std::string &description) {
    tasks.push_back({description});
    saveToFile();
  }

  void markCompleted(size_t index) {
    if (index < tasks.size()) {
      tasks[index].completed = true;
      saveToFile();
    }
  }

  void removeTask(size_t index) {
    if (index < tasks.size()) {
      tasks.erase(tasks.begin() + index);
      saveToFile();
    }
  }

  void showTasks() const {
    if (tasks.empty()) {
      std::cout << "No tasks yet!\n";

      return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
      const auto &task = tasks[i];

      std::cout << std::format("[{}] {}. {}\n", task.completed ? "X" : " ",
                               i + 1, task.description);
    }
  }
};

int main() {
  TodoList todoList;
  std::string command;

  while (true) {
    std::cout << "\n=== Todo List ===\n"
              << "1. Add task\n"
              << "2. Mark task as completed\n"
              << "3. Remove task\n"
              << "4. Show tasks\n"
              << "5. Exit\n"
              << "Choose option: ";

    std::getline(std::cin, command);

    if (command == "1") {
      std::cout << "Enter task desc: ";
      std::string description;
      std::getline(std::cin, description);

      todoList.addTask(description);
    } else if (command == "2") {
      std::cout << "Enter task number: ";
      std::string index;
      std::getline(std::cin, index);

      todoList.markCompleted(std::stoul(index) - 1);
    } else if (command == "3") {
      std::cout << "Enter task number to remove: ";
      std::string index;
      std::getline(std::cin, index);

      todoList.removeTask(std::stoul(index) - 1);
    } else if (command == "4") {
      todoList.showTasks();
    } else if (command == "5") {
      break;
    }
  }
}