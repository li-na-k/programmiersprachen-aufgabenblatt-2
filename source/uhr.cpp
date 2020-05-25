#include "window.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>

int main(int argc, char* argv[])
{

  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    //win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    //win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    //win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    //draw clock
    Vec2 center{400,400};
    Circle circle1{{center}, 300.0f, {0.0f, 0.5f, 0.8f}};
    circle1.draw(win);

    //Rotationsmatrix 
    //Eine Minute auf Radius = 6 Deg = 0,10472 Rad 
    const float rad_minute = 0.1047f;
    Mat2 rotmax = make_rotation_mat2(rad_minute);

    //find how many sec / minutes / hours have gone by
    int aktuelle_sek = win.get_time(); //cast to int
    int aktuelle_minuten = aktuelle_sek / 60; //cast to int
    int aktuelle_stunden = aktuelle_minuten / 60; //cast to int

    //default end position of Vec2 clock hands
    Vec2 sek_point{400.0f, 130.0f};
    Vec2 minute_point{400.0f, 130.0f};
    Vec2 hour_point{400.0f, 200.0f};

    // set end position of clock hands to current position
    for(int i = 0; i < aktuelle_sek; ++i){
      sek_point -= center;
      sek_point = sek_point * rotmax;
      sek_point += center;
    }

    for(int i = 0; i < aktuelle_minuten; ++i){ //minuten
      minute_point -= center;
      minute_point = minute_point * rotmax;
      minute_point += center;
   }

   for(int i = 0; i < aktuelle_stunden; ++i){ //stunden
      hour_point -= center;
      hour_point = hour_point * rotmax;
      hour_point += center;
   }
  
    
    std::string clock_text = "ROLEX";
    win.draw_text(360.0f, 200.0f, 32, clock_text);

    //draw clock hands
    win.draw_line(400.0f,400.0f, minute_point.x, minute_point.y, 0.0f, 0.1f, 0.9f); //Minutenzeiger
    win.draw_line(400.0f,400.0f, hour_point.x, hour_point.y, 0.0f, 0.9f, 0.9f, 2.5f);  //Stundenzeiger
    win.draw_line(400.0f,400.0f, sek_point.x, sek_point.y, 0.5f, 0.0f, 0.0f, 0.5f);  //Sekundenzeiger


    

    win.update();

  }

  return 0;
}
