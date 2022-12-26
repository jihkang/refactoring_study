#include <iostream>

using namespace std;

int arr[500001];
int tmp[500001];
void merge(int s, int e, int& cnt) {
	int i, j;
	int mid;
	int	ind;

	i = s;
	ind = 0;
	mid = (s + e) / 2;
	j = mid + 1;
	while (i <= mid && j <= e) {
		if (arr[i] > arr[j]) {
			tmp[ind] = arr[j];
			j++;
		}
		else
		{
			tmp[ind] = arr[i];
			i++;
		}
		ind++;
	}
	while (i <= mid) {
		tmp[ind] = arr[i];
		ind++;
		i++;
	}
	while (j <= e) {
		tmp[ind] = arr[j];
		j++;
		ind++;
	}
	i = s;
	ind = 0;
	while (i <= e) {
		arr[i] = tmp[ind];
		i++;
		if (cnt == 1) {
			cout << tmp[ind] << "\n";
		}
		cnt--;
		ind++;
	}
}

void mergeSort(int s, int e, int& cnt) {
	if (s >= e)
		return ;
	int mid = (s + e) / 2;
	mergeSort(s, mid, cnt);
	mergeSort(mid + 1, e, cnt);
	merge(s, e, cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];	
	}
	mergeSort(0, n - 1 , m);
	if (m > 0) 
		cout << "-1" << "\n";
	return 0;
}