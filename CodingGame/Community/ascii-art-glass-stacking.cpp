#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int glass_height()
{
    return 4;
}

int glass_width()
{
    return 5;
}

int max_height_glasses(const int N)
{
    return (sqrt(1.0 + 4 * 2 * N) - 1.0) / 2.0;
}

void draw_glasses(const int glasses_length, vector<string>& image)
{
    int left_x = (image[0].size() - glass_width()) / 2;
    int left_y = 0;
    for (int i = 1; i <= glasses_length; ++i)
    {
       int init_x = left_x;
       for (int glass_id = 1; glass_id <= i; ++glass_id)
       {
            for (int base = 0; base < glass_width(); ++base)
                image[left_y + glass_height() - 1][init_x + base] = '*';
            for (int h_side = 0; h_side < glass_height(); ++h_side)
            {
                image[left_y + h_side][init_x + 1] = '*';
                image[left_y + h_side][init_x + 3] = '*';
            }
            image[left_y][init_x + glass_width() / 2] = '*';
            init_x += glass_width() + 1;
       }
       left_x -= glass_width() / 2  + 1;
       left_y += glass_height();
    }
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    const int seq_length = max_height_glasses(N);
    vector<string> image(seq_length * glass_height(), 
        string(seq_length - 1 + seq_length * glass_width(), ' '));
    draw_glasses(seq_length, image);
    for (int i = 0; i < image.size(); ++i)
        cout << image[i] << endl;
}