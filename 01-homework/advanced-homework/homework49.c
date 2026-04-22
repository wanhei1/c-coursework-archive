#include <stdio.h>
int main(int argc, char **argv){
int n, i, arr_src[100] = {0}, max= 0, arr_res[100] = {1};
scanf("%d", &n);
getchar();
for(i = 0; i < n; i++)
{
scanf("%d", &arr_src[i]);
getchar();
if (i > 0)
{
if(arr_src[i] == arr_src[i-1])
{
arr_res[i] = arr_res[i-1] + 1;
}
else if(arr_src[i] != arr_src[i-1])
{
arr_res[i] = 1;
}
}
}
int start, end;
for(i = 0; i < n; i++)
{
if(arr_res[i] > max)
{
max = arr_res[i];
end = i;
}
}
start = end - (max - 1);
if(max > 1)
printf("The longest equal number list is from %d to %d.\n", start, end);
else 
printf("No equal number list.\n");
return 0;}