# include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 10, x = 0;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces the item %d",x);
    ++mutex;
}
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d",x);
    x--;
    ++mutex;
}

int main()
{
    int n, i;
    printf("1.Producer"
    "\n2.Consumer"
    "\n3.Exit");
    for (i = 1; i>0; i++) {
        scanf("%d", &n);
        switch (n) {
        case 1:
            if ((mutex == 1)
            && (empty != 0)){
                producer();
            }
            break;

            case 2:
            if ((mutex ==1)
            && (full != 0)) {
              consumer();
            }
            break;

            case 3:
            exit(0);
            break;
        }
    }
}
