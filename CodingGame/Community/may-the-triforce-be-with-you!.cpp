#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void draw_triforce(vector<string>& image, const int triangle_height, const int triangle_width)
{
    image[0][0] = '.';
    int left_x = (image[0].size() - triangle_width) / 2;
    int left_y = 0;
    for (int i = 1; i <= 2; ++i)
    {
        int init_x = left_x;
        for (int j = 1; j <= i; ++j)
        {
            for (int h = 0; h < triangle_height; ++h)
            {
                const int off = triangle_width / 2 - h;  
                int w = off;
                for (; w + off < triangle_width; ++w)
                    image[left_y + h][init_x + w] = '*';
                for (; j == i && init_x + w < image[left_y + h].size(); )
                    image[left_y + h].pop_back();
            }
            init_x += triangle_width + 1;
        }
        left_x -= triangle_width / 2 + 1;
        left_y += triangle_height;
    }
}
int main()
{
    int N;
    cin >> N; cin.ignore();
    const int triangle_height = N;
    const int triangle_width = 2 * N - 1;
    vector<string> image(2 * N, string(triangle_width * 2 + 1, ' '));
    draw_triforce(image, triangle_height, triangle_width);
    for (int i = 0; i < image.size(); ++i)
        cout << image[i] << endl;
}
