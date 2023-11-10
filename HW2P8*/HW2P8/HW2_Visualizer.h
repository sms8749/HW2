//
//  HW2_Visualizer.h
//  HW2Prob8
//
//  Created by Serin Santhosh on 11/7/23.
//

#ifndef HW2_VISUALIZER
#define HW2_VISUALIZER

#include <iostream>
#include <array>
#include <map>
#include <string>
// need to compile and link the SDL library to the program and place into the file!
// if not the "#include "SDL.h" file will not work and the code will not run!
// Once again must compile and link the SDL library into the program or the line "#include "SDL.h" " will not run!
#include "SDL2/SDL.h"

#define WIDTH 1366
#define HEIGHT 803

struct plane_draw
{
  SDL_Vertex v1, v2, v3;
};

class Plane_Viz
{
public:
  std::map<std::pair<std::string, std::string>, double> airspace = 
{
    {    
        {"SCE","ORD"}, 640}, // miles
        { {"ORD","SCE"}, 640},
        { {"SCE","PHL"}, 160},
        { {"PHL","SCE"}, 160},
        { {"SCE","EWR"}, 220},
        { {"EWR","SCE"}, 220},
  };
  std::map<std::string, std::pair<int, int>> airport_location = 
    {
        {"SCE", {870,400}},
        {"ORD", {235,475}},
        {"PHL", {1030,425}},
        {"EWR", {1080,345}},
  };
  std::map<std::string, SDL_Color> plane_colors = { 
      {"AA", {255,0,0,255}}, {"UA", {0,0,255,255}}, {"NA", {0,255,0,255}} };
  std::map<std::array<std::string,3>, plane_draw> planes_info;
};

class HW2_VIZ
{
  bool quit = false;
  SDL_Event event;
  SDL_Window* win;
  SDL_Renderer* renderer;
  SDL_Surface* image;
  SDL_Texture* texture;
  SDL_Rect dest;
  Plane_Viz p_viz;
public:
    HW2_VIZ ();

  void visualize_plane (std::string airline, std::string origin, std::string des, double pos);
  void update (double dt);
};

#endif // !HW2_VISUALIZER
