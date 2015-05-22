#ifndef LISTDROPDOWN_HPP_INCLUDED
#define LISTDROPDOWN_HPP_INCLUDED

#include "Widget.hpp"
#include <vector>
#include <string>

class ListDropDown : public Widget{
protected:
    std::vector<std::string>Items;
    bool open, scrollable;
    int max_open_item, visible_index;
    float Content_Size, Window_Size, Grip_Position, Content_Position, Grip_Size;
public:
    ListDropDown(Application* ap, int x, int y, int sx, int sy, int mop);
    //virtual void EventHandler(genv::event ev);
    virtual void Draw();
    void AddItem(std::string new_item);
    void DeleteVisibleItem();
    void SetVisibleIndex();
    void ClearItems();
    void ScrollbarAlgorithm();
    int GetVisibleIndex();
    std::string GetVisibleValue();


};

#endif // LISTDROPDOWN_HPP_INCLUDED
