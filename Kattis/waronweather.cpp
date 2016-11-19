/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: waronweather
 * Problem Title: War on Weather
 * Keyword: computation geometry
 *
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN 101
#define eps 1e-8

int eps_compare(const double& x, const double& y)
{
	double delta = x - y;
	if(fabs(delta) < eps) return 0;
	else return delta < 0 ? -1 : 1;
}

class Vector_3D{
	public:
	double x, y, z;
	Vector_3D(double _x=0, double _y=0, double _z=0):x(_x), y(_y), z(_z){}
	Vector_3D(const Vector_3D& _s, const Vector_3D& _e):x(_e.x - _s.x), y(_e.y - _s.y), z(_e.z - _s.z){}

	double get_length()const
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}
	
	Vector_3D do_cross_product(const Vector_3D& v)const
	{
		return Vector_3D(y * v.z - z * v.y, \
				 z * v.x - x * v.z, \
				 x * v.y - y * v.x);
	}

	double do_dot_product(const Vector_3D& v)const
	{
		return x * v.x + y * v.y + z * v.z;
	}
	
	/* get area of the parallelogram*/
	double get_area(const Vector_3D& v)const
	{
		return this->do_cross_product(v).get_length();
	}
};

int main()
{
	int k,m;
	Vector_3D sat[MAXN], target[MAXN];
	bool is_ok[MAXN];
	const double r = 40000 / (2 * M_PI);
	while(scanf("%d %d", &k, &m), k != 0 && m != 0){
		int count = 0;
		for(int i = 0;i < k;i++) scanf("%lf %lf %lf", &sat[i].x, &sat[i].y, &sat[i].z);
		for(int i = 0;i < m;i++) scanf("%lf %lf %lf", &target[i].x, &target[i].y, &target[i].z);
		memset(is_ok, 0, sizeof(is_ok));
		for(int i = 0;i < k;i++){
			const Vector_3D& cur = sat[i];
			for(int j = 0;j < m;j++){
				if(is_ok[j]) continue;
				double dis = cur.do_dot_product(target[j]) / r;
				if(eps_compare(dis, r) >= 0){
					count++;
					is_ok[j] = 1;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
