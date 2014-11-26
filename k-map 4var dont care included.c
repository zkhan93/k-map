#include<stdio.h>
#include<string.h>

int kmap(int a);

int main()
{
  char op;
  int sr=0,dntcr[16],dc=0,hf[16],hb[16],vu[16],vd[16],c=0,d=0,octate[8],quad[24],pair[32],max=0,a=0,b=0,c0=0,c1=0,c2=0,c3=0,r0=0,r1=0,r2=0,r3=0,x=0,n=0,minterms[16],table[4][4], mark[4][4],i,j,k,swapc[4],swapr[4],f8=0,f4=0,f4c=0,f2=0,f1=0;
for(i=0;i<32;i++)
{
	pair[i]=0;
}
for(i=0;i<24;i++)
{
	quad[i]=0;
}
for(i=0;i<8;i++)
{
	octate[i]=0;
} 
printf("\n\t");
for(i=0;i<61;i++)
{
	if(i==0)
	printf("%c",201);
	else if(i==60)
	printf("%c",187);
	else
	printf("%c",205);
}
printf("\n\t%c\t\tK-Map Minimizer by- Zeeshan Khan \t    %c\n\t",186,186);
for(i=0;i<61;i++)
{
	if(i==0)
	printf("%c",200);
	else if(i==60)
	printf("%c",188);
	else
	printf("%c",205);
}
printf("\n\t");



  printf("\n\n\n\tEnter the number of min terms: ");
  scanf("%d",&n);
  fflush(stdin);
printf("\n\n\tEnter the number of don't care terms: ");
scanf("%d",&dc);
 fflush(stdin);


if(n==0||(n==0&&dc==0))
{
	printf("\n\n\tNULL ");
	printf("\n\n\tProgram Ended\n\n\tTo Restart Program press 1 and hit Enter\n\n\tTo Exit press 0 and hit Enter\n\t");
	scanf("%d",&i);
	if(i==1)
	main();
	else
	exit(0);
}
if((n+dc)==16)
  { 
   
   printf("\n\n\tY = 1\n");
   printf("\n\tProgram Ended\n");
   printf("\n\n\tProgram Ended\n\n\tTo Restart Program press 1 and hit Enter\n\n\tTo Exit press 0 and hit Enter\n\t");
   scanf("%d",&i);
  if(i==1)
  main();
  else
   exit(0);
}
if((n+dc)>16)
{
	printf("\n\n\tInvalid Input!!!\n\n\tTotal number of minters cannot exceed 16..");
	printf("\n\n\tProgram Ended\n\n\tTo Restart Program press 1 and hit Enter\n\n\tTo Exit press 0 and hit Enter\n\t");
   scanf("%d",&i);
  if(i==1)
  main();
  else
   exit(0);
	
}
for(i=0;i<16;i++)
{
	minterms[i]=0;
	dntcr[i]=0;
}
printf("\n\tEnter all the min terms with a single spaces between them..\n\n\tF( A,B,C,D ) = %c ",228);
  for(i=0;i<n;i++)
     {
			scanf("%d",&minterms[i]);
     }
 fflush(stdin);
printf("\n\tEnter all the don't care terms with a single spaces between them..\n\n\td( A,B,C,D ) = %c ",228);
  for(i=0;i<dc;i++)
     {
			scanf("%d",&dntcr[i]);
     }
     fflush(stdin);
for(i=0;i<n;i++)
{
	for(j=0;j<dc;j++)
	{
		if(minterms[i]==dntcr[j])
		{
			
		printf("\n\n\tMinterms and Don't care Terms have a common value.");
		printf("\n\n\tProgram Ended\n\n\tTo Restart Program press 1 and hit Enter\n\n\tTo Exit press 0 and hit Enter\n\t");
		scanf("%d",&i);
  		if(i==1)
  		main();
  		else
		exit(0);
		}
		}
}
max=minterms[0];
for(i=1;i<n;i++)
{
if(max<minterms[i])
max=minterms[i];
}
for(i=0;i<dc;i++)
{
if(max<dntcr[i])
max=dntcr[i];
}

if(max<8)
 {
		printf ("\n\tINVALID TERMS!!\n\n\tThe provided terms can solved in less than four variables K-Maps..\n\n\tplease enter four variable minters!!!");
		printf("\n\n\tProgram Ended\n\n\tTo Restart Program press 1 and hit Enter\n\n\tTo Exit press 0 and hit Enter\n\t");
		scanf("%d",&i);
  		if(i==1)
  		main();
  		else
		exit(0);
	
}


if(max>15)
{
	printf ("\n\tINVALID TERMS!!\n\n\tThe provided terms cannot be solved in four variables K-Map..\n\n\tplease enter four variable minters!!!\n\n\tProgramme Ended ");
	printf("\n\n\tProgram Ended\n\n\tTo Restart Program press 1 and hit Enter\n\n\tTo Exit press 0 and hit Enter\n\t");
	scanf("%d",&i);
	if(i==1)
	main();
	else
	exit(0);
}

for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
table[i][j]=0;
mark [i][j]=0;
}
}

for(x=0;x<n;x++)
{
  for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
         {
           if(minterms[x]==((i*4)+j))
				table[i][j]=1;
          }
     }
}
for(x=0;x<dc;x++)
{
  for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
         {
           if(dntcr[x]==((i*4)+j))
			table[i][j]=120;
				
          }
     }
}

 
 //swap table
for(i=0;i<4;i++)
   {
    swapc[i]=table[i][3];
    table[i][3]=table[i][2];
    table[i][2]=swapc[i];
   }

for(j=0;j<4;j++)
   {
    swapr[j]=table[3][j];
    table[3][j]=table[2][j];
    table[2][j]=swapr[j];
   }
//swap mark
for(i=0;i<4;i++)
   {
    swapc[i]=mark[i][3];
    mark[i][3]=mark[i][2];
    mark[i][2]=swapc[i];
   }

for(j=0;j<4;j++)
   {
    swapr[j]=mark[3][j];
    mark[3][j]=mark[2][j];
    mark[2][j]=swapr[j];
   }
 
printf("\n\n\tK-map created...Successfully\n\n\t");
for(i=0;i<4;i++)
{
	if(i==0)
	printf("\n\t\t   C'D'\t   C'D \t   CD \t   CD'");
	printf("\n\t\t");
			for(k=0;k<33;k++)
			{
				if(k==0&&i==0)
				printf("%c",201);
				else if(k==32&&i==0)
				printf("%c",187);
				else if((k%8==0)&&i==0)
				printf("%c",203);
				else if(i!=0 && k%8==0)
				{
					if(k==0)
					printf("%c",204);
					else if(k==32)
					printf("%c",185);
					else
					printf("%c",206);
					}
				
				else
				printf("%c",205);
				
				}
			if(i==0)
			printf("\n\tA'B'\t");
			if(i==1)
			printf("\n\tA'B\t");
			if(i==2)
			printf("\n\tAB\t");
			if(i==3)
			printf("\n\tAB'\t");
for(j=0;j<4;j++)
{
	 if(table[i][j]==120)
	 printf("%c   %c\t",186,table[i][j]);
	 else
	 printf("%c   %d\t",186,table[i][j]);
	 }
	 printf("%c",186);
}
printf("\n\t\t");
		for(k=0;k<33;k++)
			{
				if(k==0)
				printf("%c",200);
				else if(k==32)
				printf("%c",188);
				else if((k%8==0))
				printf("%c",202);
				else
				printf("%c",205);
				}
				
//logic start..here

//for octate

// for octate in rows
for(i=0;i<4;i++)
   {
    f8=0;
    sr=0;
    for(j=0;j<4;j++)
       {
         if(table[i][j]==1||table[i][j]==120)
         {
				f8++;
				sr=sr+table[i][j];
				}
         if(f8==4)
        {
        switch(i)
	{
		case 0:
			if(sr>=120)
			r0=2;
			else
			r0=1;
			break;
		case 1:
			if(sr>=120)
			r1=2;
			else
			r1=1;
			break;
		case 2:
			if(sr>=120)
			r2=2;
			else
			r2=1;
			break;
		case 3:
			if(sr>=120)
			r3=2;
			else
			r3=1;
			break;
	}
}    }}

if(r0>0&&r1>0)
{
	if(r0==2||r1==2)
	octate[0]=2;
	else
	octate[0]=1;
	for(i=0;i<4;i++)
	{
		mark[0][i]++;
		mark[1][i]++;
		}
}
if(r1>0&& r2>0)
{
	if(r1==2||r2==2)
	octate[1]=2;
	else
	octate[1]=1;
	for(i=0;i<4;i++)
{	mark[1][i]++;
	mark[2][i]++;
}}

if(r2>0&& r3>0)
{
	if(r2==2||r3==2)
	octate[2]=2;
	else
	octate[2]=1;
	for(i=0;i<4;i++)
{
	mark[2][i]++;
	mark[3][i]++;
}
}
if(r3>0&& r0>0)
{
	if(r3==2||r0==2)
	octate[3]=2;
	else
	octate[3]=1;
for(i=0;i<4;i++)
{
	mark[3][i]++;
	mark[0][i]++;
}
}

//for colomn
for(i=0;i<4;i++)
   {
    f8=0;
    sr=0;
    for(j=0;j<4;j++)
       {
         if(table[j][i]==1||table[j][i]==120)
         {
				f8++;
				sr=sr+table[j][i];
			}
         if(f8==4)
        {
        switch(i)
	{
		case 0:
			if(sr>=120)
			c0=2;
			else
			c0=1;
			break;
		case 1:
			if(sr>=120)
			c1=2;
			else
			c1=1;
			break;
		case 2:
			if(sr>=120)
			c2=2;
			else
			c2=1;
			break;
		case 3:
			if(sr>=120)
			c3=2;
			else
			c3=1;
			break;
	}
}    }}

if(c0>0&& c1>0)
{
	if(c0==2||c2==2)
	octate[4]=2;
	else
	octate[4]=1;
	for(i=0;i<4;i++)
	{
		mark[i][0]++;
		mark[i][1]++;
		}
}
if(c1>0&& c2>0)
{
	if(c1==2||c2==2)
	octate[5]=2;
	else
	octate[5]=1;
	for(i=0;i<4;i++)
	{
		mark[i][1]++;
		mark[i][2]++;
		}

}
if(c2>0&& c3>0)
{
	if(c2==2||c3==2)
	octate[6]=2;
	else
	octate[6]=1;
	for(i=0;i<4;i++)
	{
		mark[i][2]++;
		mark[i][3]++;
		}
}
if(c3>0&& c0>0)
{
	if(c3==2||c0==2)
	octate[7]=2;
	else
	octate[7]=1;
	for(i=0;i<4;i++)
	{
		mark[i][3]++;
		mark[i][0]++;
		}
}

//checking for dont6 care

for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(table[i][j]==120)
				mark[i][j]=mark[i][j]+5;
			}
		}	

for(i=0;i<8;i++)
{
	if(octate[i]==2)
	{
		switch(i)
		{
			case 0:
				for(j=0;j<4;j++)
				{
					mark[0][j]--;
					mark[1][j]--;
					}
				if(mark[0][0]==0||mark[0][1]==0||mark[0][2]==0||mark[0][3]==0||mark[1][0]==0||mark[1][1]==0||mark[1][2]==0||mark[1][3]==0)
				for(j=0;j<4;j++)
				{
					mark[0][j]++;
					mark[1][j]++;
					}
				else
				octate[0]=0;
				break;
			case 1:
				for(j=0;j<4;j++)
				{
					mark[1][j]--;
					mark[2][j]--;
				}
					if(mark[1][0]==0||mark[1][1]==0||mark[1][2]==0||mark[1][3]==0||mark[2][0]==0||mark[2][1]==0||mark[2][2]==0||mark[2][3]==0)
					for(j=0;j<4;j++)
				{
					mark[1][j]++;
					mark[2][j]++;
				}
					else
					octate[1]=0;
				break;
			case 2:
				for(j=0;j<4;j++)
				{
					mark[2][j]--;
					mark[3][j]--;
				}
					if(mark[2][0]==0||mark[2][1]==0||mark[2][2]==0||mark[2][3]==0||mark[3][0]==0||mark[3][1]==0||mark[3][2]==0||mark[3][3]==0)
					for(j=0;j<4;j++)
				{
					mark[2][j]++;
					mark[3][j]++;
				}
					else
					octate[2]=0;
				break;
			case 3:
				for(j=0;j<4;j++)
				{
					mark[3][j]--;
					mark[0][j]--;
				}
					if(mark[3][0]==0||mark[3][1]==0||mark[3][2]==0||mark[3][3]==0||mark[0][0]==0||mark[0][1]==0||mark[0][2]==0||mark[0][3]==0)
				for(j=0;j<4;j++)
				{
					mark[3][j]++;
					mark[0][j]++;
				}
					else
					octate[2]=0;
				break;
			case 4:
				for(j=0;j<4;j++)
				{
					mark[j][0]--;
					mark[j][1]--;
				}
					if(mark[0][0]==0||mark[1][0]==0||mark[2][0]==0||mark[3][0]==0||mark[0][1]==0||mark[1][1]==0||mark[2][1]==0||mark[3][1]==0)
					for(j=0;j<4;j++)
				{
					mark[j][0]++;
					mark[j][1]++;
				}
					else
					octate[2]=0;
				break;
			case 5:
				for(j=0;j<4;j++)
				{
					mark[j][1]--;
					mark[j][2]--;
				}
				if(mark[0][1]==0||mark[1][1]==0||mark[2][1]==0||mark[3][1]==0||mark[0][2]==0||mark[1][2]==0||mark[2][2]==0||mark[3][2]==0)
					for(j=0;j<4;j++)
				{
					mark[j][1]++;
					mark[j][2]++;
				}
					else
					octate[2]=0;
				break;
			case 6:
				for(j=0;j<4;j++)
				{
					mark[j][2]--;
					mark[j][3]--;
				}
				if(mark[0][2]==0||mark[1][2]==0||mark[2][2]==0||mark[3][2]==0||mark[0][3]==0||mark[1][3]==0||mark[2][3]==0||mark[3][3]==0)
					for(j=0;j<4;j++)
				{
					mark[j][2]++;
					mark[j][3]++;
				}
					else
					octate[2]=0;
				break;
			case 7:
				for(j=0;j<4;j++)
				{
					mark[j][3]--;
					mark[j][0]--;
				}
				if(mark[0][3]==0||mark[1][3]==0||mark[2][3]==0||mark[3][3]==0||mark[0][0]==0||mark[1][0]==0||mark[2][0]==0||mark[3][0]==0)
					for(j=0;j<4;j++)
				{
					mark[j][3]++;
					mark[j][0]++;
				}
					else
					octate[2]=0;
				break;
			}
		}
}


for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(table[i][j]==120)
				mark[i][j]=mark[i][j]-5;
			}
		}	
// end of octate pairing....



// pairing of 4 i.e quad. ( 4 in a row or coloumn)..

//row
if(r0>0 && r1==0 && r3==0)
{
	if(r0==2)
	quad[0]=2;
	else
		quad[0]=1;
		for(i=0;i<4;i++)
		{
			mark[0][i]++;
		
			}
	}
if(r1>0 && r0==0 && r2==0)
{
	if(r1==2)
	quad[1]=2;
	else
		quad[1]=1;
		for(i=0;i<4;i++)
		{
			mark[1][i]++;
			}
	}
if(r2>0 && r1==0 && r3==0)
{
	if(r2==2)
	quad[2]=2;
	else
		quad[2]=1;
		for(i=0;i<4;i++)
		{
			mark[2][i]++;
			}
	}
if(r3>0 && r2==0 && r0==0)
{
	if(r3==2)
	quad[3]=2;
	else
		quad[3]=1;
		for(i=0;i<4;i++)
		{
			mark[3][i]++;
			}
	}

//coloumn

if(c0>0 && c1==0 && c3==0)
{
	if(c0==2)
	quad[4]=2;
	else
		quad[4]=1;
		for(i=0;i<4;i++)
		{
			mark[i][0]++;
			}
	}
if(c1>0 && c0==0 && c2==0)
{
	if(c1==2)
	quad[5]=2;
	else
		quad[5]=1;
		for(i=0;i<4;i++)
		{
			mark[i][1]++;
			}
	}
if(c2>0 && c1==0 && c3==0)
{
	if(c2==2)
	quad[6]=2;
	else
		quad[6]=1;
		for(i=0;i<4;i++)
		{
			mark[i][2]++;
			}
	}
if(c3>0 && c2==0 && c0==0)
{
	if(c3==2)
	quad[7]=2;
	else
		quad[7]=1;
		for(i=0;i<4;i++)
		{
			mark[i][3]++;
			}
	}


// pairing of quad as 2x2 matrix total 9 octates
sr=0;
for(a=0;a<3;a++)
{
	for(b=0;b<3;b++)
	{
		for(i=a;i<(a+2);i++)
		{
			for(j=b;j<(b+2);j++)
			{
				if(table[i][j]==1||table[i][j]==120)
				{
					f4++;
					sr=sr+table[i][j];
				}
			}
		}
		if(f4==4&&sr<480)
		{
			//condition for rows & columns to be zero
			if (a==0 && b==0)
			{
 				if ((r0==0||r1==0)&&(c0==0||c1==0))
				{
					if(sr>=120)
						quad[8]=2;
					else
						quad[8]=1;
						mark[0][0]++;
						mark[0][1]++;
						mark[1][0]++;
						mark[1][1]++;
				}
			}
			if(a==0 && b==1)
			{
				if ((r0==0||r1==0)&&(c1==0||c2==0))
				{
					if(sr>=120)
						quad[9]=2;
					else
						quad[9]=1;
						mark[0][1]++;
						mark[0][2]++;
						mark[1][1]++;
						mark[1][2]++;
				}
			}
			if(a==0 && b==2)
			{
				if ((r0==0||r1==0)&&(c2==0||c3==0))
				{
					if(sr>=120)
						quad[10]=2;
					else
						quad[10]=1;
						mark[0][2]++;
						mark[0][3]++;
						mark[1][2]++;
						mark[1][3]++;
				}
			}
			if(a==1 && b==0)
			{
				if ((r1==0||r2==0)&&(c0==0||c1==0))
				{
					if(sr>=120)
						quad[11]=2;
					else
						quad[11]=1;
						mark[1][0]++;
						mark[1][1]++;
						mark[2][0]++;
						mark[2][1]++;
				}
			}
			if(a==1 && b==1)
			{
				if ((r1==0||r2==0)&&(c1==0||c2==0))
				{
					if(sr>=120)
						quad[12]=2;
					else
						quad[12]=1;
						mark[1][1]++;
						mark[1][2]++;
						mark[2][1]++;
						mark[2][2]++;
				}
			}
			if(a==1 && b==2)
			{
				if ((r1==0||r2==0)&&(c2==0||c3==0))
				{
					if(sr>=120)
						quad[13]=2;
					else
						quad[13]=1;
						mark[1][2]++;
						mark[1][3]++;
						mark[2][2]++;
						mark[2][3]++;
				}
			}
			if(a==2 && b==0)
			{
				if ((r2==0||r3==0)&&(c0==0||c1==0))
				{
					if(sr>=120)
						quad[14]=2;
					else
						quad[14]=1;
						mark[2][0]++;
						mark[2][1]++;
						mark[3][0]++;
						mark[3][1]++;
				}
			}
			if(a==2 && b==1)
			{
				if ((r2==0||r3==0)&&(c1==0||c2==0))
				{
					if(sr>=120)
						quad[15]=2;
					else
						quad[15]=1;
						mark[2][1]++;
						mark[2][2]++;
						mark[3][1]++;
						mark[3][2]++;
				}
			}
			if(a==2 && b==2)
			{
				if ((r2==0||r3==0)&&(c2==0||c3==0))
				{
					if(sr>=120)
						quad[16]=2;
					else
						quad[16]=1;
						mark[2][2]++;
						mark[2][3]++;
						mark[3][2]++;
						mark[3][3]++;
				}
			}
		}
	f4=0;
	sr=0;
	}
}
sr=0;
// rolling quards
//for corner quard...
sr=table[0][0]+table[0][3]+table[3][0]+table[3][3];
	if((table[0][0]==1||table[0][0]==120)&&(table[0][3]==1||table[0][3]==120)&&(table[3][0]==1||table[3][0]==120)&&(table[3][3]==1||table[3][3]==120)&&(mark[0][0]==0||mark[0][3]==0||mark[3][0]==0||mark[3][3]==0))
	{
		if(sr>=120)
			quad[23]=2;
		else
		quad[23]=1;
		mark[0][0]++;
		mark[0][3]++;
		mark[3][0]++;
		mark[3][3]++;
	}

if ((r0==0||r3==0)&&(c0==0||c3==0))
{
for(a=0;a<3;a++)
	{
	f4c=0;
	sr=0;
	for(i=a;i<(a+2);i++)
		{
		for(j=0;j<4;j+=3)
			{
			 if(table[i][j]==1||table[i][j]==120)
			 {
					f4c++;
					sr=sr+table[i][j];
				}
			if(f4c==4)
			{
			switch(a)
			{
			case 0:
				if(mark[0][0]==0||mark[0][3]==0||mark[1][0]==0||mark[1][3]==0)
				{
					if(sr>=120)
						quad[17]=2;
					else
						quad[17]=1;
						mark[0][0]++;
						mark[0][3]++;
						mark[1][0]++;
						mark[1][3]++;
				}
				break;
			case 1:
				if(mark[1][0]==0||mark[1][3]==0||mark[2][0]==0||mark[2][3]==0)
				{
					if(sr>=120)
						quad[18]=2;
					else
						quad[18]=1;
						mark[1][0]++;
						mark[1][3]++;
						mark[2][0]++;
						mark[2][3]++;
				}
			break;
			case 2:
				if(mark[2][0]==0||mark[2][3]==0||mark[3][0]==0||mark[3][3]==0)
				{
					if(sr>=120)
						quad[19]=2;
					else
						quad[19]=1;
						mark[2][0]++;
						mark[2][3]++;
						mark[3][0]++;
						mark[3][3]++;
				}
				break;
			}
			}
			
			}
		}
	}
	
	
for(a=0;a<3;a++)
	{
	sr=0;
	f4c=0;
	for(j=a;j<(a+2);j++)
		{
		for(i=0;i<4;i+=3)
			{
			 if(table[i][j]==1||table[i][j]==120)
			 {
				f4c++;
				sr=sr+table[i][j];
				}
			if(f4c==4)
			{
			switch(a)
			{
			case 0:
				if(mark[0][0]==0||mark[0][1]==0||mark[3][0]==0||mark[3][1]==0)
				{
					if(sr>=120)
						quad[20]=2;
					else
						quad[20]=1;
						mark[0][0]++;
						mark[0][1]++;
						mark[3][0]++;
						mark[3][1]++;
				}
			break;
			case 1:
				if(mark[0][1]==0||mark[0][2]==0||mark[3][1]==0||mark[3][2]==0)
				{
					if(sr>=120)
						quad[21]=2;
					else
						quad[21]=1;
						mark[0][1]++;
						mark[0][2]++;
						mark[3][1]++;
						mark[3][2]++;
					}
					break;
			case 2:
				if(mark[0][2]==0||mark[0][3]==0||mark[3][2]==0||mark[3][3]==0)
				{
					if(sr>=120)
						quad[22]=2;
					else
						quad[22]=1;
						mark[0][2]++;
						mark[0][3]++;
						mark[3][2]++;
						mark[3][3]++;
				}
				break;
			}
			}
			
			}
		}
	}
}

// end of quards.... FINALLLY..


// pairs total 32 24(12 vertical & 12 horizontal) normal and 8(4,4) rolling   

//compulsory pairs they have no other options
for(i=0;i<4;i++)
{
	for(j=0;j<4;j++)
	{
		if(table[i][j]==1&&mark[i][j]==0)
		{
			
			if(j==0)
				hb[4*i+j]=((table[i][3]==1||table[i][3]==120)&&(mark[i][3]==0));
			else
				hb[4*i+j]=((table[i][j-1]==1||table[i][j-1]==120)&&(mark[i][j-1]==0));
			if(j==3)
				hf[4*i+j]=((table[i][0]==1||table[i][0]==120)&&(mark[i][0]==0));
			else
				hf[4*i+j]=((table[i][j+1]==1||table[i][j+1]==120)&&(mark[i][j+1]==0));
			if(i==0)
				vu[4*i+j]=((table[3][j]==1||table[3][j]==120)&&(mark[3][j]==0));
			else
				vu[4*i+j]=((table[i-1][j]==1||table[i-1][j]==120)&&(mark[i-1][j]==0));
			if(i==3)
				vd[4*i+j]=((table[0][j]==1||table[0][j]==120)&&(mark[0][j]==0));
			else
				vd[4*i+j]=((table[i+1][j]==1||table[i+1][j]==120)&&(mark[i+1][j]==0));

		if(hf[4*i+j]==1&&hb[4*i+j]==0&&vu[4*i+j]==0&&vd[4*i+j]==0)
		{
			pair[(4*i)+j]=1;
			hf[4*i+j]=0;
				if(j==3)
				{
					mark[i][3]++;mark[i][0]++;
					}
				else
				{
					mark[i][j]++;mark[i][j+1]++;
					}
			}
		if(hb[4*i+j]==1&&hf[4*i+j]==0&&vu[4*i+j]==0&&vd[4*i+j]==0)
		{
			if(j==0)
			pair[(4*i)+3]=1;
			else
			pair[(4*i)+(j-1)]=1;
			hb[4*i+j]=0;
			if(j==0)
				{
					mark[i][3]++;mark[i][0]++;
					}
				else
				{
					mark[i][j]++;mark[i][j-1]++;
					}
			
			}
		if(vu[4*i+j]==1&&hf[4*i+j]==0&&hb[4*i+j]==0&&vd[4*i+j]==0)
		{
			if(i==0)
			pair[28+j]=1;
			else
			pair[16+(4*(i-1))+j]=1;
			vu[4*i+j]=0;
				if(i==0)
				{
					mark[3][j]++;mark[0][j]++;
					} 
				else
				{
					mark[i][j]++;mark[i-1][j]++;
					}
			}
		if(vd[4*i+j]==1&&hf[4*i+j]==0&&hb[4*i+j]==0&&vu[4*i+j]==0)
		{
			pair[16+(4*i)+j]=1;
			vd[4*i+j]=0;
				if(i==3)
				{
					mark[3][j]++;mark[0][j]++;
					} 
				else
				{
					mark[i][j]++;mark[i+1][j]++;
					}
			}
			
			
		}		
	}
}

// checking of dont care quards removing
for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(table[i][j]==120)
				mark[i][j]=mark[i][j]+5;
			}
		}	
/*		
printf("\n");
for(i=0;i<32;i++)
{
	printf("%d ",pair[i]);
	
}
printf("\n\n\tmark");
for(i=0;i<4;i++)
{
	printf("\n\n\t");
	for(j=0;j<4;j++)
	{
		printf("%d\t",mark[i][j]);
		}
}
*/
for(i=0;i<24;i++)
{
	if(quad[i]==2)
	{
						
		switch(i)
		{
		case 0:
				mark[0][0]--;
				mark[0][1]--;
				mark[0][2]--;
				mark[0][3]--;
			if(mark[0][0]==0||mark[0][1]==0||mark[0][2]==0||mark[0][3]==0)
			{
				mark[0][0]++;
				mark[0][1]++;
				mark[0][2]++;
				mark[0][3]++;
				}
			else 
				quad[0]=0;
			break;
		case 1:
				mark[1][0]--;
				mark[1][1]--;
				mark[1][2]--;
				mark[1][3]--;
			if(mark[1][0]==0||mark[1][1]==0||mark[1][2]==0||mark[1][3]==0)
			{
				mark[1][0]++;
				mark[1][1]++;
				mark[1][2]++;
				mark[1][3]++;
				}
			else 
				quad[1]=0;
			break;
		case 2:
				mark[2][0]--;
				mark[2][1]--;
				mark[2][2]--;
				mark[2][3]--;
			if(mark[2][0]==0||mark[2][1]==0||mark[2][2]==0||mark[2][3]==0)
			{
				mark[2][0]++;
				mark[2][1]++;
				mark[2][2]++;
				mark[2][3]++;
				}
			else 
				quad[2]=0;
			break;
		case 3:
				mark[3][0]--;
				mark[3][1]--;
				mark[3][2]--;
				mark[3][3]--;
			if(mark[3][0]==0||mark[3][1]==0||mark[3][2]==0||mark[3][3]==0)
			{
				mark[3][0]++;
				mark[3][1]++;
				mark[3][2]++;
				mark[3][3]++;
				}
			else 
				quad[3]=0;
			break;
		case 4:
				mark[0][0]--;
				mark[1][0]--;
				mark[2][0]--;
				mark[3][0]--;
			if(mark[0][0]==0||mark[1][0]==0||mark[2][0]==0||mark[3][0]==0)
			{
				mark[0][0]++;
				mark[1][0]++;
				mark[2][0]++;
				mark[3][0]++;
				}
			else 
				quad[4]=0;
			break;
		case 5:
				mark[0][1]--;
				mark[1][1]--;
				mark[2][1]--;
				mark[3][1]--;
			if(mark[0][1]==0||mark[1][1]==0||mark[2][1]==0||mark[3][1]==0)
			{
				mark[0][1]++;
				mark[1][1]++;
				mark[2][1]++;
				mark[3][1]++;
				}
			else 
				quad[5]=0;
			break;
		case 6:
				mark[0][2]--;
				mark[1][2]--;
				mark[2][2]--;
				mark[3][2]--;
			if(mark[0][2]==0||mark[1][2]==0||mark[2][2]==0||mark[3][2]==0)
			{
				mark[0][2]++;
				mark[1][2]++;
				mark[2][2]++;
				mark[3][2]++;
				}
			else 
				quad[6]=0;
			break;
		case 7:
				mark[0][3]--;
				mark[1][3]--;
				mark[2][3]--;
				mark[3][3]--;
			if(mark[0][3]==0||mark[1][3]==0||mark[2][3]==0||mark[3][3]==0)
			{
				mark[0][3]++;
				mark[1][3]++;
				mark[2][3]++;
				mark[3][3]++;
				}
			else 
				quad[7]=0;
			break;
		case 8:
			mark[0][0]--;
				mark[0][1]--;
				mark[1][0]--;
				mark[1][1]--;
			if(mark[0][0]==0||mark[0][1]==0||mark[1][0]==0||mark[1][1]==0)
			{
				mark[0][0]++;
				mark[0][1]++;
				mark[1][0]++;
				mark[1][1]++;
				}
			else 
				quad[8]=0;
			break;
		case 9:
			mark[0][1]--;
				mark[0][2]--;
				mark[1][1]--;
				mark[1][2]--;
			if(mark[0][1]==0||mark[0][2]==0||mark[1][1]==0||mark[1][2]==0)
			{
				mark[0][1]++;
				mark[0][2]++;
				mark[1][1]++;
				mark[1][2]++;
				}
			else 
				quad[9]=0;
			break;
		case 10:
				mark[0][2]--;
				mark[0][3]--;
				mark[1][2]--;
				mark[1][3]--;
			if(mark[0][2]==0||mark[0][3]==0||mark[1][2]==0||mark[1][3]==0)
			{
				mark[0][2]++;
				mark[0][3]++;
				mark[1][2]++;
				mark[1][3]++;
				}
			else 
				quad[10]=0;
			break;
		case 11:
			mark[1][0]--;
				mark[1][1]--;
				mark[2][0]--;
				mark[2][1]--;
			if(mark[1][0]==0||mark[1][1]==0||mark[2][0]==0||mark[2][1]==0)
			{
				mark[1][0]++;
				mark[1][1]++;
				mark[2][0]++;
				mark[2][1]++;
				}
			else
				quad[11]=0;
			break;
		case 12:
				mark[1][1]--;
				mark[1][2]--;
				mark[2][1]--;
				mark[2][2]--;
			if(mark[1][1]==0||mark[1][2]==0||mark[2][1]==0||mark[2][2]==0)
			{
				mark[1][1]++;
				mark[1][2]++;
				mark[2][1]++;
				mark[2][2]++;
				}
			else 
				quad[12]=0;
			break;
		case 13:
				mark[1][2]--;
				mark[1][3]--;
				mark[2][2]--;
				mark[2][3]--;
			if(mark[1][2]==0||mark[1][3]==0||mark[2][2]==0||mark[2][3]==0)
			{
				mark[1][2]++;
				mark[1][3]++;
				mark[2][2]++;
				mark[2][3]++;
				}
			else 
				quad[13]=0;
			break;
		case 14:
				mark[2][0]--;
				mark[2][1]--;
				mark[3][0]--;
				mark[3][1]--;
			if(mark[2][0]==0||mark[2][1]==0||mark[3][0]==0||mark[3][1]==0)
			{
				mark[2][0]++;
				mark[2][1]++;
				mark[3][0]++;
				mark[3][1]++;
				}
			else 
				quad[14]=0;
			break;
		case 15:
				mark[2][1]--;
				mark[2][2]--;
				mark[3][1]--;
				mark[3][2]--;
			if(mark[2][1]==0||mark[2][2]==0||mark[3][1]==0||mark[3][2]==0)
			{
				mark[2][1]++;
				mark[2][2]++;
				mark[3][1]++;
				mark[3][2]++;
				}
			else 
				quad[15]=0;
			break;
		case 16:
				mark[2][2]--;
				mark[2][3]--;
				mark[3][2]--;
				mark[3][3]--;
			if(mark[2][2]==0||mark[2][3]==0||mark[3][2]==0||mark[3][3]==0)
			{
				mark[2][2]++;
				mark[2][3]++;
				mark[3][2]++;
				mark[3][3]++;
				}
			else 
				quad[16]=0;
			break;
		case 17:
				mark[0][0]--;
				mark[1][0]--;
				mark[0][3]--;
				mark[1][3]--;
			if(mark[0][0]==0||mark[1][0]==0||mark[0][3]==0||mark[1][3]==0)
			{
				mark[0][0]++;
				mark[1][0]++;
				mark[0][3]++;
				mark[1][3]++;
				}
			else 
				quad[17]=0;
			break;
		case 18:
				mark[1][0]--;
				mark[2][0]--;
				mark[1][3]--;
				mark[2][3]--;
			if(mark[1][0]==0||mark[2][0]==0||mark[1][3]==0||mark[2][3]==0)
			{
				mark[1][0]++;
				mark[2][0]++;
				mark[1][3]++;
				mark[2][3]++;
				}
			else 
				quad[18]=0;
			break;
		case 19:
				mark[2][0]--;
				mark[3][0]--;
				mark[2][3]--;
				mark[3][3]--;
			if(mark[2][0]==0||mark[3][0]==0||mark[2][3]==0||mark[3][3]==0)
			{
				mark[2][0]++;
				mark[3][0]++;
				mark[2][3]++;
				mark[3][3]++;
				}
			else 
				quad[19]=0;
			break;
		case 20:
				mark[3][0]--;
				mark[3][1]--;
				mark[0][0]--;
				mark[0][1]--;
			if(mark[3][0]==0||mark[3][1]==0||mark[0][0]==0||mark[0][1]==0)
			{
				mark[3][0]++;
				mark[3][1]++;
				mark[0][0]++;
				mark[0][1]++;
				}
			else 
				quad[20]=0;
			break;
		case 21:
				mark[3][1]--;
				mark[3][2]--;
				mark[0][1]--;
				mark[0][2]--;
			if(mark[3][1]==0||mark[3][2]==0||mark[0][1]==0||mark[0][2]==0)
			{
				mark[3][1]++;
				mark[3][2]++;
				mark[0][1]++;
				mark[0][2]++;
				}
			else 
				quad[21]=0;
			break;
		case 22:
				mark[3][2]--;
				mark[3][3]--;
				mark[0][2]--;
				mark[0][3]--;
			if(mark[3][2]==0||mark[3][3]==0||mark[0][2]==0||mark[0][3]==0)
			{
				mark[3][2]++;
				mark[3][3]++;
				mark[0][2]++;
				mark[0][3]++;
				}
			else 
				quad[22]=0;
			break;
		case 23:
				mark[3][2]--;
				mark[3][3]--;
				mark[0][2]--;
				mark[0][3]--;
			if(mark[0][0]==0||mark[0][3]==0||mark[3][0]==0||mark[3][3]==0)
			{
				mark[0][0]++;
				mark[0][3]++;
				mark[3][0]++;
				mark[3][3]++;
				}
			else 
				quad[23]=0;
			break;
			}
}
}
/*
for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(table[i][j]==120)
				mark[i][j]=mark[i][j]-5;
			}
		}	


printf("\n");
for(i=0;i<8;i++)
{
	printf("%d ",octate[i]);
}
*/

for(i=0;i<4;i++)
{
	for(j=0;j<4;j++)
	{
		if(table[i][j]==1&&mark[i][j]==0)
		{
			
			if(j==0)
				hb[4*i+j]=((table[i][3]==1||table[i][3]==120)&&(mark[i][3]==0));
			else
				hb[4*i+j]=((table[i][j-1]==1||table[i][j-1]==120)&&(mark[i][j-1]==0));
			if(j==3)
				hf[4*i+j]=((table[i][0]==1||table[i][0]==120)&&(mark[i][0]==0));
			else
				hf[4*i+j]=((table[i][j+1]==1||table[i][j+1]==120)&&(mark[i][j+1]==0));
			if(i==0)
				vu[4*i+j]=((table[3][j]==1||table[3][j]==120)&&(mark[3][j]==0));
			else
				vu[4*i+j]=((table[i-1][j]==1||table[i-1][j]==120)&&(mark[i-1][j]==0));
			if(i==3)
				vd[4*i+j]=((table[0][j]==1||table[0][j]==120)&&(mark[0][j]==0));
			else
				vd[4*i+j]=((table[i+1][j]==1||table[i+1][j]==120)&&(mark[i+1][j]==0));

		if(hf[4*i+j]==1&&hb[4*i+j]==0&&vu[4*i+j]==0&&vd[4*i+j]==0)
		{
			pair[(4*i)+j]=1;
			hf[4*i+j]=0;
				if(j==3)
				{
					mark[i][3]++;mark[i][0]++;
					}
				else
				{
					mark[i][j]++;mark[i][j+1]++;
					}
			}
		if(hb[4*i+j]==1&&hf[4*i+j]==0&&vu[4*i+j]==0&&vd[4*i+j]==0)
		{
			if(j==0)
			pair[(4*i)+3]=1;
			else
			pair[(4*i)+(j-1)]=1;
			hb[4*i+j]=0;
			if(j==0)
				{
					mark[i][3]++;mark[i][0]++;
					}
				else
				{
					mark[i][j]++;mark[i][j-1]++;
					}
			
			}
		if(vu[4*i+j]==1&&hf[4*i+j]==0&&hb[4*i+j]==0&&vd[4*i+j]==0)
		{
			if(i==0)
			pair[28+j]=1;
			else
			pair[16+(4*(i-1))+j]=1;
			vu[4*i+j]=0;
				if(i==0)
				{
					mark[3][j]++;mark[0][j]++;
					} 
				else
				{
					mark[i][j]++;mark[i-1][j]++;
					}
			}
		if(vd[4*i+j]==1&&hf[4*i+j]==0&&hb[4*i+j]==0&&vu[4*i+j]==0)
		{
			pair[16+(4*i)+j]=1;
			vd[4*i+j]=0;
				if(i==3)
				{
					mark[3][j]++;mark[0][j]++;
					} 
				else
				{
					mark[i][j]++;mark[i+1][j]++;
					}
			}
			
			
		}		
	}
}

for(i=0;i<4;i++)
{
	for(j=0;j<4;j++)
	{
		if(table[i][j]==1&&mark[i][j]==0)
		{
			if(j==0)
				hb[4*i+j]=((table[i][3]==1||table[i][3]==120)&&(mark[i][3]==0));
			else
				hb[4*i+j]=((table[i][j-1]==1||table[i][j-1]==120)&&(mark[i][j-1]==0));
			if(j==3)
				hf[4*i+j]=((table[i][0]==1||table[i][0]==120)&&(mark[i][0]==0));
			else
				hf[4*i+j]=((table[i][j+1]==1||table[i][j+1]==120)&&(mark[i][j+1]==0));
			if(i==0)
				vu[4*i+j]=((table[3][j]==1||table[3][j]==120)&&(mark[3][j]==0));
			else
				vu[4*i+j]=((table[i-1][j]==1||table[i-1][j]==120)&&(mark[i-1][j]==0));
			if(i==3)
				vd[4*i+j]=((table[0][j]==1||table[0][j]==120)&&(mark[0][j]==0));
			else
				vd[4*i+j]=((table[i+1][j]==1||table[i+1][j]==120)&&(mark[i+1][j]==0));
			
			if(j==3)
				a=((table[i][0]==1||table[i][0]==120)&&mark[i][0]==0);
			else
				a=((table[i][j+1]==1||table[i][0]==120)&&mark[i][j+1]==0);

			if(i==3)
				b=((table[0][j]==1||table[0][j]==120)&&mark[0][j]==0);
			else
				b=((table[i+1][j]==1||table[i+1][j]==120)&&mark[i+1][j]==0);
		
				
			if(hf[4*i+j]==1&&a==1)
		{
			pair[(4*i)+j]=1;
				if(j==3)
				{
					mark[i][3]++;mark[i][0]++;
					}
				else
				{
					mark[i][j]++;mark[i][j+1]++;
					}
					continue;
			}
		
		if(vd[4*i+j]==1&&b==1)
		{
			pair[16+(4*i)+j]=1;
				if(i==3)
				{
					mark[3][j]++;mark[0][j]++;
					} 
				else
				{
					mark[i][j]++;mark[i+1][j]++;
					}
					continue;
			}
			}
		}
}

for(i=0;i<4;i++)
{
	for(j=0;j<4;j++)
	{
		if(table[i][j]==1&&mark[i][j]==0)
		{
			if(j==0)
				hb[4*i+j]=(table[i][3]==120||table[i][3]==1);
			else
				hb[4*i+j]=(table[i][j-1]==120||table[i][j-1]==1);
			if(j==3)
				hf[4*i+j]=(table[i][0]==120||table[i][0]==1);
			else
				hf[4*i+j]=(table[i][j+1]==120||table[i][j+1]==1);
			if(i==0)
				vu[4*i+j]=(table[3][j]==120||table[3][j]==1);
			else
				vu[4*i+j]=(table[i-1][j]==120||table[i-1][j]==1);
			if(i==3)
				vd[4*i+j]=(table[0][j]==120||table[0][j]==1);
			else
				vd[4*i+j]=(table[i+1][j]==120||table[i+1][j]==1);
		
		
				
			if(hf[4*i+j]==1)
		{
			pair[(4*i)+j]=1;
				if(j==3)
				{
					mark[i][3]++;mark[i][0]++;
					}
				else
				{
					mark[i][j]++;mark[i][j+1]++;
					}
			}
		if(hb[4*i+j]==1)
		{
			if(j==0)
			pair[(4*i)+3]=1;
			else
			pair[(4*i)+(j-1)]=1;
			if(j==0)
				{
					mark[i][3]++;mark[i][0]++;
					}
				else
				{
					mark[i][j]++;mark[i][j-1]++;
					}
			
			}
		if(vu[4*i+j]==1)
		{
			if(i==0)
			pair[28+j]=1;
			else
			pair[16+(4*(i-1))+j]=1;
				if(i==0)
				{
					mark[3][j]++;mark[0][j]++;
					} 
				else
				{
					mark[i][j]++;mark[i-1][j]++;
					}
			}
		if(vd[4*i+j]==1)
		{
			pair[16+(4*i)+j]=1;
				if(i==3)
				{
					mark[3][j]++;mark[0][j]++;
					} 
				else
				{
					mark[i][j]++;mark[i+1][j]++;
					}
			}
			}
		}
}



//output expression
printf("\n\n\t\t Y =");
//output octate
for(i=0;i<8;i++)
{if(octate[i]>0)
{
	switch(i)
	{
		case 0:
			printf(" A' +");
			break;
		case 1:
			printf(" B +");
			break;
		case 2:
			printf(" A +");
			break;
		case 3:
			printf(" B' +");
			break;
		case 4:
			printf(" C' +");
			break;
		case 5:
			printf(" D +");
			break;
		case 6:
			printf(" C +");
			break;
		case 7:
			printf(" D' +");
			break;
		}
}
}

// quad output
for(i=0;i<24;i++)
{
	if(quad[i]>0)
{
	switch(i)
	{
		case 0:
			if(mark[0][0]==1||mark[0][1]==1||mark[0][2]==1||mark[0][3]==1)
			printf(" A'B' +");
			else 
			{
				mark[0][0]--;
				mark[0][1]--;
				mark[0][2]--;
				mark[0][3]--;
				}
			break;
		case 1:
			if((mark[1][0]==1||mark[1][1]==1)||(mark[1][2]==1||mark[1][3]==1))
			printf(" A'B +");
			else 
			{
				
				mark[1][0]--;
				mark[1][1]--;
				mark[1][2]--;
				mark[1][3]--;
				}
			break;
		case 2:
			if(mark[2][0]==1||mark[2][1]==1||mark[2][2]==1||mark[2][3]==1)
			printf(" AB +");
			else 
			{
				
				mark[2][0]--;
				mark[2][1]--;
				mark[2][2]--;
				mark[2][3]--;
				}
			break;
		case 3:
			if(mark[3][0]==1||mark[3][1]==1||mark[3][2]==1||mark[3][3]==1)
			printf(" AB' +");
			else 
			{
				
				mark[3][0]--;
				mark[3][1]--;
				mark[3][2]--;
				mark[3][3]--;
				}
			break;
		case 4:
			if(mark[0][0]==1||mark[1][0]==1||mark[2][0]==1||mark[3][0]==1)
			printf(" C'D' +");
			else 
			{
				
				mark[0][0]--;
				mark[1][0]--;
				mark[2][0]--;
				mark[3][0]--;
				}
			break;
		case 5:
			if(mark[0][1]==1||mark[1][1]==1||mark[2][1]==1||mark[3][1]==1)
			printf(" C'D +");
			else 
			{
				
				mark[0][1]--;
				mark[1][1]--;
				mark[2][1]--;
				mark[3][1]--;
				}
			break;
		case 6:
			if(mark[0][2]==1||mark[1][2]==1||mark[2][2]==1||mark[3][2]==1)
			printf(" CD +");
			else 
			{
				
				mark[0][2]--;
				mark[1][2]--;
				mark[2][2]--;
				mark[3][2]--;
				}
			break;
		case 7:
			if(mark[0][3]==1||mark[1][3]==1||mark[2][3]==1||mark[3][3]==1)
			printf(" CD' +");
			else 
			{
				
				mark[0][3]--;
				mark[1][3]--;
				mark[2][3]--;
				mark[3][3]--;
				}
			break;
		case 8:
			if(mark[0][0]==1||mark[0][1]==1||mark[1][0]==1||mark[1][1]==1)
			printf(" A'C' +");
			else 
			{
				
				mark[0][0]--;
				mark[0][1]--;
				mark[1][1]--;
				mark[1][0]--;
				}
			break;
		case 9:
			if((mark[0][1]==1||mark[0][2])==(1||mark[1][1]==1||mark[1][2]==1))
			printf(" A'D +");
			else 
			{
				mark[0][1]--;
				mark[0][2]--;
				mark[1][1]--;
				mark[1][2]--;
				}
			break;
		case 10:
			if(mark[0][2]==1||mark[0][3]==1||mark[1][2]==1||mark[1][3]==1)
			printf(" A'C +");
			else 
			{
				
				mark[0][2]--;
				mark[0][3]--;
				mark[1][2]--;
				mark[1][3]--;
				}
			break;
		case 11:
			if(mark[1][0]==1||mark[1][1]==1||mark[2][0]==1||mark[2][1]==1)
			printf(" BC' +");
			else 
			{
				
				mark[1][0]--;
				mark[1][1]--;
				mark[2][0]--;
				mark[2][1]--;
				}
			break;
		case 12:
			if(mark[1][1]==1||mark[1][2]==1||mark[2][1]==1||mark[2][2]==1)
			printf(" BD +");
			else 
			{
				
				mark[1][1]--;
				mark[1][2]--;
				mark[2][1]--;
				mark[2][2]--;
				}
			break;
		case 13:
			if(mark[1][2]==1||mark[1][3]==1||mark[2][2]==1||mark[2][3]==1)
			printf(" BC +");
			else 
			{
				
				mark[1][2]--;
				mark[1][3]--;
				mark[2][2]--;
				mark[2][3]--;
				}
			break;
		case 14:
			if(mark[2][0]==1||mark[2][1]==1||mark[3][0]==1||mark[3][1]==1)
			printf(" AC' +");
			else 
			{
				
				mark[2][0]--;
				mark[2][1]--;
				mark[3][0]--;
				mark[3][1]--;
				}
			break;
		case 15:
			if(mark[2][1]==1||mark[2][2]==1||mark[3][1]==1||mark[3][2]==1)
			printf(" AD +");
			else 
			{
				
				mark[2][1]--;
				mark[2][2]--;
				mark[3][1]--;
				mark[3][2]--;
				}
			break;
		case 16:
			if(mark[2][2]==1||mark[2][3]==1||mark[3][2]==1||mark[3][3]==1)
			printf(" AC +");
			else 
			{
				
				mark[2][2]--;
				mark[2][3]--;
				mark[3][2]--;
				mark[3][3]--;
				}
			break;
		case 17:
			if(mark[0][0]==1||mark[1][0]==1||mark[0][3]==1||mark[1][3]==1)
			printf(" A'D' +");
			else 
			{
				
				mark[0][0]--;
				mark[1][0]--;
				mark[0][3]--;
				mark[1][3]--;
				}
			break;
		case 18:
			if(mark[1][0]==1||mark[2][0]==1||mark[1][3]==1||mark[2][3]==1)
			printf(" BD' +");
			else 
			{
				
				mark[1][0]--;
				mark[2][0]--;
				mark[1][3]--;
				mark[2][3]--;
				}
			break;
		case 19:
			if(mark[2][0]==1||mark[3][0]==1||mark[2][3]==1||mark[3][3]==1)
			printf(" AD' +");
			else 
			{
				
				mark[2][0]--;
				mark[3][0]--;
				mark[2][3]--;
				mark[3][3]--;
				}
			break;
		case 20:
			if(mark[3][0]==1||mark[3][1]==1||mark[0][0]==1||mark[0][1]==1)
			printf(" B'C' +");
			else 
			{
				
				mark[3][0]--;
				mark[3][1]--;
				mark[0][0]--;
				mark[0][1]--;
				}
			break;
		case 21:
			if(mark[3][1]==1||mark[3][2]==1||mark[0][1]==1||mark[0][2]==1)
			printf(" B'D +");
			else 
			{
				
				mark[3][1]--;
				mark[3][2]--;
				mark[0][1]--;
				mark[0][2]--;
				}
			break;
		case 22:
			if(mark[3][2]==1||mark[3][3]==1||mark[0][2]==1||mark[0][3]==1)
			printf(" B'C +");
			else 
			{
				
				mark[3][2]--;
				mark[3][3]--;
				mark[0][2]--;
				mark[0][3]--;
				}
			break;
		case 23:
			if(mark[0][0]==1||mark[0][3]==1||mark[3][0]==1||mark[3][3]==1)
			printf(" B'D' +");
			else 
			{
				
				mark[0][0]--;
				mark[0][3]--;
				mark[3][0]--;
				mark[3][3]--;
				}
			break;
			}
}
}




// pairs
for(i=0;i<32;i++)
{
	if(pair[i]==1)
	{
		switch(i)
		{
			
		case 0:
			if(mark[0][0]==1||mark[0][1]==1)
			printf(" A'B'C' +");
			else
			{
				mark[0][0]--;
				mark[0][1]--;
				}
			break;
		case 1:
			if(mark[0][1]==1||mark[0][2]==1)
			printf(" A'B'D +");
			else
			{
				mark[0][1]--;
				mark[0][2]--;
				}
			break;
		case 2:
			if(mark[0][2]==1||mark[0][3]==1)
			printf(" A'B'C +");
			else
			{
				mark[0][2]--;
				mark[0][3]--;
				}
			break;
		case 3:
			if(mark[0][3]==1||mark[0][0]==1)
			printf(" A'B'D' +");
			else
			{
				mark[0][3]--;
				mark[0][0]--;
				}
			break;
		case 4:
			if(mark[1][0]==1||mark[1][1]==1)
			printf(" A'BC' +");
			else
			{
				mark[1][0]--;
				mark[1][1]--;
				}
			break;
		case 5:
			if(mark[1][1]==1||mark[1][2]==1)
			printf(" A'BD +");
			else
			{
				mark[1][1]--;
				mark[1][2]--;
				}
			break;
		case 6:
			if(mark[1][2]==1||mark[1][3]==1)
			printf(" A'BC +");
			else
			{
				mark[1][2]--;
				mark[1][3]--;
				}
			break;
		case 7:
			if(mark[1][3]==1||mark[1][0]==1)
			printf(" A'BD' +");
			else
			{
				mark[1][3]--;
				mark[1][0]--;
				}
			break;
		case 8:
			if(mark[2][0]==1||mark[2][1]==1)
			printf(" ABC' +");
			else
			{
				mark[2][0]--;
				mark[2][1]--;
				}
			break;
		case 9:
			if(mark[2][1]==1||mark[2][2]==1)
			printf(" ABD +");
			else
			{
				mark[2][1]--;
				mark[2][2]--;
				}
			break;
		case 10:
			if(mark[2][2]==1||mark[2][3]==1)
			printf(" ABC +");
			else
			{
				mark[2][2]--;
				mark[2][3]--;
				}
			break;
		case 11:
			if(mark[2][3]==1||mark[2][0]==1)
			printf(" ABD' +");
			else
			{
				mark[2][3]--;
				mark[2][0]--;
				}
			break;
		case 12:
			if(mark[3][0]==1||mark[3][1]==1)
			printf(" AB'C' +");
			else
			{
				mark[3][0]--;
				mark[3][1]--;
				}
			break;
		case 13:
			if(mark[3][1]==1||mark[3][2]==1)
			printf(" AB'D +");
			else
			{
				mark[3][1]--;
				mark[3][2]--;
				}
			break;
		case 14:
			if(mark[3][2]==1||mark[3][3]==1)
			printf(" AB'C +");
			else
			{
				mark[3][2]--;
				mark[3][3]--;
				}
			break;
		case 15:
			if(mark[3][3]==1||mark[3][0]==1)
			printf(" AB'D' +");
			else
			{
				mark[3][3]--;
				mark[3][0]--;
				}
			break;
		case 16:
			if(mark[0][0]==1||mark[1][0]==1)
			printf(" A'C'D' +");
			else
			{
				mark[0][0]--;
				mark[1][0]--;
				}
			break;
		case 17:
			if(mark[0][1]==1||mark[1][1]==1)
			printf(" A'C'D +");
			else
			{
				mark[0][1]--;
				mark[1][1]--;
				}
			break;
		case 18:
			if(mark[0][2]==1||mark[1][2]==1)
			printf(" A'CD +");
			else
			{
				mark[0][2]--;
				mark[1][2]--;
				}
			break;
		case 19:
			if(mark[0][3]==1||mark[1][3]==1)
			printf(" A'CD' +");
			else
			{
				mark[0][3]--;
				mark[1][3]--;
				}
			break;
		case 20:
			if(mark[1][0]==1||mark[2][0]==1)
			printf(" BC'D' +");
			else
			{
				mark[1][0]--;
				mark[2][0]--;
				}
			break;
		case 21:
			if(mark[1][1]==1||mark[2][1]==1)
			printf(" BC'D +");
			else
			{
				mark[1][1]--;
				mark[2][1]--;
				}
			break;
		case 22:
			if(mark[1][2]==1||mark[2][2]==1)
			printf(" BCD +");
			else
			{
				mark[1][2]--;
				mark[2][2]--;
				}
			break;
		case 23:
			if(mark[1][3]==1||mark[2][3]==1)
			printf(" BCD' +");
			else
			{
				mark[1][3]--;
				mark[2][3]--;
				}
			break;
		case 24:
			if(mark[2][0]==1||mark[3][0]==1)
			printf(" AC'D' +");
			else
			{
				mark[2][0]--;
				mark[3][0]--;
				}
			break;
		case 25:
			if(mark[2][1]==1||mark[3][1]==1)
			printf(" AC'D +");
			else
			{
				mark[2][1]--;
				mark[3][1]--;
				}
			break;
		case 26:
			if(mark[2][2]==1||mark[3][2]==1)
			printf(" ACD +");
			else
			{
				mark[2][2]--;
				mark[3][2]--;
				}
			break;
		case 27:
			if(mark[2][3]==1||mark[3][3]==1)
			printf(" ACD' +");
			else
			{
				mark[2][3]--;
				mark[3][3]--;
				}
			break;
		case 28:
			if(mark[3][0]==1||mark[0][0]==1)
			printf(" B'C'D' +");
			else
			{
				mark[3][0]--;
				mark[0][0]--;
				}
			break;
		case 29:
			if(mark[3][1]==1||mark[0][1]==1)
			printf(" B'C'D +");
			else
			{
				mark[3][1]--;
				mark[0][1]--;
				}
			break;
		case 30:
			if(mark[3][2]==1||mark[0][2]==1)
			printf(" B'CD +");
			else
			{
				mark[3][2]--;
				mark[0][2]--;
				}
			break;
		case 31:
			if(mark[3][3]==1||mark[0][3]==1)
			printf(" B'CD' +");
			else
			{
				mark[3][3]--;
				mark[0][3]--;
				}
			break;
			
			}
	}
}



//for singles...
for(i=0;i<4;i++)
{
	for(j=0;j<4;j++)
	{
		if(table[i][j]==1&&mark[i][j]==0)
		{
			switch(i)
			{
				case 0:
					if(j==0)
					printf(" A'B'C'D' +");
					if(j==1)
					printf(" A'B'C'D +");
					if(j==2)
					printf(" A'B'CD +");
					if(j==3)
					printf(" A'B'CD' +");
					break;
	
				case 1:
					if(j==0)
					printf(" A'BC'D' +");
					if(j==1)
					printf(" A'BC'D +");
					if(j==2)
					printf(" A'BCD +");
					if(j==3)
					printf(" A'BCD' +");
					break;
					
				case 2:
					if(j==0)
					printf(" ABC'D' +");
					if(j==1)
					printf(" ABC'D +");
					if(j==2)
					printf(" ABCD +");
					if(j==3)
					printf(" ABCD' +");
					break;
					
				case 3:
					if(j==0)
					printf(" AB'C'D' +");
					if(j==1)
					printf(" AB'C'D +");
					if(j==2)
					printf(" AB'CD +");
					if(j==3)
					printf(" AB'CD' +");
					break;
				}
			}
		}
}
/*
printf("\n\n\tmark");
for(i=0;i<4;i++)
{
	printf("\n\n\t");
	for(j=0;j<4;j++)
	{
		printf("%d\t",mark[i][j]);
		}
}
*/
 fflush(stdin);
printf("\n\n\tProgram Ended\n\n\tTo Restart Program press 1 and hit Enter\n\n\tTo Exit press 0 and hit Enter\n\t");
scanf("%d",&i);
  if(i==1)
  main();
return 0;
}

