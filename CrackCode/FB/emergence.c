/* Given a sorted array, find the emergence of given number.
 * Use Binary search to find the first occurrence of the number and binary search for the last occurrence of the number then result is (j-i+1)
 */


int
first_occ (int arr[], int l, int h, int target) 
{
	if (l>h) 
		return -1;

	int mid = l+ (h-l)/2;

	if (arr[mid] == target && (mid==0 || arr[mid-1] < target)) {
			return mid;
	}

	if (arr[mid] > target) {
		return first_occ (arr, l, mid-1, target);
	} else {
		return first_occ (arr, mid+1, h, target);
	}

}

int last_occ (int arr[], int l, int h, int n, int target) 
{
	if (l>h)
		return -1;

	int mid = l+ (h-l)/2;

	if (arr[mid] == target && (mid == n-1|| arr[mid+1] > target)) {
		return mid;
	}

	if (arr[mid] > target) {
		return last_occ (arr, l, mid-1, n, target);
	} else {
		return last_occ (arr, mid+1, h, n, target);
	}
}

int find (int arr[], int n, int target) {
	int f = 0, l =0;

	f = first_occ (arr, 0, n-1, target);
	l = last_occ (arr, 0, n-1, n, target);

	printf ("Number %d occurs from %d to %d.\n", target, f, l);
}


