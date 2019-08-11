#include<stdio.h>
void main()
{
  int n;
  printf("Enter the number : ");
  scanf("%d",&n);
  int row=0,column=0,i=1;
  int arr[n][n];
  int boundary=n-1;
  int sizeLeft=n-1;
  char move='r';
  int flag=1;
  for(i=1;i<(n*n)+1;i++)
  {
    arr[row][column]=i;
    //printf("-->%d row: %d column: %d\n",i,row,column);
    switch (move) {
      case 'r':column+=1;break;
      case 'd':row+=1;break;
      case 'l':column-=1;break;
      case 'u':row-=1;break;
    }
    if(i==boundary)
    {
      boundary+=sizeLeft;
      if (flag!=2) {
        flag=2;
      } else {
        flag=1;
        sizeLeft-=1;
      }
    switch (move) {
      case 'r':move='d';break;
      case 'd':move='l';break;
      case 'l':move='u';break;
      case 'u':move='r';break;
    }
  }
  }
  int j=0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arr[i][j]>9)
      {printf("%d ",arr[i][j]);}
      else
      {printf("%d  ",arr[i][j]);}
    }
    printf("\n");
  }
}
