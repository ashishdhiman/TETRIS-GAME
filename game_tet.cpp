/*
      This code is only for demonstration purpose and as it is basis.
			and without any warrenty .....
****************************************************
		This is compiled in TurboC++ compiler and runned under windows environment.
		AUTHOR: ASHISH DHIMAN
		Email id: ashishdhiman_del@yahoo.com
		feedbacks..queries & compliments r heartly welcomed....
Hi Guys!!There is a bug in this code...when the inverted_L block is made to rotate in the 4th position while near any
wall or blocks...it behaves unanamiously!!!
Rest is fine and working
ENJOY!!!
*/
	#include <dos.h>
	#include <iostream.h>
	#include <graphics.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>
	#include <bios.h>
	#include <ctype.h>
	#include <math.h>
	void build(int xloc, int yloc,int color=RED)

{
	  int x1,x2,y1,y2,x3,y3,x4,y4;
	  x1=xloc-10;
	  x2=xloc+10;
	  y1=yloc-10;
	  y2=yloc+10;
	  x3=xloc-8;
	  y3=yloc-8;
	  x4=xloc+8;
	  y4=yloc+8;
if(color==BLACK)
{	  setcolor(BLACK);
	  rectangle(x1,y1,x2,y2);
}
else
{ 	  setcolor(RED);
	  rectangle(x1,y1,x2,y2);
}
if(color==BLACK)
{         setcolor(BROWN);
	  rectangle(x3,y3,x4,y4);
	  setfillstyle(SOLID_FILL, BLACK);
	  floodfill(xloc,yloc,color);
}
else if(color==WHITE)
{    	  setfillstyle(SOLID_FILL,WHITE);
	   floodfill(xloc,yloc,RED);
}
else
{	  setfillstyle(SOLID_FILL,BROWN);
	  floodfill(xloc,yloc,RED);
	  setcolor(BLACK);
	  rectangle(x3,y3,x4,y4);
}
}

	  void shape(int *xloc,int *yloc,int blkno,int seq,int *flag)
{
	  switch(blkno)
{
case 0:
	  switch(seq)
{
case 0:
case 2:                      //POS0
	  xloc[1]=xloc[0]+21;
	  xloc[2]=xloc[0]+42;
	  xloc[3]=xloc[0]+63;
	  yloc[1]=yloc[0];
	  yloc[2]=yloc[0];
	  yloc[3]=yloc[0];

	  if(*flag==1)

{         build(xloc[0],yloc[0],WHITE);   //stick at rest
	  build(xloc[1],yloc[1],WHITE);
	  build(xloc[2],yloc[2],WHITE);
	  build(xloc[3],yloc[3],WHITE);

	  goto end;
}
	  build(xloc[0],yloc[0]);   //stick
	  build(xloc[1],yloc[1]);
	  build(xloc[2],yloc[2]);
	  build(xloc[3],yloc[3]);

	  break;
case 1:
case 3:                      //POS1
	  xloc[1]=xloc[0];
	  xloc[2]=xloc[0];
	  xloc[3]=xloc[0];
	  yloc[1]=yloc[0]+21;
	  yloc[2]=yloc[0]+42;
	  yloc[3]=yloc[0]+63;

	  if(*flag==1)

{         build(xloc[0],yloc[0],WHITE);   //stick at rest
	  build(xloc[1],yloc[1],WHITE);
	  build(xloc[2],yloc[2],WHITE);
	  build(xloc[3],yloc[3],WHITE);

	  goto end;
}
	  build(xloc[0],yloc[0]);   //stick
	  build(xloc[1],yloc[1]);
	  build(xloc[2],yloc[2]);
	  build(xloc[3],yloc[3]);

	  break;

}
end:
	  break;
case 1:                       //POS0{DEFAULT}SQUARE NO SEQUANCE IS NEEDED
	  xloc[1]=xloc[0]+21;
	  xloc[2]=xloc[0]+21;
	  xloc[3]=xloc[0];
	  yloc[1]=yloc[0];
	  yloc[2]=yloc[0]-21;
	  yloc[3]=yloc[0]-21;
	  if(*flag==1)

{         build(xloc[0],yloc[0],WHITE);   //square at rest
	  build(xloc[1],yloc[1],WHITE);
	  build(xloc[2],yloc[2],WHITE);
	  build(xloc[3],yloc[3],WHITE);

	  goto end1;
}
	  build(xloc[0],yloc[0]);    //square
	  build(xloc[1],yloc[1]);
	  build(xloc[2],yloc[2]);
	  build(xloc[3],yloc[3]);
end1:
	  break;
case 2:
	  switch(seq)
{
case 0:

	  xloc[1]=xloc[0]+21;
	  xloc[2]=xloc[0]-21;
	  xloc[3]=xloc[0]-21;
	  yloc[1]=yloc[0];
	  yloc[2]=yloc[0];
	  yloc[3]=yloc[0]-21;
	  if(*flag==1)

{         build(xloc[0],yloc[0],WHITE);   //invL at rest
	  build(xloc[1],yloc[1],WHITE);
	  build(xloc[2],yloc[2],WHITE);
	  build(xloc[3],yloc[3],WHITE);

	  goto end2;
}
	  build(xloc[0],yloc[0]);  //invL
	  build(xloc[1],yloc[1]);
	  build(xloc[2],yloc[2]);
	  build(xloc[3],yloc[3]);
	  break;
case 1:

	  xloc[1]=xloc[0];
	  xloc[2]=xloc[0];
	  xloc[3]=xloc[0]+21;
	  yloc[1]=yloc[0]+21;
	  yloc[2]=yloc[0]-21;
	  yloc[3]=yloc[0]-21;
	  if(*flag==1)

{         build(xloc[0],yloc[0],WHITE);   //invL at rest
	  build(xloc[1],yloc[1],WHITE);
	  build(xloc[2],yloc[2],WHITE);
	  build(xloc[3],yloc[3],WHITE);

	  goto end2;
}
	  build(xloc[0],yloc[0]);  //invL
	  build(xloc[1],yloc[1]);
	  build(xloc[2],yloc[2]);
	  build(xloc[3],yloc[3]);

	  break;

case 2:

	  xloc[1]=xloc[0]-21;
	  xloc[2]=xloc[0]+21;
	  xloc[3]=xloc[0]+21;
	  yloc[1]=yloc[0];
	  yloc[2]=yloc[0];
	  yloc[3]=yloc[0]+21;
	  if(*flag==1)

{         build(xloc[0],yloc[0],WHITE);   //invL at rest
	  build(xloc[1],yloc[1],WHITE);
	  build(xloc[2],yloc[2],WHITE);
	  build(xloc[3],yloc[3],WHITE);
	  goto end2;
}

	  build(xloc[0],yloc[0]);  //invL
	  build(xloc[1],yloc[1]);
	  build(xloc[2],yloc[2]);
	  build(xloc[3],yloc[3]);
	  break;
case 3:
	  xloc[1]=xloc[0];
	  xloc[2]=xloc[0];
	  xloc[3]=xloc[0]-21;
	  yloc[1]=yloc[0]-21;
	  yloc[2]=yloc[0]+21;
	  yloc[3]=yloc[0]+21;
	  if(*flag==1)

{         build(xloc[0],yloc[0],WHITE);   //invL at rest
	  build(xloc[1],yloc[1],WHITE);
	  build(xloc[2],yloc[2],WHITE);
	  build(xloc[3],yloc[3],WHITE);

	  goto end2;
}
	  build(xloc[0],yloc[0]);  //invL
	  build(xloc[1],yloc[1]);
	  build(xloc[2],yloc[2]);
	  build(xloc[3],yloc[3]);
	  break;
}
end2:
	  break;
case 3:
	  switch(seq)
{
case 0:                        //POS0
case 2:
	  xloc[1]=xloc[0]+21;
	  xloc[2]=xloc[0];
	  xloc[3]=xloc[0]-21;
	  yloc[1]=yloc[0];
	  yloc[2]=yloc[0]+21;
	  yloc[3]=yloc[0]+21;
	  if(*flag==1)

{         build(xloc[0],yloc[0],WHITE);   //Z at rest
	  build(xloc[1],yloc[1],WHITE);
	  build(xloc[2],yloc[2],WHITE);
	  build(xloc[3],yloc[3],WHITE);

	  goto end3;
}
	  build(xloc[0],yloc[0]);       //Z
	  build(xloc[1],yloc[1]);
	  build(xloc[2],yloc[2]);
	  build(xloc[3],yloc[3]);
	  break;
case 1:
case 3:                        //POS1
	  xloc[1]=xloc[0];xloc[2]=xloc[0]-21;xloc[3]=xloc[0]-21;yloc[1]=yloc[0]+21;yloc[2]=yloc[0];yloc[3]=yloc[0]-21;
	  if(*flag==1)

{         build(xloc[0],yloc[0],WHITE);   //Z at rest
	  build(xloc[1],yloc[1],WHITE);
	  build(xloc[2],yloc[2],WHITE);
	  build(xloc[3],yloc[3],WHITE);

	  goto end3;
}
	  build(xloc[0],yloc[0]);       //Z
	  build(xloc[1],yloc[1]);
	  build(xloc[2],yloc[2]);
	  build(xloc[3],yloc[3]);
}
end3:
	  break;
}
}
	  void shapeb(int *xloc,int *yloc,int blkno,int seq,int check)
{
	  switch(blkno)
{
case 0:
	  switch(seq)
{
case 0:                      //POS0
case 2:
	  xloc[1]=xloc[0]+21;
	  xloc[2]=xloc[0]+42;
	  xloc[3]=xloc[0]+63;
	  yloc[1]=yloc[0];
	  yloc[2]=yloc[0];
	  yloc[3]=yloc[0];
	  if(check==1)
	  {
	  goto end;
	  }
	  build(xloc[0],yloc[0],BLACK);   //stick
	  build(xloc[1],yloc[1],BLACK);
	  build(xloc[2],yloc[2],BLACK);
	  build(xloc[3],yloc[3],BLACK);
end:
	  break;
case -1:
case 1:                      //POS1
case 3:
	  xloc[1]=xloc[0];
	  xloc[2]=xloc[0];
	  xloc[3]=xloc[0];
	  yloc[1]=yloc[0]+21;
	  yloc[2]=yloc[0]+42;
	  yloc[3]=yloc[0]+63;
	  if(check==1)
	  {
	  goto end1;
	  }
	  build(xloc[0],yloc[0],BLACK);   //stick
	  build(xloc[1],yloc[1],BLACK);
	  build(xloc[2],yloc[2],BLACK);
	  build(xloc[3],yloc[3],BLACK);
end1:
	  break;

}
	  break;
case 1:                       //POS0{DEFAULT}NO SEQUANCE IS NEEDED
	  xloc[1]=xloc[0]+21;
	  xloc[2]=xloc[0]+21;
	  xloc[3]=xloc[0];
	  yloc[1]=yloc[0];
	  yloc[2]=yloc[0]-21;
	  yloc[3]=yloc[0]-21;
	  if(check==1)
	  {
	  goto end2;
	  }
	  build(xloc[0],yloc[0],BLACK);    //square
	  build(xloc[1],yloc[1],BLACK);
	  build(xloc[2],yloc[2],BLACK);
	  build(xloc[3],yloc[3],BLACK);
end2:
	  break;
case 2:
	  switch(seq)
{
case 0:

	  xloc[1]=xloc[0]+21;
	  xloc[2]=xloc[0]-21;
	  xloc[3]=xloc[0]-21;
	  yloc[1]=yloc[0];
	  yloc[2]=yloc[0];
	  yloc[3]=yloc[0]-21;
	  if(check==1)
	  break;
	  build(xloc[0],yloc[0],BLACK);  //invL
	  build(xloc[1],yloc[1],BLACK);
	  build(xloc[2],yloc[2],BLACK);
	  build(xloc[3],yloc[3],BLACK);
	  break;
case 1:

	  xloc[1]=xloc[0];
	  xloc[2]=xloc[0];
	  xloc[3]=xloc[0]+21;
	  yloc[1]=yloc[0]+21;
	  yloc[2]=yloc[0]-21;
	  yloc[3]=yloc[0]-21;
	  if(check==1)
	  break;
	  build(xloc[0],yloc[0],BLACK);  //invL
	  build(xloc[1],yloc[1],BLACK);
	  build(xloc[2],yloc[2],BLACK);
	  build(xloc[3],yloc[3],BLACK);
	  break;
case 2:
	  xloc[1]=xloc[0]-21;
	  xloc[2]=xloc[0]+21;
	  xloc[3]=xloc[0]+21;
	  yloc[1]=yloc[0];
	  yloc[2]=yloc[0];
	  yloc[3]=yloc[0]+21;
	  if(check==1)
	  break;
	  build(xloc[0],yloc[0],BLACK);  //invL
	  build(xloc[1],yloc[1],BLACK);
	  build(xloc[2],yloc[2],BLACK);
	  build(xloc[3],yloc[3],BLACK);
	  break;
case 3:
case -1:
	  xloc[1]=xloc[0];
	  xloc[2]=xloc[0];
	  xloc[3]=xloc[0]-21;
	  yloc[1]=yloc[0]-21;
	  yloc[2]=yloc[0]+21;
	  yloc[3]=yloc[0]+21;
	  if(check==1)
	  break;
	  build(xloc[0],yloc[0],BLACK);  //invL
	  build(xloc[1],yloc[1],BLACK);
	  build(xloc[2],yloc[2],BLACK);
	  build(xloc[3],yloc[3],BLACK);
	  break;
}
	  break;

case 3:
	  switch(seq)
{
case 0:                        //POS0
case 2:
	  xloc[1]=xloc[0]+21;
	  xloc[2]=xloc[0];
	  xloc[3]=xloc[0]-21;
	  yloc[1]=yloc[0];
	  yloc[2]=yloc[0]+21;
	  yloc[3]=yloc[0]+21;
	  if(check==1)
	  {
	  break;
	  }
	  build(xloc[0],yloc[0],BLACK);       //Z
	  build(xloc[1],yloc[1],BLACK);
	  build(xloc[2],yloc[2],BLACK);
	  build(xloc[3],yloc[3],BLACK);
	  break;
case 1:
case 3:
case -1:			//POS1
	  //yloc[0]=yloc[0]+21;
	  xloc[1]=xloc[0];
	  xloc[2]=xloc[0]-21;
	  xloc[3]=xloc[0]-21;
	  yloc[1]=yloc[0]+21;
	  yloc[2]=yloc[0];
	  yloc[3]=yloc[0]-21;
	  if(check==1)
	  {
	  break;
	  }
	  build(xloc[0],yloc[0],BLACK);       //Z
	  build(xloc[1],yloc[1],BLACK);
	  build(xloc[2],yloc[2],BLACK);
	  build(xloc[3],yloc[3],BLACK);
	  break;

}
	  break;

default:  cout<<"SORRY";
}

}
	void go(int *xloc,int *yloc,int blkno,int *seq)
{
	char ch;
	int key;
	while (bioskey(1) != 0)
{
	key = bioskey(0);
}
	delay(30);


	switch((char)key)

{	case 'a'  :
		  shapeb(xloc,yloc,blkno,*seq,0);
		  if(getpixel(*xloc-13,yloc[0]) == YELLOW || getpixel(*(xloc+1)-13,yloc[1]) == YELLOW || getpixel(*(xloc+2)-13,yloc[2]) == YELLOW || getpixel(*(xloc+3)-13,yloc[3]) == YELLOW)
		  break;
		  if((getpixel(*xloc-19,*yloc) ==  WHITE )|| (getpixel(xloc[1]-19,yloc[1]) == WHITE )|| (getpixel(xloc[2]-19,yloc[2]) == WHITE )|| (getpixel(xloc[3]-19,yloc[3]) == WHITE))
		  break;
		  *xloc=*xloc-21;
		  break;
	case 'd' :
		  shapeb(xloc,yloc,blkno,*seq,0);
		  if(getpixel(*xloc+13,yloc[0]) == YELLOW || getpixel(*(xloc+1)+13,yloc[1]) == YELLOW || getpixel(*(xloc+1)+13,yloc[2]) == YELLOW || getpixel(*(xloc+3)+13,yloc[3]) == YELLOW)
		  break;
		  if((getpixel(xloc[0]+19,yloc[0]) ==  WHITE )|| (getpixel(xloc[1]+19,yloc[1]) == WHITE )|| (getpixel(xloc[2]+19,yloc[2]) == WHITE )|| (getpixel(xloc[3]+19,yloc[3]) == WHITE))
		  break;
		  *xloc=*xloc+21;
		  break;
	case 'w' :
		  if((*seq+1)==4)
		  {
		  *seq=-1;
		  }
		  shapeb(xloc,yloc,blkno,*seq+1,1);
		  if(getpixel(xloc[3],yloc[3]) == YELLOW || getpixel(xloc[1],yloc[1]) == YELLOW || getpixel(xloc[2],yloc[2]) == YELLOW || getpixel(xloc[0],yloc[0]) == YELLOW)
		  {shapeb(xloc,yloc,blkno,*seq,1);
		  goto endrotate;
		  }
		  if(getpixel(xloc[3],yloc[3]) ==  WHITE || getpixel(xloc[1],yloc[1]) == WHITE || getpixel(xloc[2],yloc[2]) == WHITE || getpixel(xloc[0],yloc[0]) == WHITE)
		  {shapeb(xloc,yloc,blkno,*seq,1);
		  goto endrotate;
		  }shapeb(xloc,yloc,blkno,*seq,0);
		  *seq=*seq+1;
		  shape(xloc,yloc,blkno,*seq,0);
		  shapeb(xloc,yloc,blkno,*seq,0);
endrotate:
		  break;
	case 'p' :
		shape(xloc,yloc,blkno,*seq,0);
		setcolor(BLACK);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy((getmaxx()/2)+160,(getmaxy()/2)+70,"active");
presspause:
		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy((getmaxx()/2)+160,(getmaxy()/2)+70,"paused");
		delay(800);
		shapeb(xloc,yloc,blkno,*seq,0);
		setcolor(BLACK);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy((getmaxx()/2)+160,(getmaxy()/2)+70,"paused");
		delay(800);
		shape(xloc,yloc,blkno,*seq,0);
		while (bioskey(1) != 0)
		ch=getch();
		while(ch!='p')
		goto presspause;
		shapeb(xloc,yloc,blkno,*seq,0);
		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy((getmaxx()/2)+160,(getmaxy()/2)+70,"active");
		break;
}
}
	void scan(int *yloc)
{       static int lines;
	int xcheck,count=0;
	char ch[2];
	for(int j=0;j<=3;j++)
{
	count=0;
	for(xcheck=61;xcheck<=334;xcheck=xcheck+21)
{
	switch(j)
{
case 0:
       if(getpixel(xcheck,yloc[j])==WHITE)
       count=count+1;
       if(count==14)
{
      sound(350);
      delay(200);
      nosound();
      for(xcheck=61;xcheck<=334;xcheck=xcheck+21)
      build(xcheck,yloc[j],BLACK);
      for(int i=21;i<=357;i=i+21)
{
      for(xcheck=61;xcheck<=334;xcheck=xcheck+21)
{
      if(getpixel(xcheck,yloc[j]-i)==WHITE)
{
      build(xcheck,yloc[j]-i,BLACK);
      build(xcheck,yloc[j]-(i-21),WHITE);
}
}
}
      lines=lines+1;
      goto showline;
}
      break;
case 1:
       if(getpixel(xcheck,yloc[j])==WHITE)
       count=count+1;
       if(count==14)
{
      sound(350);
      delay(200);
      nosound();
      for(xcheck=61;xcheck<=334;xcheck=xcheck+21)
      build(xcheck,yloc[j],BLACK);
      for(int i=21;i<=357;i=i+21)
{
      for(xcheck=61;xcheck<=334;xcheck=xcheck+21)
{
      if(getpixel(xcheck,yloc[j]-i)==WHITE)
{
      build(xcheck,yloc[j]-i,BLACK);
      build(xcheck,yloc[j]-(i-21),WHITE);
}
}
}
      lines=lines+1;
      goto showline;
}
      break;
case 2:
       if(getpixel(xcheck,yloc[j])==WHITE)
       count=count+1;
       if(count==14)
{
      sound(350);
      delay(200);
      nosound();
      for(xcheck=61;xcheck<=334;xcheck=xcheck+21)
      build(xcheck,yloc[j],BLACK);
      for(int i=21;i<=357;i=i+21)
{
      for(xcheck=61;xcheck<=334;xcheck=xcheck+21)
{
      if(getpixel(xcheck,yloc[j]-i)==WHITE)
{
      build(xcheck,yloc[j]-i,BLACK);
      build(xcheck,yloc[j]-(i-21),WHITE);
}
}
}
      lines=lines+1;
      goto showline;
}
      break;
case 3:
       if(getpixel(xcheck,yloc[j])==WHITE)
       count=count+1;
       if(count==14)
{
      sound(350);
      delay(200);
      nosound();

      for(xcheck=61;xcheck<=334;xcheck=xcheck+21)
      build(xcheck,yloc[j],BLACK);
      for(int i=21;i<=357;i=i+21)
{
      for(xcheck=61;xcheck<=334;xcheck=xcheck+21)
{
      if(getpixel(xcheck,yloc[j]-i)==WHITE)
{
      build(xcheck,yloc[j]-i,BLACK);
      build(xcheck,yloc[j]-(i-21),WHITE);
}
}
}
      lines=lines+1;
      goto showline;
}
      break;
showline:
      sprintf(ch,"%d",lines-1);
      setcolor(BLACK);
      settextstyle(0,HORIZ_DIR,1);
      outtextxy((getmaxx()/2)+130,(getmaxy()/2)-50,ch);
      sprintf(ch,"%d",lines);
      setcolor(WHITE);
      settextstyle(0,HORIZ_DIR,1);
      outtextxy((getmaxx()/2)+130,(getmaxy()/2)-50,ch);

}
}
}
}
	void move(int xloc,int yloc,int blkno,int seq,int sensitivity=2)

{       int count=0,k=0;
	int xlocarr[4],ylocarr[4],flag=0;
	xlocarr[0]=xloc,ylocarr[0]=yloc;
	shape(xlocarr,ylocarr,blkno,0,0);
	delay(200);
checkagain:
	for(int i=0;i<=3;i++)
	{
		if(getpixel(xlocarr[i],ylocarr[i]+13) == YELLOW)
			goto colourfound;
		if(getpixel(xlocarr[i],ylocarr[i]+19) == WHITE)
			goto colourfound;
	}
	shapeb(xlocarr,ylocarr,blkno,seq,0);
	*ylocarr=*ylocarr+21;
	shape(xlocarr,ylocarr,blkno,seq,0);
	delay(250);

	for(count=1;count<=sensitivity;count++)
	{while (bioskey(1) != 0)
	{
		go(xlocarr,ylocarr,blkno,&seq);
		k=1;
		break;
	}
	if(k==1)
	{shapeb(xlocarr,ylocarr,blkno,seq,0);
	shape(xlocarr,ylocarr,blkno,seq,0);k=0;
	delay(200);
	}
	}goto checkagain;
colourfound:
	flag=1;
	if(*ylocarr<=114)
	{
gameover:
		setcolor(RED);
		settextstyle(4,HORIZ_DIR,7);
		outtextxy(getmaxx()/2-300,getmaxy()/2-100,"GAME OVER");
		setcolor(BLACK);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy((getmaxx()/2)+160,(getmaxy()/2)+70,"active");
		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy((getmaxx()/2)+160,(getmaxy()/2)+70,"Game Over");
		getch();
		exit(1);
	}
	shape(xlocarr,ylocarr,blkno,seq,&flag);
	sound(500);
	delay(100);
	nosound();
	scan(ylocarr);
}


	void origin()
{
	randomize();
loop:
	int xloc=124,yloc=72,seq,blkno;
	blkno=random(4);
	move(xloc,yloc,blkno,0);
goto    loop;

}

	  void main()
{
		clrscr();
	   /* request auto detection */
		int gdriver = DETECT, gmode, errorcode,midx,midy,ch=0;
	   /* initialize graphics, local variables*/
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
             // The game arena starts frm here  //
		setcolor(GREEN);
		rectangle(36,28,359,473);
		setcolor(GREEN);
		rectangle(50,40,345,461);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(48,38,GREEN);
		midx=(getmaxx()/2);
		midy=getmaxy()/2;
		setcolor(YELLOW);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
		outtextxy(midx+80,midy-200,"TETRIS");
		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(midx+80,midy-50,"LINES  ");
		//setcolor(WHITE);
		//settextstyle(0,HORIZ_DIR,1);
		//outtextxy(midx+80,midy,"SCORE");
		setcolor(YELLOW);
		settextstyle(7,HORIZ_DIR,1);
		outtextxy(midx+80,midy+30,"Press 'p' to pause");
		setcolor(YELLOW);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(midx+80,midy+70,"status :");
		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(90,15,"CONTROLS: 'W' ROTATE,'A' LEFT,'D' RIGHT");
pressenter:
		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(midx+160,midy+70,"Waiting for ENTER");
		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(90,60,"Press Enter When Ready....");
		delay(800);
		setcolor(BLACK);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(90,60,"Press Enter When Ready....");
		delay(800);
		while (bioskey(1) != 0)
		ch=getch();
		while(ch!=13)
		goto pressenter;
		setcolor(BLACK);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(midx+160,midy+70,"Waiting for ENTER");
		setcolor(WHITE);
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(midx+160,midy+70,"active");
		//build(376,51,RED);
       // The game arena overs here  //
		origin();
		closegraph();
}
