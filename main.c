#include <stdio.h>
#include <stdlib.h>
#include <bmpio.h>
unsigned char pic[2000][2000][3];
unsigned char ans[2000][2000][3];
unsigned char ans2[2000][2000][3];
double rad[2000][2000];
double sot[2000][2000];
void resize (unsigned char p[2000][2000][3],int wid,int hei,int nwid,int nhei,char name[]){

	for(int i=0;i<2000;i++){
		for(int j=0;j<2000;j++){
			for(int k=0;k<3;k++){
				ans[i][j][k]=0;
				ans2[i][j][k]=0;
			}
		}
	}
	
		
	double a=nwid/1.0/wid;
	double e=nhei/1.0/hei;
	for(int i=0;i<nwid;i++){
		for(int j=0;j<wid;j++){
			rad[i][j]=0.0;
		}
	}
	double m=a;
	int t=0;
	if(nwid>=wid){
		for(int i=0;i<nwid;i++){
			if(m>=1){
				rad[i][t]=1;
				m--;
				continue;	
			}
			if(m<1){
				rad[i][t]=m;
				rad[i][t+1]=1-m;
				m=a-(1-m);
				t++;
				continue;
			}
			if(m==0)
			m=a;
		}
	}
	else{
		m=1;
		for(int i=0;i<wid;i++){
			if(m>=a){
				rad[t][i]=a;
				m-=a;
				continue;
			}
			else{
				rad[t][i]=m;
				rad[t+1][i]=a-m;
				m=1-(a-m);
				t++;
				continue;
			}
			if(m==0)
			m==1;
			
		}
	}
		for(int i=0;i<nhei;i++){
		for(int j=0;j<hei;j++){
			sot[i][j]=0.0;
		}
	}
	
	m=e;
    t=0;
    if(nhei>=hei){
	for(int i=0;i<nhei;i++){
			if(m>=1){
				sot[i][t]=1;
				m--;
				continue;
			}
			if(m<1){
				sot[i][t]=m;
				sot[i][t+1]=1-m;
				m=e-(1-m);
				t++;
				continue;
			}
			if(m==0)
			m=e;
		}
	}
		else{
		m=1;
		for(int i=0;i<hei;i++){
			if(m>=e){
				sot[t][i]=e;
				m-=e;
				continue;
			}
			else{
				sot[t][i]=m;
				sot[t+1][i]=e-m;
				m=1-(e-m);
				t++;
				continue;
			}
			if(m==0)
			m==1;
			
		}
	}
	
	
	
	for(int i=0;i<hei;i++){
		for(int j=0;j<nwid;j++){
			for(int k=0;k<wid;k++){
				ans[i][j][0]+=p[i][k][0]*rad[j][k];
				ans[i][j][1]+=p[i][k][1]*rad[j][k];
				ans[i][j][2]+=p[i][k][2]*rad[j][k];
			}
		}
	}
	for(int j=0;j<nwid;j++){
		for(int i=0;i<nhei;i++){
			for(int k=0;k<hei;k++){
				ans2[i][j][0]+=ans[k][j][0]*sot[i][k];
				ans2[i][j][1]+=ans[k][j][1]*sot[i][k];
				ans2[i][j][2]+=ans[k][j][2]*sot[i][k];
			}
		}
	}
	saveBMP(ans2,nwid,nhei,name);
	printf("file ba name %s zakhire shod\n",name);
}
int main() {
	int n,arz,tool,b=1,nwid,nhei;
	char num[80];
	double t,a;
	char p[100];
	printf("tedad aks ra vared konid:  ");
	scanf("%d",&n);
	for(int q=1;q<=n;q++){
		printf("addrese akse %d ra vared konid:  ",q);
		scanf("\n");
		gets(p);
		printf("arz va ertefaye jadid ra vared konid:  ");
		scanf("%d %d",&nwid,&nhei);
		
		int wid,hei,maxt,mint,maxa,mina;
 		readBMP(p,&wid,&hei,pic);
		sprintf( num,"ans%d.bmp",b);
		resize(pic,wid,hei,nwid,nhei,num);
   		b++;
}
	return 0;
}
