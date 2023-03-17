/* computes the dimensional weight of a 
box from input provided by the user */

#include <stdio.h>

int main(void)
{
    int height, lenght, width, volume, weight;

    printf("enter height of box: ");
    scanf("%d",&height);
    printf("enter lenght of box: ");
    scanf("%d",&lenght);
    printf("enter width of box: ");
    scanf("%d",&width);

    volume = height * lenght * width;
    weight = (volume + 165) / 166;

    printf("volume (cubic inches): %d\n",volume);
    printf("dimensional weight (pounds): %d\n", weight);

    return 0;
}