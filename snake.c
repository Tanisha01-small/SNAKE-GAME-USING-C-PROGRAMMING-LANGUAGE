

 /* ******************SNAKE GAME ***********************
         BY - TANISHA SINGHAL(2K20/A5/14)
              AKKSHITA SWAIN (2K20/A5/23) 
 */





#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int width=20 ;
int height=20;  // global variable as we are using in different functions for the same variables value
int x,y ;       
int fruitX,fruitY;
int score;
int gameover;
int flag ;
int tailX[100];
int tailY[100];
int countTail=0;

void set_up()   // to set the initial value of every variable 
{

    gameover=0;
    x=width/2;         // dimensions of the box
    y=height/2;

    label1: 

    fruitX=rand()%20 ; // rand function is used for getting fruit at random positions wihtin those boundaries 
    if(fruitX==0)
    goto label1 ;      // goto function is used to jump to a particular function (label)

    label2: 

    fruitY=rand()%20 ;
    if(fruitY==0)
    goto label2 ;

    score=0;

}

void draw()    // fucntion to make boundaries
{

    int i,j,k;

    system("cls");  // cls is used so that to clear the previous code(screen) and we get a clear boundaries

    for(i=0;i<width;i++)
    {

         for(j=0;j<height;j++)
        {
         if(i==0||i==height-1||j==0||j==width-1)
        {
            printf("#");
        }
         else
        {
             if(i==x && j==y)
            {
                printf("o");
            }
             else if(i==fruitX && j==fruitY)
            {
                printf("F");
            }
             else

            {   int ch=0 ;

                for (k=0;k<countTail;k++)
                {
                    if(i==tailX[k] && j==tailY[k])
                    {
                        printf("o");
                        ch=1 ;
                    }
                } 
                if(ch==0)
                printf(" ");
            }
           
        }
          

        }  
        printf("\n");
    }
  
         printf("score=%d",score) ;     
   
    
}

void input(){

    if(kbhit())
    {
       switch(getch())
       {
        case 'a' :
            flag=1;
            break;
        case 's':
           flag=2;
           break ;
        case 'w':
           flag =3;
           break;
        case 'z':
           flag=4;
           break;   

        case 'l':
           gameover=1 ;      
                                                               
       }
    }
}

void Make_logic()

{
    int i ;
    int prevX=tailX[0];
    int prevY=tailY[0];

    int prev2X ;
    int prev2Y ;

    tailX[0]=x ;
    tailY[0]=y ;

    for(i=1;i<countTail;i++)
    {

        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;

    }



    switch(flag)
    {
        case 1:
           y-- ;
           break;
        case 2:
           y++ ;
           break;
        case 3:
           x-- ;
           break ;
        case 4:
           x++ ;
           break ;

        default :
          break ;
    }

    if (x<0||x>width||y<0||y>height)
    {
        gameover=1;
        for(i=0;i<countTail;i++)
        {
            if(x==tailX[i] && y==tailY[i])
            gameover=1;
        }
    }

    if (x==fruitX && y==fruitY)
    {
        label3: 

     fruitX=rand()%20 ;
     if(fruitX==0)
     goto label3 ;
 
     label4: 
 
     fruitY=rand()%20 ;
     if(fruitY==0)
     goto label4 ;

     score+=10 ;

     countTail++ ;

    }
    
    

}

int main()
{
    char c ;
    label5 :

    set_up();

    while(!gameover)

    {
        draw();
        input();
        Make_logic();

        for(int m=0;m<1000;m++)
        {
            for(int n=0;n<10000;n++)
            {

            }
        }

        for(int m=0;m<1000;m++)
        {
            for(int n=0;n<10000;n++)
            {

            }
        }
        for(int m=0;m<1000;m++)
        {
            for(int n=0;n<10000;n++)
            {

            }
        }
       
    } 

    printf("\n press Y to continue again:");
    scanf("%c" , &c);  

    if(c=='y'||c=='Y')
     goto label5 ;
        
    
   return 0 ;
}