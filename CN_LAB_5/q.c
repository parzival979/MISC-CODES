#include <stdio.h>
#include <stdlib.h>

int main(){
    int numFrames,windowSize,frameDropFreq;
    printf("Please enter the Number of frames\n");
    scanf("%d",&numFrames);
    printf("Please enter the window size\n");
    scanf("%d",&windowSize);
    printf("Please enter the frame Drop frequency\n");
    scanf("%d",&frameDropFreq);
    if(frameDropFreq<=windowSize){
        printf("The given combination of inputs is unsolvable\n");
        exit(0);
    }
    int numberOfFramesSent = 0,currentFrame = 1;
    while (1){
        if(currentFrame>numFrames){
            break;
        }
        else if(numFrames-currentFrame<windowSize-1){
            if((numberOfFramesSent+1)%frameDropFreq == 0){
                numberOfFramesSent+=numFrames-currentFrame+1;
            }
            else{
                currentFrame++;numberOfFramesSent++;
            }
        }
        else{
            if((numberOfFramesSent+1)%frameDropFreq == 0){
                numberOfFramesSent+=windowSize;
            }
            else{
                currentFrame++;numberOfFramesSent++;
            }
        }
    }
    printf("The number of frames sent is %d\n",numberOfFramesSent);
}