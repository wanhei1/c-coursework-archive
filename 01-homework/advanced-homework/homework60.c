#include <stdio.h>
#include <stdlib.h>
int main() {
struct student {
int num;
float scores;
};
student *stu = new student;
float insert = 0, temp = 0;
int i = 0;
for (; insert != -1; i++) {
scanf("%f", &insert);
stu[i].num = i + 1;
stu[i].scores = insert;
}
for (int m = 0; m < i - 2; m++) {
for (int n = 0; n < i - 2; n++) {
temp = stu[n].scores;
if (temp < stu[n + 1].scores) {
stu[n].scores = stu[n + 1].scores;
stu[n + 1].scores = temp;
temp = stu[n].num;
stu[n].num = stu[n+1].num;
stu[n+1].num = (int)temp;
}
}
}
for (int j = 0 ; j < i - 1 ; j++){
printf("%s%d%s\t%s%d\t%s%.2f\n","第",j+1,"名：","号数：",stu[j].num,"成绩：",stu[j].scores);
}
system("PAUSE");
return 0;
}
