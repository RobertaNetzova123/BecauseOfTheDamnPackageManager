#include <stdio.h>
struct tm_t
{
    int hour;
    int mins;
};
struct daytime_t
{
    int month;
    int day;
    struct tm_t info;
};

struct daytime_t razlika (struct daytime_t, struct daytime_t);
int main()
{
    struct daytime_t sum,sum2;

    scanf("%d%d",&sum.info.hour,&sum.info.mins);
    scanf("%d%d",&sum2.info.hour, & sum2.info.mins);
    razlika(sum,sum2);



    return 0;
}

struct daytime_t razlika(struct daytime_t sum1, struct daytime_t sum2 )
{
    struct daytime_t razl;
    razl.info.hour = sum2.info.hour - sum1.info.hour;
    razl.info.mins = sum2.info.mins - sum1.info.mins;
    // if(razlika.info.mins < 0) {razlika.info.mins=razlika.info.mins*(-1);}
    return razl;

}
