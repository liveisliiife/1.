#include "Window.h"

Window::Window() {
    this->activeTab = 0;
    tabs.append(Tab());
}

Tab Window::getActiveTab() {
    if (tabs.getSize()) return tabs.getNodeAtIndex(activeTab)->data;
    else return Tab();
}

bool Window::isEmpty() const {
    if (tabs.isEmpty()) return true;
    else return false;
}

void Window::newTab(const Tab &tab) {
    if (activeTab == tabs.getSize()-1) tabs.append(tab);
    else tabs.insertAtIndex(tab, activeTab+1);
    activeTab++;
}


void Window::closeTab() {
    tabs.removeNodeAtIndex(activeTab);
    if (tabs.isEmpty()) activeTab = -1;
    if (activeTab == tabs.getSize()) activeTab--;
}

void Window::moveActiveTabTo(int index) {
    if(index>=tabs.getSize()) index = tabs.getSize()-1;
    if (activeTab == index) return;
    tabs.moveToIndex(activeTab, index);
    activeTab = index;
}

void Window::changeActiveTabTo(int index) {
    if (index<0 || index>= tabs.getSize()) ;
    else activeTab = index;
}

void Window::addTab(Node<Tab> &tab) {
    if(!tabs.getSize()) activeTab=0;
    tabs.append(tab.data);
}

void Window::print() {
    if(tabs.isEmpty()) std::cout << "Window is empty" << std::endl;
    else std::cout << "The active tab is tab " << activeTab << std::endl;
    tabs.print();
}
