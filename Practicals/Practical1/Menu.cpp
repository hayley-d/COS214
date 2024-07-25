//
// Created by hayley on 2024/07/24.
//

#include "Menu.h"

Menu::Menu() = default;

bool Menu::addCourse(Course *course) {
  const std::string& description = course->getDescription();
  if(courses.find(description) != courses.end()) {
    return false;
  }
  courses[description] = course;
  return true;
}

bool Menu::addMenuItem(std::string courseDescription, std::string description, float price, int stock) {
  auto courseIterator = courses.find(courseDescription);
  if( courseIterator != courses.end()) {
    return courseIterator->second->addMenuItem(description,price,stock);
  }
  return false;
}

void Menu::printMenu() const {
  for(const auto& item : courses) {
      std::cout << item.first << std::endl;
      item.second->printMenuItems();
  }
}

void Menu::inventory() {
  for(const auto& item : courses) {
    std::cout << item.first << std::endl;
    item.second->printInventory();
  }
}

float Menu::orderItem(std::string courseDescription, char item) {
  auto courseIterator = courses.find(courseDescription);

  if(courseIterator != courses.end()) {
    MenuItem* menuItem = courseIterator->second->getMenuItem(item - 'a');
    if(menuItem->getStock() == 0) {
      return 0;
    }
    else {
      menuItem->reduceStock();
      return menuItem->getPrice();
    }
  }

  return 0;
}

bool Menu::isCourseEmpty() {
  return courses.empty();
}

void Menu::closeShop() {
  std::cout << "Closing shop. Deleting all " << courses.size() << " courses" << std::endl;
  for(auto& item : courses) {
    delete item.second;
  }
  courses.clear();
}

Menu::~Menu() {
  std::cout << "Menu destructor called" << std::endl;
  closeShop();
}


