#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct BoundBox
{
    BoundBox(const int x, const int y, const int height, const int width) : 
        LeftX(x), LeftY(y), Width(width), Height(height) 
    {
    }
    
    int LeftX;
    int LeftY;
    int Width;
    int Height;
};

int building_piece_height(const vector<string>& image, const int col)
{
    int i = 0;
    for (; i < image.size() && image[i][col] != '#'; ++i)
        ;
    return image.size() - i;
}

int main()
{
    int W;
    int H;
    cin >> W >> H; cin.ignore();
    int max_y = -1;
    vector<string> image(H, string());
    vector<BoundBox> boxes;
    for (int i = 0; i < H; i++)
    {
        getline(cin, image[i]);
        if (max_y == -1 && find(image[i].begin(), image[i].end(), '#') != image[i].end())
            max_y = i;
    }
    BoundBox curr_box(0, max_y, 0, 0);
    for (int j = 0; j < W; ++j)
    {
        const int building_height = building_piece_height(image, j);
        if (building_height != 0)
        {
            ++curr_box.Width;
            curr_box.Height = max(curr_box.Height, building_height);
        }
        else
        {
            if (curr_box.Height == H - max_y)
                boxes.push_back(curr_box);
            curr_box = BoundBox(j + 1, max_y, 0, 0);
        }
    }
    if (curr_box.Height == H - max_y)
        boxes.push_back(curr_box);

    for (int box_id = 0; box_id < boxes.size(); ++box_id)
    {
        const BoundBox& curr_box = boxes[box_id];
        for (int i = 0; i < curr_box.Height; ++i)
        {
            int right_side = curr_box.Width - 1;
            while (image[curr_box.LeftY + i][curr_box.LeftX + right_side] != '#')
                --right_side;
            for (int j = 0; j <= right_side; ++j)
                cout << image[curr_box.LeftY + i][curr_box.LeftX + j];
            cout << endl;
        }       
        if (box_id + 1 < boxes.size())
            cout << endl;
    }
}
