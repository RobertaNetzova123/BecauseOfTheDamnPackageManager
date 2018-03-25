#include <stdio.h>
   
struct house_t
{
        int floors;
        float area;
        int dec;
};
 
struct house_t buy_house(struct house_t houses[10]);
 
int main()
{
        struct house_t houses[10];
        for(int i = 0; i < 2; i++)
        {
                scanf("%d %f %d", &houses[i].floors, &houses[i].area, &houses[i].dec);
        }

        struct house_t home = buy_house(houses);
        printf("%d %.2f %d", home.floors, home.area, home.dec);
        return 0;

}
 
struct house_t buy_house(struct house_t houses[10])
{
        for(int i = 0; i < 10; i++)
        {
                if(houses[i].floors >= 2 && houses[i].area >= 1 && houses[i].dec == 1) return houses[i];
        }
}

