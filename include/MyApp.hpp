#ifndef MYAPP_HPP_INCLUDED
#define MYAPP_HPP_INCLUDED
#include "Widget.hpp"
#include "StaticText.hpp"
#include "DynamicText.hpp"
#include "Application.hpp"

class MyApp : public Application
{
protected:
    /*** CREATING WIDGET POINTERS ***/
    DynamicText *st1;
    DynamicText *st2;
    DynamicText *st3;
    /*** MYAPP VARIABLES***/
public:
    MyApp(int w, int h);
    void Show();


};

#endif // MYAPP_HPP_INCLUDED
