#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cfloat>
#include<ctime>
using namespace std;
float xfirstx;
float yfirsty;
float xsecondx;
float ysecondy;
class mymath{
public:
  float mysqrt(const float x){
  const double prec=0.00001;
  float low,high,anstry;
    if (x < 1){
    low = x;
    high = 1;
   }
   else{
    low = 1;
    high = x;
   }
   while ((high-low) > prec){
    anstry = (low+high)/2;
    if(anstry*anstry>x)
     high=anstry;
    else
     low=anstry;
   }
   return (low + high)/2;
  }
};
class points{
  float x;
  float y;
public:
  float showx(){
      return x;
  }
  float showy(){
      return y;
  }
  void setx(float in){
    x=in;
  }
  void sety(float in){
    y=in;
  }
  int xpartition(points arr[],int p,int q){
  int k=p;
  for(int i=p+1;i<=q;i++){
    if(arr[i].showx()<arr[p].showx()){
      k++;
      points temp=arr[k];
      arr[k]=arr[i];
      arr[i]=temp;
    }
  }
  points temp=arr[p];
  arr[p]=arr[k];
  arr[k]=temp;
  return k;
    }
  int ypartition(points arr[],int p,int q){
  int k=p;
  for(int i=p+1;i<=q;i++){
    if(arr[i].showy()<arr[p].showy()){
      k++;
      points temp=arr[k];
      arr[k]=arr[i];
      arr[i]=temp;
    }
  }
    points temp=arr[p];
    arr[p]=arr[k];
    arr[k]=temp;
    return k;
      }
  void xquicksort(points arr[],int p,int q){
    if(p<q){
    int k=xpartition(arr,p,q);
    xquicksort(arr,p,k-1);
    xquicksort(arr,k+1,q);
    }
  }
  void yquicksort(points arr[],int p,int q){
    if(p<q){
    int k=ypartition(arr,p,q);
    yquicksort(arr,p,k-1);
    yquicksort(arr,k+1,q);
    }
  }
  float absolutevalue(float x){
    if(x<0) return -x;
    else return x;
  }

  float dist(points a, points b){
    mymath callobj;
    return callobj.mysqrt(((a.showx()-b.showx())*(a.showx()-b.showx())+(a.showy()-b.showy())*(a.showy()-b.showy())));
}
float findinstrip(points strip[],float del,int length){
float mind=del;
    int j;
    for(int i=0;i<length;i++){
      for(int j=i+1;j<length && strip[j].showy()-strip[i].showy()<mind;j++){
        if(strip[0].dist(strip[i],strip[j])<mind){
          mind=strip[0].dist(strip[i],strip[j]);
          xfirstx=strip[i].showx();
          yfirsty=strip[i].showy();
          xsecondx=strip[j].showx();
          ysecondy=strip[j].showy();
      }
    }
  }
  return mind;
}
float findclosestpair(points xsorted[],points ysorted[], int n){
  if(n<=5){
    static float d=FLT_MAX;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(xsorted[0].dist(xsorted[i],xsorted[j])<d){
          d=xsorted[0].dist(xsorted[i],xsorted[j]);
          xfirstx=xsorted[i].showx();
          yfirsty=xsorted[i].showy();
          xsecondx=xsorted[j].showx();
          ysecondy=xsorted[j].showy();
        }
      }
    }
    return d;
  }
  else{
  int mid=n/2;
  float xmid=xsorted[mid].showx();
  points yl[mid+1],yr[n-mid-1];
  int ylpos=0,yrpos=0;
  for(int i=0;i<n;i++){
      if(ysorted[i].showx()<=xmid){
        yl[ylpos]=ysorted[i];
        ylpos++;
      }
      else{
        yr[yrpos]=ysorted[i];
        yrpos++;
      }
    }
  float lmin=findclosestpair(xsorted,yl,mid+1);
  float rmin=findclosestpair(xsorted+mid+1,yr,n-mid-1);
  float del=min(lmin,rmin);
  int ypos=0;
  points ystrip[n];
  for(int i=0;i<n;i++){
      if(xsorted[0].absolutevalue(ysorted[i].showx()-xmid)<del){
        ystrip[ypos]=ysorted[i];
        ypos++;
      }
}
if(del<findinstrip(ystrip,del,ypos))  return del;
else return findinstrip(ystrip,del,ypos);
}
}
};
int main(){
int n;
points callingobject;
cout<<"Give the number of points : ";
cin>>n;
points input[n],xsorted[n],ysorted[n];
// srand(time(NULL));
for(int i=0;i<n;i++){
  input[i].setx(((float)(rand())/(float)(RAND_MAX))*(100));
  input[i].sety(((float)(rand())/(float)(RAND_MAX))*(100));
  xsorted[i]=input[i];
  ysorted[i]=input[i];
}
int time1=clock();
callingobject.xquicksort(xsorted,0,n-1);
callingobject.yquicksort(ysorted,0,n-1);
float distance=callingobject.findclosestpair(xsorted,ysorted,n);
int time2=clock();
cout<<"The closest pair of points are ("<<xfirstx<<","<<yfirsty<<") and ("<<xsecondx<<","<<ysecondy<<")."<<endl;
cout<<"The distance between them is "<<distance<<"."<<endl;
cout<<"The time taken for the computation is "<<(time2-time1)<<" microseconds"<<endl;
return 0;
}
