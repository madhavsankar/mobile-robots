#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stdio.h>      /* printf, scanf, puts, NULL */
#include<stdlib.h>     /* srand, rand */
#include<time.h>
#include<omp.h>
#define ll long long

using namespace std;

int setsize(set<ll> arr[], ll size[],ll n) {
	for (ll i = 0; i < n; ++i) {
		size[i] = arr[i].size();
	}
	for (ll i = 0; i < n; ++i) {
		if (size[i] != 1)
			return 0;
	}
	return 1;
}

void randomize(set<ll> arr[],ll n) {
	for (ll i = 0; i < n; ++i) {
		ll temp = rand() % n + 1;
		ll temp2 = rand() % n + 1;
		set<ll> t = arr[temp-1];
		arr[temp-1] = arr[temp2-1];
		arr[temp2-1] = t;
		//cout<<"\n"<<temp<<temp2<<"\n";
	}
}

void printrobots(set<ll> arr[], ll n) {
	for (ll i = 0; i < n; ++i) {
		set<ll> t = arr[i];
		cout << "Node : " << i << " has robots ";
		for (set<ll>::iterator it = t.begin(); it != t.end(); it++) {
			cout << *it<<" ";
		}
		cout << "\n";
	}
}

void dispersion(set<ll> arr[],ll n) {
	int count=0;
	while (1) {
		count++;
		ll size[10];
		ll move[10];
		ll temp[10];
		for (ll i = 0; i < n; ++i) {
			move[i] = 0;
			temp[i] = -1;
		}
		randomize(arr, n);
		cout<<"Round : "<<count<<"\n";
		printrobots(arr, n);
		
		ll val = setsize(arr, size, n);
		
		if (val == 1) {
			return;
		}
		
		#pragma omp parallel for
		for (ll i = 0; i < n; ++i) {
			if (size[i] > 1) {
				ll j = (i + 1) % n;
				while (j != i) {
					if (size[j] > 1) {
						break;
					}
					if (size[j] == 0) {
						move[i] = 1;
						break;
					}
					j = (j + 1) % n;
				}
			}
			else if (size[i] == 1) {
				int fl1 = 0,fl2 = 0;
				ll j = (i + 1) % n;
				while (j != i) {
					if (size[j] > 1) {
						break;
					}
					if (size[j] == 0) {
						fl1 = 1;
						break;
					}
					j = (j + 1) % n;
				}
				j = (i + n - 1) % n;
				while (j != i) {
					if (size[j] > 0) {
						fl2 = 1;
						break;
					}
					j = (j + n - 1) % n;
				}
				
				if(fl1 == 1 && fl2 == 1)
					move[i] = 1;
			}
		}
		

		//movements
		#pragma omp parallel for
		for (ll i = 0; i < n; ++i) {
			if (move[i] == 1) {
				ll r = *(arr[i].begin());
				set<ll>::iterator it;
				it = arr[i].find(r);
				arr[i].erase(it);
				temp[(i + 1) % n] = r;
			}
		}
	
		#pragma omp parallel for
		for (ll i = 0; i < n; ++i) {
			if (temp[i] != -1) {
				arr[i].insert(temp[i]);
			}
		}
		
	}
}

int main() {
	ll n;
	cout<<"Enter number of nodes\n";
	cin >> n;
	set<ll> arr[10];
	srand(time(NULL));
	cout<<"Enter the robot configuration\n";
	for (ll i = 0; i < n; ++i) {
		set<ll> t; //temp set storing all robots in this node
		ll k;
		cin >> k;
		for (ll j = 0; j < k; ++j) {
			ll t2; cin >> t2;
			t.insert(t2);
		}
		arr[i] = t;
	}
	dispersion(arr, n);
}
