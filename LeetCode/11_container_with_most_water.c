int maxArea(int* height, int heightSize) {
    int maxArea = 0, currentArea, width;
    int head = 0, rear = heightSize - 1;
    while(head != rear){
        width = rear - head;
        if(height[head] < height[rear]){
            currentArea = height[head] * width;
            head++;
        }else{
            currentArea = height[rear] * width;
            rear--;
        }
        maxArea = currentArea > maxArea ? currentArea : maxArea;
    }
    return maxArea;
}
