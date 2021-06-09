#include <bits/stdc++.h>
using namespace std;
long double pi=M_PI;
struct scan_point
{
    double longi,lati,magnetic_field,nebu;
};
vector<scan_point>v;
vector<double>nebulosity_values;
vector<double>distances;
double toRadians(const double degree)
{
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
double distance(double lat1, double lat2, double long1, double long2)
{
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     double dlong = long2 - long1;
     double dlat = lat2 - lat1;
     double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
    ans = 2 * asin(sqrt(ans));
     double R = 6371;
    ans = ans * R;

    return ans;
}
vector<double>ratios;
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    double sum1=0.00,sum=0.00,a,b,c,d,e,latitude_start,latitude_end,longitude_start,longitude_end;
    int cnt=0,cnt2=0,cnt3=0;
    while(scanf("%lf",&b)!=EOF)
    {
        scanf("%lf %lf %lf",&c,&d,&e);
        cnt2++;
        if(cnt2==1)
        {
            latitude_start=b;
            longitude_start=c;
        }
        if(e>0.5&&e<99.5)
        {
            scan_point aj;
            aj.lati=b;
            aj.longi=c;
            aj.magnetic_field=d;
            aj.nebu=e;
            v.push_back(aj);
            sum+=e;
            sum1+=e;
            cnt++;
            cnt3++;
        }
    }
    printf("%lf %d: %lf\n\n",sum,cnt,sum/cnt);
    int cnt5=0,averages=0;
     double suma=0,sumamag=0;
    for(register int i=0;i<v.size();i++)
    {
        if(cnt5==0)
        {
            latitude_start=v[i].lati;
            longitude_start=v[i].longi;
        }
        cnt5++;
        suma+=v[i].nebu;
        sumamag+=v[i].magnetic_field;
        if(cnt5==5)
        {
            averages++;
            printf("Step %d:\nAverage nebulosity: %lf\nAverage magnetic_field: %lf\nLat&Long Start Point: %lf %lf\nLat&Long End Point: %lf %lf\n",averages,suma/5,sumamag/5,latitude_start,longitude_start,v[i].lati,v[i].longi);
            ratios.push_back((suma/5)/(sumamag/5));
            nebulosity_values.push_back(suma/5);
            distances.push_back(distance(latitude_start,v[i].lati,longitude_start,v[i].longi));
            printf("Distance between points: %lf km\n\n",distance(latitude_start,v[i].lati,longitude_start,v[i].longi));
            suma=sumamag=0;
            cnt5=0;
        }
        ///printf("Scan Point %d:\n",i+1);
        ///printf("Latitude: %lf\nLongitude: %lf\nMagnetic Field: %lf\nNebulosity: %lf\n",v[i].lati,v[i].longi,v[i].magnetic_field,v[i].nebu);
        ///printf("\n");
    }
    int i=v.size()-1;
    averages++;
    printf("Step %d:\nAverage nebulosity: %lf\nAverage magnetic_field: %lf\nLat&Long Start Point: %lf %lf\nLat&Long End Point: %lf %lf\n",averages,suma/4,sumamag/4,latitude_start,longitude_start,v[i].lati,v[i].longi);
    printf("Distance between points: %lf km\n\n",distance(latitude_start,v[i].lati,longitude_start,v[i].longi));
    ratios.push_back((suma/5)/(sumamag/5));
    nebulosity_values.push_back(suma/5);
    distances.push_back(distance(latitude_start,v[i].lati,longitude_start,v[i].longi));
    for(register int i=0;i<ratios.size();i++)
        printf("%lf\n",ratios[i]);
    for(register int i=0;i<nebulosity_values.size();i++)
        printf("%lf\n",nebulosity_values[i]);
    for(register int i=0;i<distances.size();i++)
        printf("%lf\n",distances[i]);
    return 0;
}
