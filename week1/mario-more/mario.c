#include <cs50.h>
#include <stdio.h>

int ask_user_for_height();
void render_mario_less(int height);

int main(void)
{
    render_mario_less(ask_user_for_height());
}

int ask_user_for_height()
{

    int min_height = 1;
    int max_height = 8;
    int height;
    do 
    {
        height = get_int("Height: ");
    }

    while (height < min_height || height > max_height);

    return height;
}

void render_mario_less(int height) 
{
    int spaces_to_render = height - 1;
    string space_icon = " ";
    string block_icon = "#";

    for (int rows = 0; rows < height; rows++)
    {
        int blocks_to_render = rows + 1;
        for (int spaces = spaces_to_render; spaces > rows; spaces--)
        {
            printf("%s", space_icon);     
        }

        for (int blocks = 0; blocks < blocks_to_render; blocks++)
        {
            printf("%s", block_icon);    
        }
        printf("%s%s", space_icon, space_icon);     

        for (int blocks = 0; blocks < blocks_to_render; blocks++)
        {
            printf("%s", block_icon);    
        }

        printf("\n");    
    }
}
