
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/fl_draw.H>

using namespace std;

#define C 10

//城市坐标
int citys_position[C][2] =
{
    {1304, 2312}, {3639, 1315}, {4177, 2244}, {3712, 1399}, {3488, 1535},
    {3326, 1556}, {3238, 1229}, {4196, 1004}, {4312, 7900}, {4386, 570}
};

//最优解序列
int best[C] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};

void drawOptimalPath(Fl_Window* window)
{
    Fl_Box* box = new Fl_Box(10, 10, 500, 500);
    box->box(FL_BORDER_BOX);
    box->color(FL_WHITE);

    for (int i = 0; i < C; i++)
    {
        int cityIndex = best[i] - 1;
        double x = citys_position[cityIndex][0];
        double y = citys_position[cityIndex][1];

        fl_color(FL_RED);
        fl_circle(x, y, 5);

        if (i < C - 1)
        {
            int nextCityIndex = best[(i + 1) % C] - 1; // Fix: Use modulo operator to wrap around the array
            double nextX = citys_position[nextCityIndex][0];
            double nextY = citys_position[nextCityIndex][1];

            fl_color(FL_BLUE);
            fl_line(x, y, nextX, nextY);
            fl_polygon(nextX, nextY, nextX - 5, nextY - 5, nextX + 5, nextY - 5);
        }
    }

    window->end();
    window->show();
}

int main()
{
    Fl_Window* window = new Fl_Window(5000, 5000, "Optimal Path");
    drawOptimalPath(window);
    return Fl::run();
}