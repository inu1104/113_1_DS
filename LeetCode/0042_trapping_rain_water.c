int trap(int *height, int heightSize)
{
    int result = 0;
    int head = 0, rear = heightSize - 1;
    int head_height = height[head], rear_height = height[rear];
    while (head < rear)
    {
        if (height[head] < height[rear])
        {
            head++;
            if (head_height < height[head])
                head_height = height[head];
            else
                result += head_height - height[head];
        }
        else
        {
            rear--;
            if (rear_height < height[rear])
                rear_height = height[rear];
            else
                result += rear_height - height[rear];
        }
    }
    return result;
}
