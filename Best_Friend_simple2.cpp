#include<bits/stdc++.h>
using namespace std;
int x;
int b;
pair<double, double> p[100000];

double distance (pair<double, double> a, pair<double, double> b){
    return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
}

int main(){
    cin >> x;
    while (x>0)
    {
        /* code */
        cin >> b;
        pair<double,double> p[100000];
        for(int i=0;i<b;i++)cin>>p[i].first>>p[i].second;
        sort(p,p+b);
        double d = 5e18; 
        for(int i=0;i<=b-1;i++){
            for(int j=i+1;j<=b-1;j++){
            if(p[j].first > p[i].first + d){
               break;
            }else{
            d = min(d, distance(p[i],p[j]));
            }
        }
    }
        cout<<d<<endl;
        x--;
    }
}