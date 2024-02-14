#include<stdio.h>
#include<conio.h>
#include<dos.h>

const int height=20;
const int width=20;

//p1 snake
int headx,heady,fruitx,fruity;
int bodyx[100],bodyy[100];

//p2 snake
int p2_headx,p2_heady,p2_tail_len;
int p2_bodyx[100],p2_bodyy[100];


int gameover;

//p1 controls
enum direction{stop=0,left,right,up,down};
enum direction dir;

//p2 controls
enum Direct2{s=0,l,r,u,d};
enum Direct2 D2;


int tail_len;
int i,j,k,m,score,p2_score;
void setup();
void draw();
void input();
int custom_kbhit();
void logic();
void overscreen();

void main()
{
char start;
printf("p1 controls = w,a,s,d\np2 controls = i,j,k,l");
printf("\n\n\t=======================\n\tenter s to start\n\t==================\n");
scanf("%s",&start);
if(start=='s')
{
setup();
while(gameover==0)
{
draw();
input();
logic();
delay(200);
system("cls");
}
}
}


void setup()
{
gameover=0;
dir=stop;
D2=s;
headx=height/2;
heady=width/2;

p2_headx=height/3;
p2_heady=width/3;

p2_tail_len=0;
fruitx=rand()%height;
fruity=rand()%width;
score=0;
p2_score=0;


}

void draw()
{
system("cls");
//upper bound
printf("\n\t\t");
for(i=0;i<width-8;i++)
{

printf("||");
}

printf("\n");
//mid bound snake fruit
for(i=0;i<height;i++)
{
for(j=0;j<width;j++)
{

if(j==0)
{
printf("\t\t||");
}

if(i==heady && j==headx)
{
printf("O");
}
else if(i==p2_heady && j==p2_headx)
{
printf("O");
}
else if(i==fruity && j==fruitx)
{
printf("*");
}
else
{
int print=0;
for(k=0;k<tail_len;k++)
{
if(bodyx[k]==j && bodyy[k]==i){
printf("o");
print=1;
}
}
//body for p2
for(m=0;m<p2_tail_len;m++)
{
if(p2_bodyx[m]==j && p2_bodyy[m]==i){
printf("0");
print=1;
}
}

if(print==0)
{
printf(" ");
}
}
if(j==width-1)
{
printf("||");
}
}
printf("\n");
}


printf("\t\t");
for(i=0;i<width-8;i++)
{
printf("||");
}

printf("\t\t\tp1 score: %d\np2 score: %d",score,p2_score);
}

void input()
{
if(custom_kbhit()) {
switch(getch())
{
case 'w':
dir=up;
break;

case 'i':
D2=u;
break;

case 's':
dir=down;
break;

case 'k':
D2=d;
break;

case 'a':
dir=left;
break;

case 'j':
D2=l;
break;

case 'd':
dir=right;
break;

case 'l':
D2=r;
break;

default:
break;
}
}
}

void logic()
{


//p1 body logic
int pre_bodyx=bodyx[0];
int pre_bodyy=bodyy[0];
int pre_2bodyx,pre_2bodyy;

int p2_pre_bodyx=p2_bodyx[0];
int p2_pre_bodyy=p2_bodyy[0];
int p2_pre_2bodyx,p2_pre_2bodyy;


bodyx[0]=headx;
bodyy[0]=heady;

p2_bodyx[0]=p2_headx;
p2_bodyy[0]=p2_heady;


for(i=1;i<tail_len;i++)
{
pre_2bodyx=bodyx[i];
pre_2bodyy=bodyy[i];
bodyx[i]=pre_bodyx;
bodyy[i]=pre_bodyy;
pre_bodyx=pre_2bodyx;
pre_bodyy=pre_2bodyy;
}

for(m=1;m<p2_tail_len;m++)
{
p2_pre_2bodyx=p2_bodyx[m];
p2_pre_2bodyy=p2_bodyy[m];
p2_bodyx[m]=p2_pre_bodyx;
p2_bodyy[m]=p2_pre_bodyy;
p2_pre_bodyx=p2_pre_2bodyx;
p2_pre_bodyy=p2_pre_2bodyy;
}




//p2 input
switch(D2)
{
case l:
p2_headx--;
break;

case r:
p2_headx++;
break;

case u:
p2_heady--;
break;

case d:
p2_heady++;
break;
default:
break;
}

//p1 input
switch(dir)
{
case left:
headx--;
break;

case right:
headx++;
break;

case up:
heady--;
break;

case down:
heady++;
break;
default:
break;
}


if(headx>=width || headx<0 || heady>=height || heady<0)
{

overscreen();
}

if(p2_headx>=width || p2_headx<0 || p2_heady>=height || p2_heady<0)
{

overscreen();
}

if(headx==fruitx && heady==fruity)
{
fruitx=rand()%width;
fruity=rand()%height;
score++;
tail_len++;
}
if(p2_headx==fruitx && p2_heady==fruity)
{
fruitx=rand()%width;
fruity=rand()%height;
p2_score++;
p2_tail_len++;
}
}

int custom_kbhit()
{
return bioskey(1);
}


void overscreen()
{
printf("\n\n\t\tGAMEOVER\n\n\t\t");
delay(1300);
gameover=1;
}
