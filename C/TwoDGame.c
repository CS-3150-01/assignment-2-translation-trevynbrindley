#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char **argv) {
    char map[20][100];

    for(int i=0; i<20; i++){
        for(int j=0; j<100; j++){
            map[i][j] = '\0';
        }
    }

    map[2][2] = 'P';

    bool proceed = true;
    bool argsCheck = false;

    int argsRunIndex = 0;

    char directions[][5] = {"North", "East", "South", "West"};
    static int directionX[] = {0, -1, 0, 1};
    static int directionY[] = {1, 0, -1, 0};

    static int currentDirection = 0;

    int currentPosition[] = {2,2};

    char input;

    if(argc>0){
        argsCheck = true;
    }

    while(proceed){
        for(int i=0; i<20; i++){
            for(int j=0; j<100; j++){
                if(map[i][j] == '\0'){
                    printf("%c", 'x');

                }else{
                    printf("%c", map[i][j]);
                }
            }
            printf("\n");
        }

        printf("Please traverse the world and explore using these commands: \n  W - Walk Forward\n  A - Turn Left\n  D - Turn Right\n  E - Check Direction\n  Q - Quit the Game\n");

        
        if(!argsCheck){
            scanf("%s", &input);
        }else{
            if(argsRunIndex == argc){
                argsCheck = false;
                input = 'e';
            }else{
                input = argv[argsRunIndex];
                argsRunIndex++;
            }
        }

        printf("%d x %d y\n", currentPosition[0], currentPosition[1]);

        switch(input){
            case 'w':
                map[currentPosition[1]][currentPosition[0]] = '#';
                if(!((currentPosition[0] - directionX[currentDirection] < 0) || (currentPosition[0] - directionX[currentDirection] > 100)||(currentPosition[1] - directionY[currentDirection] < 0) || (currentPosition[1] - directionY[currentDirection] > 20))){
                    
                    currentPosition[0] = currentPosition[0] - directionX[currentDirection];
                    currentPosition[1] = currentPosition[1] - directionY[currentDirection];
                    
                }
                map[currentPosition[1]][currentPosition[0]] = 'P';
                break;
            case 'a':
                currentDirection--;
                    //moves your index up or down the 3 arrays listed above
                    if(currentDirection < 0){
                        currentDirection = 3;
                    }
                    break;
            case 'd':
                currentDirection++;
                    //moves your index up or down the 3 arrays listed above

                    if(currentDirection > 3){
                        currentDirection = 0;
                    }
                    break;
            case 'e':
                printf("You are facing in the %sward direction!\n\n", directions[currentDirection]);
                break;
            case 'q':
                proceed = false;
                break;
            default:
                printf("You must enter one of the commands!\n\n");
                break;
        }
    }

    return 0;
}